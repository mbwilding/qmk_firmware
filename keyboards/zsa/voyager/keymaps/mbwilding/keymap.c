// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    BASE,
    SYMB,
    NUMB,
    GAME,
    MISC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, TO(GAME),
        KC_DEL , KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   ,                      KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , S(KC_2),
        KC_BSPC, KC_A   , KC_O   , KC_E   , KC_U   , KC_I   ,                      KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_MINS,
        S(KC_1), KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   ,                      KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , S(KC_SLSH),

                              MT(MOD_LSFT, KC_SPC), MT(MO(MISC), KC_ENT), MT(MO(NUMB), KC_TAB), MT(MO(SYMB), KC_ESC)
    ),
    [SYMB] = LAYOUT(
        _______, _______,    _______,    _______,    _______, _______,             _______, _______, _______,    _______, _______,   _______,
        _______, KC_GRV ,    S(KC_7),    S(KC_3),    S(KC_6), _______,             _______, S(KC_4), S(KC_8),    S(KC_5), _______,   _______,
        _______, S(KC_COMM), KC_LBRC,    S(KC_LBRC), S(KC_9), KC_SLSH,             _______, S(KC_0), S(KC_RBRC), KC_RBRC, S(KC_DOT), _______,
        _______, KC_EQL ,    S(KC_BSLS), KC_DOWN,    KC_UP  , _______,             _______, KC_LEFT, KC_RIGHT,   KC_MINS, S(KC_EQL), _______,

                                                     KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS
    ),
    [NUMB] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,                      _______, KC_7   , KC_8   , KC_9   , _______, _______,
        _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______,                      _______, KC_4   , KC_5   , KC_6   , KC_0   , _______,
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______,                      _______, KC_1   , KC_2   , KC_3   , _______, _______,

                                                     KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS
    ),
    [GAME] = LAYOUT(
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , TO(BASE),
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                      KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , _______,
        KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                      KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, _______,
        KC_LSFT, KC_Z   , KC_C   , KC_X   , KC_V   , KC_B   ,                      KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, _______,

                                                     KC_SPC , KC_ENT ,    _______, _______
    ),
    [MISC] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,

                                                     KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS
    ),
};
