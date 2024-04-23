// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define BASE 0
#define SYMB 1
#define NUMB 2
#define TEMP 3

#define SH_LPAR S(KC_8)
#define SH_RPAR S(KC_9)
#define SH_LBRK ALGR(KC_8)
#define SH_RBRK ALGR(KC_9)
#define SH_LCBRK ALGR(KC_7)
#define SH_RCBRK ALGR(KC_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,     KC_3,     KC_4,      KC_5,          KC_6,    KC_7,    KC_8,      KC_9,     KC_0,   KC_PLUS,
        KC_TAB,  KC_Q,    KC_W,     KC_E,     KC_R,      KC_T,          KC_Y,    KC_U,    KC_I,      KC_O,     KC_P,   KC_LBRC,
        KC_BSPC, KC_A,    KC_S,     KC_D,     KC_F,      KC_G,          KC_H,    KC_J,    KC_K,      KC_L,  KC_SCLN,   KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,     KC_C,     KC_V,      KC_B,          KC_N,    KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,   KC_RSFT,
                       KC_LALT,   KC_ENT, MO(SYMB),   KC_LCTL,          KC_ENT,  KC_SPC, MO(NUMB),   KC_RALT
    ),
    [SYMB] = LAYOUT(
        KC_VOLD, KC_VOLU, KC_MPRV,   KC_MPLY,  KC_MNXT, _______,      _______,  _______,  _______,   _______,   _______, _______,
        KC_MUTE, _______, _______,  SH_LCBRK, SH_RCBRK, _______,      _______, C(KC_LEFT), KC_UP, C(KC_RGHT),   _______, _______,
         KC_DEL, _______, _______,   SH_LPAR,  SH_RPAR, _______,      KC_PGUP,  KC_LEFT,   KC_DOWN,  KC_RGHT,   _______, _______,
        _______, _______, _______,   SH_LBRK,  SH_RBRK, _______,      KC_PGDN,  KC_HOME,   KC_END,   _______,   _______, _______,
                           _______,  _______,  _______, _______,      _______,  _______,  _______,   _______
    ),

    [NUMB] = LAYOUT(
        _______, _______, _______, _______, _______,  _______,           _______,  _______,  _______,  _______,  _______, _______,
        _______, _______,    KC_7,    KC_8,    KC_9,  _______,           _______,    KC_F7,    KC_F8,    KC_F9,   KC_F10, _______,
        _______, _______,    KC_4,    KC_5,    KC_6,  KC_0,              _______,    KC_F4,    KC_F5,    KC_F6,   KC_F11, _______,
        _______, _______,    KC_1,    KC_2,    KC_3,  _______,           _______,    KC_F1,    KC_F2,    KC_F3,   KC_F12, _______,
                          _______, _______, _______,  _______,           _______,  _______,  _______,  _______
    ),

    [TEMP] = LAYOUT( // NOT IN USE
        _______, _______,    _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______, _______,
        _______, _______,    _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______, _______,
        _______, _______,    _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______, _______,
        _______, _______,    _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______, _______,
                             _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______
    )
};
