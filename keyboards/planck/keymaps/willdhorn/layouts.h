#pragma once

#include <stdint.h>

// MODIFIERS
#define SFT(kc) LSFT(kc)
#define ALT(KC) LALT(KC)
#define CTL(kc) LCTL(kc)
#define CMD(kc) LCMD(kc)
#define MOD_LCMD MOD_LGUI

// MOD TAP DEFINES
#define MS(kc) MT(MOD_LSFT, kc)
#define MC(kc) MT(MOD_LCTL, kc)
#define MA(kc) MT(MOD_LALT, kc)
#define MG(kc) MT(MOD_LCMD, kc)
#define SFT_ESC MT(MOD_LSFT, KC_ESC)
#define SFT_ENT MT(MOD_RSFT, KC_ENT)
#define CTRL_CAPS MT(MOD_LCTL, KC_CAPSLOCK)
#define CMD_CAPS MT(MOD_LCMD, KC_CAPSLOCK)



// KEYCODES
#define KC_SFT KC_LSFT
#define KC_CTL KC_LCTL
#define KC_ALT KC_LALT
#define KC_CMD KC_LCMD
// Shortcut for Window Management (Rectangle)
#define WM(kc) LALT(LCTL(kc))

#define KC_DASH ALT(KC_MINUS)
#define KC_CRRT KC_CIRC

#define KC_HOME CMD(KC_LEFT)
#define KC_END CMD(KC_RIGT)
#define KC_EMOJI LCTL(LCMD(KC_SPACE))

// Left-hand home row mods (QWERTY)
// #define CTL_A LCTL_T(KC_A)
// #define ALT_S LALT_T(KC_S)
// #define SFT_D LSFT_T(KC_D)
// #define GUI_F LGUI_T(KC_F)
// // Right-hand home row mods
// #define GUI_J RGUI_T(KC_J)
// #define SFT_K RSFT_T(KC_K)
// #define ALT_L LALT_T(KC_L)
// #define CTL_SCLN RCTL_T(KC_SCLN)

// Left-hand home row mods (Colemak)
//#define CTL_A LCTL_T(KC_A)
// #define ALT_R LALT_T(KC_R)
// #define SFT_S LSFT_T(KC_S)
// #define GUI_T LGUI_T(KC_T)

// // Right-hand home row mods
// #define GUI_N RGUI_T(KC_N)
// #define SFT_E RSFT_T(KC_E)
// #define ALT_I LALT_T(KC_I)
// #define CTL_O RCTL_T(KC_O)



// SHORTCUTS
#define S_UNDO CMD(KC_Z)
#define S_CUT CMD(KC_X)
#define S_COPY CMD(KC_C)
#define S_PASTE CMD(KC_V)

#define S_TABL SFT(CMD(KC_LBRC)) 
#define S_TABR SFT(CMD(KC_RBRC))


#define VS_BACK C(KC_MINUS)
#define VS_FWRD S(C(KC_MINUS))


enum default_layers {
    _QWERTY,
    _COLEMAK,
    _DEFAULT_RANGE_
};

enum planck_layers {
    _NUM = _DEFAULT_RANGE_,
    _SYMBOLS,
    _NAV,
    // _CMD,
    // _SYM_EXT,
    _WIN_CTL,
    _ADJUST,
    _MAX_LAYER_
    // TODO: APP SWITCH/SHORTCUTS
};

enum planck_keycodes {
    KC_LAYERCOLOR = EZ_SAFE_RANGE
};

// from left to right on base row
#define LK_LEFT MO(_WIN_CTL)
#define LK_LOWR MO(_SYMBOLS)
#define LK_RAIS MO(_NUM)
#define LK_RGHT MO(_NAV)


#define PLANCK_LAYOUT(...) LAYOUT_planck_mit(__VA_ARGS__)
#define PLANCK_LED_LAYER(...) { __VA_ARGS__ }

/* Base - NOT A REAL LAYER:
 *    The base mod positions for all other layouts, but we still want the layout
 *    layers to be the "default layer" so we can take advantage of DF()
 *    without dealing with TO() (is this worth it tho?)
 *    NOTE:  The other option is to make this base layer the default layer 
 *           and use TO to change layouts
 */
#define TOP_ROW(...) KC_DEL, __VA_ARGS__, KC_BSPACE
#define HOME_ROW(...) KC_TAB, __VA_ARGS__, KC_ENT
#define BOTTOM_ROW(...) KC_ESC, __VA_ARGS__, KC_SLASH
#define BASE_ROW(L1, L2, L3, R1, R2, R3) L1, L2, L3, LK_LEFT, LK_LOWR, KC_SPACE, LK_RAIS, LK_RGHT, R1, R2, R3

#define HOME_MOD(L1, L2, L3, L4, L5, R5, R4, R3, R2, R1)  HOME_ROW(LCTL_T(L1), LALT_T(L2), LSFT_T(L3), LGUI_T(L4), L5, R5, RGUI_T(R4), RSFT_T(R3), LALT_T(R2), RCTL_T(R1))
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
#define ___QWERTY_1___ TOP_ROW(   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P)
#define ___QWERTY_2___ HOME_MOD(  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN)
#define ___QWERTY_3___ BOTTOM_ROW(KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_QUOTE)
#define ___QWERTY_4___ BASE_ROW(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_COLEMAK))
#define LAYER_QWERTY PLANCK_LAYOUT(___QWERTY_1___, ___QWERTY_2___, ___QWERTY_3___, ___QWERTY_4___)

//  COLEMAK DH MOD                                       
//  -----------------------------------------------
//   *   Q   W   F   P   B   J   L   U   Y   ;   *
//   *   A   R   S   T   G   M   N   E   I   O   *
//   *   Z   X   C   D   V   K   H   ,   .   /   *
//   *   *   *   *   *   [ * ]   *   *   *   *   *
#define ___COLEMAK_1__ TOP_ROW(   KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y,        KC_SCOLON)
#define ___COLEMAK_2__ HOME_MOD(  KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O)
#define ___COLEMAK_3__ BOTTOM_ROW(KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H,   KC_COMMA, KC_DOT, KC_QUOTE)
#define ___COLEMAK_4__ BASE_ROW(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_QWERTY))

#define LAYER_COLEMAK PLANCK_LAYOUT(___COLEMAK_1__, ___COLEMAK_2__, ___COLEMAK_3__, ___COLEMAK_4__)

//  SYMBOL - BASE          
#define ___SYMBOLS_1__ STD_ROW(_______, KC_LBRC, KC_RBRC, KC_EXLM, _______, KC_AT,   KC_CRRT, KC_LCBR, KC_RCBR, KC_DLR)
#define ___SYMBOLS_2__ STD_ROW(KC_HASH, KC_SLSH, KC_ASTR, KC_PLUS, _______, KC_TILD, KC_EQL,  KC_LPRN, KC_RPRN, KC_COLON)
#define ___SYMBOLS_3__ KC_CAPSLOCK,KC_PERC, KC_PIPE, KC_AMPR, KC_MINS, _______, KC_GRV,  KC_UNDS, KC_LABK, KC_RABK, KC_DQUO, KC_BSLS
#define ___SYMBOLS_4__ EMPTY_BASE_ROW

#define LAYER_SYMBOLS PLANCK_LAYOUT(___SYMBOLS_1__, ___SYMBOLS_2__, ___SYMBOLS_3__, ___SYMBOLS_4__)

//  NUM                                             
#define _____NUM_1____ STD_ROW(KC_F1,  KC_F2,  KC_F3, KC_F4, KC_F5, _______,          KC_7,    KC_8,    KC_9, _______)
#define _____NUM_2____ STD_ROW(KC_F6,  KC_F7,  KC_F8, KC_F9, KC_F10, _______,         KC_4,    KC_5,    KC_6, KC_0)
#define _____NUM_3____ STD_ROW(KC_F11, KC_F12, _______, _______, _______, _______,    KC_1,    KC_2,    KC_3, KC_DOT)
#define _____NUM_4____ _______,_______, _______, _______, _______, _______, _______, KC_COMMA, _______, _______, _______

#define LAYER_NUM PLANCK_LAYOUT(_____NUM_1____, _____NUM_2____, _____NUM_3____, _____NUM_4____)

// NAV 
#define _____NAV_1____ STD_ROW(_______, _______, _______, _______, _______, _______, _______, S_TABL,  S_TABR,  _______)
#define _____NAV_2____ STD_ROW(_______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______)
#define _____NAV_3____ STD_ROW(_______, _______, _______, _______, _______, _______, _______, VS_BACK, VS_FWRD, _______)
#define _____NAV_4____ EMPTY_BASE_ROW

#define LAYER_NAV PLANCK_LAYOUT(_____NAV_1____, _____NAV_2____, _____NAV_3____, _____NAV_4____)

//  CMD
//  --- ---- ---- ---- ---- --- --- --- --- --- --- ---
//   –   –    –    –    –    –   –   –   –   –   –   –
//   –  Undo Cut  Copy Pste  –   –   –   –   –   –   –
//   –  Redo  –    –    –    –   –   –   –   –   –   –
//   –   –    –   (X)   –    [ - ]   –   –   –   –   - 
// #define ___COMMAND_1__ STD_ROW(_______,_______,_______,_______, _______, _______, KC_F1,  KC_F2,  KC_F3,  KC_F4)
// #define ___COMMAND_2__ STD_ROW(_______,_______,_______,_______, _______, _______, KC_F5,  KC_F6,  KC_F7,  KC_F8)
// #define ___COMMAND_3__ STD_ROW(S_UNDO, S_CUT,  S_COPY, S_PASTE, _______, _______, KC_F9,  KC_F10, KC_F11, KC_F12)
// #define ___COMMAND_4__ EMPTY_BASE_ROW
// 
// #define LAYER_COMMAND PLANCK_LAYOUT(___COMMAND_1__, ___COMMAND_2__, ___COMMAND_3__, ___COMMAND_4__)

//  SYMBOL - EXT.                                   
//  --- --- --- --- --- --- --- --- --- --- --- --- 
//   –   –   -   -   -   –   –   !   /   *   %   –  
//   –   -   -   -   -   –   ~   +   =   :   &   –  
//   –   –   -   -   -   –   `   -   <   >   |   –  
//   –   –   –   –  (X)    -    (X)  –   –   –   –  
// #define ___SYM_EXT_1__ STD_ROW(_______, _______, _______, _______, _______, KC_GRAVE, KC_TILDE, KC_EXLM, KC_AMPR, KC_PIPE)
// #define ___SYM_EXT_2__ STD_ROW(_______, _______, _______, _______, _______, _______,  KC_PUS,  KC_SLSH, KC_ASTR, KC_COLN)
// #define ___SYM_EXT_3__ STD_ROW(_______, _______, _______, _______, _______, _______,  KC_MINS,  KC_LABK, KC_RABK, KC_PERC)
// #define ___SYM_EXT_4__ EMPTY_BASE_ROW
// 
// #define LAYER_SYM_EXT PLANCK_LAYOUT(___SYM_EXT_1__, ___SYM_EXT_2__, ___SYM_EXT_3__, ___SYM_EXT_4__)

// Window Management
#define ___WIN_CTL_1__ STD_ROW( WM(KC_Q), WM(KC_W), WM(KC_E), WM(KC_R), XXXXXXX,  WM(KC_Y), WM(KC_U), WM(KC_I),     WM(KC_O), WM(KC_P))
#define ___WIN_CTL_2__ _______, WM(KC_A), WM(KC_S), WM(KC_D), WM(KC_F), WM(KC_G), WM(KC_H), WM(KC_J), WM(KC_K),     WM(KC_L), WM(KC_SCOLON), WM(KC_ENTER)
#define ___WIN_CTL_3__ STD_ROW( XXXXXXX,  WM(KC_X), WM(KC_C), WM(KC_V), XXXXXXX,  WM(KC_N), WM(KC_M), WM(KC_COMMA), WM(KC_DOT), XXXXXXX)
#define ___WIN_CTL_4__ EMPTY_BASE_ROW

#define LAYER_WIN_CTL PLANCK_LAYOUT(___WIN_CTL_1__, ___WIN_CTL_2__, ___WIN_CTL_3__, ___WIN_CTL_4__)

// ADJUST 
#define ___ADJUST_1___ XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ___ADJUST_2___ STD_ROW(XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX)
#define ___ADJUST_3___ STD_ROW(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, KC_LAYERCOLOR, RGB_MOD, XXXXXXX)
#define ___ADJUST_4___ BASE_ROW(_______,_______, _______,                                                    RESET,   DEBUG, XXXXXXX)

#define LAYER_ADJUST PLANCK_LAYOUT(___ADJUST_1___, ___ADJUST_2___, ___ADJUST_3___, ___ADJUST_4___)

