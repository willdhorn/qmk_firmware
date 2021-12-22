#include QMK_KEYBOARD_H
#include "print.h"

#include "tap_dances.h"
#include "key_defs.h"
#include "layers.h"


qk_tap_dance_action_t tap_dance_actions[] = {
    //[TD_SPACE] = ACTION_TAP_DANCE_DOUBLE(MO(_APPS_WNDW), KC_CAPS),
    [TD_APPSW_L] = ACTION_TAP_DANCE_FN(handle_app_switch_mode_left),
    [TD_APPSW_M] = ACTION_TAP_DANCE_FN(handle_app_switch_mode_mid),
    [TD_APPSW_R] = ACTION_TAP_DANCE_FN(handle_app_switch_mode_right)
};

bool app_switch_mode = false;

void handle_app_switch_mode_left(qk_tap_dance_state_t *state, void *user_data) {
#ifdef DEBUG_TAP_DANCE
    dprintf("Tap Dance Left - count:%d, mode:%d", state->count, get_app_switch_dance_mode(state));
#endif
    switch(get_app_switch_dance_mode(state)) {
      case ATTD_SINGLE_TAP_OFF:
          tap_code16(CMD(SFT(KC_TAB)));
          break;
      case ATTD_DOUBLE_TAP_OFF:
          app_switch_on();
          tap_code16(SFT(KC_TAB));
          break;
      case ATTD_SINGLE_TAP_ON:
          tap_code16(SFT(KC_TAB));
          break;
      case ATTD_DOUBLE_TAP_ON:
          for (int i = 0; i < state->count; i++) {
              tap_code16(SFT(KC_TAB));
          }
          break;
    }
}

void handle_app_switch_mode_mid(qk_tap_dance_state_t *state, void *user_data) {
#ifdef DEBUG_TAP_DANCE
    dprintf("Tap Dance Mid - count:%d, mode:%d", state->count, get_app_switch_dance_mode(state));
#endif
    switch(get_app_switch_dance_mode(state)) {
      case ATTD_SINGLE_TAP_OFF:
          tap_code16(CMD(KC_GRAVE));
          break;
      case ATTD_SINGLE_TAP_ON:
          app_switch_off();
          break;
      case ATTD_DOUBLE_TAP_OFF:
          app_switch_on();
          tap_code16(KC_TAB);
          tap_code16(SFT(KC_TAB));
          break;
      case ATTD_DOUBLE_TAP_ON:
          app_switch_off();
          tap_code16(CTL(KC_DOWN));
          break;
    }
}

void handle_app_switch_mode_right(qk_tap_dance_state_t *state, void *user_data) {
#ifdef DEBUG_TAP_DANCE
    dprintf("Tap Dance Right - count:%d, mode:%d", state->count, get_app_switch_dance_mode(state));
#endif
    switch(get_app_switch_dance_mode(state)) {
      case ATTD_SINGLE_TAP_OFF:
          tap_code16(CMD(KC_TAB));
          break;
      case ATTD_DOUBLE_TAP_OFF:
          app_switch_on();
          tap_code16(KC_TAB);
          tap_code16(KC_TAB);
          break;
      case ATTD_SINGLE_TAP_ON:
          tap_code16(KC_TAB);
          break;
      case ATTD_DOUBLE_TAP_ON:
          for (int i = 0; i < state->count; i++) {
              tap_code16(KC_TAB);
          }
          break;
    }
}

void app_switch_on() {
    app_switch_mode = true;
    register_code16(KC_LCMD);
}

void app_switch_off() {
    app_switch_mode = false;
    unregister_code16(KC_LCMD);
}

ad_mode_t get_app_switch_dance_mode(qk_tap_dance_state_t *state) {
  if (state->count == 1) { // Single Tap
      return app_switch_mode ? ATTD_SINGLE_TAP_ON : ATTD_SINGLE_TAP_OFF;
  } else {  // Double Tap (+)
      return app_switch_mode ? ATTD_DOUBLE_TAP_ON : ATTD_DOUBLE_TAP_OFF;
  }
}

