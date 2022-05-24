#pragma once

#include "willdhorn.h"

// clang-format off

/* === TYPING === */

#define IS_LETTER(kc) (KC_A <= (kc) && (kc) <= KC_Z)
#define IS_NUMBER(kc) (KC_1 <= (kc) && (kc) <= KC_0) // ignores num pad keys
#define IS_SYSTEM_KEY(kc) ( \
  (kc) == KC_BACKSPACE || \
  (kc) == KC_ENTER || \
  (kc) == KC_TAB || \
  (kc) == KC_ESCAPE || \
  (kc) == KC_SPACE || \
  (kc) == kSpace \
)

// .,;:?!'"
#define IS_SYM_PUNCTUATION(kc) ( \
  (kc) == KC_DOT || \
  (kc) == KC_COMM || \
  (kc) == KC_SCLN || \
  (kc) == KC_COLN || \
  (kc) == KC_QUES || \
  (kc) == KC_EXLM || \
  (kc) == KC_QUOT || \
  (kc) == KC_DQUO )

// (){}[]<>
#define IS_SYM_PAREN(kc) ( \
  (kc) == KC_LPRN || \
  (kc) == KC_RPRN || \
  (kc) == KC_LBRC || \
  (kc) == KC_RBRC || \
  (kc) == KC_LCBR || \
  (kc) == KC_RCBR || \
  (kc) == KC_LABK || \
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
  (kc) == KC_PLUS || \
  (kc) == KC_MINS || \
  (kc) == KC_ASTR || \
  (kc) == KC_SLSH )
// ^$#~`
#define IS_SYM_SPECIAL(kc) ( \
  (kc) == KC_CRRT || \
  (kc) == KC_DLR || \
  (kc) == KC_AT || \
  (kc) == KC_TILD || \
  (kc) == KC_GRV )

/* === SYSTEM === */

#define IS_ARROW(kc) ((KC_RIGHT <= (kc) && (kc) <= KC_UP) )

#define IS_NAV_SC(kc) ((kc) == S_TABL || \
  (kc) == S_TABR || \
  (kc) == OSX_HOME || \
  (kc) == OSX_END \
)

#define IS_SYSTEM_SC(kc) ( \
  (kc) == S_UNDO || \
  (kc) == S_CUT || \
  (kc) == S_COPY || \
  (kc) == S_PASTE || \
  (kc) == S_CLIPBOARD || \
  (kc) == S_SNIPPETS \
)

#define IS_DESKTOP_KEY(kc) ( \
    (kc) == OSX_APP_NEXT \
)

/* === LAYERS === */

#define IS_LAYER_KEY(kc) (IS_MO_LAYER(kc) || IS_TO_LAYER(kc) || IS_DF_LAYER(kc) || IS_LT_LAYER(kc) || IS_OSL_LAYER(kc) || IS_CUSTOM_LK(kc))

#define IS_MO_LAYER(kc) ((kc) >= QK_MOMENTARY && (kc) <= QK_MOMENTARY_MAX)
#define IS_TO_LAYER(kc) ((kc) >= QK_TO && (kc) <= QK_TO_MAX)
#define IS_DF_LAYER(kc) ((kc) >= QK_DEF_LAYER && (kc) <= QK_DEF_LAYER_MAX)
#define IS_LT_LAYER(kc) ((kc) >= QK_LAYER_TAP && (kc) <= QK_LAYER_TAP_MAX)
#define IS_OSL_LAYER(kc) ((kc) >= QK_ONE_SHOT_LAYER && (kc) <= QK_ONE_SHOT_LAYER_MAX)
#define IS_CUSTOM_LK(kc) ( \
    (kc) == LAYER_FN_DEF || \
    (kc) == LAYER_FN_NAV || \
    (kc) == LAYER_FN_SYM \
)

#define LT_KEYCODE(lt) ((lt)&0xFF)
#define LT_LAYER(lt) ((lt>>8)&0xF)
// clang-format on

/* === MODS === */

// Mods set top 3 bits (6,7,8) to indicate mod and bits 1 and 2 are used for mod encoding (non one-hot)
#define IS_MOD_KEY(kc) ((((kc) >> 5) & 0x07) == 0x07)

#define IS_MOD_TAP(kc) ((kc) >= QK_MOD_TAP && (kc) <= QK_MOD_TAP_MAX)
#define IS_OSM(kc) ((kc) >= QK_ONE_SHOT_MOD && (kc) <= QK_ONE_SHOT_MOD_MAX)

#define MT_KEYCODE(mt) ((mt)&0xFF)
#define MT_MODS(mt) ((((mt) >> 8) & 0x10) ? (((mt) >> 4) & 0xF0) : (((mt) >> 8) & 0x0F)) // get correct (L/R) mod mask
#define OSM_MODS(osm) ((osm)&0xFF)                                                       // OSM uses 8 mod bits instead of 5 like MT

/* === OTHER QUANTUM === */

#define IS_TAP_DANCE(kc) ((kc) >= QK_TAP_DANCE && (kc) <= QK_TAP_DANCE_MAX)

/* === MEDIA === */

#define IS_VOL_KEY(kc) ((kc) == KC_MUTE || (kc) == KC_VOLD || (kc) == KC_VOLU)
#define IS_MED_KEY(kc) ((kc) == KC_MPRV || (kc) == KC_MNXT || (kc) == KC_MPLY || (kc) == KC_MSTP)
#define IS_RGB_KEY(kc) (((kc) >= RGB_TOG && (kc) <= RGB_MODE_RGBTEST) || (kc) == RGB_MODE_TWINKLE || (kc) == TOGGLE_LAYER_COLOR || (kc) == KC_LAYERCOLOR || (kc) == KC_LED_INC_BRGT || (kc) == KC_LED_DCR_BRGT)

/* === VSCODE === */
#define IS_VSC_KEY(kc) (IS_VSC_CURSOR(kc) || IS_VSC_SELECT(kc) || IS_VSC_SIDEBAR(kc) || IS_VSC_PROBLEM(kc) || IS_VSC_FNDSRCH(kc) || IS_VSC_GOTO(kc) || IS_VSC_DEBUG(kc) || IS_VSC_REFNCE(kc) || IS_VSC_REFAC(kc) || IS_VSC_EDTFCS(kc) || IS_VSC_EDTSPLT(kc))
#define IS_VSC_CURSOR(kc) ((kc) == VSC_BACK || (kc) == VSC_FWRD)
#define IS_VSC_SELECT(kc) ((kc) == VSC_SEL_EXPND || (kc) == VSC_SEL_SHRNK || (kc) == VSC_SEL_LINE)
#define IS_VSC_SIDEBAR(kc) ((kc) == VSC_SB_EXPLR || (kc) == VSC_SB_SEARC || (kc) == VSC_SB_DEBUG || (kc) == VSC_SB_SRCTL || (kc) == VSC_BP_TERML || (kc) == VSC_BP_PRBLM)

#define IS_VSC_PROBLEM(kc) ((kc) == VSC_PROB_PREV || (kc) == VSC_PROB_NEXT)
#define IS_VSC_FNDSRCH(kc) ((kc) == VSC_FIND || (kc) == VSC_FIND_PREV || (kc) == VSC_FIND_NEXT)
#define IS_VSC_GOTO(kc) ((kc) == VSC_GOTO_SYMB || (kc) == VSC_GOTO_LINE)

#define IS_VSC_DEBUG(kc) ((kc) == VSC_DBG_RUN || (kc) == VSC_DBG_BRKP || (kc) == VSC_DBG_OVR || (kc) == VSC_DBG_IN)
#define IS_VSC_REFNCE(kc) ((kc) == VSC_GOTO_DEF || (kc) == VSC_PEEK_DEF || (kc) == VSC_SHOW_REF)
#define IS_VSC_REFAC(kc) ((kc) == VSC_RENAME)
#define IS_VSC_EDTFCS(kc) ((kc) == VSC_FCS_G_PREV || (kc) == VSC_FCS_G_NEXT || (kc) == VSC_MV_EDTR_LFT || (kc) == VSC_MV_EDTR_RGT)
#define IS_VSC_EDTSPLT(kc) ((kc) == VSC_EDTR_SPLT || (kc) == VSC_TOGL_VRT_HRZ || (kc) == VSC_MV_EDTR_G_LFT || (kc) == VSC_MV_EDTR_G_RGT)
