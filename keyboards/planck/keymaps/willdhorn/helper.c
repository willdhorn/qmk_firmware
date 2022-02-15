#include QMK_KEYBOARD_H
#include <stdint.h>

#include "config.h"
#include "helper.h"
#include "key_defs.h"
#include "layers.h"
#include "layouts.h"
#include "rgb_stuff.h"
#include "tap_dances.h"
#include "user_debug.h"

// Flags for mod tap lighting effects
extern uint16_t mod_tap_timer;
extern uint8_t mod_tap_active;

uint8_t shift_down = 0;

void process_shift_state(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;

    if (keycode ==  OSM(MOD_LSFT)|| keycode == KC_LSFT) {
        if (pressed) {
            shift_down += 1;
        } else {
            shift_down -= (shift_down > 0) ? 1 : 0;
        }
    }
    dprintf("Shift state: %d\n", shift_down);
}

void process_mod_tap_keys(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;

    if (IS_MOD_TAP(keycode)) {
        if (pressed) {
            mod_tap_timer = record->event.time;
            mod_tap_active += 1;
        } else {
            mod_tap_active -= 1;
        }
    }
}

void process_default_layer_keys(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef ENABLE_LAYOUT_QWERTY
        case KC_QWERTY:
            set_single_persistent_default_layer(_QWERTY);
            break;
#endif
#ifdef ENABLE_LAYOUT_COLEMAK
        case KC_COLEMAK_DH:
            set_single_persistent_default_layer(_COLEMAK_DH);
            break;
#endif
#ifdef ENABLE_LAYOUT_ISRT
        case KC_ISRT:
            set_single_persistent_default_layer(_ISRT);
            break;
#endif
#ifdef ENABLE_LAYOUT_WORKMAN
        case KC_WORKMAN:
            set_single_persistent_default_layer(_WORKMAN);
            break;
#endif
      default: break;
    }
}

void process_led_keys(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;

    // Toggle layer coloring"
    switch (keycode) {
        case KC_LAYERCOLOR:
            if (pressed) {
                toggle_color_mode();
            }
            break;
        // Control led brightness
        case KC_LED_INC_BRGT:
            if (pressed) {
                increase_led_brightness();
            }
            break;
        case KC_LED_DCR_BRGT:
            if (pressed) {
                decrease_led_brightness();
            }
            break;
      default: break;
    }
}
// VSCode keys for chorded shortcuts (cmd-k used as leader)
void process_vscode_keys(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;

    switch (keycode) {
        // Move current editor to left/right group
        case VSC_MV_EDTR_LFT:
            if (pressed) {
                vscode_chord(ALT(KC_LEFT));
            }
            break;
        case VSC_MV_EDTR_RGT:
            if (pressed) {
                vscode_chord(ALT(KC_RIGHT));
            }
            break;
        // Switch focus to prev/next group
        case VSC_FCS_G_PREV:
            if (pressed) {
                vscode_chord(CMD(KC_LEFT));
            }
            break;
        case VSC_FCS_G_NEXT:
            if (pressed) {
                vscode_chord(CMD(KC_RIGHT));
            }
            break;
        // Move the entire editor group to the left/right
        case VSC_MV_EDTR_G_LFT:
            if (pressed) {
                vscode_chord(KC_LEFT);
            }
            break;
        case VSC_MV_EDTR_G_RGT:
            if (pressed) {
                vscode_chord(KC_RIGHT);
            }
            break;
        // Open statement definition to the side
        case VSC_OPN_DEF_SIDE:
            if (pressed) {
                vscode_chord(KC_F12);
            }
           break;
      default: break;
    }
}

void vscode_chord(uint16_t kc) {
    two_tap(CMD(KC_K), kc);
}

void two_tap(uint16_t kc1, uint16_t kc2) {
    tap_code16(kc1);
    tap_code16(kc2);
}
