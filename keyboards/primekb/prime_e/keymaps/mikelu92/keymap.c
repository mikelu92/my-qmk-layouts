#include QMK_KEYBOARD_H
#include "mikelu.h"
#ifdef STENO_ENABLE
#include "keymap_steno.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT(
    KC_TAB,   KC_QUOT,  KC_COMM,  KC_DOT, KC_P,    KC_Y,                   KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,
    KC_BSPC,  KC_A,     ALT_HL,   GUI_HL, CTL_HL,  KC_I,                   KC_D,    CTL_HR,  GUI_HR,  ALT_HR,  KC_S,    KC_MINS,
    KC_HYPR,  KC_SCLN,  KC_Q,     KC_J,   KC_K,    KC_X,          KC_ESC , KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_EQL,
    TAP_CTL,  TAP_SFT,                    OSLOW,   KC_SPC,        SFT_ENT, RSE_TAB,                            TAP_GUI, TAP_ALT
    ),

    [_LOWER] = LAYOUT(
		KC_GRV,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, KC_EQL,
		KC_TRNS,  KC_EXLM,  ALT_HL2, GUI_HL2, CTL_HL2, KC_PERC,                KC_CIRC, CTL_HR2, GUI_HR2, ALT_HR2, KC_RPRN, KC_DQT ,
		TAP_CTL,  KC_COLN,  KC_TILD, KC_LCBR, KC_RCBR, KC_TRNS,       KC_TRNS, KC_PIPE, KC_LBRC, KC_RBRC, TABU_N,  TABD_N,  COL_EQL,
		DSP_OFF,  KC_TRNS,                    KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS
    ),

    [_RAISE] = LAYOUT(
		KC_TRNS,  KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_TRNS,                KC_6,    KC_7,    CHKESC,  KC_9,    KC_0,    KC_MINS, KC_EQL,
		KC_TRNS,  KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_TRNS,                KC_TRNS, AUTOFIL, TMUXPRF, TABU_N,  TABD_N,  KC_RBRC,
		KC_TRNS,  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_TRNS,       KC_TRNS, SRCHPWD, SCRNLYR, VIMWIND, SWPL,    SWPR,    KC_TRNS,
		KC_TRNS,  KC_TRNS,                    LOWER,   KC_TRNS,       KC_PENT, KC_PDOT,                            KC_TRNS, KC_TRNS
    ),
    [_ADJUST] = LAYOUT(
		RESET  , _______,   _______, KC_UP,   _______, _______,                _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_RGHT, _______, _______,
		_______, _______,   ALT_L,   KC_DOWN, ALT_R,   _______,                _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
		PLOVER ,  _______,  _______, KC_DOWN, _______, _______,       _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS,
		KC_TRNS,  KC_TRNS,                    KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS
    ),
    [_ARROWS] = LAYOUT(
		_______, _______,   _______, KC_UP,   _______, KC_HOME,                KC_PGUP, KC_G,    _______, KC_UP,   KC_RGHT, KC_RGHT, KC_RGHT,
		_______, KC_HOME,   ALT_L,   KC_DOWN, ALT_R,   KC_END ,                KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RGHT,
		TAP_CTL, KC_END ,   _______, KC_DOWN, KC_UP,   KC_HOME,       _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS,
		KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS
    ),
#ifdef STENO_ENABLE
    [_PLOVER] = LAYOUT(
		STN_FN,  STN_S1,    STN_TL,  STN_PL,  STN_HL,  STN_ST1,                STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR, STN_DR,
		XXXXXXX, STN_S2,    STN_KL,  STN_WL,  STN_RL,  STN_ST2,                STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
		EXT_PLV, XXXXXXX,   XXXXXXX, KC_DOWN, KC_C   , STN_N1,        STN_N7,  STN_N7,  KC_M   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		EXT_PLV, XXXXXXX,                     STN_A,   STN_O,         STN_E,   STN_U,                              XXXXXXX, XXXXXXX
    )
#endif
};

void matrix_init_user(void) {
  // set CapsLock LED to output and low
  setPinOutput(B1);
  writePinLow(B1);
  // set NumLock LED to output and low
  setPinOutput(B2);
  writePinLow(B2);
  // set ScrollLock LED to output and low
  setPinOutput(B3);
  writePinLow(B3);
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinHigh(B2);
  } else {
    writePinLow(B2);
  }
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinHigh(B1);
  } else {
    writePinLow(B1);
  }
/*
  if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
    writePinHigh(B3);
  } else {
    writePinLow(B3);
  }*/

}

////function for layer indicator LED
//layer_state_t layer_state_set_user(layer_state_t state)
//{
//    if (get_highest_layer(state) == 1) {
//    writePinHigh(B3);
//	} else {
//		writePinLow(B3);
//    }
//    return state;
//}
