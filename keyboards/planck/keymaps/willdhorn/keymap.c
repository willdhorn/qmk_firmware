#include QMK_KEYBOARD_H

#include "willdhorn.h"

// Setup to run on keyboard start up
void keyboard_post_init_user(void) {
  // help
  //  debug_enable = true;
  //     debug_matrix = true;
  print("Finalizing initialization.\n");
  dprint("Debug enabled.\n");
  rgb_matrix_enable();
  print("RGB matrix enabled.\n");
  set_default_layer_colors(default_layer_state);
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  bool pressed = record->event.pressed;
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
  return true;
}

void rgb_matrix_indicators_keymap(void) {
  // Set caps lock indicator light
  if (host_keyboard_led_state().caps_lock) {
    planck_ez_left_led_level(255);
  } else {
    planck_ez_left_led_level(0);
  }
}
