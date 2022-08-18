#include QMK_KEYBOARD_H
#include "mikelu.h"
#ifdef STENO_ENABLE
#include "keymap_steno.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DVORAK] = LAYOUT_ortho_4x12(
   KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, \
   KC_BSPC, KC_A,    ALT_HL,  GUI_HL,  CTL_HL,  KC_I,    KC_D,    CTL_HR,  GUI_HR,  ALT_HR,  KC_S,    KC_MINS, \
   KC_HYPR, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_EQL,  \
   XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB,  LOWER,   KC_SPC,  SFT_ENT, RAISE,   KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX  \
),
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  _______, KC_EXLM, ALT_HL2, GUI_HL2, CTL_HL2, KC_PERC, KC_CIRC, CTL_HR2, GUI_HR2, ALT_HR2, KC_RPRN, KC_MINS,
  DSP_OFF, KC_COLN, KC_TILD, KC_LCBR, KC_RCBR, ARROWS,  KC_PIPE, KC_LBRC, KC_RBRC, TABU_N,  TABD_N,  COL_EQL,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

[_RAISE] = LAYOUT_ortho_4x12( \
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, CHKESC,  _______, _______, _______,
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   CTL_U,   _______, AUTOFIL, TMUXPRF, TABU_N,  TABD_N,  _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   CTL_D,   SCRNLYR, SRCHPWD, VIMWIND, SWPL,    SWPR,    KC_BTN1,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),
[_ADJUST] =  LAYOUT_ortho_4x12( \
  RESET  , QWERTY,  _______, KC_UP,   _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_RGHT, _______,
  _______, _______, ALT_L,   KC_DOWN, ALT_R,   _______, DVORAK,  KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
  PLOVER,  CHNGOS,  _______, KC_DOWN, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_ARROWS] =  LAYOUT_ortho_4x12( \
  _______, _______, _______, KC_UP,   _______, KC_HOME, KC_PGUP, _______, KC_UP,   _______, KC_RGHT, _______,
  _______, _______, ALT_L,   KC_DOWN, ALT_R,   KC_END,  KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  _______, _______, _______, KC_DOWN, KC_UP,   KC_HOME, _______, _______, _______, SWPL,    SWPR,    _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),
#ifdef STENO_ENABLE
    [_PLOVER] = LAYOUT_ortho_4x12(
      STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
      XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
      EXT_PLV, XXXXXXX, XXXXXXX, XXXXXXX, STN_A,   STN_O,   STN_E,   STN_U,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, STN_A,   STN_O,   STN_E,   STN_U,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
#endif


};
