#include QMK_KEYBOARD_H

#include "willdhorn.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // === Default Layers ===
  [_COLEMAK_DH] = LAYER_COLEMAK_DH,
#ifdef USE_LAYOUT_QWERTY
  [_QWERTY]     = LAYER_QWERTY,
#endif
#ifdef USE_LAYOUT_ISRT
  [_ISRT]       = LAYER_ISRT,
#endif
  // === Standard Layers ===
  [_NAV]        = LAYER_NAV,
  [_SYM]        = LAYER_SYM,
  [_NUM]        = LAYER_NUM,
  // [_CONFIG]     = LAYER_CONFIG,
  // === Additional Layers ===
  // [_VSCODE]     = LAYER_VSCODE,
  [_DESKTOP]    = LAYER_DESKTOP,
  [_WNDW_HALF]  = LAYER_WNDW_HALF,
  [_WNDW_QUAD]  = LAYER_WNDW_QUAD,
  [_WNDW_THRD]  = LAYER_WNDW_THRD,
  [_WNDW_SIXT]  = LAYER_WNDW_SIXT,
  [_WNDW_NINT]  = LAYER_WNDW_NINT,
};
// clang-format on

// === Matrix Scan ===
void matrix_scan_user(void) {
  matrix_scan_tap_hold();
#ifdef AUDIO_ENABLE
  matrix_scan_audio_user();
#endif
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

// ==== Process Record ====

uint16_t space_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  dprintln();
#ifdef DEBUG_KEYCODE_PRINT
  if (record->event.pressed) {
    DEBUG_KEYCODE_HEX(keycode);
    DEBUG_KEYCODE_BINARY(keycode);
  }
#endif

  if (keycode == kSpace && record->event.pressed) {
    space_timer = record->event.time;
  }

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

// === Tapping Term ===

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
  switch (keycode) {
    // case kEscape:
    // case kTab:
    // case kEnter:
    case kSpace:
      return 150;
    case kBackspace:
      return 250;
    default:
      return TAPPING_TERM;
  }
  return TAPPING_TERM;
}

// === Retro Tapping ===

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case kSpace:
      if (timer_elapsed(space_timer) < SPACE_RETRO_TAP_TERM) {
        return true;
      }
      return false;
  }
  return false;
}

// === Caps Word ===

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
    case kSpace:
    case KC_SPACE:
      add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
      return true;

    case kTab:
    case kEscape:
      return false;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case (QK_TAP_HOLD)... QK_TAP_HOLD_MAX:
    case QK_TO ... QK_ONE_SHOT_LAYER_MAX:

    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
      return true;

    default:
      return false; // Deactivate Caps Word.
  }
}

// === RGB ===
#ifdef RGB_ENABLE
__attribute__((weak)) void rgb_matrix_indicators_keymap(void) {
  return;
}

void rgb_matrix_indicators_user(void) {
  set_all_layer_colors(layer_state);
  rgb_matrix_indicators_keymap();
}
#endif

// === OLED ===

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_270;
  }
  return rotation;
}

bool oled_task_user(void) {
#  define oops _DESKTOP + 1
  // clang-format off
  static const unsigned char PROGMEM layerIcons[][128] = {
      [_COLEMAK_DH] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 240, 248, 252, 252, 62, 62, 30, 30, 30, 30, 30, 62, 62, 60, 60, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 143, 223, 223, 254, 252, 252, 248, 248, 248, 240, 240, 224, 224, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 248, 254, 255, 255, 255, 3, 1, 0, 0, 0, 0, 0, 1, 3, 255, 255, 255, 255, 252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 7, 15, 31, 63, 63, 62, 60, 124, 124, 124, 60, 62, 63, 31, 31, 15, 7, 0, 0, 0, 0, 0, 0, 0},
      [_SYM]        = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 224, 240, 248, 248, 252, 124, 124, 124, 124, 124, 252, 252, 252, 252, 188, 60, 60, 28, 28, 12, 12, 8, 0, 0, 0, 0, 0, 0, 0, 0, 124, 255, 255, 255, 255, 131, 0, 0, 0, 0, 0, 0, 0, 131, 255, 255, 255, 254, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 7, 15, 31, 63, 62, 60, 124, 124, 124, 60, 62, 31, 31, 15, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0},
      [_NUM]        = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 112, 56, 60, 28, 30, 30, 254, 254, 254, 60, 60, 60, 60, 248, 248, 248, 120, 120, 56, 60, 28, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 48, 56, 62, 31, 15, 3, 0, 0, 0, 0, 3, 15, 31, 62, 56, 48, 32, 0, 0, 0, 0, 0, 0, 0},
      [_NAV]        = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 56, 124, 252, 252, 248, 240, 192, 0, 0, 0, 0, 0, 0, 0, 192, 248, 252, 252, 124, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 31, 255, 255, 255, 248, 128, 0, 128, 240, 254, 255, 255, 31, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 63, 63, 63, 60, 63, 63, 31, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      [_DESKTOP]    = {0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,192,128,  0,  0,  0,  0,  0,  0,128,192,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,248,254,255,127, 15,  3,  1,  0,192,224,224,192,  0,  1,  3, 15,127,255,254,248,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 31,255,255,255,248,192,128,  0,128,255,255,255,255,128,  0,128,192,248,255,255,255, 31,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7, 15, 15, 31, 31, 15, 15,  7,  3,  3,  7, 15, 15, 31, 31, 15, 15,  7,  0,  0,  0,  0,  0,  0,  0},
      [oops]        = {0,  0, 16,  8,  8,200,120,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 12,100, 36, 24,  0,  0,  0,  0,  0,  0,  0,  9,  0,  0,  0,240,248,252, 30, 14, 14, 14, 14, 14, 14, 14, 30,252,248,240,  0,  0,  0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,192, 64, 32, 32, 64,192,  0,  0,  0,  0, 96,240,248,124, 30, 15,  7,  3,  1,  0,  0,  0,192, 96, 32, 96,192,  0,  0,  0,  0,  0,  1,  0,  0, 76,  3,  1,  0,  0,  0, 48,120,252,252,120, 48,  0,  0,  0,  0,  0,  0,  0,  1,  0, 92,  3,  1}
  };
  // clang-format on

  // Mods
  uint8_t mods = get_mods() | get_oneshot_mods();
  oled_write_P(mods & MOD_MASK_CTRL ? PSTR("C") : PSTR(" "), get_oneshot_mods() & MOD_MASK_CTRL);
  oled_write_P(mods & MOD_MASK_ALT ? PSTR("A") : PSTR(" "), get_oneshot_mods() & MOD_MASK_ALT);
  oled_write_P(mods & MOD_MASK_SHIFT ? PSTR("S") : PSTR(" "), get_oneshot_mods() & MOD_MASK_SHIFT || is_caps_word_on());
  oled_write_P(mods & MOD_MASK_GUI ? PSTR("G") : PSTR(" "), get_oneshot_mods() & MOD_MASK_GUI);

  // Layer Status
  oled_write_P(PSTR("\nLayer\n"), false);
  const unsigned char *curIcon;

  switch (get_highest_layer(layer_state)) {
    case _COLEMAK_DH:
#  ifdef USE_LAYOUT_QWERTY
    case _QWERTY:
#  endif
#  ifdef USE_LAYOUT_ISRT
    case _ISRT:
#  endif
      curIcon = layerIcons[_COLEMAK_DH];
      break;
    case _NAV:
      curIcon = layerIcons[_NAV];
      break;
    case _SYM:
      curIcon = layerIcons[_SYM];
      break;
    case _NUM:
      curIcon = layerIcons[_NUM];
      break;
    case _DESKTOP:
    case _WNDW_HALF:
    case _WNDW_THRD:
    case _WNDW_QUAD:
    case _WNDW_SIXT:
    case _WNDW_NINT:
      curIcon = layerIcons[_DESKTOP];
      break;
    default:
      oled_write(get_u8_str(get_highest_layer(layer_state), ' '), false);
      curIcon = layerIcons[oops];
  }

  oled_write_raw_P((const char *)curIcon, 128);

  // Host Keyboard LED Status
  // led_t led_state = host_keyboard_led_state();
  // oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
  // oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
  // oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

  return false;
}
#endif
