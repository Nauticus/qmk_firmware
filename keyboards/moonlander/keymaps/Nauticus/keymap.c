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
#include "oneshot.h"

#define L_NAV LT(NAV, KC_ENT)

enum layers {
    BASE,  // default layer
    NAV,
    QWERTY,
};

enum custom_keycodes {
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
    OS_FST = KC_DLR,
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
    OS_LST = KC_EXLM,
    OS_RB1 = KC_AT,
    OS_RB2 = KC_BSLS,
    OS_MEH,
};

const key_override_t n1_plus_override = ko_make_basic(MOD_MASK_SHIFT, OS_N1, KC_1);
const key_override_t n2_lbrc_override = ko_make_basic(MOD_MASK_SHIFT, OS_N2, KC_2);
const key_override_t n3_lcbr_override = ko_make_basic(MOD_MASK_SHIFT, OS_N3, KC_3);
const key_override_t n4_lprn_override = ko_make_basic(MOD_MASK_SHIFT, OS_N4, KC_4);
const key_override_t n5_ampr_override = ko_make_basic(MOD_MASK_SHIFT, OS_N5, KC_5);
const key_override_t n6_eql_override = ko_make_basic(MOD_MASK_SHIFT, OS_N6, KC_6);
const key_override_t n7_rprn_override = ko_make_basic(MOD_MASK_SHIFT, OS_N7, KC_7);
const key_override_t n8_rcbr_override = ko_make_basic(MOD_MASK_SHIFT, OS_N8, KC_8);
const key_override_t n9_rbrc_override = ko_make_basic(MOD_MASK_SHIFT, OS_N9, KC_9);
const key_override_t n0_astr_override = ko_make_basic(MOD_MASK_SHIFT, OS_N0, KC_0);
const key_override_t hash_dllr_override = ko_make_basic(MOD_MASK_SHIFT, OS_FST, KC_HASH);
const key_override_t perc_excl_override = ko_make_basic(MOD_MASK_SHIFT, OS_LST, KC_PERC);
const key_override_t circ_at_override = ko_make_basic(MOD_MASK_SHIFT, OS_RB1, KC_CIRC);
const key_override_t pipe_bsls_override = ko_make_basic(MOD_MASK_SHIFT, OS_RB2, KC_PIPE);

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
    &hash_dllr_override,
    &perc_excl_override,
    &circ_at_override,
    &pipe_bsls_override,
    NULL
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        OS_FST,  OS_N1,   OS_N2,   OS_N3,   OS_N4,   OS_N5,  _______,            _______, OS_N6,   OS_N7,   OS_N8,   OS_N9,   OS_N0,   OS_LST,
        KC_TAB,  KC_SCLN, KC_COMMA,KC_DOT,  KC_P,    KC_Y,   _______,            _______, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,   _______,            _______, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
        KC_LSFT, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,                                KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
        _______, KC_GRV,  CW_TOGG, KC_LEFT, KC_RGHT,         KC_LCTL,            KC_RCTL,          KC_DOWN, KC_UP,   OS_RB1,  OS_RB2,  _______,
                                            KC_BSPC, KC_DEL, KC_LGUI,            KC_RGUI, L_NAV,   KC_SPC
    ),
    [NAV] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,           _______, _______, OS_CTRL, OS_SHFT, OS_ALT,  OS_CMD,  _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, OS_MEH,  _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    if (keycode == KC_ESC) {
        return true;
    }
    return false;
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case KC_LSFT:
        case KC_RSFT:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
        case L_NAV:
            return true;
        default:
            return false;
    }
}

void keyboard_post_init_user(void) {
    rgblight_disable_noeeprom();
    rgb_matrix_disable();
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;
oneshot_state os_meh_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, MOD_MASK_SHIFT, OS_SHFT,
        keycode, record
    );

    update_oneshot(
        &os_ctrl_state, MOD_MASK_CTRL, OS_CTRL,
        keycode, record
    );

    update_oneshot(
        &os_alt_state, MOD_MASK_ALT, OS_ALT,
        keycode, record
    );

    update_oneshot(
        &os_cmd_state, MOD_MASK_GUI, OS_CMD,
        keycode, record
    );

    // update_oneshot(
    //     &os_meh_state, MOD_MASK_CAG, OS_MEH,
    //     keycode, record
    // );

    return true;
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//         case NAV:
//             rgb_matrix_enable();
//             rgb_matrix_sethsv(0, 0, 175);
//             break;
//         default:
//             rgb_matrix_disable();
//     }
//
//     return state;
// }
