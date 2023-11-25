// Copyright 2023 Tamaroh (@Tamaroh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT
// for reducing memory usage
#define DYNAMIC_KEYMAP_LAYER_COUNT 3

// LED setting
#define RGBLIGHT_DEFAULT_HUE 180

// pointing device setting
#define ADNS5050_SCLK_PIN D0
#define ADNS5050_SDIO_PIN D1
#define ADNS5050_CS_PIN   D4
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 1

