#pragma once

#include "quantum.h"

enum { // Tap Dance Key Dances
    TD_APPSW_L = 0,
    TD_APPSW_M,
    TD_APPSW_R,
};

typedef enum ad_mode_t {  // Tap Dance Modes
    ATTD_SINGLE_TAP_OFF = 1,
    ATTD_SINGLE_TAP_ON,
    ATTD_DOUBLE_TAP_OFF,
    ATTD_DOUBLE_TAP_ON,
} ad_mode_t;

void app_switch_on(void);
void app_switch_off(void);

void handle_app_switch_mode_left(qk_tap_dance_state_t *state, void *user_data);
void handle_app_switch_mode_mid(qk_tap_dance_state_t *state, void *user_data);
void handle_app_switch_mode_right(qk_tap_dance_state_t *state, void *user_data);

// #define APP_SWITCH_MODE(state) ((state->count == 1) ? (app_switch_mode ? ATTD_SINGLE_TAP_ON : ATTD_SINGLE_TAP_OFF) :(app_switch_mode ? ATTD_DOUBLE_TAP_ON : ATTD_DOUBLE_TAP_OFF))
ad_mode_t get_app_switch_dance_mode(qk_tap_dance_state_t *state);