#pragma once

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h and rules.mk options at
  https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#define RGB_ENABLE

// Layout switch
// #define KB_LAYOUT_STANDARD  // otherwise, use split layout

// Default layouts
#define ENABLE_LAYOUT_QWERTY
#define ENABLE_LAYOUT_COLEMAK
#define ENABLE_LAYOUT_ISRT

#undef ENABLE_LAYOUT_WORKMAN


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


// Audio
#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)
#    define MIDI_BASIC
#endif
