# SRC += muse.c
# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
SRC += tap_dances.c
SRC += rgb_stuff.c
SRC += key_overrides.c
CONSOLE_ENABLE = yes
COMMAND_ENABLE = no
AUDIO_ENABLE = no
WEBUSB_ENABLE = yes
ORYX_ENABLE = yes
DYNAMIC_MACRO_ENABLE = no
TAP_DANCE_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
