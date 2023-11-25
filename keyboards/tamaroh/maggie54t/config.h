// Copyright 2023 Tamaroh (@Tamaroh)
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
#define DYNAMIC_KEYMAP_LAYER_COUNT 3

#define ADNS5050_SCLK_PIN D0
#define ADNS5050_SDIO_PIN D1
#define ADNS5050_CS_PIN   D4
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// only required if not setting mouse layer elsewhere
#define AUTO_MOUSE_DEFAULT_LAYER 1
