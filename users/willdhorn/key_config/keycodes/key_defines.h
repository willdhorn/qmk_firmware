#pragma once

#include "willdhorn.h"

/*
  === Default Keys ===
  I may change how these keys work, and I want changes to be reflected in every layer/keymap
*/
#define kSpace MT(MOD_LSFT, KC_SPACE)
#define kBackspace TH(thBackspace)
#define kEnter TH(thEnter)
// #define kEscape TH(thEscape)
#define kTab KC_TAB

#define kComma RCMD_T(KC_COMMA)
#define kPeriod RALT_T(KC_DOT)
#define kQuote RCTL_T(KC_QUOTE)

#define kLeft TH(thLeft)
#define kRight TH(thRight)
#define kAltLeft TH(thAltLeft)
#define kAltRight TH(thAltRight)

// Layers
#define lk_Default TO(0)
#define lk_Symbol TO(_SYM)
#define lk_Num TO(_NUM)
#define lk_Nav TH(thNav)
#define lk_Ext TO(_EXT)
#define lk_Desktop TO(_DESKTOP)
#define lk_Config TO(_CONFIG)
// #define LKT_VSC TO(_VSCODE)

/*
  === General ===
*/
#define _x_ KC_NO
#define ___ KC_TRNS
#define KC_DASH ALT(KC_MINUS) // Em-dash
#define KC_CRRT KC_CIRC

/*
  === MAC SHORTCUTS ===
*/
// HOME AND END KEYS
#define OSX_HOME CMD(KC_LEFT)
#define OSX_END CMD(KC_RIGHT)
#define OSX_BKSP_LINE CMD(KC_BACKSPACE)
#define OSX_DEL_LINE CTL(KC_K)
// GENERAL
#define S_UNDO CMD(KC_Z)
#define S_CUT CMD(KC_X)
#define S_COPY CMD(KC_C)
#define S_PASTE CMD(KC_V)
#define S_CLIPBOARD CMD(CTL((KC_V))) // PASTE FROM CLIPBOARD
// OTHER
#define S_ALFRED CMD(KC_SPACE)
#define S_SNIPPETS CMD(CTL((KC_G))) // ALFRED SNIPPETS
#define S_PALETTE CMD(SFT(KC_P))
#define KC_EMOJI LCTL(LCMD(KC_SPACE))
// TABS
#define S_TABL SFT(CMD(KC_LBRC))
#define S_TABR SFT(CMD(KC_RBRC))
// DESKTOPS AND MISSION CONTROL
#define OSX_DESK_PREV CTL(KC_LEFT)
#define OSX_DESK_RIGHT CTL(KC_RIGHT)
#define OSX_MC_DESKS CTL(KC_UP)
#define OSX_MC_APPS CTL(KC_DOWN)
// TAP DANCE
#define OSX_APP_PREV TD(TD_APPSW_L)
#define OSX_APP_WNDW TD(TD_APPSW_M)
#define OSX_APP_NEXT TD(TD_APPSW_R)

/*
  === WINDOW ARRANGEMENT ===
*/
#define WM(kc) LALT(LCTL(kc)) // Shortcut for Window Management (Rectangle)

#define WM_FULL WM(KC_ENT)

#define WM_H_L WM(KC_H)
#define WM_H_R WM(KC_L)
#define WM_H_U WM(KC_K)
#define WM_H_D WM(KC_J)
#define WM_H_M WM(KC_SCLN)

#define WM_4Q_UL WM(KC_Y)
#define WM_4Q_UR WM(KC_O)
#define WM_4Q_LL WM(KC_N)
#define WM_4Q_LR WM(KC_DOT)

#define WM_4V_L WM(KC_U)
#define WM_4V_LC WM(KC_M)
#define WM_4V_RC WM(KC_COMMA)
#define WM_4V_R WM(KC_I)

#define WM_3_L WM(KC_A)
#define WM_3_LL WM(KC_S)
#define WM_3_M WM(KC_D)
#define WM_3_RR WM(KC_F)
#define WM_3_R WM(KC_G)

#define WM_6_UL WM(KC_W)
#define WM_6_UM WM(KC_E)
#define WM_6_UR WM(KC_R)
#define WM_6_LL WM(KC_X)
#define WM_6_LM WM(KC_C)
#define WM_6_LR WM(KC_V)

#define WM_9_BL WM(KC_KP_1)
#define WM_9_BC WM(KC_KP_2)
#define WM_9_BR WM(KC_KP_3)
#define WM_9_ML WM(KC_KP_4)
#define WM_9_MC WM(KC_KP_5)
#define WM_9_MR WM(KC_KP_6)
#define WM_9_TL WM(KC_KP_7)
#define WM_9_TC WM(KC_KP_8)
#define WM_9_TR WM(KC_KP_9)

// WINDOW LAYERS
#define WNDW_LAYER_H OSL(_WNDW_HALF)
#define WNDW_LAYER_Q OSL(_WNDW_QUAD)
#define WNDW_LAYER_V OSL(_WNDW_VERT)
#define WNDW_LAYER_3 OSL(_WNDW_THRD)
#define WNDW_LAYER_6 OSL(_WNDW_SIXT)
#define WNDW_LAYER_9 OSL(_WNDW_NINT)

/*
  === VISUAL STUDIO CODE ===
*/
// MOVE CURSOR TO PREVIOUS LOCATION
#define VSC_BACK CTL(KC_MINUS)
#define VSC_FWRD SFT(CTL(KC_MINUS))
// RUN/DEBUG
#define VSC_DBG_RUN KC_F5
#define VSC_DBG_BRKP KC_F9
#define VSC_DBG_OVR KC_F10
#define VSC_DBG_IN KC_F11
// FIND
#define VSC_FIND CMD(KC_F)
#define VSC_FIND_PREV SFT(CMD(KC_G))
#define VSC_FIND_NEXT CMD(KC_G)
// LOOKUP CODE
#define VSC_RENAME KC_F2
#define VSC_GOTO_DEF KC_F12
#define VSC_PEEK_DEF ALT(KC_F12)
#define VSC_SHOW_REF SFT(KC_F12)
// GOTOS
#define VSC_PROB_PREV SFT(KC_F8)
#define VSC_PROB_NEXT KC_F8
#define VSC_GOTO_SYMB SFT(CMD(KC_O))
#define VSC_GOTO_LINE CTL(KC_G)
// SELECTION
#define VSC_SEL_EXPND CTL(SFT(CMD(KC_RIGHT)))
#define VSC_SEL_SHRNK CTL(SFT(CMD(KC_LEFT)))
#define VSC_SEL_LINE CMD(KC_L)
// SPLIT EDITOR
#define VSC_EDTR_SPLT CMD(KC_BSLS)
#define VSC_TOGL_VRT_HRZ ALT(CMD(KC_0))
// SIDE BAR TABS
#define VSC_SB_EXPLR ALT(SFT(CMD(KC_E)))
#define VSC_SB_SEARC ALT(SFT(CMD(KC_F)))
#define VSC_SB_DEBUG ALT(SFT(CMD(KC_D)))
#define VSC_SB_SRCTL ALT(SFT(CMD(KC_G)))
// BOTTOM PANEL TABS
#define VSC_BP_TERML CTL(KC_GRAVE)
#define VSC_BP_PRBLM SFT(CMD(KC_M))
