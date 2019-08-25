#include QMK_KEYBOARD_H

/*
 * Inspired by SpaceFN
 * http://geekhack.org/index.php?topic=51069.0
 */

/*
 * TODO: 
 * media keys, backlight control
 */

enum keyboard_layers {
  _QWERTY,
  _SPACEFN,
  _NUMPAD
};

enum td_keycodes {
  _TD_SHFT_CAPS
};

// Tap Dance definition
qk_tap_dance_action_t tap_dance_actions[] = {
  // tap once for SHIFT, twice for Caps Lock
  [_TD_SHFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

// KC_TRANS
#define ___ _______ 
// Momentarily activate SpaceFN layer, normal SPACE when tapped 
#define SPACE_FN LT(_SPACEFN, KC_SPC)
// Ctrl when held, Enter when tapped
#define CTL_ENT LCTL_T(KC_ENT)
// Toggle Numpad layer
#define NUMPAD TG(_NUMPAD)
// Tap once for SHIFT, twice for Caps Lock
#define SHFT_CAPS TD(_TD_SHFT_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Default: Qwerty 
 */
[_QWERTY] = LAYOUT_60_ansi(
         GRAVE_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,    KC_BSPC,
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,    KC_RBRC,   KC_BSLS,
         CTL_ENT,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,    KC_ENT,
         SHFT_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
         KC_CAPS,   KC_LGUI, KC_LALT,                            SPACE_FN,                           NUMPAD,  KC_RGUI,    KC_APP,    KC_RCTL
),

/* Overlay1: SpaceFN 
 */
[_SPACEFN] = LAYOUT_60_ansi(
         ___,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
         ___,    KC_END,  KC_HOME, KC_UP,   KC_PGUP, KC_PGDN, ___,     ___,     ___,     ___,     ___,     ___,     ___,     KC_GRAVE,
         ___,    ___,     KC_LEFT, KC_DOWN, KC_RGHT, ___,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ___,     ___,     ___,
         ___,    ___,     ___,     ___,     ___,     ___,     ___,     ___,     ___,     ___,     ___,     ___,
         ___,    ___,     ___,                               ___,                                 ___,     ___,     ___,     ___
),

/* Overlay2: NumPad (and Navigation) 
 */
[_NUMPAD] = LAYOUT_60_ansi(
         ___,    ___,     ___,     ___,     ___,     ___,     ___,     KC_P7,   KC_P8,   KC_P9,   ___,     ___,     ___,     ___,
         ___,    KC_END,  KC_HOME, KC_UP,   KC_PGUP, KC_PGDN, ___,     KC_P4,   KC_P5,   KC_P6,   ___,     ___,     ___,     ___,
         ___,    ___,     KC_LEFT, KC_DOWN, KC_RGHT, ___,     ___,     KC_P1,   KC_P2,   KC_P3,   ___,     ___,     ___,
         ___,    ___,     ___,     ___,     ___,     ___,     ___,     KC_P0,   ___,     ___,     ___,     ___,
         ___,    ___,     ___,                               ___,                                 ___,     ___,     ___,     ___
),
};

