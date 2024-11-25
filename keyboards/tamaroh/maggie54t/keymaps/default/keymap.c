// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
// #include "print.h"
enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

bool set_scrolling = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                   KC_LGUI,   MO(1),  KC_SPC, KC_BTN1, KC_BTN3, DRAG_SCROLL, KC_BSPC, LT(2, KC_ENT), KC_RALT
    ),
    [1] = LAYOUT(
        _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,                            KC_BTN3, KC_BTN2, _______, _______, _______, _______,
        _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD,                            _______, _______, _______, _______, _______, _______,
        _______,  KC_LNG2, KC_LEFT, KC_UP,   KC_RGHT, KC_PGUP,                         _______, _______, _______, _______, _______, _______,
        _______,  KC_LNG1, KC_HOME, KC_DOWN, KC_END,  KC_PGDN,                         _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, QK_BOOT, _______,  KC_BTN1, _______, _______
    ),
    [2] = LAYOUT(
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, KC_F11,  KC_F12,  _______,
        _______, _______, _______, _______, _______, _______,                            KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, _______, _______,
        _______, _______, _______, _______, _______, _______,                            KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______,
                                   _______,   KC_NO, _______, _______, _______, _______, _______, _______, _______
    )
};
// trackball setting, comment out below to disable

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_WH_U);
        } else {
            tap_code(KC_WH_D);
        }
    }
    return false;
}

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        scroll_accumulated_h += (float)mouse_report.x / 24;
        scroll_accumulated_v += (float)mouse_report.y / 24;
        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;
        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRAG_SCROLL:
            // Toggle set_scrolling when DRAG_SCROLL key is pressed or released
            set_scrolling = record->event.pressed;
            break;
        default:
            break;
    }
    return true;
}
