#pragma once

#include "config.h"
#include "key_defs.h"

enum default_layers {
    _QWERTY,
    _COLEMAK_DH,
    _ISRT,
    _DEFAULT_RANGE_ };

enum user_layers {
    _EXT = _DEFAULT_RANGE_,
    _SYM,
    _NUM,
    _ADJUST,
    _DESKTOP,
    _VSCODE,
    _WNDW_HALF,
    _WNDW_THRD,
    _WNDW_QUAD,
    _WNDW_SIXT,
    _WNDW_NINT,
    _NAV,
    _WNDW_VERT,
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
#define QWERTY_R3 KC_N, KC_M, TH_COMMA, TH_DOT, TH_QUOT

// COLEMAK-DH
#define COLEMAK_DH_L1 KC_Q, KC_W, KC_F, KC_P, KC_B
#define COLEMAK_DH_L2 KC_A, KC_R, KC_S, KC_T, KC_G
#define COLEMAK_DH_L3 KC_Z, KC_X, KC_C, KC_D, KC_V
// #define COLEMAK_DH_L3 TH_UNDO_Z, TH_CUT_X, TH_COPY_C, TH_PASTE_D, TH_CLIPBOARD_V


#define COLEMAK_DH_R1 KC_J, KC_L, KC_U, KC_Y, TH_BKSP
#define COLEMAK_DH_R2 KC_M, KC_N, KC_E, KC_I, KC_O
#define COLEMAK_DH_R3 KC_K, KC_H, TH_COMMA, TH_DOT, TH_QUOT

// ISRT
#define ISRT_L1 KC_Y, KC_C, KC_L, KC_M, KC_K
#define ISRT_L2 KC_I, KC_S, KC_R, KC_T, KC_G
#define ISRT_L3 KC_Q, KC_V, KC_W, KC_D, KC_J

#define ISRT_R1 KC_Z, KC_F, KC_U,     TH_QUOT, TH_BKSP
#define ISRT_R2 KC_M, KC_N, KC_E,     KC_A,    KC_O
#define ISRT_R3 KC_B, KC_H, TH_COMMA, TH_DOT,  KC_X

/*
  === THUMB KEYS ===
*/

#ifndef KB_LAYOUT_STANDARD
#   define DEFAULT_BASE  BASE_ROW(SPLT_LLFT, SPLT_LMID, SPLT_LRGT,   OSM(MOD_LCMD), SPACE_KEY, SPLT_RRGT)
#   define FALLBACK_BASE BASE_ROW(SPLT_LLFT, SPLT_LMID, SPLT_LRGT,   SPACE_KEY,     LK_DEF, SPLT_RRGT)
#   define SYMBOL_BASE   BASE_ROW(SPLT_LLFT, SPLT_LMID, SPLT_LRGT,   SPACE_KEY,     LK_DEF, TH_LK_SYM)
#   define EXTEND_BASE   BASE_ROW(LK_DEF,    SPLT_LMID, SPLT_LRGT,   SPACE_KEY,     LK_DEF, SPLT_RRGT)
#endif

/*
  === COMMON LAYERS ===
*/

#define EXT_L1 KC_TAB, OSM(MOD_LCTL), _x_,           _x_,           _x_
#define EXT_L2 TH_ESC, OSM(MOD_LALT), OSM(MOD_LCMD), OSM(MOD_LSFT), S_CLIPBOARD
#define EXT_L3 S_UNDO, S_CUT,         S_COPY,        S_PASTE,       S_SNIPPETS

#define EXT_R1 _x_, LK_ADJ,  KC_UP,   LK_VSC,   TH_BKSP
#define EXT_R2 _x_, TH_LEFT, KC_DOWN, TH_RIGHT, TH_ENTER
#define EXT_R3 _x_, LK_SWT,  _x_,     S_ALFRED, _x_

#define EXT_BASE EXTEND_BASE


// SYM
#define SYM_L1 KC_PIPE, KC_CRRT, KC_DLR,  KC_AMPR, _x_
#define SYM_L2 TH_ESC,  TH_LCBR, TH_LPRN, TH_LBRC, TH_TILD
#define SYM_L3 KC_BSLS, KC_PERC, _x_,     KC_COLN, _x_

#define SYM_R1 _x_,    KC_HASH, KC_PLUS, KC_SCLN, TH_BKSP
#define SYM_R2 KC_GRV, TH_EQLS, TH_MINS, TH_SLSH, TH_ENTER
#define SYM_R3 KC_AT,  KC_UNDS, KC_ASTR, TH_LABK, TH_QUOT

#define SYM_BASE SYMBOL_BASE


// NUM
#define NUM_L1 SYM_L1
#define NUM_L2 SYM_L2
#define NUM_L3 KC_4, KC_3, KC_2, KC_1, KC_5

#define NUM_R1 SYM_R1
#define NUM_R2 SYM_R2
#define NUM_R3 KC_6, KC_0, KC_7, KC_8, KC_9

#define NUM_BASE SYMBOL_BASE


/*
  === COMMANDS ===
*/
// VSCODE
#define VSCODE_L1 VSC_SB_DEBUG, VSC_BACK,      VSC_FWRD,     _x_,           _x_
#define VSCODE_L2 VSC_DBG_BRKP, VSC_DBG_OVR,   VSC_DBG_RUN,  VSC_RENAME,    _x_
#define VSCODE_L3 _x_,          VSC_DBG_IN,           _x_,   VSC_SEL_EXPND, _x_

#define VSCODE_R1 _x_,     VSC_FCS_G_PREV,    VSC_TOGL_VRT_HRZ, VSC_FCS_G_NEXT,    _x_
#define VSCODE_R2 _x_,     VSC_MV_EDTR_LFT,   VSC_EDTR_SPLT,    VSC_MV_EDTR_RGT,   _x_
#define VSCODE_R3 _x_,     VSC_MV_EDTR_G_LFT, _x_,              VSC_MV_EDTR_G_RGT, _x_

#define VSCODE_BASE FALLBACK_BASE

/*
  === APPS/WINDOW MANAGEMENT ===
*/

#define DESKTOP_L1 _x_,  _x_,          WNDW_LAYER_9, _x_,          _x_
#define DESKTOP_L2 _x_,  WNDW_LAYER_6, WNDW_LAYER_3, WNDW_LAYER_H, _x_
#define DESKTOP_L3 _x_,  _x_,          _x_,          WNDW_LAYER_Q, _x_

#define DESKTOP_R1 APPS_DESK_R1
#define DESKTOP_R2 APPS_DESK_R2
#define DESKTOP_R3 APPS_DESK_R3

#define DESKTOP_BASE FALLBACK_BASE

// APPS/DESKTOPS
#define APPS_DESK_R1 _x_,     OSX_DESK_PREV, OSX_MC_DESKS, OSX_DESK_RIGHT, _x_
#define APPS_DESK_R2 _x_,     OSX_APP_PREV,  OSX_APP_WNDW, OSX_APP_NEXT,   _x_
#define APPS_DESK_R3 _x_,     _x_,           OSX_MC_APPS,  _x_,            _x_
// HALF TILING
#define WNDW_HALF_R1 _x_,     _x_,     WM_H_U, _x_,        _x_
#define WNDW_HALF_R2 _x_,     WM_H_L,  WM_H_M, WM_H_R,     WM_FULL
#define WNDW_HALF_R3 _x_,     _x_,     WM_H_D, _x_,        _x_
// QUAD TILING
#define WNDW_QUAD_R1 _x_,     WM_4Q_UL, _x_,     WM_4Q_UR, _x_
#define WNDW_QUAD_R2 _x_,     _x_,      _x_,     _x_,      _x_
#define WNDW_QUAD_R3 _x_,     WM_4Q_LL, _x_,     WM_4Q_LR, _x_
// VERTICAL FOURTH TILING
#define WNDW_VERT_R1 _x_,     _x_,      _x_,     _x_,      _x_
#define WNDW_VERT_R2 _x_,     WM_4V_L,  _x_,     WM_4V_R,  _x_
#define WNDW_VERT_R3 _x_,     WM_4V_LC, _x_,     WM_4V_RC, _x_
// THRID TILING
#define WNDW_THRD_R1 _x_,     WM_3_LL, _x_,     WM_3_RR,   _x_
#define WNDW_THRD_R2 _x_,     WM_3_L,  WM_3_M,  WM_3_R,    _x_
#define WNDW_THRD_R3 _x_,     _x_,     _x_,     _x_,       _x_
// SIXTH TILING
#define WNDW_SIXT_R1 _x_,     WM_6_UL, WM_6_UM, WM_6_UR,   _x_
#define WNDW_SIXT_R2 _x_,     _x_,     _x_,     _x_,       _x_
#define WNDW_SIXT_R3 _x_,     WM_6_LL, WM_6_LM, WM_6_LR,   _x_
// NINTH TILING
#define WNDW_NINT_R1 _x_,     WM_9_TL, WM_9_TC, WM_9_TR,   _x_
#define WNDW_NINT_R2 _x_,     WM_9_ML, WM_9_MC, WM_9_MR,   _x_
#define WNDW_NINT_R3 _x_,     WM_9_BL, WM_9_BC, WM_9_BR,   _x_

/*
  === ADJUST ===
*/

#define ADJUST_L1 RESET,  DEBUG,     _x_,     _x_,   _x_
#define ADJUST_L2 LK_DEF, KC_MPRV, KC_MNXT, KC_MPLY, _x_
#define ADJUST_L3 _x_,    _x_,     _x_,     KC_MSTP, _x_

#define ADJUST_R1 KC_QWERTY,     _x_,     _x_,           _x_,     _x_
#define ADJUST_R2 KC_COLEMAK_DH, KC_MUTE, KC_VOLD,       KC_VOLU, KC_LED_INC_BRGT
#define ADJUST_R3 KC_ISRT,       RGB_TOG, KC_LAYERCOLOR, RGB_MOD, KC_LED_DCR_BRGT

#define ADJUST_BASE FALLBACK_BASE
