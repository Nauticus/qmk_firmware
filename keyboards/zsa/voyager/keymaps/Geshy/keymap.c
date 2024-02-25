// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define N_CTBS MT(MOD_LCTL, KC_BSPC)

/* HOMEROW MODS
 * These are not the standard homerow mods that are placed in the base layer.
 * Standard homerow Implementation can cause misfire on normal typing and get in the way.
 * You can change these however you like. When you navigate to either _NAV or _SYM you'll have those
 * ready to be used. If you find that you need to use mod in combination to other keys not present
 * in the current layer, just let go of the layer trigger and keep holding the modifiers you need.
 * Having the Mods on each hand provides the flexibility of using any mod with any key.
 * */
#define N_HYP  KC_MEH
#define N_OGUI KC_LGUI
#define N_OALT KC_LALT
#define N_OSFT KC_LSFT
#define N_OCTL KC_LCTL

/* LAYERS
 * You can add new layers definitions here.
 * */
enum layers {
    _BASE,  // default layer
    _NAV,
    _SYM,
    _FUN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
                                                     N_CTBS, MO(_NAV),     KC_ENT, KC_SPC
    ),
    [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
                                                     _______, _______,    _______, _______,
    ),
    [_SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
                                                     _______, _______,    _______, _______
    ),
    [_FUN] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
                                                     _______, _______,    _______, _______
    ),
};
