// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "print.h"
#include "uuid.h"
#include "send_string_rewrite.h"


enum Layers {
    BASE,
    CLMK,
    LEFT,
    RGHT,
    SYMBOLS,
    SETTINGS,
    MOUSE,
    QUICK_NUMBERS,
    QUICK_SYMBOLS,
};

enum custom_keycodes {
    SH_UUID = SAFE_RANGE,
    SH_TIME,
    SH_REVIEWABLE,
};

#define SH_LPAR S(KC_8)
#define SH_RPAR S(KC_9)
#define SH_LBRK ALGR(KC_8)
#define SH_RBRK ALGR(KC_9)
#define SH_LCBRK ALGR(KC_7)
#define SH_RCBRK ALGR(KC_0)
#define SH_SLSH S(KC_7)


#define MT_J LT(QUICK_NUMBERS, KC_J)
#define MT_K MT(MOD_LSFT, KC_K)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |BCKSP |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |LShift|   Z  |   X  |   C  |   V  |   B  |------         -----|   N  |   M  |   ,  |   .  |   /  |RShift|
    * `-----------------------------------------/      \       /     \-----------------------------------------'
    *                   | LAlt | LGUI | LEFT |  LCTRL  /       \ Enter   | SPACE| RGHT | ALTGR|
    *                   |      |      |      |        /         \        |      |      |      |
    *                   `----------------------------'           '------''--------------------'
    */
    [BASE] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,     KC_3,     KC_4,    KC_5,        KC_6,     KC_7,     KC_8,    KC_9,    KC_0, KC_MINUS,
        KC_TAB,  KC_Q,    KC_W,     KC_E,     KC_R,    KC_T,        KC_Y,     KC_U,     KC_I,    KC_O,    KC_P, KC_LBRC,
        KC_BSPC, KC_A,    KC_S,     KC_D,     KC_F,    KC_G,        KC_H,     MT_J,     MT_K,    KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,     KC_C,     KC_V,    KC_B,        KC_N,     KC_M,  KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                       KC_LALT,  KC_LGUI, MO(LEFT), KC_LCTL,      KC_ENT,   KC_SPC, MO(RGHT), KC_RALT
    ),
    [CLMK] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,     KC_3,    KC_4,      KC_5,       KC_6,   KC_7,     KC_8,    KC_9,    KC_0, KC_MINUS,
        KC_TAB,  KC_Q,    KC_W,     KC_F,    KC_P,      KC_G,       KC_J,   KC_L,     KC_U,    KC_Y, KC_SCLN,  KC_LBRC,
        KC_BSPC, KC_A,    KC_R,     KC_S,    KC_T,      KC_D,       KC_H,   LT(QUICK_NUMBERS, KC_N), MT(MOD_LSFT, KC_E),    KC_I,    KC_O,  KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,     KC_C,    KC_V,      KC_B,       KC_K,   KC_M,  KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                       KC_LALT,   KC_LGUI,MO(LEFT),  KC_LCTL,     KC_ENT, KC_SPC, MO(RGHT), KC_RALT
    ),
    [LEFT] = LAYOUT(
        KC_VOLD,  KC_VOLU,    KC_MPRV,   KC_MPLY,  KC_MNXT,   KC_PSCR,     XXXXXXX,    XXXXXXX,      XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
        KC_MUTE,   KC_GRV,    SH_SLSH,  SH_LCBRK, SH_RCBRK,    KC_EQL,     KC_PGUP, C(KC_LEFT),        KC_UP, C(KC_RGHT), XXXXXXX, XXXXXXX,
        _______,  KC_NUBS, S(KC_NUBS),   SH_LPAR,  SH_RPAR,   KC_RBRC,     KC_PGDN,    KC_LEFT,      KC_DOWN,    KC_RGHT, S(KC_2), KC_BSLS,
        _______, KC_MINUS,    XXXXXXX,   SH_LBRK,  SH_RBRK, MO(MOUSE),     XXXXXXX,    KC_HOME,       KC_END,    XXXXXXX, XXXXXXX, XXXXXXX,
                              _______,   _______,  _______,   _______,     _______,     KC_ESC, MO(SETTINGS),    _______
    ),
    [RGHT] = LAYOUT(
        _______, _______, _______, _______,      _______,  _______,      _______,  _______,  _______,  _______,  _______, QK_BOOT,
        _______, XXXXXXX,    KC_7,    KC_8,         KC_9,  XXXXXXX,      XXXXXXX,    KC_F7,    KC_F8,    KC_F9,   KC_F10,  KC_DEL,
        _______,    KC_0,    KC_4,    KC_5,         KC_6,     KC_0,      XXXXXXX,    KC_F4,    KC_F5,    KC_F6,   KC_F11, KC_CAPS,
        _______, XXXXXXX,    KC_1,    KC_2,         KC_3,   KC_DOT,      XXXXXXX,    KC_F1,    KC_F2,    KC_F3,   KC_F12, XXXXXXX,
                          _______, _______, MO(SETTINGS),  _______,      _______,  _______,  _______,  _______
    ),
    [SYMBOLS] = LAYOUT(
        _______, _______, _______, _______, _______,  _______,      _______,  _______,  _______,  _______, _______, _______,
        _______, XXXXXXX, S(KC_7), S(KC_8), S(KC_9),  XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, S(KC_4), S(KC_5), S(KC_6),  S(KC_0),      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, S(KC_1), S(KC_2), S(KC_3),  XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
                          _______, _______, _______,  _______,      _______,  _______,  _______,  _______
    ),
    [SETTINGS] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, DF(BASE),     XXXXXXX, UG_SATU, UG_HUEU, UG_VALU, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, DF(CLMK),     XXXXXXX, SH_TIME, SH_UUID, SH_REVIEWABLE, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                          XXXXXXX, XXXXXXX,  _______,  XXXXXXX,     XXXXXXX, XXXXXXX, _______, XXXXXXX
    ),
    [MOUSE] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       MS_WHLU, XXXXXXX,   MS_UP, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, MS_ACL0, MS_ACL1, MS_ACL2, _______,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          _______, _______, _______, XXXXXXX,       MS_BTN1, MS_BTN2, _______, XXXXXXX
    ),
    [QUICK_NUMBERS] = LAYOUT(
        _______, _______, _______, _______, _______,  _______,      _______, _______, _______, _______, _______, _______,
        _______,RALT(KC_4),  KC_7,    KC_8,     KC_9,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______,RALT(KC_2),  KC_4,    KC_5,     KC_6,     KC_0,     XXXXXXX, XXXXXXX, MO(QUICK_SYMBOLS), XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX,    KC_1,    KC_2,     KC_3,   KC_DOT,     XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX,
                           _______, _______, _______,  _______,     _______, _______, _______, _______
    ),
    [QUICK_SYMBOLS] = LAYOUT(
        _______, _______, _______, _______, _______,  _______,      _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, S(KC_7), S(KC_8), S(KC_9),  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, S(KC_4), S(KC_5), S(KC_6),  S(KC_0),      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, S(KC_1), S(KC_2), S(KC_3),  XXXXXXX,      XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX,
                          _______, _______, _______,  _______,      _______, _______, _______, _______
    ),
};

/*

[WIN_BASE] = LAYOUT_iso_85(
     KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   RGB_MOD,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_ENT,             KC_PGDN,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_BSLS,            KC_HOME,
     KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(WIN_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[WIN_FN] = LAYOUT_iso_85(
     _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  RGB_TOG,
     _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
     _______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______)
};

*/


void current_uptime_str(char* buffer, int buffer_size, long unsigned int millis) {
    long unsigned int seconds = millis / 1000;
    millis %= 1000;

    long unsigned int minutes = seconds / 60;
    seconds %= 60;

    long unsigned int hours = minutes / 60;
    minutes %= 60;
    hours %= 24;

    int i = 0;
    if (hours > 0) {
        i += snprintf(&buffer[i], buffer_size - i, "%ldh ", hours);
    }

    if (minutes > 0) {
        i += snprintf(&buffer[i], buffer_size - i, "%ldm ", minutes);
    }

    snprintf(&buffer[i], buffer_size - i, "%lds %ldms", seconds, millis);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    int current_layer = get_highest_layer(state);
    switch (current_layer) {
        case BASE:
            rgblight_setrgb_at(0, 25, 0, 0);
            break;
        case CLMK:
            rgblight_setrgb_at(0, 0, 25, 0);
            break;
        default:
            rgblight_setrgb_at(0, 0, 0, 0);
    }

    rgblight_setrgb_at(10, 10, 10, 1);
    return state;
}

void keyboard_post_init_user(void) {
    // Customize these values to desired behaviour
    debug_enable=true;
    debug_matrix=false;
    debug_keyboard=false;
    debug_mouse=false;

    default_layer_state_set_user(default_layer_state);
}

void send_uuid(void) {
    char buffer[150] = { 0 };
    generate_uuid(buffer, sizeof(buffer));
    send_string_rewrite(buffer, sizeof(buffer), CLMK);
    SEND_STRING(buffer);
}

void send_uptime(void) {
    char buffer[150] = "Uptime: ";
    int len = strlen(buffer);
    long unsigned int millis = timer_read32();
    current_uptime_str(buffer + len, sizeof(buffer) - len, millis);
    send_string_rewrite(buffer, sizeof(buffer), CLMK);
    SEND_STRING(buffer);
}

void send_reviewable(void) {
    char buffer[250] =
        ":unicorn:"
        " -waiting-for-risk-review"
        " +waiting-for-team"
        " +risk-review-ongoing"
        " +assignee:@sighol";
    send_string_rewrite(buffer, sizeof(buffer), CLMK);
    SEND_STRING(buffer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case SH_UUID: send_uuid(); return false;
            case SH_TIME: send_uptime(); return false;
            case SH_REVIEWABLE: send_reviewable(); return false;
        }
    }
    return true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_SCLN:
        case KC_SLSH:
        case KC_QUOT:
        case KC_LBRC:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
