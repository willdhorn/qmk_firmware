#pragma once

#include "config.h"

enum default_layers { _QWERTY, _COLEMAK_DH, _ISRT, _WORKMAN, _DEFAULT_RANGE_ };

enum planck_layers {
    // EXT contains the edge keys (for split 5x3 layout)
    _EXT = _DEFAULT_RANGE_,
    // NUM contains a numpad under the RH and more symbols (that are also commonly used with numbers)
    _NUM,
    _NAV,
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

#define COLEMAK_DH_R1 KC_J, KC_L, KC_U, KC_Y, KC_BSPACE
#define COLEMAK_DH_R2 KC_M, KC_N, KC_E, KC_I, KC_O
#define COLEMAK_DH_R3 KC_K, KC_H, KC_COMMA, KC_DOT, KC_QUOTE

// ISRT
#define ISRT_L1 KC_Y, KC_C, KC_L, KC_M, KC_K
#define ISRT_L2 KC_I, KC_S, KC_R, KC_T, KC_G
#define ISRT_L3 KC_Q, KC_V, KC_W, KC_D, KC_J

#define ISRT_R1 KC_Z, KC_F, KC_U, KC_COMMA, KC_QUOTE
#define ISRT_R2 KC_M, KC_N, KC_E, KC_A, KC_O
#define ISRT_R3 KC_B, KC_H, KC_SLASH, KC_DOT, KC_O

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

#define SHORTCUT_ROW S_UNDO,  S_CUT,   S_COPY,  S_PASTE,  S_CLIPBOARD

// NAV
// #define NAV_L1 KC_BSLS, KC_LBRC, KC_RBRC, KC_PIPE, _______
// #define NAV_L2 KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_HASH
// #define NAV_L3 KC_PERC, KC_CRRT, KC_DLR,  KC_AMPR, KC_TILD
// 
// #define NAV_R1 KC_AT,   KC_LABK, KC_LCBR, KC_RCBR, KC_RABK
// #define NAV_R2 KC_GRV,  KC_EQL,  KC_LPRN, KC_RPRN, KC_COLON
// #define NAV_R3 _______, KC_UNDS, KC_QUES, KC_EXLM, KC_DQUO

#define EXT_L1 KC_TAB,  KC_ASTR, KC_PLUS, KC_PIPE,  _x_
#define EXT_L2 KC_ESC,  KC_SLSH, KC_MINS, KC_EQUAL, KC_BSLS
#define EXT_L3 SHORTCUT_ROW

#define EXT_R1 _x_,     KC_AMPR, KC_LCBR, KC_RCBR, KC_BSPACE
#define EXT_R2 KC_HASH, KC_COLN, KC_LPRN, KC_RPRN, KC_ENTER
#define EXT_R3 KC_AT,   KC_UNDS, KC_LBRC, KC_RBRC, TO(_NAV)


// NUM
#define NUM_L1 KC_CRRT, KC_ASTR, KC_PLUS, KC_DLR,   _x_
#define NUM_L2 KC_PERC, KC_SLSH, KC_MINS, KC_EQUAL, KC_HASH
#define NUM_L3 TO(0),   KC_LABK, KC_RABK, KC_TILD,  _x_

#define NUM_R1 _x_,       KC_7, KC_8, KC_9, KC_BSPACE
#define NUM_R2 KC_DOT,    KC_4, KC_5, KC_6, KC_0
#define NUM_R3 KC_COMMA,  KC_1, KC_2, KC_3, TO(_NAV)


// NAV
#define NAV_L1 KC_TAB,   _x_,     _x_,           _x_,           _x_
#define NAV_L2 KC_ESC,   _x_,     OSM(MOD_LCTL), OSM(MOD_LALT), _x_
#define NAV_L3 SHORTCUT_ROW

#define NAV_R1 _x_,     OSX_HOME, KC_UP,       OSX_END,  KC_BSPACE
#define NAV_R2 _x_,     KC_LEFT,  KC_DOWN,     KC_RIGHT, KC_ENTER
#define NAV_R3 _x_,     VSC_BACK, TO(_SWITCH), VSC_FWRD, TO(_EXT)  


/*
  === COMMANDS ===
*/
// VSCODE
#define VSCODE_L1 _x_,          VSC_SEL_SHRNK, VSC_SEL_EXPND, VSC_SB_DEBUG, _x_
#define VSCODE_L2 VSC_DBG_BRKP, VSC_DBG_IN,    VSC_DBG_OVR,   VSC_DBG_RUN,  _x_
#define VSCODE_L3 _x_,          _x_,           _x_,           VSC_RENAME,   _x_

#define VSCODE_R1 _x_,     VSC_FCS_G_PREV,    VSC_TOGL_VRT_HRZ, VSC_FCS_G_NEXT,    _x_
#define VSCODE_R2 _x_,     VSC_MV_EDTR_LFT,   VSC_EDTR_SPLT,    VSC_MV_EDTR_RGT,   _x_ 
#define VSCODE_R3 _x_,     VSC_MV_EDTR_G_LFT, _x_,              VSC_MV_EDTR_G_RGT, _x_

/*
  === APPS/WINDOW MANAGEMENT ===
*/

#define SWITCH_L1 _x_,     WNDW_LAYER_6, WNDW_LAYER_V, _x_,          _x_
#define SWITCH_L2 WM_FULL, WNDW_LAYER_3, WNDW_LAYER_Q, WNDW_LAYER_H, _x_
#define SWITCH_L3 _x_,     _x_,          _x_,          _x_,          _x_

#define SWITCH_R1 APPS_DESK_R1
#define SWITCH_R2 APPS_DESK_R2
#define SWITCH_R3 APPS_DESK_R3

// APPS/DESKTOPS
#define APPS_DESK_R1 _x_,     OSX_DESK_PREV, OSX_MC_DESKS, OSX_DESK_RIGHT, _x_
#define APPS_DESK_R2 _x_,     OSX_APP_PREV,  OSX_APP_WNDW, OSX_APP_NEXT,   _x_
#define APPS_DESK_R3 _x_,     _x_,           OSX_MC_APPS,  _x_,            TO(_NAV)
// HALF TILING
#define WNDW_HALF_R1 _x_,     _x_,     WM_H_U, _x_,        _x_
#define WNDW_HALF_R2 _x_,     WM_H_L,  WM_H_M, WM_H_R,     _x_
#define WNDW_HALF_R3 _x_,     _x_,     WM_H_D, _x_,        TO(_NAV)
// QUAD TILING
#define WNDW_QUAD_R1 _x_,     WM_4Q_UL, _x_,     WM_4Q_UR, _x_
#define WNDW_QUAD_R2 _x_,     _x_,      _x_,     _x_,      _x_
#define WNDW_QUAD_R3 _x_,     WM_4Q_LL, _x_,     WM_4Q_LR, TO(_NAV)
// VERTICAL FOURTH TILING
#define WNDW_VERT_R1 _x_,     _x_,      _x_,     _x_,      _x_
#define WNDW_VERT_R2 _x_,     WM_4V_L,  _x_,     WM_4V_R,  _x_
#define WNDW_VERT_R3 _x_,     WM_4V_LC, _x_,     WM_4V_RC, TO(_NAV)
// THRID TILING
#define WNDW_THRD_R1 _x_,     WM_3_LL, _x_,     WM_3_RR,   _x_
#define WNDW_THRD_R2 _x_,     WM_3_L,  WM_3_M,  WM_3_R,    _x_
#define WNDW_THRD_R3 _x_,     _x_,     _x_,     _x_,       TO(_NAV)
// SIXTH TILING
#define WNDW_SIXT_R1 _x_,     WM_6_UL, WM_6_UM, WM_6_UR,   _x_
#define WNDW_SIXT_R2 _x_,     _x_,     _x_,     _x_,       _x_
#define WNDW_SIXT_R3 _x_,     WM_6_LL, WM_6_LM, WM_6_LR,   TO(_NAV)

/*
  === ADJUST ===
*/

#define ADJUST_L1 RESET,   DEBUG,     _x_,     _x_,     KC_WORKMAN
#define ADJUST_L2 _x_,     KC_MPRV, KC_MNXT, KC_MPLY, _x_
#define ADJUST_L3 _x_,     _x_,     _x_,     KC_MSTP, _x_


#define ADJUST_R1 KC_QWERTY,     _x_,     _x_,           _x_,     _x_
#define ADJUST_R2 KC_COLEMAK_DH, KC_MUTE, KC_VOLD,       KC_VOLU, KC_LED_INC_BRGT
#define ADJUST_R3 KC_ISRT,    RGB_TOG, KC_LAYERCOLOR, RGB_MOD, KC_LED_DCR_BRGT