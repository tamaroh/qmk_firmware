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
