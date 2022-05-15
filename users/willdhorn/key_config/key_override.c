#include QMK_KEYBOARD_H
#include "willdhorn.h"

const key_override_t sft_ovr_hash_grave             = ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_GRAVE);
const key_override_t sft_ovr_vscode_selection       = SHIFT_OVERRIDE(VSC_SEL_EXPND, VSC_SEL_SHRNK);
const key_override_t meh_ovr_default_layer          = MEH_OVERRIDE(LK_EXT, LK_DEF);
const key_override_t alt_ovr_left_hand_th_ext_layer = ALT_OVERRIDE(TH_LK_SYM, LK_EXT);
const key_override_t alt_ovr_left_hand_ext_layer    = ALT_OVERRIDE(LK_SYM, LK_EXT);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &sft_ovr_hash_grave,
    &sft_ovr_vscode_selection,
    &meh_ovr_default_layer,
    &alt_ovr_left_hand_th_ext_layer,
    &alt_ovr_left_hand_ext_layer,
    NULL // Null terminate the array of overrides!
};
