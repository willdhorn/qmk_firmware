#include QMK_KEYBOARD_H
#include <stdint.h>

#include "process_record.h"

// Flags for mod tap lighting effects
uint16_t mod_tap_timer = 0;
uint8_t  mod_tap_active = 0;

__attribute__((weak)) bool process_keycode_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_keycode_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_keycode_keymap(keycode, record)) {
    return false;
  }

  bool pressed = record->event.pressed;

  switch (keycode) {
    // Keycodes defined in custom_keycodes
    case KC_EMPTY: // used for layer coloring; fundtionally identical to KC_NO
      return false;
    case KC_CLEAR_MODS:
      if (pressed) {
        // clear_mods();
        clear_weak_mods();
        clear_oneshot_mods();
        clear_keyboard();
      }
      return false;

    // Custom Macro keys for Tap-Hold
    case MCR_NEQL:
      if (pressed) {
        SEND_STRING("!=");
      }
      return false;
    case MCR_PRNS:
      if (pressed) {
        SEND_STRING("()");
      }
      return false;
    case MCR_BRCS:
      if (pressed) {
        SEND_STRING("[]");
      }
      return false;
    case MCR_CBRS:
      if (pressed) {
        SEND_STRING("{}");
      }
      return false;
    case MCR_TILD:
      if (pressed) {
        SEND_STRING("~/");
      }
      return false;

    // Custom Layer Macro keys for Tap-Hold
    case LAYER_FN_DEF:
      if (pressed) {
        layer_clear();
      }
      return false;
    case LAYER_FN_EXT:
      if (pressed) {
        layer_move(_EXT);
      }
      return false;
    case LAYER_FN_SYM:
      if (pressed) {
        layer_move(_SYM);
      }
      return false;

    // Custom OSMs
    case KC_OSM_CMD:
      break;
    case KC_OSM_SFT:
      break;
    case KC_OSM_ALT:
      break;
    case KC_OSM_CTL:
      break;

    default:
      break;
  }

  return true;
}

void process_mod_tap_keys(uint16_t keycode, keyrecord_t *record) {
  bool pressed = record->event.pressed;

  if (IS_MOD_TAP(keycode)) {
    if (pressed) {
      mod_tap_timer = record->event.time;
      mod_tap_active += 1;
    } else {
      mod_tap_active -= 1;
    }
  }
}

void process_default_layer_keys(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
#ifdef ENABLE_LAYOUT_QWERTY
    case KC_QWERTY:
      set_single_persistent_default_layer(_QWERTY);
      break;
#endif
#ifdef ENABLE_LAYOUT_COLEMAK
    case KC_COLEMAK_DH:
      set_single_persistent_default_layer(_COLEMAK_DH);
      break;
#endif
#ifdef ENABLE_LAYOUT_ISRT
    case KC_ISRT:
      set_single_persistent_default_layer(_ISRT);
      break;
#endif
    default:
      break;
  }
}

void process_led_keys(uint16_t keycode, keyrecord_t *record) {
  bool pressed = record->event.pressed;

  // Toggle layer coloring"
  switch (keycode) {
    case KC_LAYERCOLOR:
      if (pressed) {
        toggle_color_mode();
      }
      break;
    // Control led brightness
    case KC_LED_INC_BRGT:
      if (pressed) {
        increase_led_brightness();
      }
      break;
    case KC_LED_DCR_BRGT:
      if (pressed) {
        decrease_led_brightness();
      }
      break;
    default:
      break;
  }
}
// VSCode keys for chorded shortcuts (cmd-k used as leader)
void process_vscode_keys(uint16_t keycode, keyrecord_t *record) {
  bool pressed = record->event.pressed;

  switch (keycode) {
    // Move current editor to left/right group
    case VSC_MV_EDTR_LFT:
      if (pressed) {
        vscode_chord(ALT(KC_LEFT));
      }
      break;
    case VSC_MV_EDTR_RGT:
      if (pressed) {
        vscode_chord(ALT(KC_RIGHT));
      }
      break;
    // Switch focus to prev/next group
    case VSC_FCS_G_PREV:
      if (pressed) {
        vscode_chord(CMD(KC_LEFT));
      }
      break;
    case VSC_FCS_G_NEXT:
      if (pressed) {
        vscode_chord(CMD(KC_RIGHT));
      }
      break;
    // Move the entire editor group to the left/right
    case VSC_MV_EDTR_G_LFT:
      if (pressed) {
        vscode_chord(KC_LEFT);
      }
      break;
    case VSC_MV_EDTR_G_RGT:
      if (pressed) {
        vscode_chord(KC_RIGHT);
      }
      break;
    // Open statement definition to the side
    case VSC_OPN_DEF_SIDE:
      if (pressed) {
        vscode_chord(KC_F12);
      }
      break;
    default:
      break;
  }
}

void vscode_chord(uint16_t kc) {
  two_tap(CMD(KC_K), kc);
}

void two_tap(uint16_t kc1, uint16_t kc2) {
  tap_code16(kc1);
  tap_code16(kc2);
}
