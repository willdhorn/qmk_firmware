#pragma once

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h and rules.mk options at
  https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

// Layout switch
// #define KB_LAYOUT_STANDARD  // otherwise, use split layout

// Default layouts
#define ENABLE_LAYOUT_QWERTY
#define ENABLE_LAYOUT_COLEMAK
#define ENABLE_LAYOUT_ISRT

#undef ENABLE_LAYOUT_WORKMAN

// Key Behaviour
#undef TAPPING_TERM
#define TAPPING_TERM 220

#define TAPPING_TERM_PER_KEY
#define RETRO_TAPPING_PER_KEY
#define SPACE_RETRO_TAP_TERM 250

#define COMBO_COUNT 1

// !! ABSOLUTELY NEEDED FOR HOME ROW MODS !!
#define IGNORE_MOD_TAP_INTERRPT
// #define TAPPING_FORCE_HOLD
// This should make accidental mod triggers less likely
// '#define BILATERAL_COMBINATIONS 400

// #define TAPPING_TOGGLE 1

// ONESHOT CONFIGS
#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 3000

// DEBUG FLAGS
#define DEBUG_KEYCODE_PRINT
// #define DEBUG_LAYER_PRINT
#define DEBUG_TAP_DANCE

// Disable deprecated features for binary size
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// USB Startup (no delay)
#define USB_SUSPEND_WAKEUP_DELAY 0

#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50

// RGB Matrix
#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 900000

#define RGB_MATRIX_STARTUP_SPD 60

#undef ORYX_CONFIGURATOR
// // ORYX_CONFIGURATOR must be defined for the following to work
// #define PLANCK_EZ_LED_LOWER 3
// #define PLANCK_EZ_LED_RAISE 4
// #define PLANCK_EZ_LED_ADJUST 7
#define PLANCK_EZ_USER_LEDS

// Mouse keys
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 50

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 20

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 75

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 6

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 75

// Audio
#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)
#    define MIDI_BASIC
#endif
