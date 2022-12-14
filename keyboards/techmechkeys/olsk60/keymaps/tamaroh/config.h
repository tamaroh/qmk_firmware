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

#define WS2812_PIO_USE_PIO1
#define RGB_DI_PIN GP9
#define RGBLED_NUM 1
#define RGBLIGHT_DEFAULT_HUE 100
#define RGBLIGHT_DEFAULT_SPD	10
// #define RGBLIGHT_MODE_BREATHING 1
// #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
#define RGBLIGHT_EFFECT_RGB_TEST
// #define RGBLIGHT_MODE_RGB_TEST
