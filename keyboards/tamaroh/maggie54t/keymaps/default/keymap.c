// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
// #include "print.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                   KC_LGUI,   MO(1),  KC_SPC, KC_BTN1, KC_BTN3, KC_BTN2, KC_BSPC, LT(2, KC_ENT), KC_RALT
    ),
    [1] = LAYOUT(
        QK_BOOT, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,                            KC_BTN3, KC_BTN2, _______, _______, _______, _______,
        EE_CLR, _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD,                            _______, _______, _______, _______, _______, _______,
        _______,    KC_LNG2, KC_LEFT, KC_UP,   KC_RGHT, KC_PGUP,                         _______, _______, _______, _______, _______, _______,
        _______,    KC_LNG1, KC_HOME, KC_DOWN, KC_END,  KC_PGDN,                         _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, KC_BTN1, _______, _______
    ),
    [2] = LAYOUT(
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, KC_F11,  KC_F12,  _______,
        _______, _______, _______, _______, _______, _______,                            KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, _______, _______,
        _______, _______, _______, _______, _______, _______,                            KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______,
                                   _______,   KC_NO, _______, _______, _______, _______, _______, _______, _______
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

void keyboard_post_init_user(void) {
  debug_enable=true;
  debug_mouse=true;
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   // If console is enabled, it will print the matrix position and status of each key pressed
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: 0x%04X, row: %2u, col: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.row, record->event.key.col, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
// #endif 
//   return true;
// }