// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "uuid.h"
#include "print.h"


enum Layers {
    BASE,
    NO_MOD_TAP,
    CLMK,
    LEFT,
    RGHT,
    SYMBOLS,
    SETTINGS,
    MOUSE,
    TEMP,
};

enum custom_keycodes {
    SH_UUID = SAFE_RANGE,
    SH_TIME,
};

#define SH_LPAR S(KC_8)
#define SH_RPAR S(KC_9)
#define SH_LBRK ALGR(KC_8)
#define SH_RBRK ALGR(KC_9)
#define SH_LCBRK ALGR(KC_7)
#define SH_RCBRK ALGR(KC_0)
#define SH_SLSH S(KC_7)


// #define MT_D MT(MOD_LSFT, KC_D)

// #define MT_J LT(RGHT, KC_J)
// #define MT_K MT(MOD_LSFT, KC_K)

#define MT_D KC_D
#define MT_J KC_J
#define MT_K KC_K

const uint16_t PROGMEM number_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM symbol_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM number_combo2[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM symbol_combo2[] = {KC_J, KC_I, KC_L, COMBO_END};
combo_t key_combos[] = {
    COMBO(number_combo, MO(RGHT)),
    COMBO(number_combo2, MO(RGHT)),
    COMBO(symbol_combo, MO(SYMBOLS)),
    COMBO(symbol_combo2, MO(SYMBOLS)),
};


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
        KC_BSPC, KC_A,    KC_S,     MT_D,     KC_F,    KC_G,        KC_H,     MT_J,     MT_K,    KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,     KC_C,     KC_V,    KC_B,        KC_N,     KC_M,  KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                       KC_LALT,  KC_LGUI, MO(LEFT), KC_LCTL,      KC_ENT,   KC_SPC, MO(RGHT), KC_RALT
    ),
    [NO_MOD_TAP] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,         KC_6,    KC_7,     KC_8,   KC_9,    KC_0, KC_MINUS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,        KC_Y,    KC_U,     KC_I,   KC_O,    KC_P,  KC_LBRC,
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,      KC_G,        KC_H,    KC_J,     KC_K,   KC_L, KC_SCLN,  KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,        KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,
                       KC_LALT, KC_LGUI, MO(LEFT),  KC_LCTL,      KC_ENT,  KC_SPC, MO(RGHT), KC_RALT
    ),
    [CLMK] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,     KC_3,    KC_4,      KC_5,       KC_6,   KC_7,     KC_8,    KC_9,    KC_0, KC_MINUS,
        KC_TAB,  KC_Q,    KC_W,     KC_F,    KC_P,      KC_G,       KC_J,   KC_L,     KC_U,    KC_Y, KC_SCLN,  KC_LBRC,
        KC_BSPC, KC_A,    KC_R,     KC_S,    KC_T,      KC_D,       KC_H,   KC_N,     KC_E,    KC_I,    KC_O,  KC_QUOT,
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
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(NO_MOD_TAP), DF(BASE),     XXXXXXX, UG_SATU, UG_HUEU, UG_VALU, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, DF(CLMK),     XXXXXXX, SH_TIME, SH_UUID, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                          XXXXXXX, XXXXXXX,  _______,  XXXXXXX,     XXXXXXX, XXXXXXX, _______, XXXXXXX
    ),
    [MOUSE] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_WH_U, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,       KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, _______,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          _______, _______, _______, XXXXXXX,       KC_BTN1, KC_BTN2, _______, XXXXXXX
    ),
    [TEMP] = LAYOUT( // NOT IN USE
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______,       _______, _______, _______, _______
    )
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

// True if the operating system is translating to colemak. False if the keyboard
// is translating to colemak
bool is_os_colemak(void) {
    return default_layer_state & (1 << BASE) || default_layer_state & (1 << NO_MOD_TAP);
}

/*
 * If the OS is in colemak mode, we need to type the qwerty key codes that
 * correspond to the letter.
 */
void colemak_hex_transform(char* buffer, int buffer_size) {
    for (int i = 0; i < buffer_size; i++) {
        if (buffer[i] == 0) {
            return;
        }
        switch (buffer[i]) {
            case 'e': buffer[i] = 'k'; break;
            case 'd': buffer[i] = 'g'; break;
            case 'f': buffer[i] = 'e'; break;
            case 'n': buffer[i] = 'j'; break;
            case 'i': buffer[i] = 'l'; break;
            case 's': buffer[i] = 'd'; break;
            case 'u': buffer[i] = 'i'; break;
            case 'U': buffer[i] = 'I'; break;
            case 'p': buffer[i] = 'r'; break;
            case 't': buffer[i] = 'f'; break;
            case '=': buffer[i] = '\\'; break;
        }
    }
}

void current_uptime_str(char* buffer, int buffer_size, long unsigned int millis) {
    long unsigned int seconds = millis / 1000;
    millis %= 1000;

    long unsigned int minutes = seconds / 60;
    seconds %= 60;

    long unsigned int hours = minutes / 60;
    minutes %= 60;
    hours %= 24;

    int i = snprintf(buffer, buffer_size, "Uptime is ");
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
        case NO_MOD_TAP:
            rgblight_setrgb_at(25, 0, 0, 0);
            break;
        default:
            rgblight_setrgb_at(0, 0, 0, 0);
    }

    rgblight_setrgb_at(10, 10, 10, 1);
    return state;
}

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=false;
    debug_keyboard=false;
    debug_mouse=false;

    default_layer_state_set_user(default_layer_state);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static char buffer[37];
    static char current_time_buffer[50];

    switch (keycode) {
        case SH_UUID:
            if (record->event.pressed) {
                memset(buffer, 0, sizeof(buffer));
                generate_uuid(buffer, sizeof(buffer));
                if (is_os_colemak()) {
                    colemak_hex_transform(buffer, sizeof(buffer));
                }
                SEND_STRING(buffer);
            }
            return false; // Skip all other keycodes
        case SH_TIME:
            if (record->event.pressed) {
                memset(buffer, 0, sizeof(buffer));
                long unsigned int time = timer_read32();
                current_uptime_str(current_time_buffer, sizeof(current_time_buffer), time);
                if (is_os_colemak()) {
                    colemak_hex_transform(current_time_buffer, sizeof(current_time_buffer));
                }
                SEND_STRING(current_time_buffer);
            }
            return false;
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
