#pragma once

enum default_layers { _QWERTY, _COLEMAK_DH, _COLEMAX, _WORKMAN, _DEFAULT_RANGE_ };

enum planck_layers {
    _EXT = _DEFAULT_RANGE_,
    _SYMBOLS,
    _NUM,
    _VSCODE,
    _SWITCH,
    _WNDW_HALF,
    _WNDW_QUAD,
    _WNDW_VERT,
    _WNDW_THRD,
    _WNDW_SIXT,
    _ADJUST,
    _MAX_LAYER_
};

/*
  === DEFAULT LAYERS ===
*/

// QWERTY
#define QWERTY_L1 KC_Q, KC_W, KC_E, KC_R, KC_T
#define QWERTY_L2 KC_A, KC_S, KC_D, KC_F, KC_G
#define QWERTY_L3 KC_Z, KC_X, KC_C, KC_V, KC_B

#define QWERTY_R1 KC_Y, KC_U, KC_I, KC_O, KC_P
#define QWERTY_R2 KC_H, KC_J, KC_K, KC_L, KC_SCLN
#define QWERTY_R3 KC_N, KC_M, KC_COMMA, KC_DOT, KC_QUOTE

// COLEMAK-DH
#define COLEMAK_DH_L1 KC_Q, KC_W, KC_F, KC_P, KC_B
#define COLEMAK_DH_L2 KC_A, KC_R, KC_S, KC_T, KC_G
#define COLEMAK_DH_L3 KC_Z, KC_X, KC_C, KC_D, KC_V

#define COLEMAK_DH_R1 KC_J, KC_L, KC_U, KC_Y, KC_SCLN
#define COLEMAK_DH_R2 KC_M, KC_N, KC_E, KC_I, KC_O
#define COLEMAK_DH_R3 KC_K, KC_H, KC_COMMA, KC_DOT, KC_QUOTE

// COLEMAX - Colemak dh with CF swap and PG swap
#define COLEMAX_L1 KC_Q, KC_W, KC_C, KC_G, KC_B
#define COLEMAX_L2 KC_A, KC_R, KC_S, KC_T, KC_P
#define COLEMAX_L3 KC_Z, KC_X, KC_F, KC_D, KC_V

#define COLEMAX_R1 KC_J, KC_L, KC_U, KC_Y, KC_SCLN
#define COLEMAX_R2 KC_M, KC_N, KC_E, KC_I, KC_O
#define COLEMAX_R3 KC_K, KC_H, KC_COMMA, KC_DOT, KC_QUOTE

// WORKMAN
#define WORKMAN_L1 KC_Q, KC_D, KC_R, KC_W, KC_B
#define WORKMAN_L2 KC_A, KC_S, KC_H, KC_T, KC_G
#define WORKMAN_L3 KC_Z, KC_X, KC_M, KC_C, KC_V

#define WORKMAN_R1 KC_J, KC_F, KC_U, KC_P, KC_SCLN
#define WORKMAN_R2 KC_Y, KC_N, KC_E, KC_I, KC_O
#define WORKMAN_R3 KC_K, KC_L, KC_COMMA, KC_DOT, KC_QUOTE

/*
  === COMMON LAYERS ===
*/

// SYMBOLS
// #define SYMBOLS_L1 KC_BSLS, KC_LBRC, KC_RBRC, KC_PIPE, _______
// #define SYMBOLS_L2 KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_HASH
// #define SYMBOLS_L3 KC_PERC, KC_CRRT, KC_DLR,  KC_AMPR, KC_TILD
// 
// #define SYMBOLS_R1 KC_AT,   KC_LABK, KC_LCBR, KC_RCBR, KC_RABK
// #define SYMBOLS_R2 KC_GRV,  KC_EQL,  KC_LPRN, KC_RPRN, KC_COLON
// #define SYMBOLS_R3 _______, KC_UNDS, KC_QUES, KC_EXLM, KC_DQUO


#define SYMBOLS_L1 KC_LABK, KC_LBRC, KC_RBRC, KC_RABK, _______
#define SYMBOLS_L2 KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, _______
#define SYMBOLS_L3 EXT_L3

#define SYMBOLS_R1 _______, KC_HASH, KC_PLUS, KC_ASTR, KC_PERC
#define SYMBOLS_R2 _______, KC_EQL,  KC_MINS, KC_SLSH, KC_COLN
#define SYMBOLS_R3 _______, KC_UNDS, KC_EXLM, KC_QUES, KC_BSLS


// EXT
#define EXT_R1 XXXXXXX, OSX_HOME, KC_UP,   OSX_END,  XXXXXXX
#define EXT_R2 XXXXXXX, KC_LEFT,  KC_DOWN, KC_RIGHT, XXXXXXX
#define EXT_R3 XXXXXXX, VSC_BACK, XXXXXXX, VSC_FWRD, XXXXXXX 

#define EXT_L1 _______,       _______,       OSX_MC_DESKS,  OSX_APP_WNDW,  _______
// #define EXT_L2 KC_LCTL,      KC_LALT,      KC_LSFT,         KC_LCMD, _______
#define EXT_L2 S_UNDO,        S_CUT,         S_COPY,        S_PASTE,       _______
#define EXT_L3 OSM(MOD_LMEH), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), _______

// #define EXT_CMD1 VSC_SB_EXPLR, VSC_SEL_SHRNK, VSC_SEL_EXPND, VSC_BP_TERML, _______ 
// #define EXT_CMD2 KC_LCTL,      KC_LALT,       KC_LSFT,       KC_LCMD,      VSC_SB_SRCTL
// #define EXT_CMD3 S_UNDO,       S_CUT,         S_COPY,        S_PASTE,      _______

// NUMPAD
#define NUM_R1 KC_MINS, KC_7, KC_8, KC_9, KC_COMMA
#define NUM_R2 KC_PLUS, KC_4, KC_5, KC_6, KC_0
#define NUM_R3 KC_EQL,  KC_1, KC_2, KC_3, KC_DOT

#define NUM_L1 EMPTY_HALF
#define NUM_L2 EXT_L2
#define NUM_L3 EXT_L3


/*
  === COMMANDS ===
*/

// VSCODE
// #define VSCODE_L1 VSC_DBG_BRKP, VSC_DBG_IN, VSC_DBG_OVR,  VSC_SB_DEBUG, _______
// #define VSCODE_L2 _______,      _______,    _______,      VSC_DBG_RUN,  VSC_GOTO_DEF
// #define VSCODE_L3 _______,      _______,    VSC_SHOW_REF, VSC_PEEK_DEF, _______
#define VSCODE_L1 _______,      VSC_SEL_SHRNK, VSC_SEL_EXPND, VSC_SB_DEBUG, _______
#define VSCODE_L2 VSC_DBG_BRKP, VSC_DBG_IN,    VSC_DBG_OVR,   VSC_DBG_RUN,  _______
#define VSCODE_L3 _______,      _______,       _______,       VSC_RENAME,   _______

#define VSCODE_R1 _______, VSC_FCS_G_PREV,    VSC_TOGL_VRT_HRZ, VSC_FCS_G_NEXT,    _______
#define VSCODE_R2 _______, VSC_MV_EDTR_LFT,   VSC_EDTR_SPLT,    VSC_MV_EDTR_RGT,   _______ 
#define VSCODE_R3 _______, VSC_MV_EDTR_G_LFT, _______,          VSC_MV_EDTR_G_RGT, _______

/*
  === APPS/WINDOW MANAGEMENT ===
*/

#define SWITCH_L1 XXXXXXX, WNDW_LAYER_6, WNDW_LAYER_V, XXXXXXX,      XXXXXXX
#define SWITCH_L2 WM_FULL, WNDW_LAYER_3, WNDW_LAYER_Q, WNDW_LAYER_H, XXXXXXX
#define SWITCH_L3 XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX

#define SWITCH_R1 APPS_DESK_R1
#define SWITCH_R2 APPS_DESK_R2
#define SWITCH_R3 APPS_DESK_R3

// APPS/DESKTOPS
#define APPS_DESK_R1 XXXXXXX, OSX_DESK_PREV, OSX_MC_DESKS, OSX_DESK_RIGHT, XXXXXXX
#define APPS_DESK_R2 XXXXXXX, OSX_APP_PREV,  OSX_APP_WNDW, OSX_APP_NEXT,   XXXXXXX
#define APPS_DESK_R3 XXXXXXX, XXXXXXX,       OSX_MC_APPS,  XXXXXXX,        XXXXXXX
// HALF TILING
#define WNDW_HALF_R1 _______, XXXXXXX, WM_H_U, XXXXXXX, _______
#define WNDW_HALF_R2 _______, WM_H_L,  WM_H_M, WM_H_R,  _______
#define WNDW_HALF_R3 _______, XXXXXXX, WM_H_D, XXXXXXX, _______
// QUAD TILING
#define WNDW_QUAD_R1 _______, WM_4Q_UL, XXXXXXX, WM_4Q_UR, _______
#define WNDW_QUAD_R2 _______, XXXXXXX,  XXXXXXX, XXXXXXX,  _______
#define WNDW_QUAD_R3 _______, WM_4Q_LL, XXXXXXX, WM_4Q_LR, _______
// VERTICAL FOURTH TILING
#define WNDW_VERT_R1 _______, XXXXXXX,  XXXXXXX, XXXXXXX,  _______
#define WNDW_VERT_R2 _______, WM_4V_L,  XXXXXXX, WM_4V_R,  _______
#define WNDW_VERT_R3 _______, WM_4V_LC, XXXXXXX, WM_4V_RC, _______
// THRID TILING
#define WNDW_THRD_R1 _______, WM_3_LL, XXXXXXX, WM_3_RR, _______
#define WNDW_THRD_R2 _______, WM_3_L,  WM_3_M,  WM_3_R,  _______
#define WNDW_THRD_R3 _______, XXXXXXX, XXXXXXX, XXXXXXX, _______
// SIXTH TILING
#define WNDW_SIXT_R1 _______, WM_6_UL, WM_6_UM, WM_6_UR, _______
#define WNDW_SIXT_R2 _______, XXXXXXX, XXXXXXX, XXXXXXX, _______
#define WNDW_SIXT_R3 _______, WM_6_LL, WM_6_LM, WM_6_LR, _______

/*
  === ADJUST ===
*/

#define ADJUST_L1 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WORKMAN
#define ADJUST_L2 XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY, XXXXXXX
#define ADJUST_L3 XXXXXXX, XXXXXXX, XXXXXXX, KC_MSTP, XXXXXXX
#define ADJUST_LB XXXXXXX, XXXXXXX


#define ADJUST_R1 KC_QWERTY,     XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX
#define ADJUST_R2 KC_COLEMAK_DH, KC_MUTE, KC_VOLD,       KC_VOLU, KC_LED_INC_BRGT
#define ADJUST_R3 KC_COLEMAX,    RGB_TOG, KC_LAYERCOLOR, RGB_MOD, KC_LED_DCR_BRGT
#define ADJUST_RB RESET, DEBUG