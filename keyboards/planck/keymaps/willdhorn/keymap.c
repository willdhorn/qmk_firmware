#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif
#include <stdint.h>
#include "eeprom.h"
#include "print.h"

#include "key_defs.h"
#include "layers.h"
#include "tap_dances.h"
#include "layouts.h"
#include "rgb_stuff.h"
#include "user_debug.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_QWERTY]    = LAYER_QWERTY,
                                                              [_COLEMAK]   = LAYER_COLEMAK,
                                                              [_WORKMAN]   = LAYER_WORKMAN,
                                                              [_SYMBOLS]   = LAYER_SYMBOLS,
                                                              [_NAV]       = LAYER_NAV,
                                                              [_NUM]       = LAYER_NUM,
                                                              [_VSCODE]    = LAYER_VSCODE,
                                                              [_APPS_WNDW] = LAYER_APPS_WNDW,
                                                              [_WNDW_HALF] = LAYER_WNDW_HALF,
                                                              [_WNDW_QUAD] = LAYER_WNDW_QUAD,
                                                              [_WNDW_VERT] = LAYER_WNDW_VERT,
                                                              [_WNDW_THRD] = LAYER_WNDW_THRD,
                                                              [_WNDW_SIXT] = LAYER_WNDW_SIXT,
                                                              [_ADJUST]    = LAYER_ADJUST};

extern bool         g_suspend_state;
extern rgb_config_t rgb_matrix_config;
extern led_config_t g_led_config;

/*
  === KEY OVERRIDES ===
*/
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPACE, KC_DELETE);
const key_override_t suppress_hide_override = ko_make_basic(MOD_BIT(KC_LEFT_GUI), KC_H, KC_T);
// turn space-tap into activator key
// DEPENDANT ON WORKMAN LAYOUT
const key_override_t activate_a_override = ko_make_basic(MOD_BIT(KC_LEFT_CTRL),   KC_CAPS,  LCTL(KC_A));
const key_override_t activate_s_override = ko_make_basic(MOD_BIT(KC_LEFT_ALT),    KC_CAPS,  LALT(KC_S));
const key_override_t activate_h_override = ko_make_basic(MOD_BIT(KC_LEFT_SHIFT),  KC_CAPS,  LSFT(KC_H));
const key_override_t activate_t_override = ko_make_basic(MOD_BIT(KC_LEFT_GUI),    KC_CAPS,  LGUI(KC_T));
const key_override_t activate_n_override = ko_make_basic(MOD_BIT(KC_RIGHT_GUI),   KC_CAPS,  RGUI(KC_N));
const key_override_t activate_e_override = ko_make_basic(MOD_BIT(KC_RIGHT_SHIFT), KC_CAPS,  RSFT(KC_E));
const key_override_t activate_i_override = ko_make_basic(MOD_BIT(KC_RIGHT_ALT),   KC_CAPS,  RALT(KC_I));
const key_override_t activate_o_override = ko_make_basic(MOD_BIT(KC_RIGHT_CTRL),  KC_CAPS,  RCTL(KC_O));


// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &suppress_hide_override,
    &activate_a_override,
    &activate_s_override,
    &activate_h_override,
    &activate_t_override,
    &activate_n_override,
    &activate_e_override,
    &activate_i_override,
    &activate_o_override,
    NULL // Null terminate the array of overrides!
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
void keyboard_post_init_user(void) {
    // debug_enable = true;
    //    debug_matrix = true;
    print("Finalizing initialization.\n");
    dprint("Debug enabled.\n");
    rgb_matrix_enable();
    print("RGB matrix enabled.\n");
    set_default_layer_colors(default_layer_state);
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;
    if (get_mods() == MOD_MASK_SHIFT) {
        // both shift keys are down
        switch (keycode) {
          // DEPENDENT ON WORKMAN
          case KC_Z:
              tap_code16(S_UNDO);
              return true;
          case KC_X:
              tap_code16(S_CUT);
              return true;
          case KC_M:
              tap_code16(S_COPY);
              return true;
          case KC_C:
              tap_code16(S_PASTE);
              return true;
          default:
              break;
        }
    }
    switch (keycode) {
        // Keycodes defined in planck_keycodes
        // Toggle layer coloring
        case KC_LAYERCOLOR:
            if (pressed) {
                toggle_color_mode();
            }
            break;
        // DEFAULT LAYER
        case KC_QWERTY:
            set_single_persistent_default_layer(_QWERTY);
            break;
        case KC_WORKMAN:
            set_single_persistent_default_layer(_WORKMAN);
            break;
        case KC_COLEMAK:
            set_single_persistent_default_layer(_COLEMAK);
            break;
        // VSCode keys for chorded shortcuts (cmd-k used as leader)
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
        case VSC_OPN_DEF_SIDE:
            if (pressed) {
                vscode_chord(KC_F12);
            }
           break;  
        
        default:
            // flash the right when caps lock is on light anytime a key is pressed
            if (host_keyboard_led_state().caps_lock && IS_LETTER(keycode)) {
                if (pressed) {
                    planck_ez_right_led_level(255);
                } else {
                    planck_ez_right_led_level(0);
                }
            } else {
                planck_ez_right_led_level(0);
            }
            break;
    }

#ifdef DEBUG_KEYCODE_PRINT
    if (pressed) {
        DEBUG_KEYCODE_HEX(keycode);
        DEBUG_KEYCODE_BINARY(keycode);
    }
#endif

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYMBOLS, _NAV, _APPS_WNDW);
    state = update_tri_layer_state(state, _VSCODE, _NUM, _ADJUST);
    return state;
}

void vscode_chord(uint16_t kc) { 
    two_tap(CMD(KC_K), kc);
}

void two_tap(uint16_t kc1, uint16_t kc2) {
    tap_code16(kc1);
    tap_code16(kc2);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
#ifdef KB_LAYOUT_STANDARD
      case STD_LK_RAIS: // LT(space)
          return 185;
#else
      case SPLT_KL1:
      case SPLT_KL2:
      case SPLT_KL3:
      case SPLT_KR3:
      case SPLT_KR1:
          return 200;
      case SPLT_KR2:  // Space
          return 250;
#endif
      case MR1(KC_O):
      case MR2(KC_I):
      case ML1(KC_A):
      case ML2(KC_S):
          return 250;
      case OSX_APP_PREV:
      case OSX_APP_WNDW:
      case OSX_APP_NEXT:
          return 140;
      default:
          return TAPPING_TERM;
  }
}

// Audio and Music

#ifdef AUDIO_ENABLE
bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo += 1;
            } else {
                muse_tempo -= 1;
            }
        }
    } else {
        if (clockwise) {
#    ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
#    else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
#    endif
        } else {
#    ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
#    else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
#    endif
        }
    }
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}
#endif

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}
