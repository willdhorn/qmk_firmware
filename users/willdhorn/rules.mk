SRC += willdhorn.c

SRC += $(USER_PATH)/base/process_record.c

MULTIKEY_ENABLE ?= yes
ifeq ($(strip $(MULTIKEY_ENABLE)), yes)
	SRC += $(USER_PATH)/multikey/tap_hold.c
	SRC += $(USER_PATH)/multikey/process_tap_hold.c
endif

ifeq ($(strip $(KEY_OVERRIDE_ENABLE)), yes)
	SRC += $(USER_PATH)/key_override/key_override.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += $(USER_PATH)/tap_dance/tap_dances.c
endif

ifeq ($(strip $(RGB_ENABLE)), yes)
  SRC += $(USER_PATH)/rgb/rgb_stuff.c
endif

# AUDIO NOT TESTED FROM USERSPACE
ifeq ($(strip $(AUDIO_ENABLE)), yes)
  SRC += $(USER_PATH)/unused/audio/audio.c
endif

