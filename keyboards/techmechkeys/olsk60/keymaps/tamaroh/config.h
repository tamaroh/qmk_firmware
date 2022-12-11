// Copyright 2022 techmech-keeb (@techmech-keeb)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define HOLD_ON_OTHER_KEY_PRESS
#define PERMISSIVE_HOLD
// #define IGNORE_MOD_TAP_INTERRUPT

#define RGBLED_NUM 1
#define RGB_DI_PIN GP9
