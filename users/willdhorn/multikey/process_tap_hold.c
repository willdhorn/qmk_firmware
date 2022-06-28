#include QMK_KEYBOARD_H

#include "process_tap_hold.h"

// I really want to remove this, but it has to stay until
// the processing of custom keycodes can be refactored.
#include "willdhorn.h"

extern tap_hold_action_t tap_hold_actions[];

uint8_t shift_down;

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
    } else if (process_keycode_user(keycode,KEYRECORD_PRESS(true))) {
            tap_code16(keycode);
    }

    if (shift_down) {
        register_mods(MOD_BIT(KC_LSFT)); // I don't use right shift (at the moment at least..)
    }
    send_keyboard_report();
}

void process_record_tap_hold(uint16_t keycode, keyrecord_t *record) {
  process_shift_state(keycode, record);

  // if (QK_TAP_HOLD <= keycode && keycode <= QK_TAP_HOLD+QK_TAP_HOLD_SIZE-1) {
  if (QK_TAP_HOLD <= keycode && keycode <= QK_TAP_HOLD_MAX) {
    uint16_t idx = keycode - QK_TAP_HOLD;
    tap_hold_action_t *t = &tap_hold_actions[idx];
    if (record->event.pressed) {
      // On key press, start timer and do nothing
      t->timer = timer_read();
      t->state = th_first_press;
    } else {
      if (t->state == th_first_press) {
        // If key is released before timer expires, reset state and send tap key
        t->state = th_default;
        selectAndSendKey(t, false);
      }
    }
  } else if (record->event.pressed) {
    // If another key is pressed, interupt current tap-hold
    for (int i = 0; i < TAP_HOLD_KEY_MAX; ++i) {
      tap_hold_action_t *t = &tap_hold_actions[i];
      if (t->state == th_first_press) {
        t->state = th_default;
        selectAndSendKey(t, false);
      }
    }
  }
}

void matrix_scan_tap_hold(void) {
  for (uint8_t i = 0; i < TAP_HOLD_KEY_MAX; i++) {
    if (tap_hold_actions[i].state == th_first_press && timer_elapsed(tap_hold_actions[i].timer) >= TAP_HOLD_DELAY) {
      tap_hold_actions[i].state = th_default;
      selectAndSendKey(&tap_hold_actions[i], true);
    }
  }
}

// Shift state processing needed to keep track of whether the key is being held down
// in order to (un)register the proper shift state after some tap-holds.
void process_shift_state(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;

    if ((IS_MOD_TAP(keycode) && MT_MODS(keycode) & MOD_MASK_SHIFT) || (IS_OSM(keycode) && OSM_MODS(keycode) & MOD_MASK_SHIFT) || keycode == KC_LSFT || keycode == KC_RSFT) {
      if (pressed) {
        shift_down += 1;
      } else {
        shift_down -= (shift_down > 0) ? 1 : 0;
      }
    }
}
