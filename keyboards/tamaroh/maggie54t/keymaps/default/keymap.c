// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
enum layer_number {
    _BASE = 0,
    _LOWER = 1,
    _RAISE = 2,
    _TRACKBALL = 3
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                   KC_LGUI,   MO(1),  KC_SPC, KC_BTN1, KC_BTN2, KC_BSPC, LT(2, KC_ENT), KC_RALT
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______,    KC_LNG2, KC_LEFT, KC_UP,   KC_RGHT, KC_PGUP,                _______, _______, _______, _______, _______, _______,
        _______,    KC_LNG1, KC_HOME, KC_DOWN, KC_END,  KC_PGDN,                _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [2] = LAYOUT(
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, KC_F11,  KC_F12,  _______,
        _______, _______, _______, _______, _______, _______,                   KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, _______, _______,
        _______, _______, _______, _______, _______, _______,                   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______,
                                   _______,   KC_NO, _______, _______, _______, _______, _______, _______
    )
};

keyevent_t encoder1_ccw = {
    .key = (keypos_t){.row = 0, .col = 3},
    .pressed = false
};

keyevent_t encoder1_cw = {
    .key = (keypos_t){.row = 0, .col = 4},
    .pressed = false
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // First encoder 
        if (clockwise) {
            encoder1_cw.pressed = true;
            encoder1_cw.time = (timer_read() | 1);
            action_exec(encoder1_cw);
        } else {
            encoder1_ccw.pressed = true;
            encoder1_ccw.time = (timer_read() | 1);
            action_exec(encoder1_ccw);
        }
    }
    return true;
}

void matrix_scan_user(void) {
    if (IS_PRESSED(encoder1_ccw)) {
        encoder1_ccw.pressed = false;
        encoder1_ccw.time = (timer_read() | 1);
        action_exec(encoder1_ccw);
    }
    if (IS_PRESSED(encoder1_cw)) {
        encoder1_cw.pressed = false;
        encoder1_cw.time = (timer_read() | 1);
        action_exec(encoder1_cw);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LOWER:
    case _RAISE:
        cocot_set_scroll_mode(true);
        break;
    case _TRACKBALL:
        cocot_set_scroll_mode(false);
        break;
    default:
        cocot_set_scroll_mode(false);
        break;
    }
  return state;
};