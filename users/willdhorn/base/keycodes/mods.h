#pragma once

#include "willdhorn.h"

// MODIFIERS
#define MOD_LHYP 0xF
#define MOD_LMEH 0x7
#define MOD_RHYP 0x1F
#define MOD_RMEH 0x17

#define MOD_MASK_MEH MOD_MASK_CSA
#define MOD_MASK_HYP MOD_MASK_CSAG

#define MOD_LCMD MOD_LGUI

#define LHYP(kc) (QK_LCTL | QK_LSFT | QK_LALT | QK_LGUI | (kc))
#define LMEH(kc) (QK_LCTL | QK_LSFT | QK_LALT | (kc))

#define SFT(kc) LSFT(kc)
#define ALT(KC) LALT(KC)
#define CTL(kc) LCTL(kc)
#define CMD(kc) LCMD(kc)

//#define HYP(kc) LHYP(kc)
//#define MEH(kc) LMEH(kc)

#define MTS(kc) MT(MOD_LSFT, kc)
#define MTC(kc) MT(MOD_LCTL, kc)
#define MTA(kc) MT(MOD_LALT, kc)
#define MTG(kc) MT(MOD_LCMD, kc)

#define MTH(kc) MT(MOD_LHYP, kc)
#define MTM(kc) MT(MOD_LMEH, kc)
