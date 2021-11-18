#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif
#include <stdint.h>
#include "eeprom.h"
// #include "keymap_us_international.h"
#include "print.h"

#include "layouts.h"
#include "rgb.h"
#include "user_debug.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_QWERTY]  = LAYER_QWERTY,
                                                              [_COLEMAK] = LAYER_COLEMAK,
                                                              [_NUM_NAV] = LAYER_NUM_NAV,
                                                              [_SYMBOLS] = LAYER_SYMBOLS,
                                                              [_CMD]     = LAYER_COMMAND,
                                                              [_WIN_CTL] = LAYER_WIN_CTL,
                                                              [_ADJUST]  = LAYER_ADJUST};

const HSV layer_colors[] = {[_QWERTY]  = CL_QWERTY,
                            [_COLEMAK] = CL_COLEMAK,
                            [_NUM_NAV] = CL_NUM_NAV,
                            [_SYMBOLS] = CL_SYMBOLS,
                            [_CMD]     = CL_CMD,
                            [_WIN_CTL] = CL_WIN_CTL,
                            [_ADJUST]  = CL_ADJUST};

extern bool         g_suspend_state;
extern rgb_config_t rgb_matrix_config;
extern led_config_t g_led_config;

bool layer_stack_color = true;

void keyboard_post_init_user(void) {
    // debug_enable = true;
    //    debug_matrix = true;
    print("Finalizing initialization.\n");
    dprint("Debug enabled.\n");
    rgb_matrix_enable();
    print("RGB matrix enabled.\n");
    set_default_layer_colors(default_layer_state);
}

void rgb_matrix_indicators_user(void) { 
    set_all_layer_colors(layer_state); 
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;
    switch (keycode) {
        // Keycodes defined in planck_keycodes
        // Toggle layer coloring
        case KC_LAYERCOLOR:
            if (pressed) {
                layer_stack_color = !layer_stack_color;
            }
            break;
        // VSCode keys for chorded shortcuts (cmd-k used as leader)
        case VSC_MV_EDTR_LFT:
            vscode_chord(ALT(KC_LEFT));
            break;
        case VSC_MV_EDTR_RGT:
            vscode_chord(ALT(KC_RIGHT));
            break;
        case VSC_FCS_G_PREV:
            vscode_chord(CMD(KC_LEFT));
            break;
        case VSC_FCS_G_NEXT:
            vscode_chord(CMD(KC_RIGHT));
            break;
        case VSC_OPN_DEF_SIDE:
            vscode_chord(KC_F12);
            break;
        
        default:
            // flash the right when caps lock is on light anytime a key is pressed
            if (host_keyboard_led_state().caps_lock) {
              planck_ez_left_led_level(255);
                if (pressed) {
                    planck_ez_right_led_level(255);
                } else {
                    planck_ez_right_led_level(0);
                }
            } else {
                planck_ez_right_led_level(0);
                planck_ez_left_led_level(0);
            }
            break;
    }

#ifdef DEBUG_KEYCODE_PRINT
    if (pressed) {
        DEBUG_KEYCODE_HEX(keycode);
        DEBUG_KEYCODE_BINARY(keycode);
    }
#endif

    return true;
}

void vscode_chord(uint16_t kc) { 
    two_tap(CMD(KC_K), kc);
}


void two_tap(uint16_t kc1, uint16_t kc2) {
    tap_code16(kc1);
    tap_code16(kc2);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _WIN_CTL, _CMD, _ADJUST);
    return state;
}

uint8_t g_active_layer = 0;
void    set_g_active_layer(layer_state_t state) {
    for (uint8_t i = _MAX_LAYER_ - 1; i >= 0; i--) {
        if (layer_state_cmp(state, i)) {
            g_active_layer = i;
            dprintf("active layer: %d\n", g_active_layer);
            break;
        }
    }
}

/*
 User functions for handling layer colors
*/
void set_default_layer_colors(layer_state_t state) {
    for (int layer = 0; layer < _DEFAULT_RANGE_; layer++) {
        if (layer_state_cmp(state, layer)) {
            dprintf("\nDefault layer is %04X ", layer);
            set_layer_color(layer, layer_colors[layer]);
        }
    }
}

void set_all_layer_colors(layer_state_t state) {
    set_g_active_layer(state);
    set_default_layer_colors(default_layer_state);

    for (uint8_t layer = _DEFAULT_RANGE_; layer <= g_active_layer + 1; layer++) {
        if (layer_state_cmp(state, layer)) {
            set_layer_color(layer, layer_colors[layer]);
        }
    }
}

void set_layer_color(int layer, HSV color) {
    color.s -= g_active_layer > 0 ? C_SAT_DIM_FACTOR * (g_active_layer - layer) : 0;
    color.v -= g_active_layer > 0 ? C_VAL_DIM_FACTOR * (g_active_layer - layer) : 0;
    if (layer_stack_color) {
        for (int r = 0; r < MATRIX_ROWS; r++) {
            for (int c = 0; c < MATRIX_COLS; c++) {
                int index = g_led_config.matrix_co[r][c];
                if (index != NO_LED) {
                    uint16_t kc = pgm_read_word(&keymaps[layer][r][c]);
#ifdef DEBUG_LAYER_COLOR
                    dprintf("Keycode: 0x%04X\n", kc);
#endif
                    switch (kc) {
                        case KC_TRANSPARENT:
                            break;
                        case KC_NO:
                            set_key_layer_color(index, layer, C_BLACK);
                            break;
                        case RESET:
                            set_key_layer_color(index, layer, C_RED);
                            break;
                        case DEBUG:
                            set_key_layer_color(index, layer, C_GREEN);
                            break;
                        default:
                            if (IS_LETTER(kc)) {
                                set_key_layer_color(index, layer, CF_PALE(color));
                            // } else if(IS_MO_LAYER(kc)) {
                            //     set_key_layer_color(index, layer, CF_OPPO(color));
                            } else if (IS_MOD_TAP(kc)) {
                                set_key_layer_color(index, layer, C_RED);
                            } else {
                                set_key_layer_color(index, layer, color);
                            }
                            break;
                    }
                }
            }
        }
    }
#ifdef DEBUG_LAYER_COLOR
    else {
        dprintf("\nlayer_stack_color NOT ENABLED\n");
    }
#endif
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

// Audio and Music

#ifdef AUDIO_ENABLE
bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo += 1;
            } else {
                muse_tempo -= 1;
            }
        }
    } else {
        if (clockwise) {
#    ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
#    else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
#    endif
        } else {
#    ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
#    else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
#    endif
        }
    }
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}
#endif

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}
