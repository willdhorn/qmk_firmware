#include QMK_KEYBOARD_H

#include "process_tap_hold.h"
#include "key_defs.h"
#include "user_debug.h"


extern tap_hold_action_t tap_hold_actions[];

extern uint8_t shift_down;

void selectAndSendKey(tap_hold_action_t *t, bool is_held) {
        uint8_t mods = get_mods();
    if (shiftActive()) {
      // Suppress shift
      unregister_mods(MOD_MASK_SHIFT);

      dprintf("Tap Hold Shifted: %d\n", (is_held ? t->KC_hold_shift : t->KC_tap_shift));
      tap_code16(is_held ? t->KC_hold_shift : t->KC_tap_shift);

      // add shift back if the key is still being held down
      if (shift_down) {
        register_mods(MOD_BIT(KC_LSFT));
      }
      send_keyboard_report();
  } else {
      dprintf("Tap Hold Normal: %d\n", (is_held ? t->KC_hold : t->KC_tap));
      tap_code16(is_held ? t->KC_hold : t->KC_tap);
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

void process_record_tap_hold(uint16_t keycode, keyrecord_t *record) {
  // if (QK_TAP_HOLD <= keycode && keycode <= QK_TAP_HOLD+QK_TAP_HOLD_SIZE-1) {
  if (QK_TAP_HOLD <= keycode && keycode <= QK_TAP_HOLD_MAX) {
    uint16_t idx = keycode - QK_TAP_HOLD;
    tap_hold_action_t *t = &tap_hold_actions[idx];
    if (record->event.pressed) {
      t->timer = timer_read();
      t->state = th_first_press;
    } else {
      if (t->state == th_first_press) {
        t->state = th_default;
        selectAndSendKey(t, false);
      }
    }
  } else if (record->event.pressed) {  // only interrupt on keydown
    for (int i = 0; i < TAP_HOLD_KEY_MAX; ++i) {
      tap_hold_action_t *t = &tap_hold_actions[i];
      if (t->state == th_first_press) {
        t->state = th_default;
        selectAndSendKey(t, false);
      }
    }
  }
}
