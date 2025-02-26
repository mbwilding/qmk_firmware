#pragma once

#include "layers.h"
#include "colors.h"

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [L_BASE] = {
        // Left Keys
        C_PUNCTU, C_SYMBOL, C_SYMBOL, C_SYMBOL, C_SYMBOL, C_OFF,
        C_PUNCTU, C_PUNCTU, C_PUNCTU, C_PUNCTU, C_LETTER, C_LETTER,
        C_SYMBOL, C_LETTER, C_LETTER, C_LETTER, C_LETTER, C_LETTER,
        C_SYMBOL, C_PUNCTU, C_LETTER, C_LETTER, C_LETTER, C_LETTER,

        // Left Thumbs
        C_LAYER,  C_LAYER,

        // Right Keys
        C_OFF,    C_SYMBOL, C_SYMBOL, C_SYMBOL, C_SYMBOL, C_SYMBOL,
        C_LETTER, C_LETTER, C_LETTER, C_LETTER, C_LETTER, C_PUNCTU,
        C_LETTER, C_LETTER, C_LETTER, C_LETTER, C_LETTER, C_SYMBOL,
        C_LETTER, C_LETTER, C_LETTER, C_LETTER, C_LETTER, C_SYSTEM,

        // Right Thumbs
        C_LAYER,  C_LAYER
    },

    [L_SYMB] = {
        // Left Keys
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_SYMBOL, C_SYMBOL, C_SYMBOL, C_SYMBOL, C_OFF,
        C_OFF,    C_SYMBOL, C_SYMBOL, C_SYMBOL, C_SYMBOL, C_OFF,
        C_OFF,    C_SYMBOL, C_SYMBOL, C_OFF,    C_OFF,    C_OFF,

        // Left Thumbs
        C_LAYER,  C_LAYER,

        // Right Keys
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_SYMBOL, C_SYMBOL, C_SYMBOL, C_SYMBOL, C_OFF,
        C_OFF,    C_OFF,    C_OFF,    C_SYMBOL, C_SYMBOL, C_OFF,

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

    [L_MISC] = {
        // Left Keys
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_OFF,    C_OFF,    C_SYSTEM, C_SYSTEM, C_OFF,

        // Left Thumbs
        C_LAYER,  C_LAYER,

        // Right Keys
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_SYSTEM  C_OFF,
        C_OFF,    C_SYSTEM, C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,

        // Right Thumbs
        C_LAYER,  C_LAYER
    },

    [L_MIDI] = {
        // Left Keys
        C_LAYER,  C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,

        // Left Thumbs
        C_LAYER,  C_LAYER,

        // Right Keys
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_LAYER,
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,
        C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,    C_OFF,

        // Right Thumbs
        C_LAYER,  C_LAYER
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
    }
};
