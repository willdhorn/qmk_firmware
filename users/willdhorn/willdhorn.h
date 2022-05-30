#pragma once
#include QMK_KEYBOARD_H

#include "quantum.h"

#include "multikey/process_tap_hold.h"
#include "multikey/tap_hold.h"

#include "base/process_record.h"
#include "base/layers.h"
#include "base/layout.h"
#include "base/keycodes/custom.h"
#include "base/keycodes/key_defines.h"
#include "base/keycodes/mods.h"
#include "base/keycodes/key_tests.h"

//#include "callum_mods/callum_mods.h"

#ifdef KEY_OVERRIDE_ENABLE
#  include "key_override/key_override.h"
#endif

#ifdef TAP_DANCE_ENABLE
#  include "tap_dance/tap_dances.h"
#endif

#ifdef RGB_ENABLE
#  include "rgb/rgb_stuff.h"
#endif
// #include "print.h"

// Debugging macros
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte) (byte & 0x80 ? '1' : '0'), (byte & 0x40 ? '1' : '0'), (byte & 0x20 ? '1' : '0'), (byte & 0x10 ? '1' : '0'), (byte & 0x08 ? '1' : '0'), (byte & 0x04 ? '1' : '0'), (byte & 0x02 ? '1' : '0'), (byte & 0x01 ? '1' : '0')
#define BOOL_STR(val) ((val) ? "true" : "false")

#define DEBUG_KEYCODE_HEX(kc) dprintf("kc:   0x%04X\n", kc)
#define DEBUG_KEYCODE_BINARY(kc) dprintf("keycode:\t" BYTE_TO_BINARY_PATTERN " " BYTE_TO_BINARY_PATTERN "\n", BYTE_TO_BINARY(kc >> 8), BYTE_TO_BINARY(kc))
#define DEBUG_BYTE_BINARY(label, byte) dprintf(label ":\t" BYTE_TO_BINARY_PATTERN "\n", BYTE_TO_BINARY(byte))
