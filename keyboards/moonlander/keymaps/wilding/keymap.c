#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_us_international.h"

// LED COLORS
#define COLOR_BLACK     0,   0,   0
#define COLOR_RED       0,   255, 255
#define COLOR_ORANGE    11,  255, 255
#define COLOR_YELLOW    41,  255, 255
#define COLOR_LIME      74,  255, 255
#define COLOR_GREEN     85,  255, 255
#define COLOR_TEAL      97,  255, 255
#define COLOR_LBLUE     119, 255, 255
#define COLOR_BLUE      166, 255, 255
#define COLOR_PURPLE    175, 255, 255
#define COLOR_PINK      221, 255, 255

// LED SECTIONS
#define LED_OFF         {COLOR_BLACK}
#define LED_LETTER      {COLOR_BLUE}
#define LED_NUMBER      {COLOR_YELLOW}
#define LED_PUNCT       {COLOR_TEAL}
#define LED_SYMBOL      {COLOR_PINK}
#define LED_BRACKET     {COLOR_GREEN}
#define LED_FNUM        {COLOR_TEAL}
#define LED_MATH        {COLOR_ORANGE}
#define LED_ARROW       {COLOR_ORANGE}
#define LED_THUMB       {COLOR_PURPLE}
#define LED_LAYER       {COLOR_LBLUE}
#define LED_TOGGLE      {COLOR_RED}
#define LED_MISC        {COLOR_LIME}

enum layer_names {
    DVORAK,
    NUMBERS,
    NAVIGATION,
    GAMING
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // ROWS IN ORDER
  [DVORAK] = LAYOUT_moonlander(
    KC_GRAVE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,        KC_PLUS,        KC_AMPR,        KC_LBRACKET,                                    KC_RBRACKET,    KC_PIPE,        KC_ASTR,        KC_PERC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_AT,
    KC_EXLM,        KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           KC_LCBR,                                        KC_RCBR,        KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_QUES,
    KC_EQUAL,       KC_A,           KC_O,           KC_E,           KC_U,           KC_I,           KC_LPRN,                                        KC_RPRN,        KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_MINUS,
    KC_HASH,        KC_SCOLON,      KC_Q,           KC_J,           KC_K,           KC_X,                                                                           KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           KC_DLR,
    KC_SLASH,       KC_LCTRL,       KC_LGUI,        KC_LALT,        TO(GAMING),                     MO(NAVIGATION),                                 KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSLASH,
                                    MT(MOD_LSFT, KC_SPACE),         LT(NUMBERS,KC_BSPACE),          MT(MOD_LCTL, KC_ESCAPE),                        MT(MOD_LALT, KC_DELETE),        MT(MOD_LGUI, KC_TAB),           KC_ENTER
  ),
  [NUMBERS] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NUMLOCK,     KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_MINUS,    KC_NO,
    KC_NO,          KC_NO,          KC_F10,         KC_F11,         KC_F12,         KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_PLUS,     KC_NO,
    KC_NO,          KC_NO,          KC_F7,          KC_F8,          KC_F9,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_NO,
    KC_NO,          KC_NO,          KC_F4,          KC_F5,          KC_F6,          KC_NO,                                                                          KC_NO,          KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_ENTER,    KC_NO,
    KC_NO,          KC_NO,          KC_F1,          KC_F2,          KC_F3,                          KC_TRANSPARENT,                                 KC_TRANSPARENT,                 KC_KP_0,        KC_KP_0,        KC_KP_DOT,      KC_KP_ENTER,    KC_NO,
                                    KC_TRANSPARENT,                 KC_TRANSPARENT,                 KC_TRANSPARENT,                                 KC_TRANSPARENT,                 KC_TRANSPARENT,                 KC_TRANSPARENT
  ),
  [NAVIGATION] = LAYOUT_moonlander(
    RESET,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_UP,          KC_NO,          KC_NO,          LED_LEVEL,                                      KC_NO,          KC_NO,          KC_PGDOWN,      KC_MS_UP,       KC_PGUP,        KC_PSCREEN,     KC_NO,
    KC_NO,          KC_NO,          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          RGB_VAD,                                        RGB_VAI,        KC_NO,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_HOME,        KC_INSERT,      KC_END,         KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                          KC_TRANSPARENT,                                 KC_NO,                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                    KC_TRANSPARENT,                 KC_TRANSPARENT,                 KC_TRANSPARENT,                                 KC_LALT,                        KC_MS_BTN2,                     KC_MS_BTN1
  ),
  [GAMING] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_NO,
    KC_GRAVE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,                                           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,                                           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_NO,
    KC_LCTRL,       KC_LALT,        KC_M,           KC_I,           TO(DVORAK),                     KC_NO,                                          KC_NO,                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                    KC_SPACE,                       KC_LCTRL,                       KC_LALT,                                        KC_LGUI,                        KC_BSPACE,                      KC_ENTER
  ),
};

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    // COLUMNS | TOP -> BOT
    [DVORAK] = {
    // LEFT | LEFT -> RIGHT
        LED_PUNCT,      LED_PUNCT,      LED_MATH,       LED_SYMBOL,     LED_SYMBOL,
        LED_OFF,        LED_PUNCT,      LED_LETTER,     LED_PUNCT,      LED_THUMB,
        LED_OFF,        LED_PUNCT,      LED_LETTER,     LED_LETTER,     LED_THUMB,
        LED_SYMBOL,     LED_PUNCT,      LED_LETTER,     LED_LETTER,     LED_THUMB,
        LED_MATH,       LED_LETTER,     LED_LETTER,     LED_LETTER,     LED_TOGGLE,
        LED_SYMBOL,     LED_LETTER,     LED_LETTER,     LED_LETTER,
        LED_BRACKET,    LED_BRACKET,    LED_BRACKET,
        LED_THUMB,      LED_THUMB,      LED_THUMB,
        LED_LAYER,
    // RIGHT | RIGHT -> LEFT
        LED_SYMBOL,     LED_PUNCT,      LED_SYMBOL,     LED_SYMBOL,     LED_SYMBOL,
        LED_OFF,        LED_LETTER,     LED_LETTER,     LED_LETTER,     LED_OFF,
        LED_OFF,        LED_LETTER,     LED_LETTER,     LED_LETTER,     LED_OFF,
        LED_MATH,       LED_LETTER,     LED_LETTER,     LED_LETTER,     LED_OFF,
        LED_MATH,       LED_LETTER,     LED_LETTER,     LED_LETTER,     LED_OFF,
        LED_SYMBOL,     LED_LETTER,     LED_LETTER,     LED_LETTER,
        LED_BRACKET,    LED_BRACKET,    LED_BRACKET,
        LED_THUMB,      LED_THUMB,      LED_THUMB,
        LED_OFF
    },
    [NUMBERS] = {
    // LEFT | LEFT -> RIGHT
        LED_OFF,        LED_OFF,        LED_OFF,        LED_OFF,        LED_OFF,
        LED_OFF,        LED_OFF,        LED_OFF,        LED_OFF,        LED_OFF,
        LED_OFF,        LED_FNUM,       LED_FNUM,       LED_FNUM,       LED_FNUM,
        LED_OFF,        LED_FNUM,       LED_FNUM,       LED_FNUM,       LED_FNUM,
        LED_OFF,        LED_FNUM,       LED_FNUM,       LED_FNUM,       LED_FNUM,
        LED_OFF,        LED_OFF,        LED_OFF,        LED_OFF,
        LED_OFF,        LED_OFF,        LED_OFF,
        LED_OFF,        LED_OFF,        LED_OFF,
        LED_OFF,
    // RIGHT | RIGHT -> LEFT
        LED_OFF,        LED_OFF,        LED_OFF,        LED_OFF,        LED_OFF,
        LED_MATH,       LED_MATH,       LED_MATH,       LED_MISC,       LED_MISC,
        LED_MATH,       LED_NUMBER,     LED_NUMBER,     LED_NUMBER,     LED_PUNCT,
        LED_MATH,       LED_NUMBER,     LED_NUMBER,     LED_NUMBER,     LED_NUMBER,
        LED_TOGGLE,     LED_NUMBER,     LED_NUMBER,     LED_NUMBER,     LED_NUMBER,
        LED_OFF,        LED_OFF,        LED_OFF,        LED_OFF,
        LED_OFF,        LED_OFF,        LED_OFF,
        LED_OFF,        LED_OFF,        LED_OFF,
        LED_OFF
    },
    [NAVIGATION] = {
    // LEFT | LEFT -> RIGHT
        LED_TOGGLE,     LED_OFF,        LED_OFF,        LED_OFF,        LED_OFF,
        LED_OFF,        LED_OFF,        LED_OFF,        LED_OFF,        LED_OFF,
        LED_OFF,        LED_OFF,        LED_ARROW,      LED_OFF,        LED_OFF,
        LED_OFF,        LED_ARROW,      LED_ARROW,      LED_OFF,        LED_OFF,
        LED_OFF,        LED_OFF,        LED_ARROW,      LED_OFF,        LED_OFF,
        LED_OFF,        LED_OFF,        LED_OFF,        LED_OFF,
        LED_OFF,        LED_TOGGLE,     LED_MISC,
        LED_OFF,        LED_OFF,        LED_OFF,
        LED_OFF,
    // RIGHT | RIGHT -> LEFT
        LED_OFF,        LED_OFF,        LED_OFF,        LED_OFF,        LED_OFF,
        LED_OFF,        LED_MISC,       LED_OFF,        LED_OFF,        LED_OFF,
        LED_OFF,        LED_MISC,       LED_ARROW,      LED_MISC,       LED_OFF,
        LED_OFF,        LED_ARROW,      LED_ARROW,      LED_MISC,       LED_OFF,
        LED_OFF,        LED_MISC,       LED_ARROW,      LED_MISC,       LED_OFF,
        LED_OFF,        LED_OFF,        LED_OFF,        LED_OFF,
        LED_OFF,        LED_OFF,        LED_MISC,
        LED_MISC,       LED_MISC,       LED_THUMB,
        LED_OFF
    },
    [GAMING] = {
    // LEFT | LEFT -> RIGHT
        LED_MISC,       LED_PUNCT,      LED_THUMB,      LED_THUMB,      LED_THUMB,
        LED_NUMBER,     LED_LETTER,     LED_ARROW,      LED_LETTER,     LED_THUMB,
        LED_NUMBER,     LED_ARROW,      LED_ARROW,      LED_LETTER,     LED_LETTER,
        LED_NUMBER,     LED_LETTER,     LED_ARROW,      LED_LETTER,     LED_LETTER,
        LED_NUMBER,     LED_LETTER,     LED_LETTER,     LED_LETTER,     LED_TOGGLE,
        LED_NUMBER,     LED_LETTER,     LED_LETTER,     LED_LETTER,
        LED_NUMBER,     LED_LETTER,     LED_LETTER,
        LED_THUMB,      LED_THUMB,      LED_THUMB,
        LED_OFF,
    // RIGHT | RIGHT -> LEFT
        LED_OFF,        LED_SYMBOL,     LED_PUNCT,      LED_OFF,        LED_OFF,
        LED_NUMBER,     LED_LETTER,     LED_PUNCT,      LED_SYMBOL,     LED_OFF,
        LED_NUMBER,     LED_LETTER,     LED_LETTER,     LED_PUNCT,      LED_OFF,
        LED_NUMBER,     LED_LETTER,     LED_LETTER,     LED_PUNCT,      LED_OFF,
        LED_NUMBER,     LED_LETTER,     LED_LETTER,     LED_LETTER,     LED_OFF,
        LED_NUMBER,     LED_LETTER,     LED_LETTER,     LED_LETTER,
        LED_NUMBER,     LED_LETTER,     LED_LETTER,
        LED_THUMB,      LED_THUMB,      LED_THUMB,
        LED_OFF
    },
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
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

void rgb_matrix_indicators_user(void) {
    if (rawhid_state.rgb_control || keyboard_config.disable_layer_led) { return; }
    set_layer_color((biton32(layer_state)));
}
