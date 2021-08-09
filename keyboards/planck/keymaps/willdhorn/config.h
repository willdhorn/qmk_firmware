#pragma once



#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

// Key Behaviour
#undef TAPPING_TERM
#define TAPPING_TERM 200

// !! ABSOLUTELY NEEDED FOR HOME ROW MODS !!
#define IGNORE_MOD_TAP_INTERRUPT

#define TAPPING_FORCE_HOLD


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

// USB Startup (no delay)
#define USB_SUSPEND_WAKEUP_DELAY 0

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
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_BASIC