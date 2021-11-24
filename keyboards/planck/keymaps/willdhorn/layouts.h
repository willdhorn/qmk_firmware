#pragma once

#include <stdint.h>


enum default_layers { _COLEMAK, _QWERTY, _DEFAULT_RANGE_ };

enum planck_layers {
    _SYMBOLS  = _DEFAULT_RANGE_,
    _NAV,
    _NUM,
    _VSCODE,
    _APPS_WNDW,
    _WNDW_HALF,
    _WNDW_QUAD,
    _WNDW_VERT,
    _WNDW_THRD,
    _WNDW_SIXT,
    _ADJUST,
    _MAX_LAYER_
};

// define home mods arrangement
#define ML1(kc) LCTL_T(kc)
#define ML2(kc) LALT_T(kc)
#define ML3(kc) LSFT_T(kc)
#define ML4(kc) LGUI_T(kc)
#define MR4(kc) RGUI_T(kc)
#define MR3(kc) RSFT_T(kc)
#define MR2(kc) RALT_T(kc)
#define MR1(kc) RCTL_T(kc)

#define MOD_LEFT(l1, l2, l3, l4, l5)  ML1(l1), ML2(l2), ML3(l3), ML4(l4), l5
#define MOD_RIGHT(r5, r4, r3, r2, r1) r5, MR4(r4), MR3(r3), MR2(r2), MR1(r1)
#define EMPTY_MOD_L MOD_LEFT(_______,_______,_______,_______,_______)
#define EMPTY_MOD_R MOD_RIGHT(_______,_______,_______,_______,_______)

/*
  === LAYOUT ===
*/
#define PLANCK_LAYOUT(...) LAYOUT_planck_mit(__VA_ARGS__)

#define EMPTY_ROW _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define EMPTY_HALF _______, _______, _______, _______, _______

// STANDARD LAYOUT

// from left to right on base row
#define STD_LK_LEFT MO(_ADJUST)
#define STD_LK_LOWR MO(_SYMBOLS)
#define STD_LK_RAIS MO(_NAV)
#define STD_LK_RGHT MO(_NUM)

#define STD_DEFAULT_TOP(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1)    KC_DEL, l1, l2, l3, l4, l5, r5, r4, r3, r2, r1, KC_BSPACE
#define STD_DEFAULT_HOME(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1)   KC_TAB, l1, l2, l3, l4, l5, r5, r4, r3, r2, r1, KC_ENT
#define STD_DEFAULT_BOTTOM(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1) KC_ESC, l1, l2, l3, l4, l5, r5, r4, r3, r2, r1, KC_CAPSLOCK
#define STD_BASE(L1, L2, R2, R1) L1, L2, _______, STD_LK_LEFT, STD_LK_LOWR, KC_SPACE, STD_LK_RAIS, STD_LK_RGHT, _______, R2, R1

#define STD_ROW(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1) _______, l1, l2, l3, l4, l5, r5, r4, r3, r2, r1, _______

#define STD_DEFAULT_HOME_MOD(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1) STD_DEFAULT_HOME(ML1(l1), ML2(l2), ML3(l3), ML4(l4), l5, r5, MR4(r4), MR3(r3), MR2(r2), MR1(r1))
#define STD_HOME_MOD(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1) STD_ROW(ML1(l1), ML2(l2), ML3(l3), ML4(l4), l5, r5, MR4(r4), MR3(r3), MR2(r2), MR1(r1))

#define EMPTY_STD_BASE STD_BASE(_______, _______, _______, _______)

// SPLIT LAYOUT - WITH 3 LAYERKEYS

#define SPLT_KL1 LT(_APPS_WNDW, KC_ESC)
#define SPLT_KL2 LT(_SYMBOLS, KC_ENTER)
#define SPLT_KL3 LT(_VSCODE, KC_DEL)
#define SPLT_KR3 LT(_NUM, KC_BSPACE)
#define SPLT_KR2 LT(_NAV, KC_SPACE)
#define SPLT_KR1 LT(_ADJUST, KC_TAB)

#define SPLIT_ROW_DEFAULT(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1) l1, l2, l3, l4, l5, XXXXXXX, XXXXXXX, r5, r4, r3, r2, r1
#define SPLIT_ROW(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1) l1, l2, l3, l4, l5, _______, _______, r5, r4, r3, r2, r1
#define SPLIT_BASE_5(l1, l2, space, r2, r1) l1, l2, SPLT_KL1, SPLT_KL2, SPLT_KL3, space, SPLT_KR3, SPLT_KR2, SPLT_KR1, r2, r1
#define SPLIT_BASE_4(l1, l2, r2, r1) SPLIT_BASE_5(l1, l2, XXXXXXX, r2, r1)

#define SPLIT_HOME_MOD_DEFAULT(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1) MOD_LEFT(l1,l2,l3,l4,l5), XXXXXXX, XXXXXXX, MOD_RIGHT(r5,r4,r3,r2,r1)
#define SPLIT_HOME_MOD(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1) MOD_LEFT(l1,l2,l3,l4,l5), _______, _______, MOD_RIGHT(r5,r4,r3,r2,r1)

// #define KB_LAYOUT_STANDARD 1
#define KB_LAYOUT_SPLIT 1

#ifdef KB_LAYOUT_STANDARD
#   define DEF_TOP(...)  STD_DEFAULT_TOP(__VA_ARGS__)
#   define DEF_MID(...)  STD_DEFAULT_HOME_MOD(__VA_ARGS__)
#   define DEF_BOT(...)  STD_DEFAULT_TOP(__VA_ARGS__)
#   define BASE_ROW(...) STD_BASE(__VA_ARGS__)

#   define ROW(...)      STD_ROW(__VA_ARGS__)
#   define MOD_ROW(...)  STD_HOME_MOD(__VA_ARGS__)

#   define EMPTY_BASE     EMPTY_STD_BASE

#elif KB_LAYOUT_SPLIT
#   define DEF_TOP(...)  SPLIT_ROW_DEFAULT(__VA_ARGS__)
#   define DEF_MID(...)  SPLIT_HOME_MOD_DEFAULT(__VA_ARGS__)
#   define DEF_BOT(...)  SPLIT_ROW_DEFAULT(__VA_ARGS__)
#   define BASE_ROW(...) SPLIT_BASE_4(__VA_ARGS__)

#   define ROW(...)      SPLIT_ROW(__VA_ARGS__)
#   define MOD_ROW(...)  SPLIT_HOME_MOD(__VA_ARGS__)

#   define EMPTY_BASE    SPLIT_BASE_4(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)

#endif

/*
  === BEGIN LAYOUTS  ===
*/

//  QWERTY

#define QWERTY_1 DEF_TOP(QWERTY_L1, QWERTY_R1)
#define QWERTY_2 DEF_MID(QWERTY_L2, QWERTY_R2)
#define QWERTY_3 DEF_BOT(QWERTY_L3, QWERTY_R3)
#define QWERTY_4 EMPTY_BASE

#define LAYER_QWERTY PLANCK_LAYOUT(QWERTY_1, QWERTY_2, QWERTY_3, QWERTY_4)

//  COLEMAK DH MOD

#define COLEMAK_1 DEF_TOP(COLEMAK_L1, COLEMAK_R1)
#define COLEMAK_2 DEF_MID(COLEMAK_L2, COLEMAK_R2)
#define COLEMAK_3 DEF_BOT(COLEMAK_L3, COLEMAK_R3)
#define COLEMAK_4 EMPTY_BASE

#define LAYER_COLEMAK PLANCK_LAYOUT(COLEMAK_1, COLEMAK_2, COLEMAK_3, COLEMAK_4)

//  SYMBOLS

#define SYMBOLS_1 ROW(SYMBOLS_L1, SYMBOLS_R1)
#define SYMBOLS_2 ROW(SYMBOLS_L2, SYMBOLS_R2)
#define SYMBOLS_3 ROW(SYMBOLS_L3, SYMBOLS_R3)
#define SYMBOLS_4 EMPTY_BASE

#define LAYER_SYMBOLS PLANCK_LAYOUT(SYMBOLS_1, SYMBOLS_2, SYMBOLS_3, SYMBOLS_4)

// NAV

#define NAV_1 ROW(NAV_CMD1,  NAV_R1)
#define NAV_2 ROW(NAV_CMD2_, NAV_R2)
#define NAV_3 ROW(NAV_CMD3,  NAV_R3)
#define NAV_4 EMPTY_BASE

#define LAYER_NAV PLANCK_LAYOUT(NAV_1, NAV_2, NAV_3, NAV_4)

// NUM

#define NUM_1 ROW(    NUM_CMD1, NUM_R1)
#define NUM_2 MOD_ROW(NUM_CMD2, NUM_R2)
#define NUM_3 ROW(    NUM_CMD3, NUM_R3)
#define NUM_4 EMPTY_BASE

#define LAYER_NUM PLANCK_LAYOUT(NUM_1, NUM_2, NUM_3, NUM_4)

// VSCODE

#define VSCODE_1 ROW(VSCODE_L1, VSCODE_R1)
#define VSCODE_2 ROW(VSCODE_L2, VSCODE_R2)
#define VSCODE_3 ROW(VSCODE_L3, VSCODE_R3)
#define VSCODE_4 EMPTY_BASE

#define LAYER_VSCODE PLANCK_LAYOUT(VSCODE_1, VSCODE_2, VSCODE_3, VSCODE_4)

// APPS/WINDOWS - App switching and window arrangement

#define APPS_WNDW_1 ROW(APPS_WNDW_L1, APPS_WNDW_R1)
#define APPS_WNDW_2 ROW(APPS_WNDW_L2, APPS_WNDW_R2)
#define APPS_WNDW_3 ROW(APPS_WNDW_L3, APPS_WNDW_R3)
#define APPS_WNDW_4 EMPTY_BASE

#define LAYER_APPS_WNDW PLANCK_LAYOUT(APPS_WNDW_1, APPS_WNDW_2, APPS_WNDW_3, APPS_WNDW_4)

#define WNDW_HALF_1 ROW(EMPTY_HALF, WNDW_HALF_R1)
#define WNDW_HALF_2 ROW(EMPTY_HALF, WNDW_HALF_R2)
#define WNDW_HALF_3 ROW(EMPTY_HALF, WNDW_HALF_R3)
#define WNDW_HALF_4 EMPTY_BASE

#define WNDW_QUAD_1 ROW(EMPTY_HALF, WNDW_QUAD_R1)
#define WNDW_QUAD_2 ROW(EMPTY_HALF, WNDW_QUAD_R2)
#define WNDW_QUAD_3 ROW(EMPTY_HALF, WNDW_QUAD_R3)
#define WNDW_QUAD_4 EMPTY_BASE

#define WNDW_VERT_1 ROW(EMPTY_HALF, WNDW_VERT_R1)
#define WNDW_VERT_2 ROW(EMPTY_HALF, WNDW_VERT_R2)
#define WNDW_VERT_3 ROW(EMPTY_HALF, WNDW_VERT_R3)
#define WNDW_VERT_4 EMPTY_BASE

#define WNDW_THRD_1 ROW(EMPTY_HALF, WNDW_THRD_R1)
#define WNDW_THRD_2 ROW(EMPTY_HALF, WNDW_THRD_R2)
#define WNDW_THRD_3 ROW(EMPTY_HALF, WNDW_THRD_R3)
#define WNDW_THRD_4 EMPTY_BASE

#define WNDW_SIXT_1 ROW(EMPTY_HALF, WNDW_SIXT_R1)
#define WNDW_SIXT_2 ROW(EMPTY_HALF, WNDW_SIXT_R2)
#define WNDW_SIXT_3 ROW(EMPTY_HALF, WNDW_SIXT_R3)
#define WNDW_SIXT_4 EMPTY_BASE

#define LAYER_WNDW_HALF PLANCK_LAYOUT(WNDW_HALF_1, WNDW_HALF_2, WNDW_HALF_3, WNDW_HALF_4)
#define LAYER_WNDW_QUAD PLANCK_LAYOUT(WNDW_QUAD_1, WNDW_QUAD_2, WNDW_QUAD_3, WNDW_QUAD_4)
#define LAYER_WNDW_VERT PLANCK_LAYOUT(WNDW_VERT_1, WNDW_VERT_2, WNDW_VERT_3, WNDW_VERT_4)
#define LAYER_WNDW_THRD PLANCK_LAYOUT(WNDW_THRD_1, WNDW_THRD_2, WNDW_THRD_3, WNDW_THRD_4)
#define LAYER_WNDW_SIXT PLANCK_LAYOUT(WNDW_SIXT_1, WNDW_SIXT_2, WNDW_SIXT_3, WNDW_SIXT_4)

// ADJUST
#define ADJUST_1 ROW(ADJUST_L1, ADJUST_R1)
#define ADJUST_2 ROW(ADJUST_L2, ADJUST_R2)
#define ADJUST_3 ROW(ADJUST_L3, ADJUST_R3)
#define ADJUST_4 BASE_ROW(ADJUST_LB, ADJUST_RB)

#define LAYER_ADJUST PLANCK_LAYOUT(ADJUST_1, ADJUST_2, ADJUST_3, ADJUST_4)

void two_tap(uint16_t kc1, uint16_t kc2);
// Function for handling vscode short cut sequences
void vscode_chord(uint16_t kc);