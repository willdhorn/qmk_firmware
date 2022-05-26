#include QMK_KEYBOARD_H

#include "willdhorn.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Default Layers
  [_COLEMAK_DH] = LAYER_COLEMAK_DH,
#ifdef USE_LAYOUT_QWERTY
  [_QWERTY]     = LAYER_QWERTY,
#endif
#ifdef USE_LAYOUT_ISRT
  [_ISRT]       = LAYER_ISRT,
#endif
  // Standard Layers
  [_EXT]        = LAYER_EXT,
  [_SYM]        = LAYER_SYM,
  [_NUM]        = LAYER_NUM,
  // [_CONFIG]     = LAYER_CONFIG,
  // Additional Layers
  // [_VSCODE]     = LAYER_VSCODE,
  // [_DESKTOP]    = LAYER_DESKTOP,
  // [_WNDW_HALF]  = LAYER_WNDW_HALF,
  // [_WNDW_QUAD]  = LAYER_WNDW_QUAD,
  // [_WNDW_THRD]  = LAYER_WNDW_THRD,
  // [_WNDW_SIXT]  = LAYER_WNDW_SIXT,
  // [_WNDW_NINT]  = LAYER_WNDW_NINT,
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
  dprintln();
#ifdef DEBUG_KEYCODE_PRINT
  if (record->event.pressed) {
    DEBUG_KEYCODE_HEX(keycode);
    DEBUG_KEYCODE_BINARY(keycode);
  }
#endif

  process_record_tap_hold(keycode, record);
  // process_vscode_keys(keycode, record);
  process_default_layer_keys(keycode, record);

#ifdef RGB_ENABLE
  process_led_keys(keycode, record);
#endif

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
#ifdef TAP_DANCE_ENABLE
  switch (keycode) {
    case OSX_APP_PREV:
    case OSX_APP_WNDW:
    case OSX_APP_NEXT:
      return 140;
    default:
      return TAPPING_TERM;
  }
#endif
  return TAPPING_TERM;
}

#ifdef RGB_ENABLE
__attribute__((weak)) void rgb_matrix_indicators_keymap(void) {
  return;
}

void rgb_matrix_indicators_user(void) {
  set_all_layer_colors(layer_state);
  rgb_matrix_indicators_keymap();
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_270;
  }
  return rotation;
}

bool oled_task_user(void) {
  // Host Keyboard Layer Status
  oled_write_P(PSTR("Layer\n"), false);

  switch (get_highest_layer(layer_state)) {
    case _COLEMAK_DH:
#ifdef USE_LAYOUT_QWERTY
    case _QWERTY:
#endif
#ifdef USE_LAYOUT_ISRT
    case _ISRT:
#endif
      oled_write_P(PSTR("\n\n\n\n DEF \n"), true);
      break;
    case _EXT:
      oled_write_P(PSTR("\n\n\n EXT \n\n"), false);
      break;
    case _SYM:
      oled_write_P(PSTR("\n\n SYM \n\n\n"), false);
      break;
    case _NUM:
      oled_write_P(PSTR("\n NUM \n\n\n\n"), false);
      break;
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_ln_P(PSTR("\n? ? ? \n? ? ? \n"), false);
  }

  // Host Keyboard LED Status
  // led_t led_state = host_keyboard_led_state();
  // oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
  // oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
  // oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

  return false;
}
#endif
