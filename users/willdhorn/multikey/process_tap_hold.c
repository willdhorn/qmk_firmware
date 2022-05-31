#include QMK_KEYBOARD_H

#include "process_tap_hold.h"

// I really want to remove this, but it has to stay until
// the processing of custom keycodes can be refactored.
#include "willdhorn.h"

extern tap_hold_action_t tap_hold_actions[];

// Private functions implemented elsewhere in qmk/tmk
extern uint8_t extract_mod_bits(uint16_t code);
extern void    set_weak_override_mods(uint8_t mods);
extern void    clear_weak_override_mods(void);
extern void    set_suppressed_override_mods(uint8_t mods);
extern void    clear_suppressed_override_mods(void);

void selectAndSendKey(tap_hold_action_t *t, bool is_held) {
  uint8_t mods = get_mods();
  mods |= get_oneshot_mods();
  uint16_t keycode;
  if (shiftActive(mods)) {
    // Suppress shift
    unregister_mods(MOD_MASK_SHIFT);
    del_oneshot_mods(MOD_MASK_SHIFT);

    keycode = (is_held ? t->KC_hold_shift : t->KC_tap_shift);
  } else {
    keycode = (is_held ? t->KC_hold : t->KC_tap);
  }

  if (keycode == KC_CAPS_LOCK) { // Extra delay needed with Caps Lock for MacOS
    register_code16(keycode);
    wait_ms(100);
    unregister_code16(keycode);
  } else if (process_keycode_user(keycode, KEYRECORD_PRESS(true))) {
    tap_code16(keycode);
  }

  if (shift_down) {
    register_mods(MOD_BIT(KC_LSFT)); // I don't use right shift (at the moment at least..)
  }
  send_keyboard_report();
}

void process_record_tap_hold(uint16_t keycode, keyrecord_t *record) {
  const bool key_down       = record->event.pressed;
  uint8_t    effective_mods = get_mods();

#ifndef NO_ACTION_ONESHOT
  // Locked one shot mods are added to get_mods(), I think (why??) while oneshot mods are in get_oneshot_mods(). Still OR with get_locked_oneshot_mods because that's where those mods _should_ be saved.
  effective_mods |= get_oneshot_locked_mods() | get_oneshot_mods();
#endif

  if (IS_MOD(keycode)) {
    // The mods returned from get_mods() will be updated with this new event _after_ this code runs. Hence we manually update the effective mods here to really know the effective mods.
    if (key_down) {
      effective_mods |= MOD_BIT(keycode);
    } else {
      effective_mods &= ~MOD_BIT(keycode);
    }
  // If the key pressed is one of our tap hold keys
  } else if (QK_TAP_HOLD <= keycode && keycode <= QK_TAP_HOLD_MAX) {
    uint16_t           idx = keycode - QK_TAP_HOLD;
    tap_hold_action_t *t   = &tap_hold_actions[idx];
    if (key_down) {
      // On key press, start timer and do nothing
      t->timer = timer_read();
      if (effective_mods & MOD_MASK_SHIFT) {
        t->state = th_shift_tapped;
      } else {
        t->state = th_tapped;
      }
    } else {
      if (t->state == th_tapped || t->state == th_shift_tapped) {
        // If key is released before timer expires, reset state and send tap key
        // keycode will select keycode based on current state
        selectAndSendKey(t, false);
        t->state = th_default;
    }

  // If another key is pressed, current interupt any running timers
  // (don't interupt any held keys)
  } else if (key_down) {
    for (int i = 0; i < QK_TAP_HOLD_MAX; ++i) {
      tap_hold_action_t *t = &tap_hold_actions[i];
      if (t->state == th_tapped || th_shift_tapped) {
        t->state = th_default;
        //selectAndSendKey(t, false);
      }
    }
  }
}


void matrix_scan_tap_hold(void) {
  for (uint8_t i = 0; i < QK_TAP_HOLD_MAX; i++) {
    if (tap_hold_actions[i].state == th_tapped && timer_elapsed(tap_hold_actions[i].timer) >= TAP_HOLD_DELAY) {
      tap_hold_actions[i].state = th_default;
      selectAndSendKey(&tap_hold_actions[i], true);
    }
  }
}

// Shift state processing needed to keep track of whether the key is being held down
// in order to (un)register the proper shift state after some tap-holds.
void process_shift_state(uint16_t keycode, keyrecord_t *record) {
  bool pressed = record->event.pressed;

  if (keycode == OSM(MOD_LSFT) || keycode == KC_LSFT) {
    if (pressed) {
      shift_down += 1;
    } else {
      shift_down -= (shift_down > 0) ? 1 : 0;
    }
  }
}
