#pragma once

#include <stdint.h>
#include "config.h"

// define home mods arrangement
#define ML1(kc) kc
#define ML2(kc) kc
#define ML3(kc) kc // LCTL_T(kc)
#define ML4(kc) kc // LALT_T(kc)
#define MR4(kc) kc // RALT_T(kc)
#define MR3(kc) kc // RCTL_T(kc)
#define MR2(kc) kc
#define MR1(kc) kc

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

#ifdef KB_LAYOUT_STANDARD // STANDARD LAYOUT
#   define STD_DEFAULT_TOP(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1)    KC_EMPTY, l1, l2, l3, l4, l5, r5, r4, r3, r2, r1, KC_EMPTY
#   define STD_DEFAULT_HOME(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1)   KC_EMPTY, l1, l2, l3, l4, l5, r5, r4, r3, r2, r1, KC_EMPTY
#   define STD_DEFAULT_BOTTOM(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1) KC_EMPTY, l1, l2, l3, l4, l5, r5, r4, r3, r2, r1, KC_EMPTY
// #   define STD_DEFAULT_BASE(L1, L2, R2, R1) L1, L2, KC_EMPTY, STD_LK_LEFT, STD_LK_LOWR, STD_LK_SPCE, STD_LK_RAIS, STD_LK_RGHT, KC_EMPTY, R2, R1
#    define STD_BASE(L1, L2, R2, R1) KC_EMPTY, KC_EMPTY, KC_EMPTY, L1, L2, LK_SPACE_BAR, R2, R1, KC_EMPTY, KC_EMPTY, KC_EMPTY

#    define STD_ROW(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1) _______, l1, l2, l3, l4, l5, r5, r4, r3, r2, r1, _______

#    define STD_DEFAULT_HOME_MOD(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1) STD_DEFAULT_HOME(ML1(l1), ML2(l2), ML3(l3), ML4(l4), l5, r5, MR4(r4), MR3(r3), MR2(r2), MR1(r1))
#    define STD_DEFAULT_BOTTOM_MOD(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1) STD_DEFAULT_BOTTOM(ML1(l1), ML2(l2), ML3(l3), ML4(l4), l5, r5, MR4(r4), MR3(r3), MR2(r2), MR1(r1))
#    define STD_HOME_MOD(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1) STD_ROW(ML1(l1), ML2(l2), ML3(l3), ML4(l4), l5, r5, MR4(r4), MR3(r3), MR2(r2), MR1(r1))

#    define DEF_TOP(...) STD_DEFAULT_TOP(__VA_ARGS__)
#    define DEF_MID(...) STD_DEFAULT_HOME_MOD(__VA_ARGS__)
#    define DEF_BOT(...) STD_DEFAULT_BOTTOM(__VA_ARGS__)
#    define BASE_ROW(...) STD_BASE(__VA_ARGS__)

#    define ROW(...) STD_ROW(__VA_ARGS__)
#    define MOD_ROW(...) STD_HOME_MOD(__VA_ARGS__)

#    define EMPTY_BASE STD_BASE(KC_EMPTY, KC_EMPTY, KC_EMPTY, KC_EMPTY)

#else // SPLIT LAYOUT - WITH 3 LAYERKEYS
#   define SPLIT_ROW(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1) l1, l2, l3, l4, l5, KC_EMPTY, KC_EMPTY, r5, r4, r3, r2, r1
#   define SPLIT_BASE_6(l1, l2, l3, r3, r2, r1) KC_EMPTY, KC_EMPTY, l1, l2, l3, KC_EMPTY, r3, r2, r1, KC_EMPTY, KC_EMPTY

#    define SPLIT_HOME_MOD(l1, l2, l3, l4, l5, r5, r4, r3, r2, r1) ML1(l1), ML2(l2), ML3(l3), ML4(l4), l5, KC_EMPTY, KC_EMPTY, r5, MR4(r4), MR3(r3), MR2(r2), MR1(r1)

#    define DEF_TOP(...) SPLIT_ROW(__VA_ARGS__)
#    define DEF_MID(...) SPLIT_HOME_MOD(__VA_ARGS__)
#    define DEF_BOT(...) SPLIT_ROW(__VA_ARGS__)
#    define BASE_ROW(...) SPLIT_BASE_6(__VA_ARGS__)

#    define ROW(...) SPLIT_ROW(__VA_ARGS__)
#    define MOD_ROW(...) SPLIT_HOME_MOD(__VA_ARGS__)

#    define EMPTY_BASE SPLIT_BASE_6(KC_EMPTY, KC_EMPTY, KC_EMPTY, KC_EMPTY, KC_EMPTY, KC_EMPTY)

#endif

/*
  === BEGIN LAYOUTS  ===
*/

//  QWERTY

#define QWERTY_1 DEF_TOP(QWERTY_L1, QWERTY_R1)
#define QWERTY_2 DEF_MID(QWERTY_L2, QWERTY_R2)
#define QWERTY_3 DEF_BOT(QWERTY_L3, QWERTY_R3)
#define QWERTY_4 DEFAULT_BASE

#define LAYER_QWERTY PLANCK_LAYOUT(QWERTY_1, QWERTY_2, QWERTY_3, QWERTY_4)

//  COLEMAK DH

#define COLEMAK_DH_1 DEF_TOP(COLEMAK_DH_L1, COLEMAK_DH_R1)
#define COLEMAK_DH_2 DEF_MID(COLEMAK_DH_L2, COLEMAK_DH_R2)
#define COLEMAK_DH_3 DEF_BOT(COLEMAK_DH_L3, COLEMAK_DH_R3)
#define COLEMAK_DH_4 DEFAULT_BASE

#define LAYER_COLEMAK_DH PLANCK_LAYOUT(COLEMAK_DH_1, COLEMAK_DH_2, COLEMAK_DH_3, COLEMAK_DH_4)

//  ISRT

#define ISRT_1 DEF_TOP(ISRT_L1, ISRT_R1)
#define ISRT_2 DEF_MID(ISRT_L2, ISRT_R2)
#define ISRT_3 DEF_BOT(ISRT_L3, ISRT_R3)
#define ISRT_4 DEFAULT_BASE

#define LAYER_ISRT PLANCK_LAYOUT(ISRT_1, ISRT_2, ISRT_3, ISRT_4)

// EXT

#define EXT_1 ROW(EXT_L1, EXT_R1)
#define EXT_2 ROW(EXT_L2, EXT_R2)
#define EXT_3 ROW(EXT_L3, EXT_R3)
#define EXT_4 EXT_BASE

#define LAYER_EXT PLANCK_LAYOUT(EXT_1, EXT_2, EXT_3, EXT_4)

// SYM

#define SYM_1 ROW(SYM_L1, SYM_R1)
#define SYM_2 ROW(SYM_L2, SYM_R2)
#define SYM_3 ROW(SYM_L3, SYM_R3)
#define SYM_4 SYM_BASE


#define LAYER_SYM PLANCK_LAYOUT(SYM_1, SYM_2, SYM_3, SYM_4)

// NUM

#define NUM_1 ROW(NUM_L1, NUM_R1)
#define NUM_2 ROW(NUM_L2, NUM_R2)
#define NUM_3 ROW(NUM_L3, NUM_R3)
#define NUM_4 NUM_BASE

#define LAYER_NUM PLANCK_LAYOUT(NUM_1, NUM_2, NUM_3, NUM_4)

// VSCODE

#define VSCODE_1 ROW(VSCODE_L1, VSCODE_R1)
#define VSCODE_2 ROW(VSCODE_L2, VSCODE_R2)
#define VSCODE_3 ROW(VSCODE_L3, VSCODE_R3)
#define VSCODE_4 VSCODE_BASE

#define LAYER_VSCODE PLANCK_LAYOUT(VSCODE_1, VSCODE_2, VSCODE_3, VSCODE_4)

// APPS/WINDOWS - App switching and window arrangement

#define DESKTOP_1 ROW(DESKTOP_L1, DESKTOP_R1)
#define DESKTOP_2 ROW(DESKTOP_L2, DESKTOP_R2)
#define DESKTOP_3 ROW(DESKTOP_L3, DESKTOP_R3)
#define DESKTOP_4 DESKTOP_BASE

#define LAYER_DESKTOP PLANCK_LAYOUT(DESKTOP_1, DESKTOP_2, DESKTOP_3, DESKTOP_4)

#define WNDW_HALF_1 ROW(EMPTY_HALF, WNDW_HALF_R1)
#define WNDW_HALF_2 ROW(EMPTY_HALF, WNDW_HALF_R2)
#define WNDW_HALF_3 ROW(EMPTY_HALF, WNDW_HALF_R3)
#define WNDW_HALF_4 DESKTOP_BASE

#define WNDW_QUAD_1 ROW(EMPTY_HALF, WNDW_QUAD_R1)
#define WNDW_QUAD_2 ROW(EMPTY_HALF, WNDW_QUAD_R2)
#define WNDW_QUAD_3 ROW(EMPTY_HALF, WNDW_QUAD_R3)
#define WNDW_QUAD_4 DESKTOP_BASE

#define WNDW_VERT_1 ROW(EMPTY_HALF, WNDW_VERT_R1)
#define WNDW_VERT_2 ROW(EMPTY_HALF, WNDW_VERT_R2)
#define WNDW_VERT_3 ROW(EMPTY_HALF, WNDW_VERT_R3)
#define WNDW_VERT_4 DESKTOP_BASE

#define WNDW_THRD_1 ROW(EMPTY_HALF, WNDW_THRD_R1)
#define WNDW_THRD_2 ROW(EMPTY_HALF, WNDW_THRD_R2)
#define WNDW_THRD_3 ROW(EMPTY_HALF, WNDW_THRD_R3)
#define WNDW_THRD_4 DESKTOP_BASE

#define WNDW_SIXT_1 ROW(EMPTY_HALF, WNDW_SIXT_R1)
#define WNDW_SIXT_2 ROW(EMPTY_HALF, WNDW_SIXT_R2)
#define WNDW_SIXT_3 ROW(EMPTY_HALF, WNDW_SIXT_R3)
#define WNDW_SIXT_4 DESKTOP_BASE

#define WNDW_NINT_1 ROW(EMPTY_HALF, WNDW_NINT_R1)
#define WNDW_NINT_2 ROW(EMPTY_HALF, WNDW_NINT_R2)
#define WNDW_NINT_3 ROW(EMPTY_HALF, WNDW_NINT_R3)
#define WNDW_NINT_4 DESKTOP_BASE

#define LAYER_WNDW_HALF PLANCK_LAYOUT(WNDW_HALF_1, WNDW_HALF_2, WNDW_HALF_3, WNDW_HALF_4)
#define LAYER_WNDW_QUAD PLANCK_LAYOUT(WNDW_QUAD_1, WNDW_QUAD_2, WNDW_QUAD_3, WNDW_QUAD_4)
#define LAYER_WNDW_VERT PLANCK_LAYOUT(WNDW_VERT_1, WNDW_VERT_2, WNDW_VERT_3, WNDW_VERT_4)
#define LAYER_WNDW_THRD PLANCK_LAYOUT(WNDW_THRD_1, WNDW_THRD_2, WNDW_THRD_3, WNDW_THRD_4)
#define LAYER_WNDW_SIXT PLANCK_LAYOUT(WNDW_SIXT_1, WNDW_SIXT_2, WNDW_SIXT_3, WNDW_SIXT_4)
#define LAYER_WNDW_NINT PLANCK_LAYOUT(WNDW_NINT_1, WNDW_NINT_2, WNDW_NINT_3, WNDW_NINT_4)

// ADJUST
#define ADJUST_1 ROW(ADJUST_L1, ADJUST_R1)
#define ADJUST_2 ROW(ADJUST_L2, ADJUST_R2)
#define ADJUST_3 ROW(ADJUST_L3, ADJUST_R3)
#define ADJUST_4 ADJUST_BASE

#define LAYER_ADJUST PLANCK_LAYOUT(ADJUST_1, ADJUST_2, ADJUST_3, ADJUST_4)
