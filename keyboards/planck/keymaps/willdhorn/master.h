#pragma once

/*
  === DEFAULT LAYOUTS ===
*/

// QWERTY
#define QWERTY_L1 KC_Q, KC_W, KC_E, KC_R, KC_T
#define QWERTY_L2 KC_A, KC_S, KC_D, KC_F, KC_G
#define QWERTY_L3 KC_Z, KC_X, KC_C, KC_V, KC_B

#define QWERTY_R1 KC_Y, KC_U, KC_I, KC_O, KC_P
#define QWERTY_R2 KC_H, KC_J, KC_K, KC_L, KC_SCLN
#define QWERTY_R3 KC_N, KC_M, KC_COMMA, KC_DOT, KC_QUOTE

// COLEMAK
#define COLEMAK_L1 KC_Q, KC_W, KC_F, KC_P, KC_B
#define COLEMAK_L2 KC_A, KC_R, KC_S, KC_T, KC_G
#define COLEMAK_L3 KC_Z, KC_X, KC_C, KC_D, KC_V

#define COLEMAK_R1 KC_J, KC_L, KC_U, KC_Y, KC_SCLN
#define COLEMAK_R2 KC_M, KC_N, KC_E, KC_I, KC_O
#define COLEMAK_R3 KC_K, KC_H, KC_COMMA, KC_DOT, KC_QUOTE

/*
  === COMMON LAYERS ===
*/

// SYMBOLS
#define SYMBOLS_L1 KC_PERC, KC_LBRC, KC_RBRC, KC_QUES, KC_HASH
#define SYMBOLS_L2 KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_TILD
#define SYMBOLS_L3 KC_BSLS, KC_PIPE, KC_AMPR, KC_EXLM, _______

#define SYMBOLS_R1 KC_AT,   KC_CRRT, KC_LCBR, KC_RCBR, KC_DLR
#define SYMBOLS_R2 KC_GRV,  KC_EQL,  KC_LPRN, KC_RPRN, KC_COLON
#define SYMBOLS_R3 _______, KC_UNDS, KC_LABK, KC_RABK, KC_DQUO

// NAV
#define NAV_R1 _______, KC_UP,   S_TABL,   S_TABR,   _______
#define NAV_R2 _______, KC_DOWN, KC_LEFT,  KC_RIGHT, _______
#define NAV_R3 _______, _______, VSC_BACK, VSC_FWRD, _______

#define NAV_CMD1           VSC_SB_EXPLR, VSC_SEL_SHRNK, VSC_SEL_EXPND, VSC_BP_TERML, _______
#define NAV_CMD2_ MOD_LEFT(_______,      _______,       _______,       _______,      VSC_SB_SRCTL)
#define NAV_CMD3           _______,      _______,       _______,       _______,      _______
#define NAV_CMD2 MOD_LEFT(NAV_CMD2_)

// NUMPAD
#define NUM_R1 _______,  KC_7, KC_8, KC_9, _______
#define NUM_R2 KC_COMMA, KC_4, KC_5, KC_6, KC_0
#define NUM_R3 _______,  KC_1, KC_2, KC_3, KC_DOT

#define NUM_CMD1 VSC_BP_PRBLM, VSC_PROB_PREV, VSC_PROB_NEXT, VSC_SB_SEARC, VSC_GOTO_SYMB
#define NUM_CMD2 _______,      _______,       _______,       _______,      VSC_GOTO_LINE 
#define NUM_CMD3 _______,      VSC_FIND_PREV, VSC_FIND_NEXT, VSC_FIND,     _______

// ADJUST
#define ADJUST_L1 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ADJUST_L2 XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP
#define ADJUST_L3 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ADJUST_LB XXXXXXX, XXXXXXX


#define ADJUST_R1 XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, DF(_COLEMAK)
#define ADJUST_R2 XXXXXXX, KC_MUTE, KC_VOLD,       KC_VOLU, DF(_QWERTY)
#define ADJUST_R3 XXXXXXX, RGB_TOG, KC_LAYERCOLOR, RGB_MOD, XXXXXXX
#define ADJUST_RB RESET, DEBUG
/*
  === COMMANDS ===
*/

// VSCODE
#define VSCODE_L1 VSC_DBG_BRKP, VSC_DBG_IN, VSC_DBG_OVR,  VSC_SB_DEBUG, _______
#define VSCODE_L2 _______,      _______,    _______,      VSC_DBG_RUN,  VSC_GOTO_DEF
#define VSCODE_L3 _______,      _______,    VSC_SHOW_REF, VSC_PEEK_DEF, _______

#define VSCODE_R1 _______, _______,    VSC_FCS_G_PREV,    VSC_FCS_G_NEXT,    _______
#define VSCODE_R2 _______, VSC_RENAME, VSC_MV_EDTR_LFT,   VSC_MV_EDTR_RGT,   VSC_EDTR_SPLT
#define VSCODE_R3 _______, _______,    VSC_MV_EDTR_G_LFT, VSC_MV_EDTR_G_RGT, VSC_TOGL_VRT_HRZ

/*
  === APPS/WINDOW MANAGEMENT ===
*/
#define APPS_WNDW_L1 XXXXXXX, WNDW_LAYER_6, WNDW_LAYER_V, XXXXXXX,      XXXXXXX
#define APPS_WNDW_L2 WM_FULL, WNDW_LAYER_3, WNDW_LAYER_Q, WNDW_LAYER_H, XXXXXXX
#define APPS_WNDW_L3 XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX

#define APPS_WNDW_R1 APPS_DESK_R1
#define APPS_WNDW_R2 APPS_DESK_R2
#define APPS_WNDW_R3 APPS_DESK_R3

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


