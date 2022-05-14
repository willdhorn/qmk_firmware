#pragma once
#include <stdint.h>


// In quantum_keycodes.h 0x5C00 - 0x5FFF are reserved for dedicated quantum keys
// and custom keys, with the highest quantum keys maxing out somewhere in the mid 0x5Dxx range.
// By setting QK_TAP_HOLD_MAX to the upper end of this range, it creates as much room
// as possible for the user to define the custom keys as they want without risking a collision
#define QK_TAP_HOLD_KEYCODE_ALLOCATION 31  // 32(inclusive) is often used as the size for fixed key ranges
#define QK_TAP_HOLD_MAX 0x5FFF
#define QK_TAP_HOLD (QK_TAP_HOLD_MAX - QK_TAP_HOLD_KEYCODE_ALLOCATION)

#ifndef TAP_HOLD_DELAY
  #define TAP_HOLD_DELAY 180
#endif

#define TH(n) (QK_TAP_HOLD + n)

#define shiftActive(mods) (mods & MOD_MASK_SHIFT)

#define ACTION_TAP_HOLD_SHIFT(kc_tap, kc_tap_shift, kc_hold, kc_hold_shift) \
  { kc_tap, kc_tap_shift, kc_hold, kc_hold_shift, 0, th_default }

#define ACTION_TAP_HOLD(kc_tap, kc_hold) \
  ACTION_TAP_HOLD_SHIFT(kc_tap, LSFT(kc_tap), kc_hold, LSFT(kc_hold))

#define ACTION_TAP_CMD_HOLD(kc_tap) \
  ACTION_TAP_HOLD_SHIFT(kc_tap, LSFT(kc_tap), LCMD(kc_tap), LSFT(LCMD(kc_tap)))

typedef enum {
  th_default,
  th_first_press
} tap_hold_state;

typedef struct {
  uint16_t KC_tap;
  uint16_t KC_tap_shift;
  uint16_t KC_hold;
  uint16_t KC_hold_shift;
  uint16_t timer;
  tap_hold_state state;
} tap_hold_action_t;

void process_record_tap_hold(uint16_t keycode, keyrecord_t *record);
void matrix_scan_tap_hold(void);
void process_shift_state(uint16_t keycode, keyrecord_t *record);
