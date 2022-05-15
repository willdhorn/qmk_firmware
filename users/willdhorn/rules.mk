SRC += willdhorn.c
SRC += $(USER_PATH)/key_behavior/process_record.c
SRC += $(USER_PATH)/quantum/process_tap_hold.c

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += $(USER_PATH)/key_behavior/tap_dances.c
endif

ifeq ($(strip $(KEY_OVERRIDE_ENABLE)), yes)
	SRC += $(USER_PATH)/key_config/key_override.c
endif

ifeq ($(strip $(RGB_ENABLE)), yes)
  SRC += $(USER_PATH)/whistle_bells/rgb/rgb_stuff.c
endif

# AUDIO NOT TESTED FROM USERSPACE
ifeq ($(strip $(AUDIO_ENABLE)), yes)
  SRC += $(USER_PATH)/whistle_bells/audio/audio.c
endif

