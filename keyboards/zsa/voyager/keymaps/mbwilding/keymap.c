// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

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

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};

enum layers {
    BASE,
    SYMB,
    NUMB,
    MISC,
    GAME,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,             KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , TO(GAME),
        KC_DEL , KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   ,             KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , S_AT,
        KC_BSPC, KC_A   , KC_O   , KC_E   , KC_U   , KC_I   ,             KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_MINS,
        S_EXCLA, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   ,             KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , S_QUEST,

                  MT(MOD_LSFT, KC_SPC), MT(MO(MISC), KC_ENT),             MT(MO(NUMB), KC_TAB), MT(MO(SYMB), KC_ESC)
    ),

    [SYMB] = LAYOUT(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,             KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_GRV , S_AMPER, S_HASH , S_HAT  , KC_NO  ,             KC_NO  , S_DOLLA, S_ASTER, S_PERCE, KC_NO  , KC_NO  ,
        KC_NO  , S_LANG , KC_LBRC, S_LCUR , S_LPAR , KC_SLSH,             KC_NO  , S_RPAR , S_RCUR , KC_RBRC, S_RANG , KC_NO  ,
        KC_NO  , KC_EQL , S_PIPE , KC_DOWN, KC_UP  , KC_NO  ,             KC_NO  , KC_LEFT, KC_RGHT, KC_MINS, S_PLUS , KC_NO  ,

                                            KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS
    ),

    [NUMB] = LAYOUT(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,             KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_NO  ,             KC_NO  , KC_7   , KC_8   , KC_9   , KC_NO  , KC_NO  ,
        KC_NO  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_NO  ,             KC_NO  , KC_4   , KC_5   , KC_6   , KC_0   , KC_NO  ,
        KC_NO  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_NO  ,             KC_NO  , KC_1   , KC_2   , KC_3   , KC_NO  , KC_NO  ,

                                            KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS
    ),

    [MISC] = LAYOUT(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,             KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,             KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,             KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,             KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,

                                            KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS
    ),

    [GAME] = LAYOUT(
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,             KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , TO(BASE),
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,             KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_NO  ,
        KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,             KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_NO  ,
        KC_LSFT, KC_Z   , KC_C   , KC_X   , KC_V   , KC_B   ,             KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_NO  ,

                                            KC_SPC , KC_ENT ,             KC_NO  , KC_NO
    ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {188,255,255}, {188,255,255}, {169,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {152,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {41,255,255}, {152,255,255}, {152,255,255} },
    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,255,255}, {0,255,255}, {169,255,255}, {169,255,255}, {0,0,0}, {152,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {169,255,255}, {169,255,255}, {0,255,255}, {0,255,255}, {0,0,0}, {152,255,255}, {152,255,255} },
    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {152,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {152,255,255}, {152,255,255} },
    [4] = { {169,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {169,255,255}, {188,255,255}, {0,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {169,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {188,255,255}, {188,255,255}, {169,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {169,255,255}, {169,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {152,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {41,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
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
