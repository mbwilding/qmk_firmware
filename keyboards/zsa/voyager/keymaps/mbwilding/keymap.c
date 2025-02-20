// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define S_EXCLA      S(KC_1)        // !
#define S_AT         S(KC_2)        // @
#define S_HASH       S(KC_3)        // #
#define S_DOLLA      S(KC_4)        // $
#define S_PERCE      S(KC_5)        // %
#define S_HAT        S(KC_6)        // ^
#define S_AMPER      S(KC_7)        // &
#define S_ASTER      S(KC_8)        // *
#define S_LPAR       S(KC_9)        // (
#define S_RPAR       S(KC_0)        // )
#define S_UNDER      S(KC_MINS)     // -
#define S_PLUS       S(KC_EQL)      // +
#define S_PIPE       S(KC_BSLS)     // |
#define S_QUEST      S(KC_SLSH)     // ?
#define S_LANG       S(KC_COMM)     // <
#define S_RANG       S(KC_DOT)      // >
#define S_LCUR       S(KC_LBRC)     // {
#define S_RCUR       S(KC_RBRC)     // }

enum layers {
    BASE,
    SYMB,
    NUMB,
    GAME,
    MISC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, TO(GAME),
        KC_DEL , KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   ,             KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , S(KC_2),
        KC_BSPC, KC_A   , KC_O   , KC_E   , KC_U   , KC_I   ,             KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_MINS,
        S_EXCLA, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   ,             KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , S_QUEST,

                  MT(MOD_LSFT, KC_SPC), MT(MO(MISC), KC_ENT),             MT(MO(NUMB), KC_TAB), MT(MO(SYMB), KC_ESC)
    ),

    [SYMB] = LAYOUT(
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
        _______, KC_GRV , S_AMPER, S_HASH , S_HAT  , _______,             _______, S_DOLLA, S_ASTER, S_PERCE, _______, _______,
        _______, S_LANG , KC_LBRC, S_LCUR , S_LPAR , KC_SLSH,             _______, S_RPAR , S_RCUR , KC_RBRC, S_RANG , _______,
        _______, KC_EQL , S_PIPE , KC_DOWN, KC_UP  , _______,             _______, KC_LEFT, KC_RGHT, KC_MINS, S_PLUS , _______,

                                            KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS
    ),

    [NUMB] = LAYOUT(
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
        _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,             _______, KC_7   , KC_8   , KC_9   , _______, _______,
        _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______,             _______, KC_4   , KC_5   , KC_6   , KC_0   , _______,
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______,             _______, KC_1   , KC_2   , KC_3   , _______, _______,

                                            KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS
    ),

    [GAME] = LAYOUT(
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,             KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , TO(BASE),
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,             KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , _______,
        KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,             KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, _______,
        KC_LSFT, KC_Z   , KC_C   , KC_X   , KC_V   , KC_B   ,             KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, _______,

                                            KC_SPC , KC_ENT ,             _______, _______
    ),

    [MISC] = LAYOUT(
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,

                                            KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS
    ),
};
