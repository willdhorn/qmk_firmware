#pragma once

#include <stdint.h>

#include "willdhorn.h"

#define KEYRECORD_PRESS(pressed)       \
  &(keyrecord_t) {                     \
    {{1, 1}, pressed, timer_read()}, { \
      false, false, false, false, 1    \
    }                                  \
  }

bool process_keycode_user(uint16_t keycode, keyrecord_t *record);
void process_mod_tap_keys(uint16_t keycode, keyrecord_t *record);
void process_default_layer_keys(uint16_t keycode, keyrecord_t *record);
void process_led_keys(uint16_t keycode, keyrecord_t *record);
void process_vscode_keys(uint16_t keycode, keyrecord_t *record);

// Functions for handling vscode short cut sequences
void two_tap(uint16_t kc1, uint16_t kc2);
void vscode_chord(uint16_t kc);

// Alt-Tab mode handler
void handle_alt_tab_mode(uint16_t kc);
