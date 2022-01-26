#pragma once

#include <stdint.h>

#include "quantum.h"

// 16 COLORS THAT ARE VISUALLY DISTINCT
#define H_RED       0
#define H_BLORNG    9
#define H_ORANGE    25
#define H_YELLOW    43
#define H_YGREEN    64
#define H_LIME      73
#define H_GREEN     86
#define H_SEAGREEN  94
#define H_TURQUOISE 107
#define H_CYAN      132
#define H_BLUE      154
#define H_INDIGO    167
#define H_VIOLET    175
#define H_PURPLE    193
#define H_MAGENTA   215
#define H_HOTPINK   241

// COLORS
#define CHSV(h,s,v)    (HSV) {h,s,v}

#define C_RED       CHSV( H_RED, 255, 255 )
#define C_BLORNG    CHSV( H_BLORNG, 255, 255 )
#define C_ORANGE    CHSV( H_ORANGE, 255, 255 )
#define C_YELLOW    CHSV( H_YELLOW, 255, 255 )
#define C_YGREEN    CHSV( H_YGREEN, 255, 255 )
#define C_LIME      CHSV( H_LIME, 255, 255 )
#define C_GREEN     CHSV( H_GREEN, 255, 255 )
#define C_SEAGREEN  CHSV( H_SEAGREEN, 255, 255 )
#define C_TURQUOISE CHSV( H_TURQUOISE, 255, 255 )
#define C_CYAN      CHSV( H_CYAN, 255, 255 ) //
#define C_BLUE      CHSV( H_BLUE, 255, 255 ) // BLUE
#define C_INDIGO    CHSV( H_INDIGO, 255, 255 ) // DEEP BLUE
#define C_VIOLET    CHSV( H_VIOLET, 255, 255 ) // PURPLE
#define C_PURPLE    CHSV( H_PURPLE, 255, 255 ) // DEEP PURPLE
#define C_MAGENTA   CHSV( H_MAGENTA, 255, 255 )
#define C_HOTPINK   CHSV( H_HOTPINK, 255, 255 )

#define C_W(val)    CHSV( 0, 0, val )
#define C_WHITE C_W(255)
#define C_BLACK C_W(0)

/*
  === LAYER COLORS ===
*/

// Default Layers
#define CL_QWERTY           CHSV(12, 200, 170) // Dull pink/beige
#define CL_COLEMAK_DH       CHSV(87, 250, 240) // Green
#define CL_WORKMAN          CHSV(45, 255, 240) // Yellow
#define CL_ISRT             CHSV(170, 255, 240) // Purple

// Additional Layers
#define CL_EXT          C_RED
#define CL_NAV          C_YELLOW
#define CL_SYM          C_BLUE
#define CL_NUM          C_SEAGREEN
#define CL_VSCODE       C_PURPLE
#define CL_ADJUST       C_ORANGE

// Apps/Window Layersr
#define CL_SWITCH       C_MAGENTA
#define CL_WNDW_HALF    C_INDIGO
#define CL_WNDW_QUAD    C_RED
#define CL_WNDW_VERT    C_ORANGE
#define CL_WNDW_THRD    C_GREEN
#define CL_WNDW_SIXT    C_LIME
#define CL_WNDW_NINT    C_YELLOW

/*
  === KEY COLORS ===
*/
#define CK_EMPTY CF_PALE(CF_DIM(top_layer_color))

#define CK_LETTERS(color) ((host_keyboard_led_state().caps_lock) ? (CF_PALE(color)) : (color))
#define CK_MOD_TAP(color) CHSV(color.h, F_SUB(color.s, 50), F_ADD(color.v,100))

// #define CK_MODIFIERS      CF_PALE(C_RED)
//
// #define CK_SYM_COMMON     C_CYAN
// #define CK_SYM_BRACKET    C_TURQUOISE
// #define CK_SYM_PROGRAM    C_INDIGO
// #define CK_SYM_OTHER      C_SEAGREEN
//
// #define CK_NUMBERS        C_GREEN
//
// #define CK_ARROWS         CL_NAV
//
// #define CK_NAV_SC         C_LIME
// #define CK_SYS_SC         C_PURPLE

#define CK_VSCODE         CL_VSCODE
#define CK_VSC_LGT        CHSV(F_H_RGT((CL_VSCODE).h, 10), F_SUB((CL_VSCODE).s, 25), (CL_VSCODE).v)
#define CK_VSC_DRK        CHSV(F_H_LFT((CL_VSCODE).h, 10), (CL_VSCODE).s, F_SUB((CL_VSCODE).v, 25))

#define CK_VSC_SIDEBAR    C_INDIGO
#define CK_VSC_DEBUG      C_MAGENTA
#define CK_VSC_REFNCE     CK_VSCODE
#define CK_VSC_REFAC      CK_VSCODE
#define CK_VSC_EDTFCS     CK_VSC_LGT
#define CK_VSC_EDTSPLT    CK_VSC_DRK

#define CK_ADJ_VOL        CL_ADJUST
#define CK_ADJ_MED        C_BLORNG
#define CK_ADJ_RGB        C_HOTPINK

// THE 16 COLORS ASSIGNED TO DIFFERNT CATEGORIES OF KEYS
#define CK_MODS         C_RED
#define CK_OSM          C_BLORNG
#define CK_NAV          C_YELLOW
#define CK_OSM_ON       C_YELLOW
#define CK_NAV_SC       C_LIME
#define CK_NUMBERS      C_GREEN
#define CK_OSM_LCK      C_GREEN
#define CK_SYM_SPEC     CF_PALE(C_GREEN)
#define CK_SYM_PROG     C_SEAGREEN
#define CK_SYM_PUNC     C_TURQUOISE
#define CK_SYM_PAREN    C_CYAN
#define CK_SYM_MATH     C_BLUE
#define CK_notused      C_VIOLET
#define CK_SYS_SC       C_PURPLE
#define CK_unset        C_MAGENTA
#define CK_LAYERS       C_HOTPINK

#define F_ADD(num, add) (num>=255-add ? 255 : num+add)
#define F_SUB(num, sub) (num<=sub ? 0 : num-sub)
#define F_H_LFT(hue, amt) ((hue-amt)%255)
#define F_H_RGT(hue, amt) ((hue+amt)%255)

#define CF_PALE(color) CHSV((color).h,  (F_SUB((color).s, 50)), (color).v)
#define CF_DIM(color)  CHSV((color).h, (color).s, F_SUB((color).v, 230))
#define CF_BRGT(color) CHSV((color).h, (color).s, F_ADD((color).v, 100))

#define CF_SHFT(color) CHSV(F_H_RGT((color).h, 64), (color).s, F_ADD((color).v, 15))
#define CF_OPPO(color) CHSV(F_H_RGT((color).h, 128), (color).s, (color).v)

#define C_VAL_DIM_FACTOR 10
#define C_SAT_DIM_FACTOR 5

#define LED_BRIGHTNESS_STEP 10

void increase_led_brightness(void);
void decrease_led_brightness(void);
void toggle_color_mode(void);
HSV get_keycode_color(uint16_t, HSV);
void set_key_layer_color(int, int, HSV);
void set_layer_color(int, HSV);
void set_all_layer_colors(layer_state_t);
void set_default_layer_colors(layer_state_t);
void get_active_layer(layer_state_t);
