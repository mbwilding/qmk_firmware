// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "version.h"

#include "layers.h"
#include "colors.h"

#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

extern rgb_config_t rgb_matrix_config;

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          TO(4),
    KC_DELETE,      KC_QUOTE,       MT(MOD_LALT, KC_COMMA),MT(MOD_LGUI, KC_DOT),MT(MOD_LCTL, KC_P),KC_Y,                            KC_F,           MT(MOD_RCTL, KC_G),MT(MOD_RGUI, KC_C),MT(MOD_RALT, KC_R),KC_L,  KC_AT,
    KC_BSPC,        KC_A,           KC_O,           KC_E,           KC_U,           KC_I,                                           KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_MINUS,
    KC_EXLM,        ALL_T(KC_SCLN), MEH_T(KC_Q),    KC_J,           KC_K,           KC_X,                                           KC_B,           KC_M,           KC_W,           MEH_T(KC_V),    ALL_T(KC_Z),    KC_QUES,

                                                                    MT(MOD_LSFT, KC_SPC), LT(3,KC_ENT),                             LT(2,KC_TAB),   LT(1,KC_ESC)
  ),
  [SYMB] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_GRAVE,       KC_AMPR,        KC_HASH,        KC_CIRC,        KC_NO,                                          KC_NO,          KC_DLR,         KC_ASTR,        KC_PERC,        KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_LABK,        KC_LBRC,        KC_LCBR,        KC_LPRN,        KC_SLASH,                                       KC_BSLS,        KC_RPRN,        KC_RCBR,        KC_RBRC,        KC_RABK,        KC_NO,
    KC_TRANSPARENT, KC_EQUAL,       KC_PIPE,        KC_DOWN,        KC_UP,          KC_NO,                                          KC_NO,          KC_LEFT,        KC_RIGHT,       KC_MINUS,       KC_PLUS,        KC_NO,

                                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [NUMB] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_NO,                                          KC_NO,          KC_7,           KC_8,           KC_9,           KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_NO,                                          KC_NO,          KC_4,           KC_5,           KC_6,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_NO,                                          KC_NO,          KC_1,           KC_2,           KC_3,           KC_NO,          KC_NO,

                                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [MISC] = LAYOUT_voyager(
    KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         ,                                 KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         ,
    KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         ,                                 KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         ,
    KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         ,                                 KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         ,
    KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         ,                                 KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         ,

                                                                    KC_NO         , KC_NO         ,                                 KC_NO         , KC_NO
  ),
  [GAME] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           TO(0),
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT,
    KC_LEFT_CTRL,   KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_TRANSPARENT,
    KC_LEFT_SHIFT,  KC_Z,           KC_C,           KC_X,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT,

                                                                    KC_SPACE,       KC_ENTER,                                       KC_NO,          KC_NO
  ),
};

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [BASE] = {
        // Left Keys
        C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   ,
        C_BLUE  , C_YELLOW, C_YELLOW, C_YELLOW, C_PURPLE, C_PURPLE,
        C_BLUE  , C_PURPLE, C_PURPLE, C_PURPLE, C_PURPLE, C_PURPLE,
        C_YELLOW, C_YELLOW, C_PURPLE, C_PURPLE, C_PURPLE, C_PURPLE,

        // Left Thumbs
        C_LBLUE , C_LBLUE ,

        // Right Keys
        C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_LBLUE ,
        C_PURPLE, C_PURPLE, C_PURPLE, C_PURPLE, C_PURPLE, C_RED   ,
        C_PURPLE, C_PURPLE, C_PURPLE, C_PURPLE, C_PURPLE, C_RED   ,
        C_PURPLE, C_PURPLE, C_PURPLE, C_PURPLE, C_PURPLE, C_YELLOW,

        // Right Thumbs
        C_LBLUE , C_LBLUE
    },
    [SYMB] = {
        // Left Keys
        C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   ,
        C_OFF   , C_YELLOW, C_RED   , C_RED   , C_RED   , C_OFF   ,
        C_OFF   , C_GREEN , C_GREEN , C_GREEN , C_GREEN , C_GREEN ,
        C_OFF   , C_RED   , C_RED   , C_BLUE  , C_BLUE  , C_OFF   ,

        // Left Thumbs
        C_LBLUE , C_LBLUE ,

        // Right Keys
        C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   ,
        C_OFF   , C_RED   , C_RED   , C_RED   , C_OFF   , C_OFF   ,
        C_GREEN , C_GREEN , C_GREEN , C_GREEN , C_GREEN , C_OFF   ,
        C_OFF   , C_BLUE  , C_BLUE  , C_RED   , C_RED   , C_OFF   ,

        // Right Thumbs
        C_LBLUE , C_LBLUE
    },
    [NUMB] = {
        // Left Keys
        C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   ,
        C_OFF   , C_CYAN  , C_CYAN  , C_CYAN  , C_CYAN  , C_OFF   ,
        C_OFF   , C_CYAN  , C_CYAN  , C_CYAN  , C_CYAN  , C_OFF   ,
        C_OFF   , C_CYAN  , C_CYAN  , C_CYAN  , C_CYAN  , C_OFF   ,

        // Left Thumbs
        C_LBLUE , C_LBLUE ,

        // Right Keys
        C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   ,
        C_OFF   , C_GREEN , C_GREEN , C_GREEN , C_OFF   , C_OFF   ,
        C_OFF   , C_GREEN , C_GREEN , C_GREEN , C_GREEN , C_OFF   ,
        C_OFF   , C_GREEN , C_GREEN , C_GREEN , C_OFF   , C_OFF   ,

        // Right Thumbs
        C_LBLUE , C_LBLUE
    },
    [MISC] = {
        // Left Keys
        C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   ,
        C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   ,
        C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   ,
        C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   ,

        // Left Thumbs
        C_OFF   , C_OFF   ,

        // Right Keys
        C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   ,
        C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   ,
        C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   ,
        C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   , C_OFF   ,

        // Right Thumbs
        C_OFF   , C_OFF
    },
    [GAME] = {
        // Left Keys
        C_BLUE  , C_GREEN , C_GREEN , C_GREEN , C_GREEN , C_GREEN ,
        C_BLUE  , C_PURPLE, C_RED   , C_PURPLE, C_PURPLE, C_PURPLE,
        C_BLUE  , C_RED   , C_RED   , C_RED   , C_PURPLE, C_PURPLE,
        C_BLUE  , C_PURPLE, C_PURPLE, C_PURPLE, C_PURPLE, C_PURPLE,

        // Left Thumbs
        C_BLUE  , C_BLUE  ,

        // Right Keys
        C_GREEN , C_GREEN , C_GREEN , C_GREEN , C_GREEN , C_LBLUE ,
        C_PURPLE, C_PURPLE, C_PURPLE, C_PURPLE, C_PURPLE, C_OFF   ,
        C_PURPLE, C_PURPLE, C_PURPLE, C_PURPLE, C_YELLOW, C_OFF   ,
        C_PURPLE, C_PURPLE, C_YELLOW, C_YELLOW, C_RED   , C_OFF   ,

        // Right Thumbs
        C_OFF   , C_OFF
    },
};

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB rgb = hsv_to_rgb(hsv);
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (rawhid_state.rgb_control || keyboard_config.disable_layer_led) return false;

    uint32_t layer = biton32(layer_state);
    set_layer_color(layer);

    // TODO: If layer out of range do this
    // if (rgb_matrix_get_flags() == LED_FLAG_NONE)
    //     rgb_matrix_set_color_all(0, 0, 0);

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}
