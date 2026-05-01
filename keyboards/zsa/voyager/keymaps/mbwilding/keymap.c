// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "version.h"

// #include "features/achordion.h"
#include "keys.h"
#include "leds.h"

extern rgb_config_t rgb_matrix_config;

#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
};

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
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (rawhid_state.rgb_control || keyboard_config.disable_layer_led) return false;

    uint32_t layer = biton32(layer_state);
    if (layer < TOTAL_LAYERS) {
        set_layer_color(layer);
    } else {
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // if (!process_achordion(keycode, record)) return false;

    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}

// void housekeeping_task_user(void) {
//     achordion_task();
// }

// uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
//     // If you quickly hold a tap-hold key after tapping it, the tap action is
//     // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
//     // lead to missed triggers in fast typing. Here, returning 0 means we
//     // instead want to "force hold" and disable key repeating.
//     switch (keycode) {
//         case HOME_N:
//         // Repeating is useful for Vim navigation keys.
//         case QHOME_J:
//         case QHOME_K:
//         case QHOME_L:
//             return QUICK_TAP_TERM; // Enable key repeating.
//         default:
//             return 0; // Otherwise, force hold and disable key repeating.
//     }
// }

// bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         // Left
//         case CTL_T(KC_A):
//         case GUI_T(KC_O):
//         case ALT_T(KC_E):
//         case ALL_T(KC_SCLN):
//         case MEH_T(KC_Q):
//
//         // Right
//         case ALT_T(KC_T):
//         case RGUI_T(KC_N):
//         case RCTL_T(KC_S):
//         case MEH_T(KC_V):
//         case ALL_T(KC_Z):
//
//         // Thumbs
//         case SFT_T(KC_SPACE):
//             // Immediately select the hold action when another key is tapped.
//             return true;
//         default:
//             // Do not select the hold action when another key is tapped.
//             return false;
//     }
// }
