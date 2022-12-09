#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *    ┌───┬───┬───┬───┬───┬───┐  ┌───┬───┬───┬───┬───┬────────┐
     *    │ESC│ 1 │ 2 │ 3 │ 4 │ 5 │  │ G │ H │ I │ J │ K │  BKSP  │
     *  ┌─┴───┼───┼───┼───┼───┼───┼  ├───┼───┼───┼───┼───┼───┬────└─┐
     *  │ Tab │ B │ C │ D │ E │ F │  │ G │ H │ I │ J │ K │ [ │  \   │ 
     * ┌┴─────┼───┼───┼───┼───┼───┼  ├───┼───┼───┼───┼───┼───┴─────┬┘
     * │ Ctrl │ B │ C │ D │ E │ F │  │ G │ H │ I │ J │ K │ Enter   │     
     * ├──────┼───┼───┼───┼───┼───┼  ├───┼───┼───┼───┼───┼───┤────┬┘
     * │Shift │ B │ C │ D │ E │ F │  │ G │ H │ I │ J │ K │UP │Sft │   
     * └─┬────┼───┼───┼───┼───┼───┼  ├───┼───┼───┼───┼───┼───┼───┬┘
     *   │ A  │ B │ C │ D │ E │ F │  │ G │ H │ I │ J │ K │ L │ L │
     *   └────┴───┴───┴───┴───┴───┘  └───┴───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_5x12(
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L
    )
};
