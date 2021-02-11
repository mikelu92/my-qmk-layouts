#include QMK_KEYBOARD_H
#include "mikelu.h"

// test

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT(
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
      KC_BSPC, KC_A,    ALT_HL,  GUI_HL,  CTL_HL,  KC_I,                                         KC_D,    CTL_HR,  GUI_HR,  ALT_HR,  KC_S,    KC_MINS,
      KC_HYPR, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_SPC,  KC_ESC,   KC_PGUP, SFT_ENT, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_EQL,
                                 TAP_SFT, KC_LGUI, OSLOW,   KC_SPC,  KC_TAB,   KC_PGDN, SFT_ENT, RAISE,   ARROWS,  KC_LEAD
    ),

    [_QWERTY] = LAYOUT(
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,  KC_LALT,  KC_HYPR, SFT_ENT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                 KC_HYPR, KC_LGUI, LOWER,   KC_SPC,  CTL_ESC,  KC_LALT, SFT_ENT, RAISE,   ARROWS,  KC_LEAD
    ),

    [_LOWER] = LAYOUT(
      KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
      _______, KC_EXLM, ALT_HL2, GUI_HL2, CTL_HL2, KC_PERC,                                      KC_CIRC, CTL_HR2, GUI_HR2, ALT_HR2, KC_RPRN, KC_DQT ,
      DSP_OFF, KC_COLN, KC_TILD, KC_LCBR, KC_RCBR, ARROWS,  _______, _______,  KC_VOLU, _______, KC_PIPE, KC_LBRC, KC_RBRC, TABU_N,  TABD_N,  COL_EQL,
                                 _______, _______, _______, _______, _______,  KC_VOLD, _______, _______, KC_LCTL, KC_LALT
    ),

    [_RAISE] = LAYOUT(
      _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,                                      _______, _______, CHKESC,  _______, _______, _______,
      _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   CTL_U,                                        _______, AUTOFIL, TMUXPRF, TABU_N,  TABD_N,  _______,
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   CTL_D,   _______, _______,  RGB_MOD, _______, SCRNLYR, SRCHPWD, VIMWIND, SWPL,    SWPR,    KC_BTN1,
                                 _______, _______, _______, _______, _______,  RGB_TOG, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
      RESET  , QWERTY,  _______, KC_UP,   _______, _______,                                      _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_RGHT, _______,
      _______, _______, ALT_L,   KC_DOWN, ALT_R,   _______,                                      DVORAK,  KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
      _______, CHNGOS,  _______, KC_DOWN, _______, _______, _______, _______,  _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE,
                                 _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
    ),

    [_ARROWS] = LAYOUT(
      _______, _______, _______, KC_UP,   _______, KC_HOME,                                      KC_PGUP, _______, KC_UP,   _______, KC_RGHT, _______,
      _______, _______, ALT_L,   KC_DOWN, ALT_R,   KC_END,                                       KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
      _______, _______, _______, KC_DOWN, KC_UP,   KC_HOME, _______, KC_LALT,  CTL_SFT, KC_LCTL, _______, _______, _______, SWPL,    SWPR,    _______,
                                 _______, _______, KC_END,  _______, KC_LCTL,  _______, KC_LCTL, _______, _______, _______
    ),
};
