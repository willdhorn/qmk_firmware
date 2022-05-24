#pragma once

#include "willdhorn.h"

enum custom_keycodes {
  // UTILITY KEYS
  KC_EMPTY = EZ_SAFE_RANGE,
  KC_CLEAR_MODS,
  // PERSISTANT DEFALT LAYER
  KC_QWERTY,
  KC_COLEMAK_DH,
  KC_ISRT,

  // MACRO KEYS
  MCR_NEQL,
  MCR_SLUP,
  MCR_TILD,

  // // CALLUM MODS
  // OS_SHFT,
  // OS_CTRL,
  // OS_ALT,
  // OS_CMD,

// RGB
#ifdef RGB_ENABLE
  KC_LAYERCOLOR,
  KC_LED_INC_BRGT,
  KC_LED_DCR_BRGT,
#endif
  // VSCODE
  VSC_MV_EDTR_LFT,   // MOVE EDITOR TO LEFT GROUP
  VSC_MV_EDTR_RGT,   // MOVE EDITOR TO RIGHT GROUP
  VSC_FCS_G_PREV,    // FOCUS ON PREVIOUS GROUP
  VSC_FCS_G_NEXT,    // FOCUS ON NEXT GROUP
  VSC_MV_EDTR_G_LFT, // MOVE EDITOR GROUP LEFT
  VSC_MV_EDTR_G_RGT, // MOVE EDITOR GROUP RIGHT
  VSC_OPN_DEF_SIDE,  // OPEN DEFINITION IN OPPOSITE GROUP
  // Custom Layer Macro keys for Tap-Hold
  LAYER_FN_DEF,
  LAYER_FN_NAV,
  LAYER_FN_SYM,
};

// Custom Mod-Taps
#define MTX(n) LT(0, n)
// #define mtCmd_Comma MTX(1)
// #define mtAlt_Period MTX(2)
// #define mtCtl_Quote MTX(3)
