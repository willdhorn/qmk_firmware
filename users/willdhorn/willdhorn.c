#include QMK_KEYBOARD_H

#include "willdhorn.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Default Layers
  [_QWERTY]     = LAYER_QWERTY,
  [_COLEMAK_DH] = LAYER_COLEMAK_DH,
  [_ISRT]       = LAYER_ISRT,
  // Standard Layers
  [_EXT]        = LAYER_EXT,
  [_SYM]        = LAYER_SYM,
  [_NUM]        = LAYER_NUM,
  [_ADJUST]     = LAYER_ADJUST,
  // Additional Layers
  [_VSCODE]     = LAYER_VSCODE,
  [_DESKTOP]    = LAYER_DESKTOP,
  [_WNDW_HALF]  = LAYER_WNDW_HALF,
  [_WNDW_QUAD]  = LAYER_WNDW_QUAD,
  [_WNDW_THRD]  = LAYER_WNDW_THRD,
  [_WNDW_SIXT]  = LAYER_WNDW_SIXT,
  [_WNDW_NINT]  = LAYER_WNDW_NINT,
};

// DON'T MAKE THIS CONST
tap_hold_action_t tap_hold_actions[] = {
  [THA_BKSP] = TH_ACTION_BKSP,
  [THA_ENTER] = TH_ACTION_ENTER,
  [THA_ESC] = TH_ACTION_ESC,

  [THA_COMMA] = TH_ACTION_COMMA,
  [THA_DOT] = TH_ACTION_DOT,
  [THA_QUOT] = TH_ACTION_QUOT,

  [THA_MINS] = TH_ACTION_MINS,
  [THA_SLSH] = TH_ACTION_SLSH,
  [THA_EQLS] = TH_ACTION_EQLS,
  [THA_TILD] = TH_ACTION_TILD,

  [THA_LCBR] = TH_ACTION_LCBR,
  [THA_LPRN] = TH_ACTION_LPRN,
  [THA_LBRC] = TH_ACTION_LBRC,
  [THA_LABK] = TH_ACTION_LABK,

  [THA_LEFT] = TH_ACTION_LEFT,
  [THA_ALT_LFT] = TH_ACTION_ALT_LFT,
  [THA_RIGHT] = TH_ACTION_RIGHT,
  [THA_ALT_RGT] = TH_ACTION_ALT_RGT,

  [THA_UNDO_Z] = TH_ACTION_UNDO_Z,
  [THA_CUT_X] = TH_ACTION_CUT_X,
  [THA_COPY_C] = TH_ACTION_COPY_C,
  [THA_PASTE_D] = TH_ACTION_PASTE_D,
  [THA_CLIPBOARD_V] = TH_ACTION_CLIPBOARD_V,

  [THA_LK_DEF] = TH_ACTION_LK_DEF,
  [THA_LK_SYM] = TH_ACTION_LK_SYM,
};
// clang-format on

void matrix_scan_user(void) {
  matrix_scan_tap_hold();
#ifdef AUDIO_ENABLE
  matrix_scan_audio_user();
#endif
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool pressed = record->event.pressed;

  dprintln();
#ifdef DEBUG_KEYCODE_PRINT
  if (pressed) {
    DEBUG_KEYCODE_HEX(keycode);
    DEBUG_KEYCODE_BINARY(keycode);
  }
#endif

  process_record_tap_hold(keycode, record);
  process_vscode_keys(keycode, record);
  process_led_keys(keycode, record);
  process_default_layer_keys(keycode, record);
  process_mod_tap_keys(keycode, record);

  // Execute keymap specific handling first
  if (!process_record_keymap(keycode, record)) {
    return false;
  }

  // Process custom keycodes
  return process_keycode_user(keycode, record);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
#ifndef BILATERAL_COMBINATIONS
  if (IS_MOD_TAP(keycode)) {
    return 300;
  }
#endif
  switch (keycode) {
    case OSX_APP_PREV:
    case OSX_APP_WNDW:
    case OSX_APP_NEXT:
      return 140;
    default:
      return TAPPING_TERM;
  }
}

__attribute__((weak)) void rgb_matrix_indicators_keymap(void) {
  return;
}

void rgb_matrix_indicators_user(void) {
  set_all_layer_colors(layer_state);
  rgb_matrix_indicators_keymap();
}
