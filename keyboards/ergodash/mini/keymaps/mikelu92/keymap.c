#include QMK_KEYBOARD_H
#include "mikelu.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT( \
     KC_GRV,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,   KC_HOME,                        KC_PGUP, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, \
     KC_BSPC, KC_A,    ALT_HL,  GUI_HL,  CTL_HL,  KC_I,   KC_END,                         KC_PGDN, KC_D,    CTL_HR,  GUI_HR,  ALT_HR, KC_S,     KC_MINS, \
     KC_HYPR, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,   KC_ESC,                         SFT_ENT, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_EQL,  \
     TAP_RSE, TAP_SFT, CMBSRT,  CMBSRT,           OSLOW,  KC_SPC,  KC_TAB,       SFT_ENT, SFT_ENT, RAISE,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),

  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_HOME,                        KC_PGUP, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_END,                         KC_PGDN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC ,                        KC_SPC , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
    KC_LCTL, KC_HYPR, KC_LALT, _______,          LOWER,   KC_SPC , KC_DEL,       KC_SPC,  KC_SPC , RAISE,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),
  [_LOWER] = LAYOUT( \
    KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
    _______, KC_EXLM, ALT_HL2, GUI_HL2, CTL_HL2, KC_PERC, _______,                        _______, KC_CIRC, CTL_HR2, GUI_HR2, ALT_HR2, KC_RPRN, KC_DQT , \
    KC_DEL,  KC_COLN, KC_TILD, KC_LCBR, KC_RCBR, ARROWS,  _______,                        _______, KC_PIPE, KC_LBRC, KC_RBRC, TABU,    TABD,    COL_EQL, \
    DSP_OFF, _______, _______, _______,          _______, _______, _______,      _______, _______, _______,          TAP_GUI, TAP_ALT, KC_VOLU, KC_MUTE  \
  ),

  [_RAISE] = LAYOUT( \
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,                        _______, _______, _______, CHKESC,  KC_J,    KC_K,    _______,  \
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   CTL_U,   _______,                        _______, _______, AUTOFIL, TMUXPRF, TABU,    TABD,    _______, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   CTL_D,   _______,                        _______, SCRNLYR, SRCHPWD, VIMWIND, SWPL,    SWPR,    KC_BTN1, \
    _______, _______, _______, _______,          _______, _______, _______,      _______, _______, _______,          LSCRN,   DSCRN,   USCRN,   RSCRN    \
  ),

  [_ADJUST] = LAYOUT( \
    RESET  , QWERTY,  _______, KC_UP,   _______, _______, _______,                        _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_RGHT, _______, \
    _______, _______, ALT_L,   KC_DOWN, ALT_R,   _______, _______,                        _______, DVORAK,  KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, \
    _______, CHNGOS,  _______, KC_DOWN, _______, _______, _______,                        _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, \
    RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,          _______, _______, _______,      _______, _______, _______,          RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI \
  ),

  [_ARROWS] = LAYOUT(
    _______, _______, _______, KC_UP,   _______, KC_HOME, KC_HOME,                        KC_PGUP, KC_PGUP, _______, KC_UP,   _______, KC_RGHT, _______, \
    _______, _______, ALT_L,   KC_DOWN, ALT_R,   KC_END,  KC_END,                         KC_PGDN, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, \
    _______, _______, _______, KC_DOWN, KC_HOME, _______, KC_LALT,                        KC_LCTL, _______, _______, _______, SWPL,    SWPR,    _______, \
    _______, _______, KC_PDOT, KC_P0,            _______, _______, KC_LCTL,      KC_PENT, KC_PENT, KC_PDOT,          _______, _______, _______, _______  \
  ),
};
