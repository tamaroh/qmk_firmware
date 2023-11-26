/*
Copyright 2022 aki27

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "quantum.h"
#include <math.h>
#include "maggie54t.h"
#include "wait.h"
#include "debug.h"
#include <stdio.h>



// Invert vertical scroll direction
#ifndef COCOT_SCROLL_INV_DEFAULT
#    define COCOT_SCROLL_INV_DEFAULT 1
#endif

#ifndef COCOT_CPI_OPTIONS
#    define COCOT_CPI_OPTIONS { 250, 500, 750, 1000, 1250 }
#    ifndef COCOT_CPI_DEFAULT
#       define COCOT_CPI_DEFAULT 3
#    endif
#endif
#ifndef COCOT_CPI_DEFAULT
#    define COCOT_CPI_DEFAULT 3
#endif

#ifndef COCOT_SCROLL_DIVIDERS
#    define COCOT_SCROLL_DIVIDERS { 1, 2, 3, 4, 5, 6 }
#    ifndef COCOT_SCROLL_DIV_DEFAULT
#       define COCOT_SCROLL_DIV_DEFAULT 4
#    endif
#endif
#ifndef COCOT_SCROLL_DIV_DEFAULT
#    define COCOT_SCROLL_DIV_DEFAULT 4
#endif


#ifndef COCOT_ROTATION_ANGLE
#    define COCOT_ROTATION_ANGLE { -60, -45, -30, -15, 0, 15, 30, 45, 60 }
#    ifndef COCOT_ROTATION_DEFAULT
#       define COCOT_ROTATION_DEFAULT 1
#    endif
#endif
#ifndef COCOT_ROTATION_DEFAULT
#    define COCOT_ROTATION_DEFAULT 1
#endif


cocot_config_t cocot_config;
uint16_t cpi_array[] = COCOT_CPI_OPTIONS;
uint16_t scrl_div_array[] = COCOT_SCROLL_DIVIDERS;
uint16_t angle_array[] = COCOT_ROTATION_ANGLE;
#define CPI_OPTION_SIZE (sizeof(cpi_array) / sizeof(uint16_t))
#define SCRL_DIV_SIZE (sizeof(scrl_div_array) / sizeof(uint16_t))
#define ANGLE_SIZE (sizeof(angle_array) / sizeof(uint16_t))


// Trackball State
bool     BurstState        = false;  // init burst state for Trackball module
uint16_t MotionStart       = 0;      // Timer for accel, 0 is resting state

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {

    // double rad = angle_array[cocot_config.rotation_angle] * (M_PI / 180) * -1;
    double rad = 45 * (M_PI / 180) * -1;
    int8_t x_rev =  + mouse_report.x * cos(rad) - mouse_report.y * sin(rad);
    int8_t y_rev =  + mouse_report.x * sin(rad) + mouse_report.y * cos(rad);

        mouse_report.x = x_rev;
        mouse_report.y = y_rev;

    return pointing_device_task_user(mouse_report);
}





void eeconfig_init_kb(void) {
    cocot_config.cpi_idx = COCOT_CPI_DEFAULT;
    cocot_config.scrl_div = COCOT_SCROLL_DIV_DEFAULT;
    cocot_config.rotation_angle = COCOT_ROTATION_DEFAULT;
    cocot_config.scrl_inv = COCOT_SCROLL_INV_DEFAULT;
    cocot_config.scrl_mode = false;
    eeconfig_update_kb(cocot_config.raw);
    eeconfig_init_user();
}
