#pragma once

#include "willdhorn.h"

/*
  === LAYOUT ===
*/

#undef LAYOUT
#define LAYOUT(...) LAYOUT_split_3x6_3(__VA_ARGS__)

#define EMPTY_ROW _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define EMPTY_HALF _______, _______, _______, _______, _______, _______

#define ROW_WRAPPER(l0, l1, l2, l3, l4, l5, r5, r4, r3, r2, r1, r0) l0, l1, l2, l3, l4, l5, r5, r4, r3, r2, r1, r0
#define THUMB_KEYS_WRAPPER(lNear, lCenter, lFar, rFar, rCenter, rNear) lNear, lCenter, lFar, rFar, rCenter, rNear

#define L5(l1, l2, l3, l4, l5) KC_EMPTY, l1, l2, l3, l4, l5
#define R5(r5, r4, r3, r2, r1) r5, r4, r3, r2, r1, KC_EMPTY

#define ROW(...) ROW_WRAPPER(__VA_ARGS__)
#define THUMB_KEYS(...) THUMB_KEYS_WRAPPER(__VA_ARGS__)

/*
  === BEGIN LAYOUTS  ===
*/

//  COLEMAK DH
#define COLEMAK_DH_1 ROW(COLEMAK_DH_L1, COLEMAK_DH_R1)
#define COLEMAK_DH_2 ROW(COLEMAK_DH_L2, COLEMAK_DH_R2)
#define COLEMAK_DH_3 ROW(COLEMAK_DH_L3, COLEMAK_DH_R3)
#define COLEMAK_DH_4 DEFAULT_THUMB

#define LAYER_COLEMAK_DH LAYOUT(COLEMAK_DH_1, COLEMAK_DH_2, COLEMAK_DH_3, COLEMAK_DH_4)

#ifdef USE_LAYOUT_QWERTY
//  QWERTY
#  define QWERTY_1 ROW(QWERTY_L1, QWERTY_R1)
#  define QWERTY_2 ROW(QWERTY_L2, QWERTY_R2)
#  define QWERTY_3 ROW(QWERTY_L3, QWERTY_R3)
#  define QWERTY_4 DEFAULT_THUMB

#  define LAYER_QWERTY LAYOUT(QWERTY_1, QWERTY_2, QWERTY_3, QWERTY_4)
#endif

#ifdef USE_LAYOUT_ISRT
//  ISRT
#  define ISRT_1 ROW(ISRT_L1, ISRT_R1)
#  define ISRT_2 ROW(ISRT_L2, ISRT_R2)
#  define ISRT_3 ROW(ISRT_L3, ISRT_R3)
#  define ISRT_4 DEFAULT_THUMB

#  define LAYER_ISRT LAYOUT(ISRT_1, ISRT_2, ISRT_3, ISRT_4)
#endif

// EXT
#define EXT_1 ROW(EXT_L1, EXT_R1)
#define EXT_2 ROW(EXT_L2, EXT_R2)
#define EXT_3 ROW(EXT_L3, EXT_R3)
#define EXT_4 EXT_THUMB

#define LAYER_EXT LAYOUT(EXT_1, EXT_2, EXT_3, EXT_4)

// SYM
#define SYM_1 ROW(SYM_L1, SYM_R1)
#define SYM_2 ROW(SYM_L2, SYM_R2)
#define SYM_3 ROW(SYM_L3, SYM_R3)
#define SYM_4 SYM_THUMB

#define LAYER_SYM LAYOUT(SYM_1, SYM_2, SYM_3, SYM_4)

// NUM
#define NUM_1 ROW(NUM_L1, NUM_R1)
#define NUM_2 ROW(NUM_L2, NUM_R2)
#define NUM_3 ROW(NUM_L3, NUM_R3)
#define NUM_4 NUM_THUMB

#define LAYER_NUM LAYOUT(NUM_1, NUM_2, NUM_3, NUM_4)

// CONFIG
#define CONFIG_1 ROW(CONFIG_L1, CONFIG_R1)
#define CONFIG_2 ROW(CONFIG_L2, CONFIG_R2)
#define CONFIG_3 ROW(CONFIG_L3, CONFIG_R3)
#define CONFIG_4 CONFIG_THUMB

#define LAYER_CONFIG LAYOUT(CONFIG_1, CONFIG_2, CONFIG_3, CONFIG_4)

// VSCODE
#define VSCODE_1 ROW(VSCODE_L1, VSCODE_R1)
#define VSCODE_2 ROW(VSCODE_L2, VSCODE_R2)
#define VSCODE_3 ROW(VSCODE_L3, VSCODE_R3)
#define VSCODE_4 VSCODE_THUMB

#define LAYER_VSCODE LAYOUT(VSCODE_1, VSCODE_2, VSCODE_3, VSCODE_4)

// APPS/WINDOWS - App switching and window arrangement
#define DESKTOP_1 ROW(DESKTOP_L1, DESKTOP_R1)
#define DESKTOP_2 ROW(DESKTOP_L2, DESKTOP_R2)
#define DESKTOP_3 ROW(DESKTOP_L3, DESKTOP_R3)
#define DESKTOP_4 DESKTOP_THUMB

#define LAYER_DESKTOP LAYOUT(DESKTOP_1, DESKTOP_2, DESKTOP_3, DESKTOP_4)

#define WNDW_HALF_1 ROW(EMPTY_HALF, WNDW_HALF_R1)
#define WNDW_HALF_2 ROW(EMPTY_HALF, WNDW_HALF_R2)
#define WNDW_HALF_3 ROW(EMPTY_HALF, WNDW_HALF_R3)
#define WNDW_HALF_4 DESKTOP_THUMB

#define WNDW_QUAD_1 ROW(EMPTY_HALF, WNDW_QUAD_R1)
#define WNDW_QUAD_2 ROW(EMPTY_HALF, WNDW_QUAD_R2)
#define WNDW_QUAD_3 ROW(EMPTY_HALF, WNDW_QUAD_R3)
#define WNDW_QUAD_4 DESKTOP_THUMB

#define WNDW_VERT_1 ROW(EMPTY_HALF, WNDW_VERT_R1)
#define WNDW_VERT_2 ROW(EMPTY_HALF, WNDW_VERT_R2)
#define WNDW_VERT_3 ROW(EMPTY_HALF, WNDW_VERT_R3)
#define WNDW_VERT_4 DESKTOP_THUMB

#define WNDW_THRD_1 ROW(EMPTY_HALF, WNDW_THRD_R1)
#define WNDW_THRD_2 ROW(EMPTY_HALF, WNDW_THRD_R2)
#define WNDW_THRD_3 ROW(EMPTY_HALF, WNDW_THRD_R3)
#define WNDW_THRD_4 DESKTOP_THUMB

#define WNDW_SIXT_1 ROW(EMPTY_HALF, WNDW_SIXT_R1)
#define WNDW_SIXT_2 ROW(EMPTY_HALF, WNDW_SIXT_R2)
#define WNDW_SIXT_3 ROW(EMPTY_HALF, WNDW_SIXT_R3)
#define WNDW_SIXT_4 DESKTOP_THUMB

#define WNDW_NINT_1 ROW(EMPTY_HALF, WNDW_NINT_R1)
#define WNDW_NINT_2 ROW(EMPTY_HALF, WNDW_NINT_R2)
#define WNDW_NINT_3 ROW(EMPTY_HALF, WNDW_NINT_R3)
#define WNDW_NINT_4 DESKTOP_THUMB

#define LAYER_WNDW_HALF LAYOUT(WNDW_HALF_1, WNDW_HALF_2, WNDW_HALF_3, WNDW_HALF_4)
#define LAYER_WNDW_QUAD LAYOUT(WNDW_QUAD_1, WNDW_QUAD_2, WNDW_QUAD_3, WNDW_QUAD_4)
#define LAYER_WNDW_VERT LAYOUT(WNDW_VERT_1, WNDW_VERT_2, WNDW_VERT_3, WNDW_VERT_4)
#define LAYER_WNDW_THRD LAYOUT(WNDW_THRD_1, WNDW_THRD_2, WNDW_THRD_3, WNDW_THRD_4)
#define LAYER_WNDW_SIXT LAYOUT(WNDW_SIXT_1, WNDW_SIXT_2, WNDW_SIXT_3, WNDW_SIXT_4)
#define LAYER_WNDW_NINT LAYOUT(WNDW_NINT_1, WNDW_NINT_2, WNDW_NINT_3, WNDW_NINT_4)
