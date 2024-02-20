#include QMK_KEYBOARD_H

enum layer_names {
    _L0,
    _L1,
    _L2,
    _L3,
    _L4
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   
    [_L0] = LAYOUT_split_5x6(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINUS, 
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOTE,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLASH), KC_EQUAL,
    LOPT_T(KC_ESC),   LT(_L1, KC_F10),  KC_DEL,  KC_SPACE,     KC_ENT,  KC_BSPC, LT(_L2, KC_F9),        LT(_L3, KC_F2),
    KC_UP,   KC_DOWN, KC_LGUI,                                                               KC_PSCR, KC_RIGHT, KC_LEFT
    ),

    [_L1] = LAYOUT_split_5x6(
    _______,XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   LCA(KC_DEL),   KC_1,    KC_2,    KC_3,    KC_0,    KC_P,   RSFT(KC_GRV), 
    _______,LCTL(KC_A),KC_F4,   KC_F5,   KC_F6,   LCA(KC_H),     KC_4,    KC_5,    KC_6,    KC_L,    RSFT(KC_SCLN), RSFT(KC_QUOTE),
    _______,LCTL(KC_Z),KC_F7,   KC_F8,   KC_F9,   KC_F10,        KC_7,    KC_8,    KC_9,    KC_DOT,  RSFT(KC_SLASH), RSFT(KC_EQUAL),
    _______,   _______,    _______,  _______,                       _______,   _______,    RALT(KC_GRV),    _______,
    KC_PGUP,   KC_PGDN, LGUI(KC_D),                                                     RALT(KC_PSCR), KC_END, KC_HOME
    ),

    [_L2] = LAYOUT_split_5x6(
    _______, XXXXXXX,   XXXXXXX,   LSFT(KC_LBRC),LSFT(KC_RBRC),XXXXXXX,          RSFT(KC_1),  RSFT(KC_2), RSFT(KC_3),  RSFT(KC_0),KC_P,   RSFT(KC_MINUS), 
    _______, LCTL(KC_A),LCTL(KC_S),KC_LBRC,      KC_RBRC,      XXXXXXX,          RSFT(KC_4),  RSFT(KC_5), RSFT(KC_6),  KC_L,      RSFT(KC_SCLN), RSFT(KC_QUOTE),
    _______, LCTL(KC_Z),XXXXXXX,   LSFT(KC_9),   LSFT(KC_0),   XXXXXXX,          RSFT(KC_7),  RSFT(KC_8), RSFT(KC_9),  KC_DOT,    KC_BSLS, RSFT(KC_EQUAL),
    _______,   RALT(KC_GRV),    _______,  KC_MS_BTN1,                   KC_MS_BTN2,   _______,    _______,    _______,
    KC_MS_WH_UP,   KC_MS_WH_DOWN, LGUI(KC_V),                                                     RALT(KC_PSCR), KC_MS_WH_LEFT, KC_MS_WH_RIGHT
    ),

    [_L3] = LAYOUT_split_5x6(
    _______, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         LCTL(KC_Y),LCTL(KC_U),LCTL(KC_I),LCTL(KC_O),LCTL(KC_P),XXXXXXX,
    _______, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         LCTL(KC_H),XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    _______, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    _______,   MO(_L4),    KC_MS_BTN3,  KC_MS_BTN1,                        KC_MS_BTN2,   KC_MS_BTN4,    KC_MS_BTN5,    _______,
    LALT(KC_TAB),   LSA(KC_TAB), LGUI(KC_D),                                                     RALT(KC_PSCR), RGUI(RCTL(KC_RIGHT)), RGUI(RCTL(KC_LEFT))
    ),

    [_L4] = LAYOUT_split_5x6(
    XXXXXXX,    RGB_MOD,    RGB_RMOD,   XXXXXXX,    XXXXXXX,   XXXXXXX,         KC_MS_BTN4, KC_MS_U,    KC_MS_BTN5, XXXXXXX,    XXXXXXX,   XXXXXXX, 
    XXXXXXX,    RGB_HUI,    RGB_HUD,    XXXXXXX,    XXXXXXX,   XXXXXXX,         KC_MS_L,    KC_MS_BTN2, KC_MS_R,    XXXXXXX,    XXXXXXX,   XXXXXXX,
    XXXXXXX,    RGB_SAI,    RGB_SAD,    XXXXXXX,    XXXXXXX,   XXXXXXX,         XXXXXXX,    KC_MS_D,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,
    _______,   _______,    _______,  _______,                       _______,   _______,    KC_MS_BTN1,    _______,
    RGB_VAI,   RGB_VAD, RGB_TOG,                                                     KC_MS_BTN3,  KC_MS_WH_UP, KC_MS_WH_DOWN
    )
};

#ifdef ENCODER_ENABLE
const uint8_t rt_matrix[][2][2] = {
    {{4,0},{4,1}},
    {{9,0},{9,1}},
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    keypos_t key;

    int      cw = 0;
    if (clockwise) cw = 1;
    key.row          = rt_matrix[index][cw][0];
    key.col          = rt_matrix[index][cw][1];

    action_exec((keyevent_t){.key = key, .pressed = true, .time = (timer_read() | 1)});
    action_exec((keyevent_t){.key = key, .pressed = false, .time = (timer_read() | 1)});

    return false;
}
#endif
