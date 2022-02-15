#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif
#include <stdint.h>
#include "eeprom.h"
#include "print.h"

#include "process_tap_hold.h"

#include "helper.h"
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


tap_hold_action_t tap_hold_actions[] = {
  [THA_DEL] = TH_ACTION_DEL,
  [THA_COMMA] = TH_ACTION_COMMA,
  [THA_DOT] = TH_ACTION_DOT,
  [THA_QUOT] = TH_ACTION_QUOT,
  [THA_LEFT] = TH_ACTION_LEFT,
  [THA_ALT_LFT] = TH_ACTION_ALT_LFT,
  [THA_RIGHT] = TH_ACTION_RIGHT,
  [THA_ALT_RGT] = TH_ACTION_ALT_RGT,
  [THA_ENTER] = TH_ACTION_ENTER,
};


/*
  === START CONFIG ===
*/
// Keyboard wake state
extern bool         g_suspend_state;
// Lighting configs for keyboard (mostly hardware stuff)
extern rgb_config_t rgb_matrix_config;
extern led_config_t g_led_config;

// Flags for mod tap lighting effects
extern uint16_t mod_tap_timer;
extern uint8_t mod_tap_active;

// Flag to track the physical state of shift keys (as int to handle multiple shift keys)
extern uint8_t shift_down;
// Mod states as of last key record
static uint8_t mod_state;
static uint8_t osm_mod_state;

// Setup to run on keyboard start up
void keyboard_post_init_user(void) {
    // debug_enable = true;
    //    debug_matrix = true;
    print("Finalizing initialization.\n");
    dprint("Debug enabled.\n");
    rgb_matrix_enable();
    print("RGB matrix enabled.\n");
    set_default_layer_colors(default_layer_state);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;
    mod_state = get_mods();
    osm_mod_state = get_oneshot_mods();

    process_shift_state(keycode, record);

    process_record_tap_hold(keycode, record);
    process_vscode_keys(keycode, record);
    process_led_keys(keycode, record);
    process_default_layer_keys(keycode, record);
    process_mod_tap_keys(keycode, record);

    switch (keycode) {
        // Keycodes defined in custom_keycodes
        case KC_EMPTY:  // used for layer coloring; fundtionally identical to KC_NO
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

        default: break;
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
        dprintln();
    }
#endif
    return true;
}

void matrix_scan_user(void) {
    matrix_scan_tap_hold();
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
