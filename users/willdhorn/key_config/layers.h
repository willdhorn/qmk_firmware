#pragma once

#include "willdhorn.h"

// clang-format off
enum default_layers {
    _QWERTY,
    _COLEMAK_DH,
    _ISRT,
    _DEFAULT_RANGE_ };

enum user_layers {
    _EXT = _DEFAULT_RANGE_,
    _SYM,
    _NUM,
    _NAV,
    _CONFIG,
    _VSCODE,
    _DESKTOP,
    _WNDW_HALF,
    _WNDW_THRD,
    _WNDW_QUAD,
    _WNDW_SIXT,
    _WNDW_NINT,
    // _WNDW_VERT,
    _MAX_LAYER_
};

// THUMB KEYS
#define LTHMB_L lk_Nav
#define LTHMB_M kSpace
#define LTHMB_R lk_Symbol
#define RTHMB_L lk_Default
#define RTHMB_M kSpace
#define RTHMB_R kBackspace

#define DEFAULT_THUMB  THUMB_KEYS(LTHMB_L, LTHMB_M, LTHMB_R, RTHMB_L, RTHMB_M, RTHMB_R)
#define SYMBOL_THUMB   THUMB_KEYS(LTHMB_L, LTHMB_M, LTHMB_R, RTHMB_L, KC_UNDS, RTHMB_R)
#define NUMBER_THUMB   THUMB_KEYS(LTHMB_L, LTHMB_M, LTHMB_R, RTHMB_L, TH(thNum_Dot), RTHMB_R)

/*
  === STANDARD LAYERS ===
*/

#define NAV_L1 ___,    kAltLeft, KC_UP,   kAltRight,   ___
#define NAV_L2 kTab,   kLeft,    KC_DOWN, kRight,      ___
#define NAV_L3 S_UNDO, S_CUT,    S_COPY,  TH(thPaste), ___

#define NAV_R1 ___, ___, ___, ___, ___
#define NAV_R2 ___, ___, ___, ___, kEnter
#define NAV_R3 ___, ___, ___, ___, ___

#define NAV_THUMB DEFAULT_THUMB

// SYM
#define SYM_L1 KC_AT,  KC_TILD, KC_ASTR, ___,     ___
#define SYM_L2 lk_Num, KC_SLSH, KC_MINS, KC_PLUS, ___
#define SYM_L3 ___,    KC_PIPE, KC_AMPR, KC_UNDS, ___

#define SYM_R1 ___, KC_HASH, KC_LBRC, KC_RBRC, ___
#define SYM_R2 ___, KC_EQL,  KC_LPRN, KC_RPRN, kEnter
#define SYM_R3 ___, KC_BSLS, ___, ___, ___

#define SYM_THUMB SYMBOL_THUMB

// NUM
#define NUM_L1 ___, ___, ___, ___, ___
#define NUM_L2 ___, ___, ___, ___, ___
#define NUM_L3 ___, ___, ___, ___, ___

#define NUM_R1 ___, KC_7, KC_8, KC_9, ___
#define NUM_R2 ___, KC_4, KC_5, KC_6, KC_0
#define NUM_R3 ___, KC_1, KC_2, KC_3, ___

#define NUM_THUMB NUMBER_THUMB

// CONFIG
#define CONFIG_L1 RESET,  DEBUG,   _x_,     _x_,     _x_
#define CONFIG_L2 LK_DEF, KC_MPRV, KC_MNXT, KC_MPLY, _x_
#define CONFIG_L3 _x_,    _x_,     _x_,     KC_MSTP, _x_

#define CONFIG_R1 KC_QWERTY, _x_, _x_, _x_, _x_
#define CONFIG_R2 KC_COLEMAK_DH, KC_MUTE, KC_VOLD, KC_VOLU, KC_LED_INC_BRGT
#define CONFIG_R3 KC_ISRT, RGB_TOG, KC_LAYERCOLOR, RGB_MOD, KC_LED_DCR_BRGT

#define CONFIG_THUMB DEFAULT_THUMB

/*
  === ACTIONS ===
*/
// VSCODE
#define VSCODE_L1 VSC_SB_DEBUG, VSC_BACK, VSC_FWRD, _x_, _x_
#define VSCODE_L2 VSC_DBG_BRKP, VSC_DBG_OVR, VSC_DBG_RUN, VSC_RENAME, _x_
#define VSCODE_L3 _x_, VSC_DBG_IN, _x_, VSC_SEL_EXPND, _x_

#define VSCODE_R1 _x_, VSC_FCS_G_PREV, VSC_TOGL_VRT_HRZ, VSC_FCS_G_NEXT, _x_
#define VSCODE_R2 _x_, VSC_MV_EDTR_LFT, VSC_EDTR_SPLT, VSC_MV_EDTR_RGT, _x_
#define VSCODE_R3 _x_, VSC_MV_EDTR_G_LFT, _x_, VSC_MV_EDTR_G_RGT, _x_

#define VSCODE_THUMB DEFAULT_THUMB

/*
  === APPS/WINDOW MANAGEMENT ===
*/

#define DESKTOP_L1 _x_, _x_, WNDW_LAYER_9, _x_, _x_
#define DESKTOP_L2 _x_, WNDW_LAYER_6, WNDW_LAYER_3, WNDW_LAYER_H, _x_
#define DESKTOP_L3 _x_, _x_, _x_, WNDW_LAYER_Q, _x_

#define DESKTOP_R1 APPS_DESK_R1
#define DESKTOP_R2 APPS_DESK_R2
#define DESKTOP_R3 APPS_DESK_R3

#define DESKTOP_THUMB DEFAULT_THUMB

// APPS/DESKTOPS
#define APPS_DESK_R1 _x_, OSX_DESK_PREV, OSX_MC_DESKS, OSX_DESK_RIGHT, _x_
#define APPS_DESK_R2 _x_, OSX_APP_PREV, OSX_APP_WNDW, OSX_APP_NEXT, _x_
#define APPS_DESK_R3 _x_, _x_, OSX_MC_APPS, _x_, _x_
// HALF TILING
#define WNDW_HALF_R1 _x_, _x_, WM_H_U, _x_, _x_
#define WNDW_HALF_R2 _x_, WM_H_L, WM_H_M, WM_H_R, WM_FULL
#define WNDW_HALF_R3 _x_, _x_, WM_H_D, _x_, _x_
// QUAD TILING
#define WNDW_QUAD_R1 _x_, WM_4Q_UL, _x_, WM_4Q_UR, _x_
#define WNDW_QUAD_R2 _x_, _x_, _x_, _x_, _x_
#define WNDW_QUAD_R3 _x_, WM_4Q_LL, _x_, WM_4Q_LR, _x_
// VERTICAL FOURTH TILING
#define WNDW_VERT_R1 _x_, _x_, _x_, _x_, _x_
#define WNDW_VERT_R2 _x_, WM_4V_L, _x_, WM_4V_R, _x_
#define WNDW_VERT_R3 _x_, WM_4V_LC, _x_, WM_4V_RC, _x_
// THRID TILING
#define WNDW_THRD_R1 _x_, WM_3_LL, _x_, WM_3_RR, _x_
#define WNDW_THRD_R2 _x_, WM_3_L, WM_3_M, WM_3_R, _x_
#define WNDW_THRD_R3 _x_, _x_, _x_, _x_, _x_
// SIXTH TILING
#define WNDW_SIXT_R1 _x_, WM_6_UL, WM_6_UM, WM_6_UR, _x_
#define WNDW_SIXT_R2 _x_, _x_, _x_, _x_, _x_
#define WNDW_SIXT_R3 _x_, WM_6_LL, WM_6_LM, WM_6_LR, _x_
// NINTH TILING
#define WNDW_NINT_R1 _x_, WM_9_TL, WM_9_TC, WM_9_TR, _x_
#define WNDW_NINT_R2 _x_, WM_9_ML, WM_9_MC, WM_9_MR, _x_
#define WNDW_NINT_R3 _x_, WM_9_BL, WM_9_BC, WM_9_BR, _x_

/*
  === DEFAULT LAYERS ===
*/

// QWERTY
#define QWERTY_L1 KC_Q, KC_W, KC_E, KC_R, KC_T
#define QWERTY_L2 KC_A, KC_S, KC_D, KC_F, KC_G
#define QWERTY_L3 LCTL_T(KC_Z), LALT_T(KC_X), LCMD_T(KC_C), KC_V, KC_B

#define QWERTY_R1 KC_Y, KC_U, KC_I, KC_O, KC_P
#define QWERTY_R2 KC_H, KC_J, KC_K, KC_L, KC_COLN
#define QWERTY_R3 KC_N, KC_M, kComma, kPeriod, kQuote

// COLEMAK-DH
#define COLEMAK_DH_L1 KC_Q, KC_W, KC_F, KC_P, KC_B
#define COLEMAK_DH_L2 KC_A, KC_R, KC_S, KC_T, KC_G
#define COLEMAK_DH_L3 LCTL_T(KC_Z), LALT_T(KC_X), LCMD_T(KC_C), KC_D, KC_V

#define COLEMAK_DH_R1 KC_J, KC_L, KC_U, KC_Y, KC_COLN
#define COLEMAK_DH_R2 KC_M, KC_N, KC_E, KC_I, KC_O
#define COLEMAK_DH_R3 KC_K, KC_H, kComma, kPeriod, kQuote

// ISRT
#define ISRT_L1 KC_Y, KC_C, KC_L, KC_M, KC_K
#define ISRT_L2 KC_I, KC_S, KC_R, KC_T, KC_G
#define ISRT_L3 LCTL_T(KC_Q), LALT_T(KC_V), LCMD_T(KC_W), KC_D, KC_J

#define ISRT_R1 KC_Z, KC_F, KC_U, kQuote, KC_COLN
#define ISRT_R2 KC_M, KC_N, KC_E, KC_A, KC_O
#define ISRT_R3 KC_B, KC_H, kComma, kPeriod, KC_X
