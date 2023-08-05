// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │   │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │   │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │   │ N │ M │ , │ . │ / │
      * └───┴───┼───┼───┼───┤   ├───┼───┼───┼───┴───┘
      *         │Win│Tab│Spc│   │ BS│Ent│Alt│
      *         └───┴───┴───┘   └───┴───┴───┘
      */
    [0] = LAYOUT(
        KC_NO, KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,            KC_NO,
        KC_NO, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    RCTL_T(KC_SCLN), KC_NO,
        KC_NO, KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH), KC_NO,
                             KC_LGUI, LT(1, KC_TAB), KC_SPC,      KC_BSPC, LT(2, KC_ENT),KC_RALT
    ),
    [1] = LAYOUT(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, KC_LNG2, KC_LEFT, KC_UP,   KC_RGHT, KC_PGUP,         _______, _______, _______, _______, KC_COLN, _______,
        _______, KC_LNG1, KC_HOME, KC_DOWN, KC_END,  KC_PGDN,         _______, _______, KC_LABK, KC_RABK, KC_QUES, _______,
                                   _______, _______, _______,         KC_DEL,  MO(3), _______
    ),
    [2] = LAYOUT(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, KC_ESC,  _______, KC_GRV,  KC_QUOT, _______,         KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, _______,
        _______, _______, _______, KC_TILD, KC_DQUO, _______,         KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______,
                                   _______,   MO(3), _______,         _______, _______, _______
    ),
    [3] = LAYOUT(
        _______,   KC_F1,  KC_F2 ,   KC_F3,   KC_F4,   KC_F5,         KC_F6,     KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
        _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______,         _______, _______, _______
    )
};
