#include QMK_KEYBOARD_H

#include "process_record.h"

__attribute__((weak)) bool process_keycode_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

// === Process Record ===
bool process_keycode_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_keycode_keymap(keycode, record)) {
    return false;
  }

  bool pressed = record->event.pressed;

  switch (keycode) {
    // Custom Oneshot layer handling
    case OSL(_SYM):
      if (!pressed) {
        // on release, Also turn NUM layer off
        // This doesn't allow oneshot to activate anything in NUM but that's too difficult at the moment
        layer_off(_NUM);
      }
      return true;

    case TG(_NUM):
      if (pressed) {
        if (IS_LAYER_OFF(_NUM) && (get_oneshot_layer_state() & ONESHOT_PRESSED)) {
          layer_on(_NUM);
        } else {
          layer_off(_NUM);
        }
      }
      return false;

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
    case MCR_DIRUP:
      if (pressed) {
        SEND_STRING("../");
      }
      return false;

    // // Custom Layer Macro keys for Tap-Hold
    // case LAYER_FN_DEF:
    //   if (pressed) {
    //     layer_clear();
    //   }
    //   return false;
    // case LAYER_FN_NAV:
    //   if (pressed) {
    //     layer_move(_NAV);
    //   }
    //   return false;
    // case LAYER_FN_SYM:
    //   if (pressed) {
    //     layer_move(_SYM);
    //   }
    //   return false;

    default:
      break;
  }

  return true;
}

// === Process Default Layer Keys ===
void process_default_layer_keys(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
#ifdef USE_LAYOUT_COLEMAK
    case KC_COLEMAK_DH:
      set_single_persistent_default_layer(_COLEMAK_DH);
      break;
#endif
#ifdef USE_LAYOUT_QWERTY
    case KC_QWERTY:
      set_single_persistent_default_layer(_QWERTY);
      break;
#endif
#ifdef USE_LAYOUT_ISRT
    case KC_ISRT:
      set_single_persistent_default_layer(_ISRT);
      break;
#endif
    default:
      break;
  }
}

#ifdef CALLUM_MODS_ENABLE
oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_cmd_state  = os_up_unqueued;

void process_callum_mods(..., ...) {
  update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
  update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
  update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
  update_oneshot(&os_cmd_state, KC_LCMD, OS_CMD, keycode, record);
}

bool is_oneshot_cancel_key(uint16_t keycode) {
  switch (keycode) {
    case LKM_NAV:
    case KC_CLEAR_MODS:
      return true;
    default:
      return false;
  }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
  switch (keycode) {
    case LKT_SYM:
    case LKM_NAV:
    case LKT_NAV:
    case LKT_DEF:
    case LKT_ADJ:
    case LKT_SWT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
      return true;
    default:
      return false;
  }
}
#endif

#ifdef RGB_ENABLE
// Flags for mod tap lighting effects
uint16_t mod_tap_timer  = 0;
uint8_t  mod_tap_active = 0;

void process_led_keys(uint16_t keycode, keyrecord_t *record) {
  bool pressed = record->event.pressed;

  if (IS_MOD_TAP(keycode)) {
    if (record->event.pressed) {
      mod_tap_timer = record->event.time;
      mod_tap_active += 1;
    } else {
      mod_tap_active -= 1;
    }
  }

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
#endif

// === Process VSCode Keys ===
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
