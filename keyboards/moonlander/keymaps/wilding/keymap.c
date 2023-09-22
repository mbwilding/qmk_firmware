#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_us_international.h"

// KEY NAMES
#define KC_MAC_UNDO     LGUI(KC_Z)
#define KC_MAC_CUT      LGUI(KC_X)
#define KC_MAC_COPY     LGUI(KC_C)
#define KC_MAC_PASTE    LGUI(KC_V)
#define KC_PC_UNDO      LCTL(KC_Z)
#define KC_PC_CUT       LCTL(KC_X)
#define KC_PC_COPY      LCTL(KC_C)
#define KC_PC_PASTE     LCTL(KC_V)
#define ES_LESS_MAC     KC_GRAVE
#define ES_GRTR_MAC     LSFT(KC_GRAVE)
#define ES_BSLS_MAC     ALGR(KC_6)
#define NO_PIPE_ALT     KC_GRAVE
#define NO_BSLS_ALT     KC_EQUAL
#define LSA_T(kc)       MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC     ALGR(KC_8)
#define SE_SECT_MAC     ALGR(KC_6)
#define MOON_LED_LEVEL  LED_LEVEL

// LED COLORS
#define LED_OFF         0,0,0
// #define LED_LETTERS     166,255,255     // BLUE
// #define LED_NUMBERS     97,255,255      // TEAL

#define LED_PINK        221,255,255
#define LED_YELLOW      41,255,255
#define LED_BLUE        166,255,255     // BLUE
#define LED_PURPLE      175,255,255
#define LED_RED         0,255,255
#define LED_GREEN       85,255,255
#define LED_ORANGE      11,255,255
#define LED_TEAL        97,255,255
#define LED_LIME        74,255,255
#define LED_LBLUE       119,255,255

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};

enum layer_names {
    DVORAK,
    NUM,
    NAV,
    GAME
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_state_cmp(state, DVORAK)) {
        autoshift_enable();
    } else {
        autoshift_disable();
    }
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // ROWS IN ORDER
  [DVORAK] = LAYOUT_moonlander(
    KC_GRAVE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,        KC_PLUS,        KC_AMPR,        KC_LBRACKET,                                    KC_RBRACKET,    KC_PIPE,        KC_ASTR,        KC_PERC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_AT,
    KC_EXLM,        KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           KC_LCBR,                                        KC_RCBR,        KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_QUES,
    KC_EQUAL,       KC_A,           KC_O,           KC_E,           KC_U,           KC_I,           KC_LPRN,                                        KC_RPRN,        KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_MINUS,
    KC_HASH,        KC_SCOLON,      KC_Q,           KC_J,           KC_K,           KC_X,                                                                           KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           KC_DLR,
    KC_SLASH,       KC_LCTRL,       KC_LGUI,        KC_LALT,        TO(GAME),                       MO(NAV),                                        KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSLASH,
                                    MT(MOD_LSFT, KC_SPACE),         LT(NUM,KC_BSPACE),              MT(MOD_LCTL, KC_ESCAPE),                        MT(MOD_LALT, KC_DELETE),        MT(MOD_LGUI, KC_TAB),           KC_ENTER
  ),
  [NUM] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NUMLOCK,     KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_MINUS,    KC_NO,
    KC_NO,          KC_NO,          KC_F10,         KC_F11,         KC_F12,         KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_PLUS,     KC_NO,
    KC_NO,          KC_NO,          KC_F7,          KC_F8,          KC_F9,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_NO,
    KC_NO,          KC_NO,          KC_F4,          KC_F5,          KC_F6,          KC_NO,                                                                          KC_NO,          KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_ENTER,    KC_NO,
    KC_NO,          KC_NO,          KC_F1,          KC_F2,          KC_F3,                          KC_TRANSPARENT,                                 KC_TRANSPARENT,                 KC_KP_0,        KC_KP_0,        KC_KP_DOT,      KC_KP_ENTER,    KC_NO,
                                    KC_TRANSPARENT,                 KC_TRANSPARENT,                 KC_TRANSPARENT,                                 KC_TRANSPARENT,                 KC_TRANSPARENT,                 KC_TRANSPARENT
  ),
  [NAV] = LAYOUT_moonlander(
    RESET,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_UP,          KC_NO,          KC_NO,          MOON_LED_LEVEL,                                 KC_NO,          KC_NO,          KC_PGDOWN,      KC_MS_UP,       KC_PGUP,        KC_PSCREEN,     KC_NO,
    KC_NO,          KC_NO,          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          RGB_VAD,                                        RGB_VAI,        KC_NO,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_NO,          KC_NO,
    LCTL(KC_Y),     KC_PC_UNDO,     KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    KC_NO,                                                                          KC_NO,          KC_HOME,        KC_INSERT,      KC_END,         KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                          KC_TRANSPARENT,                                 KC_NO,                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                    KC_TRANSPARENT,                 KC_TRANSPARENT,                 KC_TRANSPARENT,                                 KC_LALT,                        KC_MS_BTN2,                     KC_MS_BTN1
  ),
  [GAME] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_NO,
    KC_GRAVE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,                                           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,                                           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_NO,
    KC_LCTRL,       KC_LALT,        KC_M,           KC_I,           TO(DVORAK),                     KC_NO,                                          KC_NO,                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                    KC_SPACE,                       KC_LCTRL,                       KC_LALT,                                        KC_LGUI,                        KC_BSPACE,                      KC_ENTER
  ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    // COLUMNS | TOP -> BOT
    [DVORAK] = {
    // LEFT | LEFT -> RIGHT
        {LED_PINK},     {LED_YELLOW},   {LED_PINK},     {LED_PINK},     {LED_PINK},
        {LED_OFF},      {LED_YELLOW},   {LED_BLUE},     {LED_YELLOW},   {LED_PURPLE},
        {LED_OFF},      {LED_YELLOW},   {LED_BLUE},     {LED_BLUE},     {LED_PURPLE},
        {LED_PINK},     {LED_YELLOW},   {LED_BLUE},     {LED_BLUE},     {LED_PURPLE},
        {LED_PINK},     {LED_BLUE},     {LED_BLUE},     {LED_BLUE},     {LED_RED},
        {LED_PINK},     {LED_BLUE},     {LED_BLUE},     {LED_BLUE},
        {LED_GREEN},    {LED_GREEN},    {LED_GREEN},
        {LED_PURPLE},   {LED_PURPLE},   {LED_PURPLE},
        {LED_ORANGE},
    // RIGHT | RIGHT -> LEFT
        {LED_PINK},     {LED_YELLOW},   {LED_PINK},     {LED_PINK},     {LED_PINK},
        {LED_OFF},      {LED_BLUE},     {LED_BLUE},     {LED_BLUE},     {LED_OFF},
        {LED_OFF},      {LED_BLUE},     {LED_BLUE},     {LED_BLUE},     {LED_OFF},
        {LED_PINK},     {LED_BLUE},     {LED_BLUE},     {LED_BLUE},     {LED_OFF},
        {LED_PINK},     {LED_BLUE},     {LED_BLUE},     {LED_BLUE},     {LED_OFF},
        {LED_PINK},     {LED_BLUE},     {LED_BLUE},     {LED_BLUE},
        {LED_GREEN},    {LED_GREEN},    {LED_GREEN},
        {LED_PURPLE},   {LED_PURPLE},   {LED_PURPLE},
        {LED_OFF}
    },
    [NUM] = {
    // LEFT | LEFT -> RIGHT
        {LED_OFF},      {LED_OFF},      {LED_OFF},      {LED_OFF},      {LED_OFF},
        {LED_OFF},      {LED_OFF},      {LED_OFF},      {LED_OFF},      {LED_OFF},
        {LED_OFF},      {LED_TEAL},     {LED_TEAL},     {LED_TEAL},     {LED_TEAL},
        {LED_OFF},      {LED_TEAL},     {LED_TEAL},     {LED_TEAL},     {LED_TEAL},
        {LED_OFF},      {LED_TEAL},     {LED_TEAL},     {LED_TEAL},     {LED_TEAL},
        {LED_OFF},      {LED_OFF},      {LED_OFF},      {LED_OFF},
        {LED_OFF},      {LED_OFF},      {LED_OFF},
        {LED_OFF},      {LED_OFF},      {LED_OFF},
        {LED_OFF},
    // RIGHT | RIGHT -> LEFT
        {LED_OFF},      {LED_OFF},      {LED_OFF},      {LED_OFF},      {LED_OFF},
        {LED_YELLOW},   {LED_YELLOW},   {LED_YELLOW},   {LED_YELLOW},   {LED_YELLOW},
        {LED_YELLOW},   {LED_GREEN},    {LED_GREEN},    {LED_GREEN},    {LED_YELLOW},
        {LED_YELLOW},   {LED_GREEN},    {LED_GREEN},    {LED_GREEN},    {LED_GREEN},
        {LED_PURPLE},   {LED_GREEN},    {LED_GREEN},    {LED_GREEN},    {LED_GREEN},
        {LED_OFF},      {LED_OFF},      {LED_OFF},      {LED_OFF},
        {LED_OFF},      {LED_OFF},      {LED_OFF},
        {LED_OFF},      {LED_OFF},      {LED_OFF},
        {LED_OFF}
    },
    [NAV] = {
    // LEFT | LEFT -> RIGHT
        {LED_RED},      {LED_OFF},      {LED_OFF},      {LED_YELLOW},   {LED_OFF},
        {LED_OFF},      {LED_OFF},      {LED_OFF},      {LED_YELLOW},   {LED_OFF},
        {LED_OFF},      {LED_OFF},      {LED_LBLUE},    {LED_YELLOW},   {LED_OFF},
        {LED_OFF},      {LED_LBLUE},    {LED_LBLUE},    {LED_YELLOW},   {LED_OFF},
        {LED_OFF},      {LED_OFF},      {LED_LBLUE},    {LED_YELLOW},   {LED_OFF},
        {LED_OFF},      {LED_OFF},      {LED_OFF},      {LED_OFF},
        {LED_OFF},      {LED_PINK},     {LED_PINK},
        {LED_OFF},      {LED_OFF},      {LED_OFF},
        {LED_OFF},
    // RIGHT | RIGHT -> LEFT
        {LED_OFF},      {LED_OFF},      {LED_OFF},      {LED_OFF},      {LED_OFF},
        {LED_OFF},      {LED_LIME},     {LED_OFF},      {LED_OFF},      {LED_OFF},
        {LED_OFF},      {LED_LIME},     {LED_LBLUE},    {LED_LIME},     {LED_OFF},
        {LED_OFF},      {LED_LBLUE},    {LED_LBLUE},    {LED_LIME},     {LED_OFF},
        {LED_OFF},      {LED_LIME},     {LED_LBLUE},    {LED_LIME},     {LED_OFF},
        {LED_OFF},      {LED_OFF},      {LED_OFF},      {LED_OFF},
        {LED_OFF},      {LED_OFF},      {LED_PINK},
        {LED_PURPLE},   {LED_PURPLE},   {LED_LBLUE},
        {LED_OFF}
    },
    [GAME] = {
    // LEFT | LEFT -> RIGHT
        {LED_LBLUE},    {LED_RED},      {LED_LBLUE},    {LED_TEAL},     {LED_TEAL},
        {LED_YELLOW},   {LED_PURPLE},   {LED_ORANGE},   {LED_PURPLE},   {LED_TEAL},
        {LED_YELLOW},   {LED_ORANGE},   {LED_ORANGE},   {LED_PURPLE},   {LED_YELLOW},
        {LED_YELLOW},   {LED_PURPLE},   {LED_ORANGE},   {LED_PURPLE},   {LED_YELLOW},
        {LED_YELLOW},   {LED_PURPLE},   {LED_PURPLE},   {LED_PURPLE},   {LED_RED},
        {LED_YELLOW},   {LED_PURPLE},   {LED_PURPLE},   {LED_PURPLE},
        {LED_YELLOW},   {LED_YELLOW},   {LED_YELLOW},
        {LED_PURPLE},   {LED_TEAL},     {LED_TEAL},
        {LED_OFF},
    // RIGHT | RIGHT -> LEFT
        {LED_OFF},      {LED_RED},      {LED_RED},      {LED_OFF},      {LED_OFF},
        {LED_YELLOW},   {LED_PURPLE},   {LED_RED},      {LED_RED},      {LED_OFF},
        {LED_YELLOW},   {LED_PURPLE},   {LED_PURPLE},   {LED_RED},      {LED_OFF},
        {LED_YELLOW},   {LED_PURPLE},   {LED_PURPLE},   {LED_RED},      {LED_OFF},
        {LED_YELLOW},   {LED_PURPLE},   {LED_PURPLE},   {LED_PURPLE},   {LED_OFF},
        {LED_YELLOW},   {LED_PURPLE},   {LED_PURPLE},   {LED_PURPLE},
        {LED_YELLOW},   {LED_YELLOW},   {LED_YELLOW},
        {LED_PURPLE},   {LED_PURPLE},   {LED_TEAL},
        {LED_OFF}
    },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
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

void rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return;
  }
  if (keyboard_config.disable_layer_led) { return; }
  set_layer_color(biton32(layer_state));
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}
