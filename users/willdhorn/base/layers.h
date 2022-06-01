#pragma once

#include "willdhorn.h"

// clang-format off
enum default_layers {
    _COLEMAK_DH,
#ifdef USE_LAYOUT_QWERTY
    _QWERTY,
#endif
#ifdef USE_LAYOUT_ISRT
    _ISRT,
#endif
    _DEFAULT_RANGE_ };
//quick fix for not having to add this flag everywhere
#ifndef USE_LAYOUT_QWERTY
  #define _QWERTY  0
#endif
#ifndef USE_LAYOUT_ISRT
  #define _ISRT 0
#endif

enum user_layers {
    _EXT = _DEFAULT_RANGE_,
    _SYM,
    _NUM,
    _CONFIG,
    _VSCODE,
    _DESKTOP,
  // TODO: Replace these layers with leader sequences to save bytes
    _WNDW_HALF,
    _WNDW_THRD,
    _WNDW_QUAD,
    _WNDW_SIXT,
    _WNDW_NINT,
    _MAX_LAYER_
};

// Layer key defines
#define lk_Default TO(0)
#define lk_Ext TO(_EXT) //TH(thExtDefault)
#define lk_Symbol TO(_SYM)
#define lk_Num TO(_NUM)
#define lk_Config TO(_CONFIG)
#define lk_Desktop TO(_DESKTOP)
// #define LKT_VSC TO(_VSCODE)

// THUMB KEYS
#define LTHMB_L lk_Num
#define LTHMB_M lk_Symbol
#define LTHMB_R kSpace
#define RTHMB_L OSM(MOD_LSFT)
#define RTHMB_M lk_Default
#define RTHMB_R lk_Ext

#define DEFAULT_THUMB  THUMB_KEYS(LTHMB_L, LTHMB_M, LTHMB_R, RTHMB_L, RTHMB_M, RTHMB_R)
#define SYMBOL_THUMB   THUMB_KEYS(LTHMB_L, LTHMB_M, LTHMB_R, RTHMB_L, RTHMB_M, RTHMB_R)
#define NUMBER_THUMB   THUMB_KEYS(LTHMB_L, LTHMB_M, LTHMB_R, TH(thNum_Dot), RTHMB_M, RTHMB_R)

/*
  === STANDARD LAYERS ===
*/

#define EXT_L1 ___, ___,     ___,      ___,     ___,         ___
#define EXT_L2 ___, ___,     ___,      ___,     ___,         S_SNIPPETS
#define EXT_L3 ___, S_UNDO,  S_CUT,    S_COPY,  TH(thPaste), ___

#define EXT_R1 ___, kAltLeft, KC_UP,   kAltRight, ___, ___
#define EXT_R2 ___, kLeft,    KC_DOWN, kRight,    ___, ___
#define EXT_R3 ___, ___, ___, ___, ___, ___

#define EXT_THUMB DEFAULT_THUMB

// SYM
#define SYM_L1 ___, ___,   KC_PIPE, KC_AMPR, KC_HASH, ___
#define SYM_L2 ___, KC_AT, KC_PERC, KC_ASTR, KC_PLUS, ___
#define SYM_L3 ___, ___,   ___,     ___,     KC_BSLS, ___

#define SYM_R1 ___, KC_TILD,        KC_LBRC, KC_RBRC, ___,     ___
#define SYM_R2 ___, TH(thkoEqual),  KC_LPRN, KC_RPRN, KC_COLN, ___
#define SYM_R3 ___, MCR_DIRUP,      ___,     ___,     ___,     ___

#define SYM_THUMB SYMBOL_THUMB

// NUM
#define NUM_L1 SYM_L1
#define NUM_L2 SYM_L2
#define NUM_L3 SYM_L3

#define NUM_R1 ___, KC_7, KC_8, KC_9, ___,  ___
#define NUM_R2 ___, KC_4, KC_5, KC_6, KC_0, ___
#define NUM_R3 ___, KC_1, KC_2, KC_3, ___,  ___

#define NUM_THUMB NUMBER_THUMB

// CONFIG
#define CONFIG_L1 ___, RESET,  DEBUG,   _x_,     _x_,     _x_
#define CONFIG_L2 ___, LK_DEF, KC_MPRV, KC_MNXT, KC_MPLY, _x_
#define CONFIG_L3 ___, _x_,    _x_,     _x_,     KC_MSTP, _x_

#define CONFIG_R1 KC_QWERTY, _x_, _x_, _x_, _x_, ___
#define CONFIG_R2 KC_COLEMAK_DH, KC_MUTE, KC_VOLD, KC_VOLU, KC_LED_INC_BRGT, ___
#define CONFIG_R3 KC_ISRT, RGB_TOG, KC_LAYERCOLOR, RGB_MOD, KC_LED_DCR_BRGT, ___

#define CONFIG_THUMB DEFAULT_THUMB

/*
  === ACTIONS ===
*/
// VSCODE
#define VSCODE_L1 ___, VSC_SB_DEBUG, VSC_BACK, VSC_FWRD, _x_, _x_
#define VSCODE_L2 ___, VSC_DBG_BRKP, VSC_DBG_OVR, VSC_DBG_RUN, VSC_RENAME, _x_
#define VSCODE_L3 ___, _x_, VSC_DBG_IN, _x_, VSC_SEL_EXPND, _x_

#define VSCODE_R1 _x_, VSC_FCS_G_PREV, VSC_TOGL_VRT_HRZ, VSC_FCS_G_NEXT, _x_, ___
#define VSCODE_R2 _x_, VSC_MV_EDTR_LFT, VSC_EDTR_SPLT, VSC_MV_EDTR_RGT, _x_, ___
#define VSCODE_R3 _x_, VSC_MV_EDTR_G_LFT, _x_, VSC_MV_EDTR_G_RGT, _x_, ___

#define VSCODE_THUMB DEFAULT_THUMB

/*
  === APPS/WINDOW MANAGEMENT ===
*/

#define DESKTOP_L1 ___, _x_, _x_, WNDW_LAYER_9, _x_, _x_
#define DESKTOP_L2 ___, _x_, WNDW_LAYER_6, WNDW_LAYER_3, WNDW_LAYER_H, _x_
#define DESKTOP_L3 ___, _x_, _x_, _x_, WNDW_LAYER_Q, _x_

#define DESKTOP_R1 APPS_DESK_R1
#define DESKTOP_R2 APPS_DESK_R2
#define DESKTOP_R3 APPS_DESK_R3

#define DESKTOP_THUMB DEFAULT_THUMB

// APPS/DESKTOPS
#define APPS_DESK_R1 _x_, OSX_DESK_PREV, OSX_MC_DESKS, OSX_DESK_RIGHT, _x_, ___
#define APPS_DESK_R2 _x_, OSX_APP_PREV, OSX_APP_WNDW, OSX_APP_NEXT, _x_, ___
#define APPS_DESK_R3 _x_, _x_, OSX_MC_APPS, _x_, _x_, ___
// HALF TILING
#define WNDW_HALF_R1 _x_, _x_, WM_H_U, _x_, _x_, ___
#define WNDW_HALF_R2 _x_, WM_H_L, WM_H_M, WM_H_R, WM_FULL, ___
#define WNDW_HALF_R3 _x_, _x_, WM_H_D, _x_, _x_, ___
// QUAD TILING
#define WNDW_QUAD_R1 _x_, WM_4Q_UL, _x_, WM_4Q_UR, _x_, ___
#define WNDW_QUAD_R2 _x_, _x_, _x_, _x_, _x_, ___
#define WNDW_QUAD_R3 _x_, WM_4Q_LL, _x_, WM_4Q_LR, _x_, ___
// VERTICAL FOURTH TILING
#define WNDW_VERT_R1 _x_, _x_, _x_, _x_, _x_, ___
#define WNDW_VERT_R2 _x_, WM_4V_L, _x_, WM_4V_R, _x_, ___
#define WNDW_VERT_R3 _x_, WM_4V_LC, _x_, WM_4V_RC, _x_, ___
// THRID TILING
#define WNDW_THRD_R1 _x_, WM_3_LL, _x_, WM_3_RR, _x_, ___
#define WNDW_THRD_R2 _x_, WM_3_L, WM_3_M, WM_3_R, _x_, ___
#define WNDW_THRD_R3 _x_, _x_, _x_, _x_, _x_, ___
// SIXTH TILING
#define WNDW_SIXT_R1 _x_, WM_6_UL, WM_6_UM, WM_6_UR, _x_, ___,
#define WNDW_SIXT_R2 _x_, _x_, _x_, _x_, _x_, ___,
#define WNDW_SIXT_R3 _x_, WM_6_LL, WM_6_LM, WM_6_LR, _x_, ___,
// NINTH TILING
#define WNDW_NINT_R1 _x_, WM_9_TL, WM_9_TC, WM_9_TR, _x_, ___
#define WNDW_NINT_R2 _x_, WM_9_ML, WM_9_MC, WM_9_MR, _x_, ___
#define WNDW_NINT_R3 _x_, WM_9_BL, WM_9_BC, WM_9_BR, _x_, ___

/*
  === DEFAULT LAYERS ===
*/

// COLEMAK-DH
#define COLEMAK_DH_L1 kTab,    KC_Q, KC_W, KC_F, KC_P, KC_B
#define COLEMAK_DH_L2 kEscape, KC_A, LCTL_T(KC_R), LALT_T(KC_S), LCMD_T(KC_T), KC_G
#define COLEMAK_DH_L3 ___,     KC_Z, KC_X, KC_C, KC_D, KC_V

#define COLEMAK_DH_R1 KC_J, KC_L,         KC_U,         KC_Y,         KC_MINS,  kBackspace
#define COLEMAK_DH_R2 KC_M, RCMD_T(KC_N), RALT_T(KC_E), RCTL_T(KC_I), KC_O,     kEnter
#define COLEMAK_DH_R3 KC_K, KC_H,         kComma,       kPeriod,      kQuote,   ___


// QWERTY
#define QWERTY_L1 ___, KC_Q, KC_W, KC_E, KC_R, KC_T
#define QWERTY_L2 ___, KC_A, KC_S, KC_D, KC_F, KC_G
#define QWERTY_L3 ___, LCTL_T(KC_Z), LALT_T(KC_X), LCMD_T(KC_C), KC_V, KC_B

#define QWERTY_R1 KC_Y, KC_U, KC_I, KC_O, KC_P, ___
#define QWERTY_R2 KC_H, KC_J, KC_K, KC_L, KC_COLN, ___
#define QWERTY_R3 KC_N, KC_M, kComma, kPeriod, kQuote, ___


// ISRT
#define ISRT_L1 ___, KC_Y, KC_C, KC_L, KC_M, KC_K
#define ISRT_L2 ___, KC_I, KC_S, KC_R, KC_T, KC_G
#define ISRT_L3 ___, LCTL_T(KC_Q), LALT_T(KC_V), LCMD_T(KC_W), KC_D, KC_J

#define ISRT_R1 KC_Z, KC_F, KC_U, kQuote, KC_COLN, ___
#define ISRT_R2 KC_M, KC_N, KC_E, KC_A, KC_O, ___
#define ISRT_R3 KC_B, KC_H, kComma, kPeriod, KC_X, ___
