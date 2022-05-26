#pragma once
#include QMK_KEYBOARD_H

#include "quantum.h"

#include "quantum/process_tap_hold.h"
#include "quantum/callum_mods.h"

#include "key_behavior/process_record.h"
#ifdef TAP_DANCE_ENABLE
#  include "key_behavior/tap_dances.h"
#endif

#include "key_config/layers.h"
#include "key_config/layout.h"
#include "key_config/key_override.h"
#include "key_config/tap_hold.h"
#include "key_config/key_tests.h"

#include "key_config/keycodes/custom.h"
#include "key_config/keycodes/key_defines.h"
#include "key_config/keycodes/mods.h"

#ifdef RGB_ENABLE
#  include "whistle_bells/rgb/rgb_stuff.h"
#endif
// #include "print.h"

// Debugging macros
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte) (byte & 0x80 ? '1' : '0'), (byte & 0x40 ? '1' : '0'), (byte & 0x20 ? '1' : '0'), (byte & 0x10 ? '1' : '0'), (byte & 0x08 ? '1' : '0'), (byte & 0x04 ? '1' : '0'), (byte & 0x02 ? '1' : '0'), (byte & 0x01 ? '1' : '0')
#define BOOL_STR(val) ((val) ? "true" : "false")

#define DEBUG_KEYCODE_HEX(kc) dprintf("kc:   0x%04X\n", kc)
#define DEBUG_KEYCODE_BINARY(kc) dprintf("keycode:\t" BYTE_TO_BINARY_PATTERN " " BYTE_TO_BINARY_PATTERN "\n", BYTE_TO_BINARY(kc >> 8), BYTE_TO_BINARY(kc))
#define DEBUG_BYTE_BINARY(label, byte) dprintf(label ":\t" BYTE_TO_BINARY_PATTERN "\n", BYTE_TO_BINARY(byte))
