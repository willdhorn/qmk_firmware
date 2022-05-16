#pragma once

#include "willdhorn.h"

#define _wrap(...) (__VA_ARGS__)

#define SFT_KO_DATA(name, kc, override, ...) const key_override_t name = ko_make_basic(MOD_MASK_SHIFT, _wrap(kc), _wrap(override));
#define MEH_KO_DATA(name, kc, override, ...) const key_override_t name = ko_make_basic(MOD_MASK_MEH, _wrap(kc), _wrap(override));

#define KO_ENTRY(name, kc, override, ...) &(name),

#define BLANK(...)


