#include QMK_KEYBOARD_H

#include "willdhorn.h"

/* === KEY OVERRIDES === */

// Generate key_override_t structs
#undef KO_SFT
#undef KO_MEH
#define KO_SFT SFT_KO_DATA
#define KO_MEH MEH_KO_DATA
#include "dicts/key_overrides.def"

// Fill key overrides array
#undef KO_SFT
#undef KO_MEH
#define KO_SFT KO_ENTRY
#define KO_MEH KO_ENTRY
const key_override_t **key_overrides = (const key_override_t *[]){
#include "dicts/key_overrides.def"
    NULL // Null terminate the array of overrides!
};

/* === TAP HOLD === */

// Fill tap-hold actions array
#undef TH_DEF
#define TH_DEF TH_ACTION
// DON'T MAKE THIS CONST
tap_hold_action_t tap_hold_actions[] = {
#include "dicts/tap_hold.def"
};
