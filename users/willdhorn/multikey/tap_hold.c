#include QMK_KEYBOARD_H

#include "willdhorn.h"

// Fill tap-hold actions array
#undef TH_DEF
#define TH_DEF TH_ACTION
// Unlike combo or key override arrays, this cannot be const since the
// the tap_hold actions contain state information for each tap hold
tap_hold_action_t tap_hold_actions[] = {
#include "tap_hold.def"
};
