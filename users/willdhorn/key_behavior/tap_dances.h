#pragma once

#include "willdhorn.h"


enum { // Tap Dance Key Dances
    // TD_BSPACE = 0,
    TD_APPSW_L=0,
    TD_APPSW_M,
    TD_APPSW_R,
};


/* TAP-HOLD DANCES */

typedef enum {
    TD_NONE,
    TD_TAP,
    TD_HOLD,
} tap_hold_state_t;

typedef struct {
    tap_hold_state_t state;
    uint16_t         key;
} tap_hold_tap_t;

#define TAP_HOLD_STATE(qk_state) ((qk_state->interrupted || !qk_state->pressed) ? TD_TAP : TD_HOLD)

void bspace_tap_hold_on_each_tap(qk_tap_dance_state_t *state, void *user_data);
void bspace_tap_hold_finished(qk_tap_dance_state_t *state, void *user_data);
void bspace_tap_hold_reset(qk_tap_dance_state_t *state, void *user_data);


/* QUAD(+) DANCES */

// see https://docs.qmk.fm/#/feature_tap_dance?id=example-4
// typedef enum {
//     TD_NONE,
//     TD_UNKNOWN,
//     TD_SINGLE_TAP,
//     TD_SINGLE_HOLD,
//     TD_DOUBLE_TAP,
//     TD_DOUBLE_HOLD,
//     TD_DOUBLE_SINGLE_TAP,  // Send two single taps
//     // TD_TRIPLE_TAP,
//     // TD_TRIPLE_HOLD
// } quad_state_t;


/* ONE SHOT MODS */


/* APP DESKTOP DANCES */

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

#define APP_DESKTOP_MODE(state) ( \
  (state->count == 1) ? \
    (app_switch_mode ? ATTD_SINGLE_TAP_ON : ATTD_SINGLE_TAP_OFF) : \
    (app_switch_mode ? ATTD_DOUBLE_TAP_ON : ATTD_DOUBLE_TAP_OFF) \
)
