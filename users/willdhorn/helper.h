#pragma once

#include <stdint.h>

#include "config.h"
#include "layers.h"
#include "layouts.h"
#include "rgb_stuff.h"
#include "tap_dances.h"
#include "user_debug.h"

bool process_custom_keys(uint16_t keycode, keyrecord_t *record);
bool process_custom_keypress(uint16_t keycode, bool pressed);
void process_mod_tap_keys(uint16_t keycode, keyrecord_t *record);
void process_default_layer_keys(uint16_t keycode, keyrecord_t *record);
void process_led_keys(uint16_t keycode, keyrecord_t *record);
void process_vscode_keys(uint16_t keycode, keyrecord_t *record);

// Functions for handling vscode short cut sequences
void two_tap(uint16_t kc1, uint16_t kc2);
void vscode_chord(uint16_t kc);

// Alt-Tab mode handler
void handle_alt_tab_mode(uint16_t kc);
