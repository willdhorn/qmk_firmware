// Default layouts
#define USE_LAYOUT_COLEMAK
#define USE_LAYOUT_QWERTY
#define USE_LAYOUT_ISRT

// Key Behaviour
#undef TAPPING_TERM
#define TAPPING_TERM 225

#define TAPPING_TERM_PER_KEY
#define RETRO_TAPPING_PER_KEY
#define SPACE_RETRO_TAP_TERM 250

#define IGNORE_MOD_TAP_INTERRUPT // !! ABSOLUTELY NEEDED FOR HOME ROW MODS !!
#define TAPPING_FORCE_HOLD // Don't repeat tapping functing when hold after tap. Needed to make space a layer key (tapSpace-holdForLayer-tapSymbol-tapSpace)
#undef PERMISIVE_HOLD
// This should make accidental mod triggers less likely
#define BILATERAL_COMBINATIONS 250

// #define TAPPING_TOGGLE 1

// ONESHOT CONFIGS
#undef ONESHOT_TAP_TOGGLE // 3 // Incompatiple with TAPPING_FORCE_HOLD
#define ONESHOT_TIMEOUT 500

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

// Disable deprecated features for binary size
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE

// USB Startup (no delay)
#define USB_SUSPEND_WAKEUP_DELAY 0

// DEBUG FLAGS
#undef DEBUG_KEYCODE_PRINT
#define DEBUG_LAYER_PRINT
// QMK flag
#undef DEBUG_MATRIX_SCAN_RATE
