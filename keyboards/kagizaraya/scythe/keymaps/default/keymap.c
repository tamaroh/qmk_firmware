/* Copyright 2019 ENDO Katsuhiro <ka2hiro@kagizaraya.jp>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum layer_names {
    _QWERTY,
    _HAPPY,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  HAPPY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 *
 *           ,------------------------------------------------.       ,------------------------------------------------.
 *           |  Esc |   1  |   2  |   3  |   4  |   5  |   -  |       |   =  |   6  |   7  |   8  |   9  |   0  |   `  |
 *           |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 *           |  Tab |   Q  |   W  |   E  |   R  |   T  |   [  |       |   ]  |   Y  |   U  |   I  |   O  |   P  |   \  |
 *           |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 *           | Ctrl |   A  |   S  |   D  |   F  |   G  | pgup |       |   '  |   H  |   J  |   K  |   L  |   ;  |Enter |
 *           |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------+------.
 *           |Shift |   Z  |   X  |   C  |   V  |   B  | pgdn |       |      |   N  |   M  |   ,  |   .  |   /  |Shift | Fn   |
 *           `--------------------+------+------+------+------|       |------+------+------+------+------+------+------+------'
 *                                | LGUI | lang2|  Fn  | Space|       | BS   |  Fn  | lang1| RAlt |
 *                                `---------------------------'       `---------------------------'
 */
[_QWERTY] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,      KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,      KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PGUP,      KC_QUOT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_PGDN,      KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  MO(_HAPPY),
                             KC_LGUI, KC_LNG2, MO(_HAPPY), KC_SPC,    KC_BSPC,  MO(_HAPPY), KC_LNG1, KC_RALT
),

/* Happy
 *
 *           ,------------------------------------------------.       ,------------------------------------------------.
 *           |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |       |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 *           |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 *           |      |      | home |  up  | end  |      |      |       |      |      |      |      |      |      |  F12 |
 *           |------+------+------+------+------+------+------|       |------+------+------+------+------+------+------|
 *           |      |      | left | down |right |      |      |       |      |   -  |  =   |   [  |   ]  |      |      |
 *           |------+------+------+------+------+------+------|       +------+------+------+------+------+------+------+------.
 *           |      |      |      |      |      |      |      |       |      |   _  |  +   |   {  |   }  |      |      |      |
 *           `--------------------+------+------+------+------|       |------+------+------+------+------+------+------+------'
 *                                |      |      |      |      |       | Del  |      |      |      |
 *                                `---------------------------'       `---------------------------'
 */
[_HAPPY] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,      _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______,  KC_HOME, KC_UP,   KC_END, _______, _______,      _______, _______, _______, _______, _______, _______,   KC_F12,
  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,      _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,      _______, KC_UNDS, KC_PLUS,  KC_LCBR, KC_RCBR,  _______, _______, _______,
                             _______, _______, _______, _______,      KC_DEL , _______, _______, _______
)

};

