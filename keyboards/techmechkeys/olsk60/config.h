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

#define WS2812_PIO_USE_PIO1
#define AUDIO_PIN GP13
#define AUDIO_PWM_DRIVER PWMD6
  #define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_B
  #define AUDIO_INIT_DELAY
  #define STARTUP_SONG SONG(M__NOTE(_C7, 30), M__NOTE(_C6, 30))
  #define AUDIO_CLICKY