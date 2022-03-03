#pragma once

#include "process_tap_hold.h"
#include "tap_dances.h"

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

#define MOD_LHYP 0xF
#define MOD_LMEH 0x7
#define MOD_RHYP 0x1F
#define MOD_RMEH 0x17

#define MOD_MASK_MEH MOD_MASK_CSA
#define MOD_MASK_HYP MOD_MASK_CSAG

#define LHYP(kc) (QK_LCTL | QK_LSFT | QK_LALT | QK_LGUI | (kc))
#define LMEH(kc) (QK_LCTL | QK_LSFT | QK_LALT | (kc))
#define RHYP(kc) (QK_RCTL | QK_RSFT | QK_RALT | QK_RGUI | (kc))
#define RMEH(kc) (QK_RCTL | QK_RSFT | QK_RALT | (kc))

#define LHYP_T(kc) MT(MOD_LCTL | MOD_LSFT | MOD_LALT | MOD_LGUI, kc)
#define LMEH_T(kc) MT(MOD_LCTL | MOD_LSFT | MOD_LALT, kc)
#define RHYP_T(kc) MT(MOD_RCTL | MOD_RSFT | MOD_RALT | MOD_RGUI, kc)
#define RMEH_T(kc) MT(MOD_RCTL | MOD_RSFT | MOD_RALT, kc)

#define _x_ KC_NO

#define LK_DEF TO(0)
#define LK_EXT TO(_EXT)
#define LK_SYM TO(_SYM)
#define LK_NUM TO(_NUM)
#define LK_NAV TO(_NAV)
#define LK_SWT TO(_SWITCH)
#define LK_ADJ TO(_ADJUST)
#define LK_VSC TO(_VSCODE)

#define SPACE_KEY MT(MOD_LMEH, KC_SPACE)

#ifdef KB_LAYOUT_STANDARD  // STANDARD LAYOUT
#    define STD_LK_LEFT TT(_NUM)
#    define STD_LK_LOWR KC_LSFT
#    define STD_LK_RAIS LT(_NAV, KC_SPACE)
#    define STD_LK_RGHT TT(_EXT)
#else  // SPLIT LAYOUT - WITH 3 LAYERKEYS
#    define SPLT_LLFT OSM(MOD_LALT)
#    define SPLT_LMID LK_EXT
#    define SPLT_LRGT OSM(MOD_LSFT)
#    define SPLT_RLFT LK_DEF
#    define SPLT_RMID SPACE_KEY
#    define SPLT_RRGT LK_SYM
#endif

/*
  === MAC SHORTCUTS ===
*/
// HOME AND END KEYS
#define OSX_HOME CMD(KC_LEFT)
#define OSX_END CMD(KC_RIGHT)
#define OSX_BKSP_LINE CMD(KC_BACKSPACE)
#define OSX_DEL_LINE CTL(KC_K)
// ALFRED (and other)
#define S_ALFRED CMD(KC_SPACE)
#define S_PALETTE CMD(SFT(KC_P))
// GENERAL
#define S_UNDO CMD(KC_Z)
#define S_CUT CMD(KC_X)
#define S_COPY CMD(KC_C)
#define S_PASTE CMD(KC_V)
#define S_CLIPBOARD CMD(CTL((KC_V))) // PASTE FROM CLIPBOARD
#define S_SNIPPETS CMD(CTL((KC_G))) // ALFRED SNIPPETS

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
#define VSC_DBG_RUN  KC_F5
#define VSC_DBG_BRKP KC_F9
#define VSC_DBG_OVR  KC_F10
#define VSC_DBG_IN   KC_F11
// FIND
#define VSC_FIND        CMD(KC_F)
#define VSC_FIND_PREV   SFT(CMD(KC_G))
#define VSC_FIND_NEXT   CMD(KC_G)
// LOOKUP CODE
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
    // UTILITY KEYS
    KC_EMPTY = EZ_SAFE_RANGE,
    KC_CLEAR_MODS,
    // PERSISTANT DEFALT LAYER
#ifdef ENABLE_LAYOUT_QWERTY
    KC_QWERTY,
#endif
#ifdef ENABLE_LAYOUT_COLEMAK
    KC_COLEMAK_DH,
#endif
#ifdef ENABLE_LAYOUT_ISRT
    KC_ISRT,
#endif
#ifdef ENABLE_LAYOUT_WORKMAN
    KC_WORKMAN,
#endif

    // MACRO KEYS
    MCR_NEQL,
    MCR_PRNS,
    MCR_BRCS,
    MCR_CBRS,
    MCR_TILD,

    // CUSTOM ONE SHOT MODS
    KC_OSM_CMD,
    KC_OSM_SFT,
    KC_OSM_ALT,
    KC_OSM_CTL,
    // RGB
    KC_LAYERCOLOR,
    KC_LED_INC_BRGT,
    KC_LED_DCR_BRGT,
    // VSCODE
    VSC_MV_EDTR_LFT,    // MOVE EDITOR TO LEFT GROUP
    VSC_MV_EDTR_RGT,    // MOVE EDITOR TO RIGHT GROUP
    VSC_FCS_G_PREV,     // FOCUS ON PREVIOUS GROUP
    VSC_FCS_G_NEXT,     // FOCUS ON NEXT GROUP
    VSC_MV_EDTR_G_LFT,  // MOVE EDITOR GROUP LEFT
    VSC_MV_EDTR_G_RGT,  // MOVE EDITOR GROUP RIGHT
    VSC_OPN_DEF_SIDE,    // OPEN DEFINITION IN OPPOSITE GROUP
    // LAYER SWITCHING
    LAYER_FN_DEF,
    LAYER_FN_EXT,
    LAYER_FN_SYM,
    LAYER_FN_SYMSWAP,
};
#ifndef ENABLE_LAYOUT_QWERTY
    #define KC_QWERTY _x_
#endif
#ifndef ENABLE_LAYOUT_COLEMAK
    #define KC_COLEMAK_DH _x_
#endif
#ifndef ENABLE_LAYOUT_ISRT
    #define KC_ISRT _x_
#endif
#ifndef ENABLE_LAYOUT_WORKMAN
    #define KC_WORKMAN _x_
#endif


/*
  === Tap Hold ===
*/
// System
#define TH_BKSP TH(THA_BKSP)
#define TH_ENTER TH(THA_ENTER)
#define TH_ESC TH(THA_ESC)
// Punctuation and Symbols
#define TH_COMMA TH(THA_COMMA)
#define TH_DOT TH(THA_DOT)
#define TH_QUOT TH(THA_QUOT)

#define TH_MINS TH(THA_MINS)
#define TH_SLSH TH(THA_SLSH)
#define TH_EQLS TH(THA_EQLS)
#define TH_TILD TH(THA_TILD)
// Brackets
#define TH_LCBR TH(THA_LCBR)
#define TH_LPRN TH(THA_LPRN)
#define TH_LBRC TH(THA_LBRC)
#define TH_LABK TH(THA_LABK)
// Arrow keys
#define TH_LEFT TH(THA_LEFT)
#define TH_ALT_LFT TH(THA_ALT_LFT)
#define TH_RIGHT TH(THA_RIGHT)
#define TH_ALT_RGT TH(THA_ALT_RGT)
// ZXCV Shortcuts
#define TH_UNDO_Z TH(THA_UNDO_Z)
#define TH_CUT_X TH(THA_CUT_X)
#define TH_COPY_C TH(THA_COPY_C)
#define TH_PASTE_D TH(THA_PASTE_D)
#define TH_CLIPBOARD_V TH(THA_CLIPBOARD_V)
// Layer Switching
#define TH_LK_DEF TH(THA_LK_DEF)
#define TH_LK_SYM TH(THA_LK_SYM)

enum tap_hold_action_keys {
#define TH_ACTION_ENTER ACTION_TAP_CMD_HOLD(KC_ENTER)
    THA_ENTER = 0,
#define TH_ACTION_ESC ACTION_TAP_HOLD_SHIFT(KC_ESC, LSFT(KC_ESC), KC_CAPSLOCK, KC_CLEAR_MODS)
    THA_ESC,
#define TH_ACTION_BKSP ACTION_TAP_HOLD_SHIFT(KC_BACKSPACE, KC_DELETE, OSX_BKSP_LINE, OSX_DEL_LINE)
    THA_BKSP,

#define TH_ACTION_COMMA ACTION_TAP_HOLD_SHIFT(KC_COMMA, KC_EXLM, KC_MINS, KC_EXLM)
    THA_COMMA,
#define TH_ACTION_DOT ACTION_TAP_HOLD_SHIFT(KC_DOT, KC_QUES, KC_SLSH, KC_QUES)
    THA_DOT,
#define TH_ACTION_QUOT ACTION_TAP_HOLD_SHIFT(KC_QUOTE, KC_BSLS, KC_DQUO, KC_BSLS)
    THA_QUOT,

#define TH_ACTION_MINS ACTION_TAP_HOLD_SHIFT(KC_MINS, KC_EXLM, KC_COMMA, KC_EXLM)
    THA_MINS,
#define TH_ACTION_SLSH ACTION_TAP_HOLD_SHIFT(KC_SLSH, KC_QUES, KC_DOT, KC_QUES)
    THA_SLSH,
#define TH_ACTION_EQLS ACTION_TAP_HOLD(KC_EQL, MCR_NEQL)
    THA_EQLS,
#define TH_ACTION_TILD ACTION_TAP_HOLD(KC_TILD, MCR_TILD)
    THA_TILD,

#define TH_ACTION_LPRN ACTION_TAP_HOLD_SHIFT(KC_LPRN, KC_RPRN, MCR_PRNS, MCR_PRNS)
    THA_LPRN,
#define TH_ACTION_LCBR ACTION_TAP_HOLD_SHIFT(KC_LCBR, KC_RCBR, MCR_CBRS, MCR_CBRS)
    THA_LCBR,
#define TH_ACTION_LBRC ACTION_TAP_HOLD_SHIFT(KC_LBRC, KC_RBRC, MCR_BRCS, MCR_BRCS)
    THA_LBRC,
#define TH_ACTION_LABK ACTION_TAP_HOLD(KC_LABK, KC_RABK)
    THA_LABK,

#define TH_ACTION_LEFT ACTION_TAP_CMD_HOLD(KC_LEFT)
    THA_LEFT,
#define TH_ACTION_RIGHT ACTION_TAP_CMD_HOLD(KC_RIGHT)
    THA_RIGHT,
#define TH_ACTION_ALT_LFT ACTION_TAP_CMD_HOLD(LALT(KC_LEFT))
    THA_ALT_LFT,
#define TH_ACTION_ALT_RGT ACTION_TAP_CMD_HOLD(LALT(KC_RIGHT))
    THA_ALT_RGT,

#define TH_ACTION_UNDO_Z ACTION_TAP_HOLD(KC_Z, S_UNDO)
    THA_UNDO_Z,
#define TH_ACTION_CUT_X ACTION_TAP_HOLD(KC_X, S_CUT)
    THA_CUT_X,
#define TH_ACTION_COPY_C ACTION_TAP_HOLD(KC_C, S_COPY)
    THA_COPY_C,
#define TH_ACTION_PASTE_D ACTION_TAP_HOLD(KC_D, S_PASTE)
    THA_PASTE_D,
#define TH_ACTION_CLIPBOARD_V ACTION_TAP_HOLD(KC_V, S_CLIPBOARD)
    THA_CLIPBOARD_V,

#define TH_ACTION_LK_DEF ACTION_TAP_HOLD(LAYER_FN_DEF, LAYER_FN_EXT)
    THA_LK_DEF,
#define TH_ACTION_LK_SYM ACTION_TAP_HOLD(LAYER_FN_SYMSWAP, LAYER_FN_SYM)
    THA_LK_SYM,

    TAP_HOLD_KEY_MAX
};

/*
  === MISC ===
*/
#define KC_DASH ALT(KC_MINUS)  // Em-dash
#define KC_CRRT KC_CIRC

#define KC_HOME CMD(KC_LEFT)
#define KC_END CMD(KC_RIGT)
#define KC_EMOJI LCTL(LCMD(KC_SPACE))

/*
  === KEY TEST MACROS ===
*/

#define IS_LETTER(kc) (KC_A <= (kc) && (kc) <= KC_Z)
#define IS_NUMBER(kc) (KC_1 <= (kc) && (kc) <= KC_0) // ignores num pad keys
#define IS_SYSTEM_KEY(kc) ( \
  (kc) == KC_BACKSPACE || \
  (kc) == TH_BKSP || \
  (kc) == KC_ENTER || \
  (kc) == TH_ENTER || \
  (kc) == KC_TAB || \
  (kc) == KC_ESCAPE || \
  (kc) == TH_ESC || \
  (kc) == KC_SPACE || \
  (kc) == SPACE_KEY \
)

// .,;:?!'"
#define IS_SYM_PUNCTUATION(kc) ( \
  (kc) == KC_DOT || \
  (kc) == TH_DOT || \
  (kc) == KC_COMM || \
  (kc) == TH_COMMA || \
  (kc) == KC_SCLN || \
  (kc) == KC_COLN || \
  (kc) == KC_QUES || \
  (kc) == KC_EXLM || \
  (kc) == KC_QUOT || \
  (kc) == TH_QUOT || \
  (kc) == KC_DQUO )

// (){}[]<>
#define IS_SYM_PAREN(kc) ( \
  (kc) == KC_LPRN || \
  (kc) == TH_LPRN || \
  (kc) == KC_RPRN || \
  (kc) == KC_LBRC || \
  (kc) == TH_LBRC || \
  (kc) == KC_RBRC || \
  (kc) == KC_LCBR || \
  (kc) == TH_LCBR || \
  (kc) == KC_RCBR || \
  (kc) == KC_LABK || \
  (kc) == TH_LABK || \
  (kc) == KC_RABK )
// _\&|%
#define IS_SYM_PROGRAMMING(kc) ( \
  (kc) == KC_UNDS || \
  (kc) == KC_AMPR || \
  (kc) == KC_PIPE || \
  (kc) == KC_HASH || \
  (kc) == KC_PERC || \
  (kc) == KC_BSLS )
// =+-*/
#define IS_SYM_MATH(kc) ( \
  (kc) == KC_EQL || \
  (kc) == TH_EQLS || \
  (kc) == KC_PLUS || \
  (kc) == KC_MINS || \
  (kc) == TH_MINS || \
  (kc) == KC_ASTR || \
  (kc) == KC_SLSH || \
  (kc) == TH_SLSH )
// ^$#~`
#define IS_SYM_SPECIAL(kc) ( \
  (kc) == KC_CRRT || \
  (kc) == KC_DLR || \
  (kc) == KC_AT || \
  (kc) == KC_TILD || \
  (kc) == TH_TILD || \
  (kc) == KC_GRV )

#define IS_ARROW(kc) ((KC_RIGHT <= (kc) && (kc) <= KC_UP) || (kc) == TH_LEFT || (kc) == TH_RIGHT)

#define IS_NAV_SC(kc) ((kc) == S_TABL || \
  (kc) == S_TABR || \
  (kc) == TH_ALT_LFT || \
  (kc) == TH_ALT_RGT || \
  (kc) == OSX_HOME || \
  (kc) == OSX_END)

//   (kc) == TH_UNDO_Z ||
//   (kc) == TH_CUT_X ||
//   (kc) == TH_COPY_C ||
//   (kc) == TH_PASTE_D ||
//   (kc) == TH_CLIPBOARD_V
#define IS_SYSTEM_SC(kc) ( \
  (kc) == S_UNDO || \
  (kc) == S_CUT || \
  (kc) == S_COPY || \
  (kc) == S_PASTE || \
  (kc) == S_CLIPBOARD)

#define IS_SWITCH_KEY(kc) ( \
    (kc) == OSX_APP_NEXT \
)

// Mods set top 3 bits (6,7,8) to indicate mod and bits 1 and 2 are used for mod encoding (non one-hot)
#define IS_MOD_KEY(kc) ((((kc)>>5) & 0x07) == 0x07)

#define IS_MOD_TAP(kc) ((kc) >= QK_MOD_TAP && (kc) <= QK_MOD_TAP_MAX)
#define IS_OSM(kc) ((kc) >= QK_ONE_SHOT_MOD && (kc) <= QK_ONE_SHOT_MOD_MAX)

#define IS_LAYER_KEY(kc) (IS_MO_LAYER(kc) || IS_TO_LAYER(kc) || IS_DF_LAYER(kc) || IS_LT_LAYER(kc) || IS_OSL_LAYER(kc) || IS_CUSTOM_LK(kc))

#define IS_MO_LAYER(kc) ((kc) >= QK_MOMENTARY && (kc) <= QK_MOMENTARY_MAX)
#define IS_TO_LAYER(kc) ((kc) >= QK_TO && (kc) <= QK_TO_MAX)
#define IS_DF_LAYER(kc) ((kc) >= QK_DEF_LAYER && (kc) <= QK_DEF_LAYER_MAX)
#define IS_LT_LAYER(kc) ((kc) >= QK_LAYER_TAP && (kc) <= QK_LAYER_TAP_MAX)
#define IS_OSL_LAYER(kc) ((kc) >= QK_ONE_SHOT_LAYER && (kc) <= QK_ONE_SHOT_LAYER_MAX)
#define IS_CUSTOM_LK(kc) ( \
    (kc) == LAYER_FN_DEF || \
    (kc) == LAYER_FN_EXT || \
    (kc) == LAYER_FN_SYM || \
    (kc) == LAYER_FN_SYMSWAP || \
    (kc) == TH_LK_SYM || \
    (kc) == TH_LK_DEF \
)

#define IS_TAP_DANCE(kc) ((kc) >= QK_TAP_DANCE && (kc) <= QK_TAP_DANCE_MAX)

#define LT_KEYCODE(lt) ((lt)&0xFF)
#define LT_LAYER(lt) ((lt>>8)&0xF)

#define MT_KEYCODE(mt) ((mt)&0xFF)
#define MT_MODS(mt) ((((mt)>>8)&0x10) ? (((mt)>>4)&0xF0) : (((mt)>>8)&0x0F)) // get correct (L/R) mod mask
#define OSM_MODS(osm) ((osm)&0xFF) // OSM uses 8 mod bits instead of 5 like MT

#define IS_VOL_KEY(kc) ( (kc) == KC_MUTE || (kc) == KC_VOLD || (kc) == KC_VOLU)
#define IS_MED_KEY(kc) ( (kc) == KC_MPRV || (kc) == KC_MNXT || (kc) == KC_MPLY || (kc) == KC_MSTP )
#define IS_RGB_KEY(kc) (((kc) >= RGB_TOG && (kc) <= RGB_MODE_RGBTEST) || (kc) == RGB_MODE_TWINKLE || (kc) == TOGGLE_LAYER_COLOR || (kc) == KC_LAYERCOLOR || (kc) == KC_LED_INC_BRGT || (kc) == KC_LED_DCR_BRGT )

/* === VSCODE === */
#define IS_VSC_KEY(kc) ( IS_VSC_CURSOR(kc) || IS_VSC_SELECT(kc) || IS_VSC_SIDEBAR(kc) || IS_VSC_PROBLEM(kc) || IS_VSC_FNDSRCH(kc) || IS_VSC_GOTO(kc) || IS_VSC_DEBUG(kc) || IS_VSC_REFNCE(kc) || IS_VSC_REFAC(kc) || IS_VSC_EDTFCS(kc) || IS_VSC_EDTSPLT(kc) )
#define IS_VSC_CURSOR(kc) ( (kc) == VSC_BACK || (kc) == VSC_FWRD )
#define IS_VSC_SELECT(kc) ( (kc) == VSC_SEL_EXPND || (kc) == VSC_SEL_SHRNK || (kc) == VSC_SEL_LINE )
#define IS_VSC_SIDEBAR(kc) ( (kc) == VSC_SB_EXPLR || (kc) == VSC_SB_SEARC || (kc) == VSC_SB_DEBUG || (kc) == VSC_SB_SRCTL || (kc) == VSC_BP_TERML || (kc) == VSC_BP_PRBLM )

#define IS_VSC_PROBLEM(kc) ( (kc) == VSC_PROB_PREV || (kc) == VSC_PROB_NEXT )
#define IS_VSC_FNDSRCH(kc) ( (kc) == VSC_FIND || (kc) == VSC_FIND_PREV || (kc) == VSC_FIND_NEXT )
#define IS_VSC_GOTO(kc) ( (kc) == VSC_GOTO_SYMB || (kc) == VSC_GOTO_LINE )

#define IS_VSC_DEBUG(kc) ( (kc) == VSC_DBG_RUN || (kc) == VSC_DBG_BRKP || (kc) == VSC_DBG_OVR || (kc) == VSC_DBG_IN )
#define IS_VSC_REFNCE(kc) ( (kc) == VSC_GOTO_DEF || (kc) == VSC_PEEK_DEF || (kc) == VSC_SHOW_REF )
#define IS_VSC_REFAC(kc) ( (kc) == VSC_RENAME )
#define IS_VSC_EDTFCS(kc) ( (kc) == VSC_FCS_G_PREV || (kc) == VSC_FCS_G_NEXT || (kc) == VSC_MV_EDTR_LFT || (kc) == VSC_MV_EDTR_RGT )
#define IS_VSC_EDTSPLT(kc) ( (kc) == VSC_EDTR_SPLT || (kc) == VSC_TOGL_VRT_HRZ || (kc) == VSC_MV_EDTR_G_LFT || (kc) == VSC_MV_EDTR_G_RGT )

/*
  === FUNCTIONS ===
*/

#define SHIFT_OVERRIDE(kc, ovrrde) ko_make_basic(MOD_MASK_SHIFT, (kc), (ovrrde));
#define ALT_OVERRIDE(kc, ovrrde) ko_make_basic(MOD_MASK_ALT, (kc), (ovrrde));
#define MEH_OVERRIDE(kc, ovrrde) ko_make_basic(MOD_MASK_MEH, (kc), (ovrrde));


// Need to refactor before removing
#define LK_SPACE_BAR LT(_ADJUST, KC_CAPSLOCK)
