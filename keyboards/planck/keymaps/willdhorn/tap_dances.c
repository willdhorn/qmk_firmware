#include QMK_KEYBOARD_H
#include "print.h"

#include "tap_dances.h"
#include "key_defs.h"
#include "layers.h"
#include "user_debug.h"

qk_tap_dance_action_t tap_dance_actions[] = {
    // tap: backspace, hold: cmd+backspace
    [TD_BSPACE] = ACTION_TAP_DANCE_FN_ADVANCED(bspace_tap_hold_on_each_tap, bspace_tap_hold_finished, bspace_tap_hold_reset),

    // One shot - 1st tap: osm, 2nd tap: del osm, hold: mod, 3tap:lock mod until next tap

    // Switch layer
    [TD_APPSW_L] = ACTION_TAP_DANCE_FN(handle_app_switch_mode_left),
    [TD_APPSW_M] = ACTION_TAP_DANCE_FN(handle_app_switch_mode_mid),
    [TD_APPSW_R] = ACTION_TAP_DANCE_FN(handle_app_switch_mode_right)
};


/* APP SWITCH DANCES */

bool app_switch_mode = false;

void handle_app_switch_mode_left(qk_tap_dance_state_t *state, void *user_data) {
#ifdef DEBUG_TAP_DANCE
    dprintf("Tap Dance Left - count:%d, mode:%d", state->count, APP_SWITCH_MODE(state));
#endif
    switch(APP_SWITCH_MODE(state)) {
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
    dprintf("Tap Dance Mid - count:%d, mode:%d", state->count, APP_SWITCH_MODE(state));
#endif
    switch(APP_SWITCH_MODE(state)) {
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
    dprintf("Tap Dance Right - count:%d, mode:%d", state->count, APP_SWITCH_MODE(state));
#endif
    switch(APP_SWITCH_MODE(state)) {
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


/* TAP-HOLD DANCES */

static tap_hold_tap_t bspace_tap = {
  .state = TD_NONE,
  .key = KC_NO,
};

void bspace_tap_hold_on_each_tap(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
      bspace_tap.key = ((state->weak_mods | state->oneshot_mods) & MOD_MASK_SHIFT) ? KC_DELETE : KC_BACKSPACE;
  } else {
      // on a double tap we want to tap the key twice
      tap_code16(bspace_tap.key);
      tap_code16(bspace_tap.key);
      // state->interrupted = true;
      state->finished = true;
      state->timer -= TAPPING_TERM; // subtract since timer is the start time of the action
  }
#ifdef DEBUG_TAP_DANCE
    dprintf("TD bspace on_tap\n");
    DEBUG_KEYCODE_HEX(bspace_tap.key);
    DEBUG_BYTE_BINARY("mods",(state->weak_mods | state->oneshot_mods));
#endif
}

void bspace_tap_hold_finished(qk_tap_dance_state_t *state, void *user_data) {
    bspace_tap.state = TAP_HOLD_STATE(state);
#ifdef DEBUG_TAP_DANCE
    dprintf("TD bspace finished\n");
    DEBUG_KEYCODE_HEX(bspace_tap.key);
    DEBUG_BYTE_BINARY("mods",(state->weak_mods | state->oneshot_mods));
#endif

    del_mods(MOD_MASK_SHIFT);
    del_weak_mods(MOD_MASK_SHIFT);
    del_oneshot_mods(MOD_MASK_SHIFT);
    if ((state->weak_mods | state->oneshot_mods) & MOD_MASK_SHIFT) {
      send_keyboard_report();
    }

    switch (bspace_tap.state) {
      case TD_TAP: register_code16(bspace_tap.key); break;
      case TD_HOLD:
        switch (bspace_tap.key) {
          case KC_BACKSPACE:
            register_code16(CMD(bspace_tap.key));
            break;
          case KC_DELETE:
            register_code16(CTL(KC_K)); // because mac
        }
        break;
      default: break;
    }
}

void bspace_tap_hold_reset(qk_tap_dance_state_t *state, void *user_data) {
#ifdef DEBUG_TAP_DANCE
    dprintf("TD bspace reset\n");
    DEBUG_KEYCODE_HEX(bspace_tap.key);
    DEBUG_BYTE_BINARY("mods",(state->weak_mods | state->oneshot_mods));
    dprintf("tap/hold state: %d, interrupted: %d, pressed: %d\n",TAP_HOLD_STATE(state), state->interrupted, state->pressed);
#endif

    switch (bspace_tap.state) {
        case TD_TAP: unregister_code16(bspace_tap.key); break;
        case TD_HOLD:
          switch (bspace_tap.key) {
            case KC_BACKSPACE:
              unregister_code16(CMD(bspace_tap.key));
              break;
            case KC_DELETE:
              unregister_code16(CTL(KC_K)); // because mac
              break;
            default: break;
          }
          break;
        default: break;
    }
    // if shift mod present, then at it back, otherwise do nothing
    add_mods((state->weak_mods) & MOD_MASK_SHIFT);
}
