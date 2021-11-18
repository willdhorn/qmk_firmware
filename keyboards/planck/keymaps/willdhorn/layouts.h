#pragma once

#include <stdint.h>

// MODIFIERS
#define SFT(kc) LSFT(kc)
#define ALT(KC) LALT(KC)
#define CTL(kc) LCTL(kc)
#define CMD(kc) LCMD(kc)
#define MOD_LCMD MOD_LGUI

// HOME MODS
#define MS(kc) MT(MOD_LSFT, kc)
#define MC(kc) MT(MOD_LCTL, kc)
#define MA(kc) MT(MOD_LALT, kc)
#define MG(kc) MT(MOD_LCMD, kc)
// MOD TAP
#define SFT_ESC MT(MOD_LSFT, KC_ESC)
#define SFT_ENT MT(MOD_RSFT, KC_ENT)
#define CTRL_CAPS MT(MOD_LCTL, KC_CAPSLOCK)
#define CMD_CAPS MT(MOD_LCMD, KC_CAPSLOCK)

// KEYCODES
// #define KC_SFT KC_LSFT
// #define KC_CTL KC_LCTL
// #define KC_ALT KC_LALT
// #define KC_CMD KC_LCMD
// Shortcut for Window Management (Rectangle)
#define WM(kc) LALT(LCTL(kc))

#define KC_DASH ALT(KC_MINUS)  // Em-dash
#define KC_CRRT KC_CIRC

#define KC_HOME CMD(KC_LEFT)
#define KC_END CMD(KC_RIGT)
#define KC_EMOJI LCTL(LCMD(KC_SPACE))

// SHORTCUTS
#define S_UNDO CMD(KC_Z)
#define S_CUT CMD(KC_X)
#define S_COPY CMD(KC_C)
#define S_PASTE CMD(KC_V)

#define S_TABL SFT(CMD(KC_LBRC))
#define S_TABR SFT(CMD(KC_RBRC))

// VISUAL STUDIO CODE
// MOVE CURSOR TO PREVIOUS LOCATION
#define VSC_BACK CTL(KC_MINUS)
#define VSC_FWRD SFT(CTL(KC_MINUS))
// RUN/DEBUG
#define VSC_DBG_RUN KC_F5
#define VSC_DBG_BRKP KC_F9
#define VSC_DBG_OVR KC_F10
#define VSC_DBG_IN KC_F11
// FIND AND RENAME SYMBOLS
#define VSC_RENAME KC_F2
#define VSC_GOTO_DEF KC_F12
#define VSC_PEEK_DEF ALT(KC_F12)
#define VSC_SHOW_REF SFT(KC_F12)
// SELECTION
#define VSC_SEL_EXPND CTL(SFT(CMD(KC_RIGHT)))
#define VSC_SEL_SHRNK CTL(SFT(CMD(KC_LEFT)))
#define VSC_SEL_LINE CMD(KC_L)
// SPLIT EDITOR
#define VSC_EDTR_SPLT CMD(KC_BSLS)
// SIDE BAR TABS
#define VSC_SB_EXPLR SFT(CMD(KC_E))
#define VSC_SB_RNDBG SFT(CMD(KC_D))
#define VSC_SB_TERML CTL(KC_GRAVE)

// Function for handling vscode short cut sequences
void vscode_chord(uint16_t kc);
void two_tap(uint16_t kc1, uint16_t kc2);

enum default_layers { _QWERTY, _COLEMAK, _DEFAULT_RANGE_ };

enum planck_layers {
    _NUM_NAV = _DEFAULT_RANGE_,
    _SYMBOLS,
    _CMD,
    _WIN_CTL,
    _ADJUST,
    _MAX_LAYER_
};

enum planck_keycodes {
    KC_LAYERCOLOR = EZ_SAFE_RANGE,
    VSC_MV_EDTR_LFT,    // MOVE EDITOR TO LEFT GROUP
    VSC_MV_EDTR_RGT,    // MOVE EDITOR TO RIGHT GROUP
    VSC_FCS_G_PREV,     // FOCUS ON PREVIOUS GROUP
    VSC_FCS_G_NEXT,     // FOCUS ON NEXT GROUP
    VSC_OPN_DEF_SIDE    // OPEN DEFINITION IN OPPOSITE GROUP
};

// from left to right on base row
#define LK_LEFT MO(_WIN_CTL)
#define LK_LOWR MO(_SYMBOLS)
#define LK_RAIS MO(_NUM_NAV)
#define LK_RGHT MO(_CMD)

// define home mods arrangement 
#define ML1(kc) LCTL_T(kc)
#define ML2(kc) LALT_T(kc)
#define ML3(kc) LSFT_T(kc)
#define ML4(kc) LGUI_T(kc)
#define MR4(kc) RGUI_T(kc)
#define MR3(kc) RSFT_T(kc)
#define MR2(kc) RALT_T(kc)
#define MR1(kc) RCTL_T(kc)

#define PLANCK_LAYOUT(...) LAYOUT_planck_mit(__VA_ARGS__)
// #define PLANCK_LED_LAYER(...) { __VA_ARGS__ }

// Base 
#define TOP_ROW(...) KC_DEL, __VA_ARGS__, KC_BSPACE
#define HOME_ROW(...) KC_TAB, __VA_ARGS__, KC_ENT
#define BOTTOM_ROW(...) KC_ESC, __VA_ARGS__, KC_CAPSLOCK
#define BASE_ROW(L1, L2, L3, R1, R2, R3) L1, L2, L3, LK_LEFT, LK_LOWR, KC_SPACE, LK_RAIS, LK_RGHT, R1, R2, R3

#define HOME_MOD(L1, L2, L3, L4, L5, R5, R4, R3, R2, R1) HOME_ROW(ML1(L1), ML2(L2), ML3(L3), ML4(L4), L5, R5, MR4(R4), MR3(R3), MR2(R2), MR1(R1))
#define STD_ROW(...) _______, __VA_ARGS__, _______

#define EMPTY_ROW _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define EMPTY_BASE_ROW BASE_ROW(_______, _______, _______, _______, _______, _______)

/* =============================
   =  *                     * =
   =  ***  BEGIN LAYOUTS  *** =
   =  *                     * =
   =============================*/

//  QWERTY - ASCII (compact)
//  --- --- --- --- --- --- --- --- --- --- --- ---
//   *   Q   W   E   R   T   Y   U   I   O   P   *
//   *   A   S   D   F   G   H   J   K   L   ;   *
//   *   Z   X   C   V   B   N   M   ,   .   /   *
//   *   *   *   *   *   [ * ]   *   *   *   *   *
#define ___QWERTY_1___ TOP_ROW(    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U,   KC_I,    KC_O,  KC_P)
#define ___QWERTY_2___ HOME_MOD(   KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J,   KC_K,    KC_L,  KC_SCLN)
#define ___QWERTY_3___ BOTTOM_ROW( KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_QUOTE)
#define ___QWERTY_4___ BASE_ROW(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)
#define LAYER_QWERTY PLANCK_LAYOUT(___QWERTY_1___, ___QWERTY_2___, ___QWERTY_3___, ___QWERTY_4___)

//  COLEMAK DH MOD
//  -----------------------------------------------
//   *   Q   W   F   P   B   J   L   U   Y   ;   *
//   *   A   R   S   T   G   M   N   E   I   O   *
//   *   Z   X   C   D   V   K   H   ,   .   /   *
//   *   *   *   *   *   [ * ]   *   *   *   *   *
#define ___COLEMAK_1__ TOP_ROW(    KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L,   KC_U,    KC_Y,  KC_SCLN)
#define ___COLEMAK_2__ HOME_MOD(   KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N,   KC_E,    KC_I,  KC_O)
#define ___COLEMAK_3__ BOTTOM_ROW( KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMMA, KC_DOT, KC_QUOTE)
#define ___COLEMAK_4__ BASE_ROW(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)

#define LAYER_COLEMAK PLANCK_LAYOUT(___COLEMAK_1__, ___COLEMAK_2__, ___COLEMAK_3__, ___COLEMAK_4__)

//  SYMBOLS
#define ___SYMBOLS_1__ STD_ROW(  KC_PERC, KC_LBRC, KC_RBRC, KC_QUES, KC_HASH, KC_AT,   KC_CRRT, KC_LCBR, KC_RCBR, KC_DLR)
#define ___SYMBOLS_2__ STD_ROW( KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_TILD, KC_GRV,  KC_EQL,  KC_LPRN, KC_RPRN, KC_COLON)
#define ___SYMBOLS_3__ STD_ROW(  KC_BSLS, KC_PIPE, KC_AMPR, KC_EXLM, _______, _______, KC_UNDS, KC_LABK, KC_RABK, KC_DQUO)
#define ___SYMBOLS_4__ EMPTY_BASE_ROW

#define LAYER_SYMBOLS PLANCK_LAYOUT(___SYMBOLS_1__, ___SYMBOLS_2__, ___SYMBOLS_3__, ___SYMBOLS_4__)

//  NUM_NAV-NAV
#define ___NUM_NAV_1__ STD_ROW(     _______, S_TABL,  KC_UP,   S_TABR,  _______, _______,  KC_7,      KC_8,      KC_9,      _______)
#define ___NUM_NAV_2__ _______,     KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_COMMA, MR4(KC_4), MR3(KC_5), MR2(KC_6), MR1(KC_0), _______
#define ___NUM_NAV_3__ STD_ROW(_______, _______, _______, _______, _______, _______,  KC_1,      KC_2,      KC_3,      KC_DOT)
#define ___NUM_NAV_4__ EMPTY_BASE_ROW

#define LAYER_NUM_NAV PLANCK_LAYOUT(___NUM_NAV_1__, ___NUM_NAV_2__, ___NUM_NAV_3__, ___NUM_NAV_4__)

// OLD NAV
// #define _____NAV_1____ STD_ROW(_______, _______, _______, _______, _______, _______, _______, S_TABL, S_TABR, _______)
// #define _____NAV_2____ STD_ROW(_______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______)
// #define _____NAV_3____ STD_ROW(_______, _______, _______, _______, _______, _______, _______, VSC_BACK, VSC_FWRD, _______)
// #define _____NAV_4____ EMPTY_BASE_ROW
// 
// #define LAYER_NAV PLANCK_LAYOUT(_____NAV_1____, _____NAV_2____, _____NAV_3____, _____NAV_4____)

//  CMD
#define ___COMMAND_1__ VSC_SB_EXPLR, VSC_EDTR_SPLT, VSC_MV_EDTR_LFT, VSC_MV_EDTR_RGT, VSC_SEL_LINE, _______, _______, VSC_DBG_RUN,  VSC_DBG_OVR,  VSC_DBG_IN,   VSC_DBG_BRKP,     _______
#define ___COMMAND_2__ VSC_SB_RNDBG, VSC_SEL_SHRNK, VSC_FCS_G_PREV,  VSC_FCS_G_NEXT, VSC_SEL_EXPND, _______, _______, VSC_RENAME,   VSC_BACK,     VSC_FWRD,     _______,          _______
#define ___COMMAND_3__ VSC_SB_TERML, S_UNDO,        S_CUT,           S_COPY,         S_PASTE,       _______, _______, VSC_PEEK_DEF, VSC_SHOW_REF, VSC_GOTO_DEF, VSC_OPN_DEF_SIDE, _______
#define ___COMMAND_4__ EMPTY_BASE_ROW

#define LAYER_COMMAND PLANCK_LAYOUT(___COMMAND_1__, ___COMMAND_2__, ___COMMAND_3__, ___COMMAND_4__)

// Window Management
#define ___WIN_CTL_1__ STD_ROW( WM(KC_Q), WM(KC_W), WM(KC_E), WM(KC_R), XXXXXXX,  WM(KC_Y), WM(KC_U), WM(KC_I),     WM(KC_O),   WM(KC_P))
#define ___WIN_CTL_2__ _______, WM(KC_A), WM(KC_S), WM(KC_D), WM(KC_F), WM(KC_G), WM(KC_H), WM(KC_J), WM(KC_K),     WM(KC_L),   WM(KC_SCOLON), WM(KC_ENTER)
#define ___WIN_CTL_3__ STD_ROW( XXXXXXX,  WM(KC_X), WM(KC_C), WM(KC_V), XXXXXXX,  WM(KC_N), WM(KC_M), WM(KC_COMMA), WM(KC_DOT), XXXXXXX)
#define ___WIN_CTL_4__ EMPTY_BASE_ROW

#define LAYER_WIN_CTL PLANCK_LAYOUT(___WIN_CTL_1__, ___WIN_CTL_2__, ___WIN_CTL_3__, ___WIN_CTL_4__)

// ADJUST
#define ___ADJUST_1___ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, DF(_QWERTY)
#define ___ADJUST_2___ XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, XXXXXXX, KC_MUTE,    KC_VOLD,    KC_VOLU, XXXXXXX, DF(_COLEMAK)
#define ___ADJUST_3___ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, KC_LAYERCOLOR, RGB_MOD, XXXXXXX, XXXXXXX
#define ___ADJUST_4___ BASE_ROW(XXXXXXX, XXXXXXX, XXXXXXX,                                                    RESET,   DEBUG,   XXXXXXX)

#define LAYER_ADJUST PLANCK_LAYOUT(___ADJUST_1___, ___ADJUST_2___, ___ADJUST_3___, ___ADJUST_4___)
