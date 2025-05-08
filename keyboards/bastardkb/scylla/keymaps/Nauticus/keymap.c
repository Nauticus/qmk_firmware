#include QMK_KEYBOARD_H

enum layer_names { _BASE, _NAV, _SYM, _FUN };

#define N_HYP  KC_MEH
#define N_OGUI KC_LGUI
#define N_OALT KC_LALT
#define N_OSFT KC_LSFT
#define N_OCTL KC_LCTL

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
};

/* KEY OVERRIDES
 * These help to override the number keys with symbols. So you get symbols unshifted and numbers with shift.
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_4x6_5(
        KC_GRV,  N_1,     N_2,     N_3,      N_4,     N_5,         N_6,     N_7,     N_8,     N_9,     N_0,     KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_ESC,  KC_A,    KC_S,    KC_D,     KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                   MO(_NAV), KC_BSPC, KC_ESC,      KC_ENT,  KC_SPC,  MO(_SYM),
                                             KC_LCTL, KC_LGUI,     KC_LALT, KC_RCTL
    ),
    [_NAV] = LAYOUT_split_4x6_5(
        _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,     _______, KC_TAB,  KC_BSPC, KC_DEL,  KC_PGUP, _______,
        _______, N_OGUI,  N_OALT,  N_OSFT,  N_OCTL,  _______,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGDN, _______,
        _______, N_HYP,   _______, _______, _______, _______,     _______, KC_HOME, _______, KC_END,  _______, _______,
                                   _______, _______, _______,     _______, _______, _______,
                                            _______, _______,     _______, _______
    ),
    [_SYM] = LAYOUT_split_4x6_5(
        _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     _______, _______, _______, _______, _______, _______,
        _______, KC_CIRC, _______, _______, _______, _______,     _______, N_OCTL,  N_OSFT,  N_OALT,  N_OGUI,  _______,
        _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, N_HYP,   _______,
                                   _______, _______, _______,     _______, _______, _______,
                                            _______, _______,     _______, _______
    ),
    [_FUN] = LAYOUT_split_4x6_5(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, KC_F12,
        _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT,     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_VOLD, KC_VOLU, _______,     QK_RBT,  _______, _______, _______, _______, _______,
                                   _______, _______, _______,     _______, _______, _______,
                                            _______, _______,     _______, _______
    ),
};

      // _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
      // _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
      // _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
      // _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
      //                            _______, _______, _______,     _______, _______, _______,
      //                                     _______, _______,     _______, _______,

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

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _SYM, _FUN);
}
