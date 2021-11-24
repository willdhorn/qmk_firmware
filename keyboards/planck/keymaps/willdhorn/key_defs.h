#pragma once

/*
 === MOD TAP/HOME MODS ===
*/
#define MS(kc) MT(MOD_LSFT, kc)
#define MC(kc) MT(MOD_LCTL, kc)
#define MA(kc) MT(MOD_LALT, kc)
#define MG(kc) MT(MOD_LCMD, kc)

// MODIFIERS
#define SFT(kc) LSFT(kc)
#define ALT(KC) LALT(KC)
#define CTL(kc) LCTL(kc)
#define CMD(kc) LCMD(kc)
#define MOD_LCMD MOD_LGUI

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

#define WM_4V_L  WM(KC_U)
#define WM_4V_LC WM(KC_M)
#define WM_4V_RC WM(KC_COMMA)
#define WM_4V_R  WM(KC_I)

#define WM_3_L  WM(KC_A)
#define WM_3_LL WM(KC_S)
#define WM_3_M  WM(KC_D)
#define WM_3_RR WM(KC_F)
#define WM_3_R  WM(KC_G)

#define WM_6_UL WM(KC_W)
#define WM_6_UM WM(KC_E)
#define WM_6_UR WM(KC_R)
#define WM_6_LL WM(KC_X)
#define WM_6_LM WM(KC_C)
#define WM_6_LR WM(KC_V)

// WINDOW LAYERS
#define WNDW_LAYER_H OSL(_WNDW_HALF)
#define WNDW_LAYER_Q OSL(_WNDW_QUAD)
#define WNDW_LAYER_V OSL(_WNDW_VERT)
#define WNDW_LAYER_3 OSL(_WNDW_THRD)
#define WNDW_LAYER_6 OSL(_WNDW_SIXT)

/*
  === MAC SHORTCUTS ===
*/
// GENERAL 
#define S_UNDO CMD(KC_Z)
#define S_CUT CMD(KC_X)
#define S_COPY CMD(KC_C)
#define S_PASTE CMD(KC_V)
// TABS
#define S_TABL SFT(CMD(KC_LBRC))
#define S_TABR SFT(CMD(KC_RBRC))
// DESKTOPS AND MISSION CONTROL
#define OSX_DESK_PREV CTL(KC_LEFT)
#define OSX_DESK_RIGHT CTL(KC_RIGHT)
#define OSX_MC_DESKS CTL(KC_UP)
#define OSX_MC_APPS CTL(KC_DOWN)

/*
  === VISUAL STUDIO CODE ===
*/
// MOVE CURSOR TO PREVIOUS LOCATION
#define VSC_BACK CTL(KC_MINUS)
#define VSC_FWRD SFT(CTL(KC_MINUS))
// RUN/DEBUG
#define VSC_DBG_RUN  KC_F5
#define VSC_DBG_BRKP KC_F9
#define VSC_DBG_OVR  KC_F10
#define VSC_DBG_IN   KC_F11
// FIND
#define VSC_FIND        CMD(KC_F)
#define VSC_FIND_PREV   SFT(CMD(KC_G))
#define VSC_FIND_NEXT   CMD(KC_G)
// LOOKUP SYMBOLS
#define VSC_RENAME   KC_F2
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

// CUSTOM KEYCODES
enum custom_keycodes {
    KC_EMPTY = EZ_SAFE_RANGE,
    KC_LAYERCOLOR,
    // VSCODE
    VSC_MV_EDTR_LFT,    // MOVE EDITOR TO LEFT GROUP
    VSC_MV_EDTR_RGT,    // MOVE EDITOR TO RIGHT GROUP
    VSC_FCS_G_PREV,     // FOCUS ON PREVIOUS GROUP
    VSC_FCS_G_NEXT,     // FOCUS ON NEXT GROUP
    VSC_MV_EDTR_G_LFT,  // MOVE EDITOR GROUP LEFT
    VSC_MV_EDTR_G_RGT,  // MOVE EDITOR GROUP RIGHT
    VSC_OPN_DEF_SIDE,    // OPEN DEFINITION IN OPPOSITE GROUP
    // APPS AND WINDOWS
    OSX_APP_PREV,  // ALT TAB MODE - PREVIOUS APP
    OSX_APP_WNDW,  // ALT TAB MODE - SELECT APP / SWITCH WINDOW
    OSX_APP_NEXT,  // ALT TAB MODE - NEXT APP
};


/*
  === MISC ===
*/
#define KC_DASH ALT(KC_MINUS)  // Em-dash
#define KC_CRRT KC_CIRC

#define KC_HOME CMD(KC_LEFT)
#define KC_END CMD(KC_RIGT)
#define KC_EMOJI LCTL(LCMD(KC_SPACE))

#define foo F(0)