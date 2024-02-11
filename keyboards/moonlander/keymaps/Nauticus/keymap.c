/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "version.h"

// delete word
#define N_DELW LALT(KC_BSPC)

#define N_CTBS MT(MOD_LCTL, KC_BSPC)

// change yabai layout
#define N_CLAY MEH(KC_A)
#define N_ENSY LT(_SYM, KC_ENT)

// change to second gaming layer
#define N_TOGT LT(_G_TWO, KC_ENT)

// One-shot mods
#define N_HYP OSM(MOD_MEH)
#define N_OGUI OSM(MOD_LGUI)
#define N_OALT OSM(MOD_LALT)
#define N_OSFT OSM(MOD_LSFT)
#define N_OCTL OSM(MOD_LCTL)

#define N_CPPS TD(TD_PCPS)

enum layers {
    _BASE,  // default layer
    _G_ONE,    // gaming layer
    _G_TWO,    // gaming layer
    _NAV,
    _SYM,
    _MOUSE,
    _FUN,
};

enum custom_keycodes {
    OS_NOOP = SAFE_RANGE,
    OS_N1 = KC_PLUS,
    OS_N2 = KC_LBRC,
    OS_N3 = KC_LCBR,
    OS_N4 = KC_LPRN,
    OS_N5 = KC_AMPR,
    OS_N6 = KC_EQL,
    OS_N7 = KC_RPRN,
    OS_N8 = KC_RCBR,
    OS_N9 = KC_RBRC,
    OS_N0 = KC_ASTR,
    OS_TEST,
};

const key_override_t n1_plus_override = ko_make_basic(MOD_MASK_SHIFT, OS_N1, KC_1);
const key_override_t n2_lbrc_override = ko_make_basic(MOD_MASK_SHIFT, OS_N2, KC_2);
const key_override_t n3_lcbr_override = ko_make_basic(MOD_MASK_SHIFT, OS_N3, KC_3);
const key_override_t n4_lprn_override = ko_make_basic(MOD_MASK_SHIFT, OS_N4, KC_4);
const key_override_t n5_ampr_override = ko_make_basic(MOD_MASK_SHIFT, OS_N5, KC_5);
const key_override_t n6_eql_override  = ko_make_basic(MOD_MASK_SHIFT, OS_N6, KC_6);
const key_override_t n7_rprn_override = ko_make_basic(MOD_MASK_SHIFT, OS_N7, KC_7);
const key_override_t n8_rcbr_override = ko_make_basic(MOD_MASK_SHIFT, OS_N8, KC_8);
const key_override_t n9_rbrc_override = ko_make_basic(MOD_MASK_SHIFT, OS_N9, KC_9);
const key_override_t n0_astr_override = ko_make_basic(MOD_MASK_SHIFT, OS_N0, KC_0);

const key_override_t **key_overrides = (const key_override_t *[]) {
    &n1_plus_override,
    &n2_lbrc_override,
    &n3_lcbr_override,
    &n4_lprn_override,
    &n5_ampr_override,
    &n6_eql_override,
    &n7_rprn_override,
    &n8_rcbr_override,
    &n9_rbrc_override,
    &n0_astr_override,
    NULL
};

enum {
    TD_PCPS = 0,
};

void pcps_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LGUI);
        register_code(KC_C);
        unregister_code(KC_C);
        unregister_code(KC_LGUI);
    } else if (state->count == 2) {
        register_code(KC_LGUI);
        register_code(KC_V);
        unregister_code(KC_V);
        unregister_code(KC_LGUI);
    }
};

// Tap Dance Declarations
tap_dance_action_t tap_dance_actions[] = {
    [TD_PCPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, pcps_finished, NULL),
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_moonlander(
        KC_GRV,    OS_N1,   OS_N2,    OS_N3,   OS_N4,   OS_N5,    LED_LEVEL,       _______, OS_N6,  OS_N7,   OS_N8,   OS_N9,   OS_N0,   KC_BSLS,
        KC_TAB,    KC_SCLN, KC_COMMA, KC_DOT,  KC_P,    KC_Y,     _______,         _______, KC_F,   KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        KC_ESC,    KC_A,    KC_O,     KC_E,    KC_U,    KC_I,     _______,         _______, KC_D,   KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
        KC_LSFT,   KC_QUOT, KC_Q,     KC_J,    KC_K,    KC_X,                               KC_B,   KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
        _______,   _______, _______,  _______, _______,           _______,         _______,         _______, _______, _______, _______, _______,
                                               N_CTBS,  MO(_NAV), _______,         _______, N_ENSY, KC_SPC
    ),
    [_G_ONE] = LAYOUT_moonlander(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   XXXXXXX,           XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LALT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   XXXXXXX,           XXXXXXX, TG(_G_ONE), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   XXXXXXX,           XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,           XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            KC_SPC,  N_TOGT, XXXXXXX,           XXXXXXX, XXXXXXX,    XXXXXXX
    ),
    [_G_TWO] = LAYOUT_moonlander(
        KC_ESC,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LALT, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LCTL, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,           XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_NAV] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, N_CPPS,  _______, _______, _______,           _______, KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
        _______, N_OGUI,  N_OALT,  N_OSFT,  N_OCTL,  _______, _______,           _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_ENT,
        _______, N_HYP,   _______, _______, _______, _______,                             _______, N_CLAY,  N_DELW,  _______, KC_PGDN, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
    [_MOUSE] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_ACL2, _______, KC_WH_U, _______, _______, _______,           _______, _______, _______, KC_MS_U, _______, _______, _______,
        _______, KC_ACL1, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______,           _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
        _______, KC_ACL0, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, KC_MS_BTN2, KC_MS_BTN1
    ),
    [_SYM] = LAYOUT_moonlander(
        _______, C(KC_1), C(KC_2), C(KC_3), C(KC_4), C(KC_5), _______,           _______, C(KC_6), C(KC_7), C(KC_8), C(KC_9), C(KC_0), KC_DEL,
        _______, KC_HASH, KC_DLR,  KC_LBRC, KC_RBRC, KC_AMPR, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_PLUS, KC_LPRN, KC_RPRN, KC_EQL,  _______,           _______, _______, N_OCTL,  N_OSFT,  N_OALT,  N_OGUI,  _______,
        _______, KC_AT,   KC_PERC, KC_LCBR, KC_RCBR, KC_ASTR,                             _______, _______, _______, _______, N_HYP,   _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
    [_FUN] = LAYOUT_moonlander(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______,    _______, _______, _______, _______, KC_F12,
        _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,           _______, TO(_G_ONE), _______, _______, _______, _______, _______,
        _______, _______, _______, KC_VOLD, KC_VOLU, _______,                             _______,    _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,             _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______,    _______
    ),
};

// clang-format on

// [EXAMPLE] = LAYOUT_moonlander(
//     _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
//                                         _______, _______, _______,           _______, _______, _______
// ),

void keyboard_post_init_user(void) {
    rgblight_disable_noeeprom();
    rgb_matrix_disable();
    // debug_enable=true;
};

// caps word setup
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
        case KC_LSFT:
        case KC_RSFT:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case N_CTBS:
        case N_ENSY:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _G_ONE:
        case _G_TWO:
        case _FUN:
            rgb_matrix_enable();
            // rgb_matrix_sethsv(0, 0, 175);
            break;
        default:
            rgb_matrix_disable();
    }

    return update_tri_layer_state(state, _NAV, _SYM, _FUN);
}
