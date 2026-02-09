// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include "keymap_us.h"
#include QMK_KEYBOARD_H

// thumb-keys
#define N_CTBS MT(MOD_LCTL, KC_BSPC)
#define N_ENSY LT(_SYM, KC_ENT)

// One-shot mods
#define N_HYP  KC_MEH
#define N_OGUI KC_LGUI
#define N_OALT KC_LALT
#define N_OSFT KC_LSFT
#define N_OCTL KC_LCTL

enum layers {
    _BASE,  // default layer
    _GAME, // gaming layer
    _NAV,
    _SYM,
    _FUN,
};

enum custom_keycodes {
    OS_NOOP = SAFE_RANGE,
    N_1 = KC_PLUS,
    N_2 = KC_LBRC,
    N_3 = KC_LCBR,
    N_4 = KC_LPRN,
    N_5 = KC_AMPR,
    N_6 = KC_EQL,
    N_7 = KC_RPRN,
    N_8 = KC_RCBR,
    N_9 = KC_RBRC,
    N_0 = KC_ASTR,
    OS_TEST,
};

/* KEY OVERRIDES
 * These help to override the number keys with symbols. So you get symbols shifted and numbers unshifted.
 * These are most common symbols that are used in programming. You can change them hovewer you like.
 */
const key_override_t n1_plus_override = ko_make_basic(MOD_MASK_SHIFT, N_1, KC_1);
const key_override_t n2_lbrc_override = ko_make_basic(MOD_MASK_SHIFT, N_2, KC_2);
const key_override_t n3_lcbr_override = ko_make_basic(MOD_MASK_SHIFT, N_3, KC_3);
const key_override_t n4_lprn_override = ko_make_basic(MOD_MASK_SHIFT, N_4, KC_4);
const key_override_t n5_ampr_override = ko_make_basic(MOD_MASK_SHIFT, N_5, KC_5);
const key_override_t n6_eql_override  = ko_make_basic(MOD_MASK_SHIFT, N_6, KC_6);
const key_override_t n7_rprn_override = ko_make_basic(MOD_MASK_SHIFT, N_7, KC_7);
const key_override_t n8_rcbr_override = ko_make_basic(MOD_MASK_SHIFT, N_8, KC_8);
const key_override_t n9_rbrc_override = ko_make_basic(MOD_MASK_SHIFT, N_9, KC_9);
const key_override_t n0_astr_override = ko_make_basic(MOD_MASK_SHIFT, N_0, KC_0);

const key_override_t *key_overrides[] = {
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
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_GRV,  N_1,     N_2,     N_3,     N_4,     N_5,                       N_6,    N_7,     N_8,     N_9,     N_0,     KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            MT(MOD_LCTL, KC_BSPC), MO(_NAV), LT(_SYM, KC_ENT), KC_SPC
    ),
    [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, G(KC_C), G(KC_V), _______,                   KC_TAB,  KC_BSPC, KC_UP,   KC_DEL,  KC_PGUP, _______,
        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGDN, KC_ENT,
        _______, KC_MEH,  _______, _______, _______, _______,                   KC_HOME, KC_END,  _______, _______, _______, _______,
                                                     _______, _______, _______, _______
    ),
    [_SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   _______, _______, _______, _______, _______, _______,
        _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS,                   _______, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, KC_MEH,  _______,
                                                     _______, _______, _______, _______
    ),
    [_FUN] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______,                   TO(_GAME), _______, _______, _______,  UG_TOGG, KC_F12,
        _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT,                   _______,    _______, _______, _______, _______, _______,
        _______, _______, _______, KC_VOLD, KC_VOLU, _______,                   _______,    _______, _______, _______, _______, _______,
                                                     _______, _______, _______, _______
    ),
    // -- Gaming Layers [START] --
    [_GAME] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
                                                     KC_SPC, MO(_NAV), LT(_FUN, KC_ENT), KC_SPC
    ),
    // -- Gaming Layers [END] --
};

void keyboard_post_init_user(void) {
    rgblight_mode(1);
    rgblight_sethsv(0, 0, 64);
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
        case MT(MOD_LCTL, KC_BSPC):
        case LT(_SYM, KC_ENT):
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case N_CTBS:
            return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;
    }
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _SYM, _FUN);
};

/* TURN OFF RGB AFTER TIMEOUT
 * This feature will turn off the RGB after a certain amount of time has passed since the last keypress.
 */

static uint32_t key_timer;           // timer for last keyboard activity, use 32bit value and function to make longer idle time possible
static void refresh_rgb(void);       // refreshes the activity timer and RGB, invoke whenever any activity happens
static void check_rgb_timeout(void); // checks if enough time has passed for RGB to timeout
bool is_rgb_timeout = false;         // store if RGB has timed out or not in a boolean

void refresh_rgb(void) {
    key_timer = timer_read32(); // store time of last refresh
    if (is_rgb_timeout)
    {
        is_rgb_timeout = false;
        rgblight_enable_noeeprom();
    }
}
void check_rgb_timeout(void) {
    if (!is_rgb_timeout && timer_elapsed32(key_timer) > RGBLIGHT_TIMEOUT) // check if RGB has already timeout and if enough time has passed
    {
        rgblight_disable_noeeprom();
        is_rgb_timeout = true;
    }
}

/* Then, call the above functions from QMK's built in post processing functions like so */
/* Runs at the end of each scan loop, check if RGB timeout has occured or not */
void housekeeping_task_user(void) {
#ifdef RGBLIGHT_TIMEOUT
    check_rgb_timeout();
#endif
}

/* Runs after each key press, check if activity occurred */
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef RGBLIGHT_TIMEOUT
    if (record->event.pressed)
        refresh_rgb();
#endif
}

/* Runs after each encoder tick, check if activity occurred */
void post_encoder_update_user(uint8_t index, bool clockwise) {
#ifdef RGBLIGHT_TIMEOUT
    refresh_rgb();
#endif
}
