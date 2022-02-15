#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif
#include <stdint.h>
#include "eeprom.h"
#include "print.h"

//#include "process_tap_hold.h"

#include "key_defs.h"
#include "layers.h"
#include "layouts.h"
#include "rgb_stuff.h"
#include "tap_dances.h"
#include "user_debug.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#ifdef ENABLE_LAYOUT_QWERTY
        [_QWERTY]       = LAYER_QWERTY,
#endif
#ifdef ENABLE_LAYOUT_COLEMAK
        [_COLEMAK_DH]   = LAYER_COLEMAK_DH,
#endif
#ifdef ENABLE_LAYOUT_ISRT
        [_ISRT]         = LAYER_ISRT,
#endif
#ifdef ENABLE_LAYOUT_WORKMAN
        [_WORKMAN]      = LAYER_WORKMAN,
#endif
        [_EXT]          = LAYER_EXT,
        [_SYM]          = LAYER_SYM,
        [_NUM]          = LAYER_NUM,
        [_VSCODE]       = LAYER_VSCODE,
        [_SWITCH]       = LAYER_SWITCH,
        [_WNDW_HALF]    = LAYER_WNDW_HALF,
        [_WNDW_QUAD]    = LAYER_WNDW_QUAD,
    //   [_WNDW_VERT]    = LAYER_WNDW_VERT,
        [_WNDW_THRD]    = LAYER_WNDW_THRD,
        [_WNDW_SIXT]    = LAYER_WNDW_SIXT,
        [_WNDW_NINT]    = LAYER_WNDW_NINT,
        [_ADJUST]       = LAYER_ADJUST,
};



// /*
//   === COMBOS ===
// */
// Need to figure out this:
//     https://beta.docs.qmk.fm/using-qmk/software-features/feature_combo#modifier-combos
// enum combo_events {
//   COMB_EMAIL,
//   COMB_CLR_LINE,
//   COMBO_LENGTH
// };
// uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!
//
// // Email - DHW + J (J is for @)
// // Clear Line - N+Backspace
// const uint16_t PROGMEM email_combo[] = {KC_D, KC_H, KC_W, KC_J, COMBO_END};
// const uint16_t PROGMEM clear_line_combo[] = {KC_BSPC, KC_N, COMBO_END};
//
//
// combo_t key_combos[] = {
//   [COMB_EMAIL] = COMBO_ACTION(email_combo),
//   [COMB_CLR_LINE] = COMBO_ACTION(clear_line_combo),
// };
// /* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */
//
// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case COMB_EMAIL:
//       if (pressed) {
//         SEND_STRING("hornsbywilliamd@gmail.com");
//       }
//       break;
//     case COMB_CLR_LINE:
//       if (pressed) {
//         tap_code16(KC_END);
//         tap_code16(S(KC_HOME));
//         tap_code16(KC_BSPC);
//       }
//       break;
//   }
// }

/*
  === START CONFIG ===
*/
extern bool         g_suspend_state;
extern rgb_config_t rgb_matrix_config;
extern led_config_t g_led_config;

void keyboard_post_init_user(void) {
    // debug_enable = true;
    //    debug_matrix = true;
    print("Finalizing initialization.\n");
    dprint("Debug enabled.\n");
    rgb_matrix_enable();
    print("RGB matrix enabled.\n");
    set_default_layer_colors(default_layer_state);
}

static uint16_t bspace_timer = 0;
extern uint16_t mod_tap_timer;
extern uint8_t mod_tap_active;

extern bool shift_down;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;
    uint8_t mod_state = get_mods();
    uint8_t osm_mod_state = get_oneshot_mods();

    switch (keycode) {
        // Keycodes defined in custom_keycodes
        case KC_EMPTY:  // used for layer coloring; fundtionally identical to KC_NO
            return false;
        case OSM(MOD_LSFT):
        case KC_LSFT:
            if (pressed) {
                shift_down = true;
            } else {
                shift_down = false;
            }
            return true;
        case KC_BACKSPACE:
            // because key overrides cant haendle this
            if (pressed) {
                bspace_timer = record->event.time;
                return false;
            } else {
                bool mod_shift = (mod_state) & MOD_MASK_SHIFT;
                bool osm_shift = (osm_mod_state) & MOD_MASK_SHIFT;
                uint16_t key       = (mod_shift | osm_shift) ? KC_DELETE : KC_BACKSPACE;
                if (timer_elapsed(bspace_timer) > TAPPING_TERM) {
                    // holding key; delete line
                    key = CMD(key);
                }
                // remove shift mod since some programs treat shift+delete differently
                del_mods((mod_state) & MOD_MASK_SHIFT);
                del_oneshot_mods((osm_mod_state) & MOD_MASK_SHIFT);

                tap_code16(key);

                // if shift mod present, then at it back, otherwise do nothing
                add_mods((mod_state) & MOD_MASK_SHIFT);
                return false;
            }
            break;

        // CUSTOM KEYS

        // Custom OSMs
        case KC_OSM_CMD:
            break;
        case KC_OSM_SFT:
            break;
        case KC_OSM_ALT:
            break;
        case KC_OSM_CTL:
            break;

        // Toggle layer coloring"
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
        // DEFAULT LAYER
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
#ifdef ENABLE_LAYOUT_WORKMAN
        case KC_WORKMAN:
            set_single_persistent_default_layer(_WORKMAN);
            break;
#endif

        // VSCode keys for chorded shortcuts (cmd-k used as leader)

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
            if (IS_MOD_TAP(keycode)) {
              if (pressed) {
                  mod_tap_timer = record->event.time;
                  mod_tap_active += 1;
              } else {
                  mod_tap_active -= 1;
              }
            }
            break;
    }

    // flash the right when caps lock is on light anytime a key is pressed
    if (host_keyboard_led_state().caps_lock && (IS_LETTER(keycode) || IS_MOD_TAP(keycode))) {
        if (pressed) {
            planck_ez_right_led_level(255);
        } else {
            planck_ez_right_led_level(0);
        }
    } else {
        planck_ez_right_led_level(0);
    }


#ifdef DEBUG_KEYCODE_PRINT
    if (pressed) {
        DEBUG_KEYCODE_HEX(keycode);
        DEBUG_KEYCODE_BINARY(keycode);
    }
#endif

    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    matrix_scan_audio_user();
#endif
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
#ifndef BILATERAL_COMBINATIONS
      case ML1(KC_A):
      case ML2(KC_S):
      case ML3(KC_R):
      case ML4(KC_T):
      case MR4(KC_N):
      case MR3(KC_E):
      case MR2(KC_I):
      case MR1(KC_O):
          return 350;
#endif
      case OSX_APP_PREV:
      case OSX_APP_WNDW:
      case OSX_APP_NEXT:
          return 140;
      case T_BSPACE:
          return 175;
      default:
          return TAPPING_TERM;
  }
}

void rgb_matrix_indicators_user(void) {
    set_all_layer_colors(layer_state);
    // Set caps lock indicator light
    if (host_keyboard_led_state().caps_lock) {
        planck_ez_left_led_level(255);
    } else {
        planck_ez_left_led_level(0);
    }
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//     state = update_tri_layer_state(state, _SWITCH, _EXT, _VSCODE);
//     state = update_tri_layer_state(state, _NUM, _SWITCH, _ADJUST);
//     return state;
// }

void vscode_chord(uint16_t kc) {
    two_tap(CMD(KC_K), kc);
}

void two_tap(uint16_t kc1, uint16_t kc2) {
    tap_code16(kc1);
    tap_code16(kc2);
}



// bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//       case STD_LK_RAIS:
//         // allows tapping term to be low for arrow key movements and faster reporting of space presses
//         // while still registering space when typing slower
//         if (timer_elapsed(space_timer) < SPACE_RETRO_TAP_TERM) {
//           return true;
//         }
//         else {
//           return false;
//         }
//
//       default:
//         return false;
//     }
// }
