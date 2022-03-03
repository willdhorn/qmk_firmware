#include QMK_KEYBOARD_H

#include "process_tap_hold.h"
#include "helper.h"
#include "key_defs.h"
#include "user_debug.h"


extern uint8_t shift_down;
extern tap_hold_action_t tap_hold_actions[];

void selectAndSendKey(tap_hold_action_t *t, bool is_held) {
    uint8_t mods = get_mods();
    mods |= get_oneshot_mods();
    uint16_t keycode;
    if (shiftActive(mods)) {
        // Suppress shift
        unregister_mods(MOD_MASK_SHIFT);
        del_oneshot_mods(MOD_MASK_SHIFT);

        keycode = (is_held ? t->KC_hold_shift : t->KC_tap_shift);

        dprint("Tap Hold Shifted: \n\t");
        DEBUG_KEYCODE_HEX(keycode);
        dprint("\t");
        DEBUG_KEYCODE_BINARY(keycode);
    } else {
        keycode = (is_held ? t->KC_hold : t->KC_tap);

        dprint("Tap Hold Normal: \n\t");
        DEBUG_KEYCODE_HEX(keycode);
        dprint("\t");
        DEBUG_KEYCODE_BINARY(keycode);
    }

    if (keycode == KC_CAPS_LOCK) {
        register_code16(keycode);
        wait_ms(100);
        unregister_code16(keycode);
    } else if (process_custom_keypress(keycode,true)) {
            tap_code16(keycode);
    }
    // add shift back if the key is still being held down
    if (shift_down) {
        register_mods(MOD_BIT(KC_LSFT)); // I don't use right shift (at the moment at least..)
    }
    send_keyboard_report();
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
