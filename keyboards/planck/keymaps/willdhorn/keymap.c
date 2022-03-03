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

const key_override_t sft_ovr_hash_grave = ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_GRAVE);
const key_override_t sft_ovr_vscode_selection = SHIFT_OVERRIDE(VSC_SEL_EXPND, VSC_SEL_SHRNK);
const key_override_t meh_ovr_default_layer = MEH_OVERRIDE(LK_EXT, LK_DEF);
const key_override_t alt_ovr_left_hand_th_ext_layer = ALT_OVERRIDE(TH_LK_SYM, LK_EXT);
const key_override_t alt_ovr_left_hand_ext_layer = ALT_OVERRIDE(LK_SYM, LK_EXT);    

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &sft_ovr_hash_grave,
    &sft_ovr_vscode_selection,
    &meh_ovr_default_layer,
    &alt_ovr_left_hand_th_ext_layer,
    &alt_ovr_left_hand_ext_layer,
    NULL // Null terminate the array of overrides!
};

// Set up combo for using the two primary thumb keys to return to the default layer
const uint16_t PROGMEM lk_def_combo[] = {SPLT_LMID, SPLT_RMID, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(lk_def_combo, LK_DEF),
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
    dprintln();

    bool pressed = record->event.pressed;
    mod_state = get_mods();
    osm_mod_state = get_oneshot_mods();

    process_shift_state(keycode, record);

    process_record_tap_hold(keycode, record);
    process_vscode_keys(keycode, record);
    process_led_keys(keycode, record);
    process_default_layer_keys(keycode, record);
    process_mod_tap_keys(keycode, record);

    // PROCESS CUSTOM KEYCODES
    bool process_key = process_custom_keys(keycode, record);

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
    return process_key;
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
