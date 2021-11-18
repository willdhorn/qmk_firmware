
#pragma once

#include <stdint.h>

// COLORS
#define CHSV(h,s,v)    (HSV) {h,s,v}
// 16 COLORS THAT ARE VISUALLY DISTINCT
#define C_RED       CHSV( 0, 255, 255 )
#define C_BLORNG    CHSV( 9, 255, 255 )
#define C_ORANGE    CHSV( 25, 255, 255 )
#define C_YELLOW    CHSV( 43, 255, 255 )
#define C_YGREEN    CHSV( 64, 255, 255 )
#define C_LIME      CHSV( 73, 255, 255 )
#define C_GREEN     CHSV( 86, 255, 255 )
#define C_SEAGREEN  CHSV( 94, 255, 255 )
#define C_TURQUOISE CHSV( 107, 255, 255 )
#define C_CYAN      CHSV( 132, 255, 255 ) // 
#define C_BLUE      CHSV( 154, 255, 255 ) // BLUE
#define C_INDIGO    CHSV( 167, 255, 255 ) // DEEP BLUE
#define C_VIOLET    CHSV( 175, 255, 255 ) // PURPLE
#define C_PURPLE    CHSV( 193, 255, 255 ) // DEEP PURPLE 
#define C_MAGENTA   CHSV( 215, 255, 255 )
#define C_HOTPINK   CHSV( 241, 255, 255 )

// THE 16 COLORS ASSIGNED TO DIFFERNT CATEGORIES OF KEYS
#define C_MODS      C_RED         // MOD KEYS
#define C_APPNAV    C_BLORNG      // NAVIGATION WITHIN APPS...
#define C_NAVSC     C_ORANGE      // NAVIGATION SHORTCUTS
#define C_NAV       C_YELLOW      // NAVIGATION (GENERAL?)
#define C_MISCSC    C_YGREEN      // MISC SHORTCUTS
#define C_BASESC    C_LIME        // BASE? SHORTCUTS
#define C_APPSC     C_GREEN       // APPLICATION SHORTCUTS
#define C_SYSPEC    C_SEAGREEN    // SPECIAL CHARACTERS
#define C_SYBRACKET C_TURQUOISE   // BRACKETS
#define C_SYPROG    C_CYAN        // PROGRAMMING SYMBOLS   
#define C_SYPARENS  C_BLUE        // PARENS
#define C_SYCOMMON  C_INDIGO      // COMMON SYMBOLS
#define C_SYPUNC    C_VIOLET      // PUNCTION SYMBOLS
#define C_MISC      C_PURPLE      // MISC
#define C_LAYERSW   C_MAGENTA     // LAYER SWITCHING
#define C_CMPLXMOD  C_HOTPINK     // COMPLEX MODS?

#define C_W(val)    CHSV( 0, 0, val )
#define C_WHITE C_W(255) 
#define C_BLACK C_W(0)

#define CL_QWERTY CHSV(30, 255, 255)
#define CL_COLEMAK CHSV(87, 255, 255)
#define CL_SYMBOLS C_INDIGO
#define CL_NUM_NAV C_SEAGREEN
#define CL_NAV C_YELLOW
#define CL_CMD C_PURPLE
#define CL_WIN_CTL C_LIME
#define CL_ADJUST C_BLORNG

#define CF_PALE(color) CHSV(color.h, color.s-50, color.v)
#define CF_OPPO(color) CHSV((color.h+128)%255, color.s, color.v)

#define IS_LETTER(kc) (KC_A <= (kc) && (kc) <= KC_Z)

// Mods set top 3 bits (6,7,8) to indicate mod and bits 1 and 2 are used for mod encoding (non one-hot)
#define IS_MOD_KEY(kc) (((kc>>5) & 0x07) == 0x07)

// Mod tap uses bits 15 and 14 for keycode and 9-12 for mods (one-hot)(w/ 13 for RH mods)
#define IS_MOD_TAP(kc) (((kc>>8)&0x0f) && (((kc>>12)&0x0e)==0x06))

// ALSO TRIGGERS ON CUSTOM (MACRO) KEYS
#define IS_MO_LAYER(kc) ((kc&QK_MOMENTARY) == QK_MOMENTARY)

#define C_VAL_DIM_FACTOR 10
#define C_SAT_DIM_FACTOR 5

void set_key_layer_color(int, int, HSV);
void set_layer_color(int, HSV);
void set_all_layer_colors(layer_state_t);
void set_default_layer_colors(layer_state_t);
void get_active_layer(layer_state_t);
