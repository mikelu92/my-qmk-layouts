#include QMK_KEYBOARD_H
#include "mikelu.h"
#include <stdio.h>


user_config_t user_config;

const uint16_t PROGMEM arrows_combo[] = {KC_Q, KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [OEU_ARROWS] = COMBO_ACTION(arrows_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case OEU_ARROWS:;
            //enum layers l = _ARROWS;
            if (pressed) {
                layer_on(_ARROWS);
            } else {
                layer_off(_ARROWS);
            }
            break;
    }
}


void keyboard_post_init_user(void) {
    // Call the keymap level matrix init.

    // Read the user config from EEPROM
    user_config.raw = eeconfig_read_user();
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_HR:
        case CTL_HL:
        case ALT_HR:
        case ALT_HL:
        case GUI_HL:
        case GUI_HR:
        case CTL_HR2:
        case CTL_HL2:
        case ALT_HR2:
        case ALT_HL2:
        case GUI_HL2:
        case GUI_HR2:
            return TAPPING_TERM + 100;
        case SFT_ENT:
            return TAPPING_TERM + 20;
        default:
            return TAPPING_TERM;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // differences based on os'
        case AUTOFIL:
            if (record->event.pressed) {
                if (!user_config.is_windows) {
                    SEND_STRING(SS_LGUI("\\"));
                } else {
                    SEND_STRING(SS_LCTL("\\"));
                }
            }
            return false;
            break;
        case SRCHPWD:
            if (record->event.pressed) {
                if (!user_config.is_windows) {
                    SEND_STRING(SS_LGUI(SS_LALT("\\")));
                } else {
                    SEND_STRING(SS_LCTL(SS_LALT("\\")));
                }
            }
            return false;
            break;
        case SWPL:
            if (record->event.pressed) {
                if (!user_config.is_windows) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));
                } else {
                    SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_LEFT))));
                }
            }
            return false;
            break;
        case SWPR:
            if (record->event.pressed) {
                if (!user_config.is_windows) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)));
                } else {
                    SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_RIGHT))));
                }
            }
            return false;
            break;
        case ALT_L:
            if (record->event.pressed) {
                if (!user_config.is_windows) {
                    SEND_STRING(SS_LALT(SS_TAP(X_LEFT)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));
                }
            }
            return false;
            break;
        case ALT_R:
            if (record->event.pressed) {
                if (!user_config.is_windows) {
                    SEND_STRING(SS_LALT(SS_TAP(X_RIGHT)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)));
                }
            }
            return false;
            break;
        case DSP_OFF:
            if (record->event.pressed) {
                if (!user_config.is_windows) {
                    SEND_STRING(SS_LCTL(SS_LGUI("q")));
                } else {
                    SEND_STRING(SS_LGUI("l"));
                }
            }
            return false;
            break;

        case CHNGOS:
            if (record->event.pressed) {
                user_config.is_windows ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;
            break;

        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
            break;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
        case ARROWS:
            if (record->event.pressed) {
                layer_on(_ARROWS);
            } else {
                layer_off(_ARROWS);
            }
            return false;
            break;
        case COL_EQL:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LSHIFT) ";" SS_UP(X_LSHIFT) "=");
            }
            return false;
            break;
        case CTL_HR:
            if (record->event.pressed && record->tap.count > 0) {
                if (get_mods() & MOD_BIT(KC_RGUI)) {
                    unregister_mods(MOD_BIT(KC_RGUI));
                    tap_code(KC_T);
                    tap_code(KC_H);
                    add_mods(MOD_BIT(KC_RGUI));
                    return false;
                    break;
                }
            }
            return true;
            break;
        case GUI_HR:
            if (record->event.pressed && record->tap.count > 0) {
                if (get_mods() & MOD_BIT(KC_RALT)) {
                    unregister_mods(MOD_BIT(KC_RALT));
                    tap_code(KC_N);
                    tap_code(KC_T);
                    add_mods(MOD_BIT(KC_RALT));
                    return false;
                    break;
                }
            }
            return true;
        case KC_G:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_RALT)) {
                    unregister_mods(MOD_BIT(KC_RALT));
                    tap_code(KC_N);
                    tap_code(KC_G);
                    add_mods(MOD_BIT(KC_RALT));
                    return false;
                    break;
                }
            }
            return true;
        case KC_F:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LALT)) {
                    unregister_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_O);
                    tap_code(KC_F);
                    add_mods(MOD_BIT(KC_LALT));
                    return false;
                    break;
                }
            }
            return true;
    case ALT_HL2:
        if (record->tap.count > 0) {
          if (record->event.pressed) {
            tap_code16(KC_AT);
          }
          return false;
        }
        return true;
    case GUI_HL2:
        if (record->tap.count > 0) {
          if (record->event.pressed) {
            tap_code16(KC_HASH);
          }
          return false;
        }
        return true;
    case CTL_HL2:
        if (record->tap.count > 0) {
          if (record->event.pressed) {
            tap_code16(KC_DLR);
          }
          return false;
        }
        return true;
    case ALT_HR2:
        if (record->tap.count > 0) {
          if (record->event.pressed) {
            tap_code16(KC_LPRN);
          }
          return false;
        }
        return true;
    case GUI_HR2:
        if (record->tap.count > 0) {
          if (record->event.pressed) {
            tap_code16(KC_ASTR);
          }
          return false;
        }
        return true;
    case CTL_HR2:
        if (record->tap.count > 0) {
          if (record->event.pressed) {
            tap_code16(KC_AMPR);
          }
          return false;
        }
        return true;
    }
    return true;
}

void matrix_scan_user(void) { leader_func(); }

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

static void render_leader_macros(void) {
    oled_write_P(PSTR("Macro Sequence\n\n"), true);
    oled_write_P(PSTR("ts: tmux window panes"), false);
    oled_write_P(PSTR("ut: update vm time\n"), false);
}

static void render_kyria_logo(void) {
    static const char PROGMEM gp_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
                                           0x00, 0x00, 0x00, 0x1e, 0x1e, 0x1e, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x1e, 0x1e, 0x1e, 0x1e, 0x3e, 0x3e, 0x7e, 0xfc, 0xfc, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                           0xff, 0xff, 0xff, 0xff, 0xff, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0xf3, 0xf9, 0xfd, 0xff, 0xff, 0xff, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7e, 0x3f, 0x3f, 0x1f, 0x1f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    oled_write_raw_P(gp_logo, sizeof(gp_logo));
}

static void render_status(void) {
    oled_write_P(PSTR("Kyria\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _DVORAK:
            if (get_highest_layer(default_layer_state) == _DVORAK) {
                oled_write_P(PSTR("Dvorak\n"), false);
            } else {
                oled_write_P(PSTR("Qwerty\n"), false);
            }
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case _ARROWS:
            oled_write_P(PSTR("Arrow\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef\n"), false);
    }
    oled_write_P(PSTR("OS: "), false);
    if (user_config.is_windows) {
        oled_write_P(PSTR("Win\n"), false);
    } else {
        oled_write_P(PSTR("Mac\n"), false);
    }
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
#    ifdef LEADER_ENABLE
        if (leader_started && timer_elapsed(leader_timer) < 3000) {
            render_leader_macros();
            return;
        }
#    endif
        render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif