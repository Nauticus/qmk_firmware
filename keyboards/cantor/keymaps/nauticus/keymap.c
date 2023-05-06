// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
        KC_NO, KC_SCLN,    KC_COMM,    KC_DOT,    KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_NO,
        KC_NO, KC_A,       KC_O,       KC_E,      KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_NO,
        KC_NO, KC_QUOTE,   KC_Q,       KC_J,      KC_K,    KC_X,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
                                       KC_LGUI,   KC_SPC,  KC_BSPC, KC_ENT,  KC_SPC,  KC_RALT
    )

    [1] = LAYOUT_split_3x6_3(
        KC_NO, KC_SCLN,    KC_COMM,    KC_DOT,    KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_NO,
        KC_NO, KC_A,       KC_O,       KC_E,      KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_NO,
        KC_NO, KC_QUOTE,   KC_Q,       KC_J,      KC_K,    KC_X,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
                                       KC_LGUI,   KC_SPC,  KC_BSPC, KC_ENT,  KC_SPC,  KC_RALT
    )
};

