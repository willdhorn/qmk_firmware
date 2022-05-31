#pragma once

#include "willdhorn.h"

#define TH_ENUM(name, key, ...) name,
#define TH_ACTION(name, key, ...) [name] = ACTION_TAP_HOLD_FULL(key, __VA_ARGS__),

#define TAP_HOLD_ALL(name, key, sft, hold, sft_hold) TH_DEF(name, key, sft, hold, sft_hold)
#define TAP_HOLD(name, key, hold) TH_DEF(name, key, LSFT(key), hold, LSFT(hold))
#define TAP_HOLD_CMD(name, key) TH_DEF(name, key, LSFT(key), LCMD(key), LSFT(LCMD(key)))

// replacement for key overrides with custom keycodes
#define TH_SFT_OVR(name, key, sft) TH_DEF(name, key, sft, key, sft)

/*** GENERATE ***/

// Generate enum values for tap-hold actions
#undef TH_DEF
#define TH_DEF TH_ENUM
enum tap_hold_action_keys {
  #include "tap_hold.def"
};

