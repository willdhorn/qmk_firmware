#pragma once

#include "willdhorn.h"

#define SHIFT_OVERRIDE(kc, ovrrde) ko_make_basic(MOD_MASK_SHIFT, (kc), (ovrrde));
#define ALT_OVERRIDE(kc, ovrrde) ko_make_basic(MOD_MASK_ALT, (kc), (ovrrde));
#define MEH_OVERRIDE(kc, ovrrde) ko_make_basic(MOD_MASK_MEH, (kc), (ovrrde));
