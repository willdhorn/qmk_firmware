#include QMK_KEYBOARD_H
#include "print.h"

#include "willdhorn.h"

// clang-format off
const HSV layer_colors[] = {
  [_QWERTY]      =  CL_QWERTY,
  [_COLEMAK_DH]  =  CL_COLEMAK_DH,
  [_ISRT]        =  CL_ISRT,
  [_EXT]         =  CL_EXT,
  [_SYM]         =  CL_SYM,
  [_NUM]         =  CL_NUM,
  [_VSCODE]      =  CL_VSCODE,
  [_DESKTOP]     =  CL_DESKTOP,
  [_WNDW_HALF]   =  CL_WNDW_HALF,
  [_WNDW_QUAD]   =  CL_WNDW_QUAD,
  [_WNDW_VERT]   =  CL_WNDW_VERT,
  [_WNDW_THRD]   =  CL_WNDW_THRD,
  [_WNDW_SIXT]   =  CL_WNDW_SIXT,
  [_WNDW_NINT]   =  CL_WNDW_NINT,
  [_ADJUST]      =  CL_ADJUST
};
// clang-format on

bool layer_stack_color = true;
#ifdef DEBUG_LAYER_PRINT
uint8_t print_lock = 0;
#endif

uint8_t  g_active_layer   = 0;
uint8_t  brightness_level = 255;
HSV      top_layer_color;
extern uint16_t mod_tap_timer;
extern uint8_t  mod_tap_active;

void set_g_active_layer(layer_state_t state) {
  for (uint8_t i = _MAX_LAYER_ - 1; i >= 0; i--) {
    if (layer_state_cmp(state, i)) {
      g_active_layer = i;
#ifdef DEBUG_LAYER_PRINT
      print_lock = (print_lock + 1);
      if (print_lock == 0) {
        dprintf("top active layer: %d\n", g_active_layer);
      }
#endif
      break;
    }
  }
}

/*
  === User functions for handling layer colors ===
*/
void set_default_layer_colors(layer_state_t state) {
  for (int layer = 0; layer < _DEFAULT_RANGE_; layer++) {
    if (layer_state_cmp(state, layer)) {
#ifdef DEBUG_LAYER_PRINT
      if (print_lock == 0) {
        dprintf("\n\ndefault layer: %04X\n", layer);
      }
#endif
      if (g_active_layer < _DEFAULT_RANGE_) {
        top_layer_color = layer_colors[layer];
      }
      set_layer_color(layer, layer_colors[layer]);
    }
  }
}

void set_all_layer_colors(layer_state_t state) {
  set_g_active_layer(state);
  top_layer_color = layer_colors[g_active_layer];
  set_default_layer_colors(default_layer_state);

  for (int8_t layer = _DEFAULT_RANGE_; layer <= g_active_layer + 1; layer++) {
    if (layer_state_cmp(state, layer)) {
      set_layer_color(layer, layer_colors[layer]);
    }
  }
}

// Call this function layer by layer from the bottom up
void set_layer_color(int layer, HSV color) {
  // bool is_default   = (layer < _DEFAULT_RANGE_);
  // bool is_top_layer = is_default ? g_active_layer == 0 : g_active_layer == layer;
#ifdef DEBUG_LAYER_PRINT
  if (print_lock == 0) {
    dprintf("[layer %d]\n", layer);
    dprintf("  is_default=%s\n", (is_default ? "true" : "false"));
    dprintf("  is_top_layer=%s\n", (is_top_layer ? "true" : "false"));
  }
#endif
  if (layer_stack_color) {
    for (int r = 0; r < MATRIX_ROWS; r++) {
      for (int c = 0; c < MATRIX_COLS; c++) {
        int index = g_led_config.matrix_co[r][c];
        if (index != NO_LED) {
          // get kecode at the current position
          uint16_t kc = pgm_read_word(&keymaps[layer][r][c]);
          if (kc != KC_TRANSPARENT) {
            HSV keyColor = get_keycode_color(kc, color);

            // if (!is_top_layer) {
            //     if (is_default && kc != KC_EMPTY) {
            //         keyColor = C_BLACK;
            //     } else {
            //         // dim colors in lower layers based on 'height'
            //         uint8_t satDim = g_active_layer > 0 ? C_SAT_DIM_FACTOR * (g_active_layer - layer) : 0;
            //         keyColor.s = F_SUB(keyColor.s, satDim);
            //         uint8_t valDim = g_active_layer > 0 ? C_VAL_DIM_FACTOR * (g_active_layer - layer) : 0;
            //         keyColor.v = F_SUB(keyColor.v, valDim);
            //     }
            // }

            keyColor.v = F_SUB(brightness_level, (255 - keyColor.v));
            set_key_layer_color(index, layer, keyColor);
          }
        }
      }
    }
  }
}

HSV get_keycode_color(uint16_t kc, HSV layer_color) {
  switch (kc) {
    case KC_NO:
      return C_BLACK;
    case KC_EMPTY:
      return CK_EMPTY;
    case RESET:
      return C_RED;
    case DEBUG:
      return C_GREEN;
    case S_SNIPPETS:
    case S_PALETTE:
    case S_ALFRED:
      return C_PURPLE;
    // WINDOW ARRANGEMENT LAYER KEYS
    case WNDW_LAYER_H:
      return CL_WNDW_HALF;
    case WNDW_LAYER_Q:
      return CL_WNDW_QUAD;
    case WNDW_LAYER_V:
      return CL_WNDW_VERT;
    case WNDW_LAYER_3:
      return CL_WNDW_THRD;
    case WNDW_LAYER_6:
      return CL_WNDW_SIXT;
    case WNDW_LAYER_9:
      return CL_WNDW_NINT;
    // DEFAULT LAYER
    case KC_QWERTY:
      return CF_PALE(CL_QWERTY);
    case KC_COLEMAK_DH:
      return CF_PALE(CL_COLEMAK_DH);
    case KC_ISRT:
      return CF_PALE(CL_ISRT);
  }

  if (IS_LETTER(kc)) {
    return CK_LETTERS(layer_color);
  } else if (IS_NUMBER(kc)) {
    return CK_NUMBERS;
  } else if (IS_ARROW(kc)) {
    return CK_NAV;
  } else if (IS_NAV_SC(kc)) {
    return CK_NAV_SC;
  } else if (IS_SYSTEM_SC(kc)) {
    return CK_SYS_SC;
  }

  /* Symbols */
  else if (IS_SYM_PUNCTUATION(kc)) {
    return CK_SYM_PUNC;
  } else if (IS_SYM_PAREN(kc)) {
    return CK_SYM_PAREN;
  } else if (IS_SYM_PROGRAMMING(kc)) {
    return CK_SYM_PROG;
  } else if (IS_SYM_MATH(kc)) {
    return CK_SYM_MATH;
  } else if (IS_SYM_SPECIAL(kc)) {
    return CK_SYM_SPEC;
  }

  /* Modifiers */
  else if (IS_SYSTEM_KEY(kc)) {
    return CK_SYSTEM;
  } else if (IS_MOD_KEY(kc)) {
    return CK_MODS;
  } else if (IS_MOD_TAP(kc)) {
    if (MT_KEYCODE(kc) == KC_SPACE) {
      return CK_SYSTEM;
    }

    HSV key_color = get_keycode_color(MT_KEYCODE(kc), layer_color);
    if ((~get_mods() & MT_MODS(kc)) == 0) {
      return CF_OPPO(key_color); // This mod key is currently held down
    }
#ifdef BILATERAL_COMBINATIONS
#  if (BILATERAL_COMBINATIONS + 0) // turn mod tap keys red when they can be used on the same hand
    else if (mod_tap_active && timer_elapsed(mod_tap_timer) > BILATERAL_COMBINATIONS) {
      return C_RED;
    }
#  endif
#endif

    // else if (get_mods()) {
    //     return C_WHITE;  // Some other mod key is being held down
    // }
    else {
      return CK_MOD_TAP(key_color); // no mods are active
    }
  } else if (IS_OSM(kc)) {
    uint8_t mods = OSM_MODS(kc);
    if (get_oneshot_mods() & mods) {
      return CK_OSM_ON;
    } else if (get_mods() & mods) {
      return CK_OSM;
    } else {
      return CK_MODS;
    }
  } else if (IS_LAYER_KEY(kc) && kc != LK_SPACE_BAR) {
    return CK_LAYERS;
  } else if (IS_DESKTOP_KEY(kc)) {
    return CL_DESKTOP;
  }
  /* ADJUSTMENTS */
  else if (IS_VOL_KEY(kc)) {
    return CK_ADJ_VOL;
  } else if (IS_MED_KEY(kc)) {
    return CK_ADJ_MED;
  } else if (IS_RGB_KEY(kc)) {
    return CK_ADJ_RGB;
  }
  /* VSCODE */
  else if (IS_VSC_KEY(kc)) {
    if (IS_VSC_CURSOR(kc)) {
      return CK_VSCODE;
    } else if (IS_VSC_FNDSRCH(kc)) {
      return CK_VSCODE;
    } else if (IS_VSC_SELECT(kc)) {
      return CK_VSC_LGT;
    } else if (IS_VSC_PROBLEM(kc)) {
      return CK_VSC_LGT;
    } else if (IS_VSC_GOTO(kc)) {
      return CK_VSC_DRK;
    } else if (IS_VSC_SIDEBAR(kc)) {
      return CK_VSC_SIDEBAR;
    } else if (IS_VSC_DEBUG(kc)) {
      return CK_VSC_DEBUG;
    } else if (IS_VSC_REFNCE(kc)) {
      return CK_VSC_REFNCE;
    } else if (IS_VSC_REFAC(kc)) {
      return CK_VSC_REFAC;
    } else if (IS_VSC_EDTFCS(kc)) {
      return CK_VSC_EDTFCS;
    } else if (IS_VSC_EDTSPLT(kc)) {
      return CK_VSC_EDTSPLT;
    }
  }
  return layer_color;
}

void set_key_layer_color(int index, int layer, HSV hsv) {
#ifdef DEBUG_LAYER_COLOR
  if (hsv.v) {
    dprintf("Setting index %d to (%d,%d,%d)\n", index, hsv.h, hsv.s, hsv.v);
  }
#endif

  RGB   rgb = hsv_to_rgb(hsv);
  float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  rgb_matrix_set_color(index, f * rgb.r, f * rgb.g, f * rgb.b);
}

void toggle_color_mode() {
  layer_stack_color = !layer_stack_color;
}

void increase_led_brightness() {
  brightness_level = F_ADD(brightness_level, LED_BRIGHTNESS_STEP);
}
void decrease_led_brightness() {
  brightness_level = F_SUB(brightness_level, LED_BRIGHTNESS_STEP);
}
