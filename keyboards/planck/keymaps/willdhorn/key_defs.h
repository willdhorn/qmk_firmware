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
// TAP DANCE
#define OSX_APP_PREV TD(TD_APPSW_L)
#define OSX_APP_WNDW TD(TD_APPSW_M)
#define OSX_APP_NEXT TD(TD_APPSW_R)

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
    // PDRSISTANT DEFALT LAYER
    KC_QWERTY,
    KC_WORKMAN,
    KC_COLEMAK_DH,
    KC_COLEMAX,
    // RGB
    KC_LAYERCOLOR,
    // VSCODE
    VSC_MV_EDTR_LFT,    // MOVE EDITOR TO LEFT GROUP
    VSC_MV_EDTR_RGT,    // MOVE EDITOR TO RIGHT GROUP
    VSC_FCS_G_PREV,     // FOCUS ON PREVIOUS GROUP
    VSC_FCS_G_NEXT,     // FOCUS ON NEXT GROUP
    VSC_MV_EDTR_G_LFT,  // MOVE EDITOR GROUP LEFT
    VSC_MV_EDTR_G_RGT,  // MOVE EDITOR GROUP RIGHT
    VSC_OPN_DEF_SIDE,    // OPEN DEFINITION IN OPPOSITE GROUP
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

// .,;?!'"()@
#define IS_SYM_COMMON(kc) ((kc) == KC_DOT || (kc) == KC_COMM || (kc) == KC_SCLN || (kc) == KC_QUES || (kc) == KC_EXLM || (kc) == KC_QUOT || (kc) == KC_DQUO || (kc) == KC_LPRN || (kc) == KC_RPRN || (kc) == KC_AT)
// {}[]
#define IS_SYM_BRACKET(kc) ( (kc) == KC_LBRC || (kc) == KC_RBRC || (kc) == KC_LCBR || (kc) == KC_RCBR )
// =_+-*/&|%<>
#define IS_SYM_PROGRAM(kc) ( (kc) == KC_EQL || (kc) == KC_UNDS || (kc) == KC_PLUS || (kc) == KC_MINS || (kc) == KC_ASTR || (kc) == KC_SLSH || (kc) == KC_AMPR || (kc) == KC_PIPE || (kc) == KC_PERC || (kc) == KC_LABK || (kc) == KC_RABK )
// \^$#~`
#define IS_SYM_OTHER(kc) ( (kc) == KC_BSLS || (kc) == KC_CRRT || (kc) == KC_DLR || (kc) == KC_HASH || (kc) == KC_TILD || (kc) == KC_GRV )

#define IS_NUMBER(kc) (KC_1 <= (kc) && (kc) <= KC_0) // ignores num pad keys
#define IS_ARROW(kc) (KC_RIGHT <= (kc) && (kc) <= KC_UP)
#define IS_NAV_SC(kc) ((kc) == S_TABL || (kc) == S_TABR)

// Mods set top 3 bits (6,7,8) to indicate mod and bits 1 and 2 are used for mod encoding (non one-hot)
#define IS_MOD_KEY(kc) (((kc>>5) & 0x07) == 0x07)

#define IS_MO_LAYER(kc) ((kc) >= QK_MOMENTARY && (kc) <= QK_MOMENTARY_MAX)
#define IS_DF_LAYER(kc) ((kc) >= QK_DEF_LAYER && (kc) <= QK_DEF_LAYER_MAX)
#define IS_LT_LAYER(kc) ((kc) >= QK_LAYER_TAP && (kc) <= QK_LAYER_TAP_MAX)
#define IS_OSL_LAYER(kc) ((kc) >= QK_ONE_SHOT_LAYER && (kc) <= QK_ONE_SHOT_LAYER_MAX)
#define IS_TAP_DANCE(kc) ((kc) >= QK_TAP_DANCE && (kc) <= QK_TAP_DANCE_MAX)
#define IS_MOD_TAP(kc) ((kc) >= QK_MOD_TAP && (kc) <= QK_MOD_TAP_MAX)

#define MT_KEYCODE(mt) ((mt)&0xFF)
#define MT_MODS(mt) ((((mt)>>8)&0x10) ? (((mt)>>4)&0xF0) : (((mt)>>8)&0x0F)) // get correct (L/R) mod mask 
#define LT_KEYCODE(lt) ((lt)&0xFF)
#define LT_LAYER(lt) ((lt>>8)&0xF)

#define IS_VOL_KEY(kc) ( (kc) == KC_MUTE || (kc) == KC_VOLD || (kc) == KC_VOLU)
#define IS_MED_KEY(kc) ( (kc) == KC_MPRV || (kc) == KC_MNXT || (kc) == KC_MPLY || (kc) == KC_MSTP )
#define IS_RGB_KEY(kc) (((kc) >= RGB_TOG && (kc) <= RGB_MODE_RGBTEST) || (kc) == RGB_MODE_TWINKLE || (kc) == TOGGLE_LAYER_COLOR || (kc) == KC_LAYERCOLOR)

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
#define IS_VSC_EDTFCS(kc) ( (kc) == VSC_FCS_G_PREV || (kc) == VSC_FCS_G_NEXT )
#define IS_VSC_EDTSPLT(kc) ( (kc) == VSC_EDTR_SPLT || (kc) == VSC_TOGL_VRT_HRZ || (kc) == VSC_MV_EDTR_LFT || (kc) == VSC_MV_EDTR_RGT || (kc) == VSC_MV_EDTR_G_LFT || (kc) == VSC_MV_EDTR_G_RGT )

/*
  === FUNCTION DECLARATIONS ===
*/

// Functions for handling vscode short cut sequences
void two_tap(uint16_t kc1, uint16_t kc2);
void vscode_chord(uint16_t kc);

// Alt-Tab mode handler
void handle_alt_tab_mode(uint16_t kc);