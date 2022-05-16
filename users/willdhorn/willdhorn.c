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
