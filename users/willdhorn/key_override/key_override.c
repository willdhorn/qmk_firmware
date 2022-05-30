#include QMK_KEYBOARD_H

#include "willdhorn.h"

// Generate key_override_t structs
#undef KO_SFT
#undef KO_MEH
#define KO_SFT SFT_KO_DATA
#define KO_MEH MEH_KO_DATA
#include "key_override.def"

// Fill key overrides array
#undef KO_SFT
#undef KO_MEH
#define KO_SFT KO_ENTRY
#define KO_MEH KO_ENTRY
const key_override_t **key_overrides = (const key_override_t *[]){
#include "key_override.def"
    NULL // Null terminate the array of overrides!
};
