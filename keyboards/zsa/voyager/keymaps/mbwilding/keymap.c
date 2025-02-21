// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "version.h"

#define MOON_LED_LEVEL LED_LEVEL

extern rgb_config_t rgb_matrix_config;
extern MidiDevice midi_device;

enum custom_keycodes {
    RGB_SLD = SAFE_RANGE,
};

// User Code

#include "colors.h"

enum layers {
    L_BASE,
    L_SYMB,
    L_NUMB,
    L_MIDI,
    L_GAME,
    // L_MISC,

    TOTAL_LAYERS,
};

enum tap_dances {
    TD_ESC_DEL,
};

// Keys

tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_DEL] = ACTION_TAP_DANCE_DOUBLE(KC_ESCAPE, KC_DELETE),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          TO(L_MIDI),       TO(L_GAME),
    KC_NO,          KC_QUOTE,       ALT_T(KC_COMM), GUI_T(KC_DOT),  CTL_T(KC_P),    KC_Y,                                           KC_F,           RCTL_T(KC_G),   RGUI_T(KC_C),   RALT_T(KC_R),   KC_L,           KC_AT,
    KC_NO,          KC_A,           KC_O,           KC_E,           KC_U,           KC_I,                                           KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_MINUS,
    KC_EXLM,        ALL_T(KC_SCLN), MEH_T(KC_Q),    KC_J,           KC_K,           KC_X,                                           KC_B,           KC_M,           KC_W,           MEH_T(KC_V),    ALL_T(KC_Z),    KC_QUES,

                                                                    SFT_T(KC_SPC),  KC_BSPC,                                        LT(L_NUMB, TD(TD_ESC_DEL)), LT(L_SYMB, KC_ENT)
  ),

  [L_SYMB] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_GRAVE,       KC_AMPR,        KC_HASH,        KC_CIRC,        KC_NO,                                          KC_NO,          KC_DLR,         KC_ASTR,        KC_PERC,        KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_LABK,        KC_LBRC,        KC_LCBR,        KC_LPRN,        KC_SLASH,                                       KC_BSLS,        KC_RPRN,        KC_RCBR,        KC_RBRC,        KC_RABK,        KC_NO,
    KC_TRANSPARENT, KC_EQUAL,       KC_PIPE,        KC_DOWN,        KC_UP,          KC_NO,                                          KC_NO,          KC_LEFT,        KC_RIGHT,       KC_MINUS,       KC_PLUS,        KC_NO,

                                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [L_NUMB] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_NO,                                          KC_NO,          KC_7,           KC_8,           KC_9,           KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_NO,                                          KC_NO,          KC_4,           KC_5,           KC_6,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_NO,                                          KC_NO,          KC_1,           KC_2,           KC_3,           KC_NO,          KC_NO,

                                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [L_MIDI] = LAYOUT_voyager(
    MI_TOGG,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          TO(L_BASE),
    MI_Cs4,         MI_Ds4,         KC_NO,          KC_NO,          MI_Gs4,         MI_As4,                                         KC_NO,          MI_Cs5,         MI_Ds5,         KC_NO,          KC_NO,          MI_Gs5,
    MI_C4,          MI_D4,          MI_E4,          MI_F4,          MI_G4,          MI_A4,                                          MI_B4,          MI_C5,          MI_D5,          MI_E5,          MI_F5,          MI_G5,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,

                                                                    MI_OCTD,        MI_TRSD,                                        MI_TRSU,        MI_OCTU
  ),

  [L_GAME] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           TO(L_BASE),
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT,
    KC_LEFT_CTRL,   KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_TRANSPARENT,
    KC_LEFT_SHIFT,  KC_Z,           KC_C,           KC_X,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT,

                                                                    KC_SPACE,       KC_ENTER,                                       KC_NO,          KC_NO
  ),

  // [L_MISC] = LAYOUT_voyager(
  //   KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  //   KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  //   KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  //   KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  //
  //                                                                   KC_NO,          KC_NO,                                          KC_NO,          KC_NO
  // ),
};

// LED

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [L_BASE] = {
        // Left Keys
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_PUNCTU, C_PUNCTU, C_PUNCTU, C_LETTER, C_LETTER,
        C_OFF,    C_LETTER, C_LETTER, C_LETTER, C_LETTER, C_LETTER,
        C_PUNCTU, C_PUNCTU, C_LETTER, C_LETTER, C_LETTER, C_LETTER,

        // Left Thumbs
        C_LAYER,  C_LAYER,

        // Right Keys
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_LAYER,  C_LAYER,
        C_LETTER, C_LETTER, C_LETTER, C_LETTER, C_LETTER, C_SYMBOL,
        C_LETTER, C_LETTER, C_LETTER, C_LETTER, C_LETTER, C_SYMBOL,
        C_LETTER, C_LETTER, C_LETTER, C_LETTER, C_LETTER, C_PUNCTU,

        // Right Thumbs
        C_LAYER,  C_LAYER
    },

    [L_SYMB] = {
        // Left Keys
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_PUNCTU, C_SYMBOL, C_SYMBOL, C_SYMBOL, C_OFF,
        C_OFF,    C_SYMBOL, C_SYMBOL, C_SYMBOL, C_SYMBOL, C_SYMBOL,
        C_OFF,    C_SYMBOL, C_SYMBOL, C_SYSTEM, C_SYSTEM, C_OFF,

        // Left Thumbs
        C_LAYER,  C_LAYER,

        // Right Keys
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_SYMBOL, C_SYMBOL, C_SYMBOL, C_OFF,    C_OFF,
        C_SYMBOL, C_SYMBOL, C_SYMBOL, C_SYMBOL, C_SYMBOL, C_OFF,
        C_OFF,    C_SYSTEM, C_SYSTEM, C_SYMBOL, C_SYMBOL, C_OFF,

        // Right Thumbs
        C_LAYER,  C_LAYER
    },

    [L_NUMB] = {
        // Left Keys
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_FKEY,   C_FKEY,   C_FKEY,   C_FKEY,   C_OFF,
        C_OFF,    C_FKEY,   C_FKEY,   C_FKEY,   C_FKEY,   C_OFF,
        C_OFF,    C_FKEY,   C_FKEY,   C_FKEY,   C_FKEY,   C_OFF,

        // Left Thumbs
        C_LAYER,  C_LAYER,

        // Right Keys
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_NUMBER, C_NUMBER, C_NUMBER, C_OFF,    C_OFF,
        C_OFF,    C_NUMBER, C_NUMBER, C_NUMBER, C_NUMBER, C_OFF,
        C_OFF,    C_NUMBER, C_NUMBER, C_NUMBER, C_OFF,    C_OFF,

        // Right Thumbs
        C_LAYER,  C_LAYER
    },

    [L_MIDI] = {
        // Left Keys
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,

        // Left Thumbs
        C_OFF,    C_OFF,

        // Right Keys
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_LAYER,
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,

        // Right Thumbs
        C_OFF,    C_OFF
    },

    [L_GAME] = {
        // Left Keys
        C_SYSTEM, C_NUMBER, C_NUMBER, C_NUMBER, C_NUMBER, C_NUMBER,
        C_SYSTEM, C_LETTER, C_WSAD  , C_LETTER, C_LETTER, C_LETTER,
        C_SYSTEM, C_WSAD  , C_WSAD  , C_WSAD  , C_LETTER, C_LETTER,
        C_SYSTEM, C_LETTER, C_LETTER, C_LETTER, C_LETTER, C_LETTER,

        // Left Thumbs
        C_LAYER,  C_LAYER,

        // Right Keys
        C_NUMBER, C_NUMBER, C_NUMBER, C_NUMBER, C_NUMBER, C_LAYER,
        C_LETTER, C_LETTER, C_LETTER, C_LETTER, C_LETTER, C_OFF,
        C_LETTER, C_LETTER, C_LETTER, C_LETTER, C_PUNCTU, C_OFF,
        C_LETTER, C_LETTER, C_PUNCTU, C_PUNCTU, C_SYMBOL, C_OFF,

        // Right Thumbs
        C_OFF,   C_OFF
    },

    // [L_MISC] = {
    //     // Left Keys
    //     C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
    //     C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
    //     C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
    //     C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
    //
    //     // Left Thumbs
    //     C_OFF,    C_OFF,
    //
    //     // Right Keys
    //     C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
    //     C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
    //     C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
    //     C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
    //
    //     // Right Thumbs
    //     C_OFF,    C_OFF
    // },
};

// Funcs

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

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
    if (rawhid_state.rgb_control || keyboard_config.disable_layer_led)
        return false;

    uint32_t layer = biton32(layer_state);
    if (layer < TOTAL_LAYERS)
    {
        set_layer_color(layer);
    }
    else
    {
        if (rgb_matrix_get_flags() == LED_FLAG_NONE)
            rgb_matrix_set_color_all(0, 0, 0);
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_SLD:
            if (record -> event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}
