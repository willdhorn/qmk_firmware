#include QMK_KEYBOARD_H
#include "key_defs.h"

// const key_override_t delete_key_override = SHIFT_OVERRIDE(KC_BSPACE, KC_DELETE);
//
// const key_override_t period_question_override = SHIFT_OVERRIDE(KC_DOT, KC_QUES);
// const key_override_t period_question_alt_override = ALT_OVERRIDE(KC_DOT, KC_QUES);
// const key_override_t comma_exclamation_override = SHIFT_OVERRIDE(KC_COMMA, KC_EXLM);
// const key_override_t comma_exclamation_alt_override = ALT_OVERRIDE(KC_COMMA, KC_EXLM);
// const key_override_t quote_dquote_alt_override = ALT_OVERRIDE(KC_QUOT, KC_DQUO);

// const key_override_t sym_lparen_lbracket_override = SHIFT_OVERRIDE(KC_LPRN, KC_LBRC);
// const key_override_t sym_rparen_rbracket_override = SHIFT_OVERRIDE(KC_RPRN, KC_RBRC);
// const key_override_t sym_lbrace_langlebr_override = SHIFT_OVERRIDE(KC_LCBR, KC_LABK);
// const key_override_t sym_rbrace_ranglebr_override = SHIFT_OVERRIDE(KC_RCBR, KC_RABK);

// const key_override_t sym_plus_carrot_override = SHIFT_OVERRIDE(KC_PLUS, KC_CRRT);
// const key_override_t sym_astrick_dollar_override = SHIFT_OVERRIDE(KC_ASTR, KC_DLR);
// const key_override_t sym_equal_tilde_override = SHIFT_OVERRIDE(KC_EQL, KC_TILD);
// const key_override_t sym_minus_ampersand_override = SHIFT_OVERRIDE(KC_MINS, KC_AMPR);
// const key_override_t sym_slash_bsls_override = SHIFT_OVERRIDE(KC_SLSH, KC_BSLS);
// const key_override_t sym_colon_semicolon_override = SHIFT_OVERRIDE(KC_COLN, KC_SCLN);
// const key_override_t sym_tilde_grave_override = SHIFT_OVERRIDE(KC_TILD, KC_GRV);


// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    // &delete_key_override,
    &period_question_override,
    &comma_exclamation_override,
    &period_question_alt_override,
    &comma_exclamation_alt_override,
    &quote_dquote_alt_override,
    // &sym_lparen_lbracket_override,
    // &sym_rparen_rbracket_override,
    &sym_lbrace_langlebr_override,
    &sym_rbrace_ranglebr_override,
    // &sym_plus_carrot_override,
    // &sym_astrick_dollar_override,
    // &sym_equal_tilde_override,
    // &sym_minus_ampersand_override,
    // &sym_slash_bsls_override,
    &sym_colon_semicolon_override,
    // &sym_tilde_grave_override,
    &sym_vscode_selection_override,
    NULL // Null terminate the array of overrides!
};
