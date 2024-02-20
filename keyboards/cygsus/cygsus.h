// Copyright 2023 piroridon (@piroridon)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

#define LAYOUT_split_5x6( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
  LES,                L31, L32, L33, R30, R31, R32,                RES, \
       LRA, LRB, LRP,                               RRP, RRA, RRB \
  ) \
  { \
    { LES, L01, L02, L03, L04, L05 }, \
    { L00, L11, L12, L13, L14, L15 }, \
    { L10, L21, L22, L23, L24, L25 }, \
    { L20, KC_NO, LRP, L31, L32, L33 }, \
    { LRA, LRB, KC_NO, KC_NO, KC_NO, KC_NO}, \
    { RES, R04, R03, R02, R01, R00 }, \
    { R05, R14, R13, R12, R11, R10 }, \
    { R15, R24, R23, R22, R21, R20 }, \
    { R25, KC_NO, RRP, R32, R31, R30 }, \
    { RRA, RRB, KC_NO, KC_NO, KC_NO, KC_NO} \
  }
