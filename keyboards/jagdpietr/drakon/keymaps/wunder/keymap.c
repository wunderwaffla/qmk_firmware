/* Copyright 2020 jagdpietr
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H


// Defines names for use in layer keycodes and the keymap
enum Layer_names {
_QW,
_FN,
_LW,
_RS
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    M1,
    M2,
    M3,
    M4,
    M5,
    M6,
    DYNAMIC_MACRO_RANGE
};

#define _______ KC_TRNS

#define M1_REC DYN_REC_START1
#define M2_REC DYN_REC_START2
#define M1_PLY DYN_MACRO_PLAY1
#define M2_PLY DYN_MACRO_PLAY2
#define M_STOP DYN_REC_STOP

#define FN_SPC LT(_FN, KC_SPC)
#define CTL_ESC LCTL_T(KC_ESC)
#define SFT_F SFT_T(KC_BSLS)
#define SFT_MIN SFT_T(KC_MINS)
#define CTL_EN RCTL_T(KC_ENT)
#define LW_PA LT(_LW, KC_PAUS)
#define GUITAB LGUI_T(KC_TAB)
#define GUIGO RGUI_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QW] = LAYOUT_ansi(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, M4,                M5,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,           KC_A,    _______, KC_D,
        CTL_ESC, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,    KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT, CTL_EN, M6,
        /* CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          CTL_EN,                     KC_X, */
        SFT_F,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_MIN,           _______,
        KC_LCTL, KC_LGUI, KC_LALT,                             FN_SPC,                    KC_LEAD,  LW_PA,          _______, _______, _______
    ),

    [_FN] = LAYOUT_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  _______,          _______,
        KC_CAPS, KC_ENT,  _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  KC_INS, _______, _______, _______,            _______, _______, _______,
        _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL, _______,          _______,                    _______,
        _______, _______, _______, _______, _______, KC_PSCR, M1,      M2,      KC_PGUP, KC_PGDN, M3,      _______,          KC_PGUP,
        RESET,   _______, _______, _______,                                              _______, _______,          KC_HOME, KC_PGDN, KC_END
    ),

    [_LW] = LAYOUT_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS, _______, _______,           _______, _______, _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,           _______,                    _______,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           _______,
        _______, _______, _______, _______,                                              _______, _______,          _______, _______, _______
    ),

    [_RS] = LAYOUT_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLCK,           _______,
        _______, _______, _______, _______, M_STOP,  M1_REC,  KC_INS,  _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______,
        _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, M2_REC,  _______, _______, _______, _______, _______, _______,          _______,                    _______,
        _______,          _______, _______, _______, KC_PSCR, _______, _______, _______, _______, _______, _______, _______, _______,
        RESET,   _______, _______, _______,                                              _______, _______,          _______, _______, _______
    )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* case RCTL_T(KC_K): */
        /*     return TAPPING_TERM - 50; */
        /* case LCTL_T(KC_D): */
        /*     return TAPPING_TERM - 50; */
        case RSFT_T(KC_J):
            return TAPPING_TERM - 30;
        case LSFT_T(KC_F):
            return TAPPING_TERM - 30;
        case RGUI_T(KC_L):
            return TAPPING_TERM + 30;
        case LGUI_T(KC_S):
            return TAPPING_TERM + 30;
        case LALT_T(KC_A):
            return TAPPING_TERM + 30;
        case RALT_T(KC_SCLN):
            return TAPPING_TERM + 30;
        default:
            return TAPPING_TERM;
    }
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    SEQ_ONE_KEY(KC_RBRC) {
      /* DYN_MACRO_PLAY1; */
      /* register_code(DYN_MACRO_PLAY1); */
      /* unregister_code(DYN_MACRO_PLAY1); */
    }
    SEQ_TWO_KEYS(KC_RBRC, KC_RBRC) {
      /* SEND_STRING(SS_TAP(DYN_REC_START1)); */
      /* register_code(DYN_REC_START1); */
      /* unregister_code(DYN_REC_START1); */
    }
    SEQ_THREE_KEYS(KC_RBRC, KC_RBRC, KC_RBRC) {
      /* SEND_STRING(SS_TAP(DYN_REC_STOP)); */
      /* register_code(DYN_REC_STOP); */
      /* unregister_code(DYN_REC_STOP); */
    }
    SEQ_TWO_KEYS(KC_D, KC_E) {
      SEND_STRING("docker logs -f $(dock"SS_TAP(X_TAB)" ps --filter='name=evalink_backend' --format='{{.Names}}') ");
    }
    SEQ_TWO_KEYS(KC_D, KC_P) {
      SEND_STRING("docker exe"SS_TAP(X_TAB)"-it $(dock"SS_TAP(X_TAB)" ps --filter='name=evalink_postgres' --format='{{.Names}}') bash"SS_TAP(X_ENTER)"psql -U postgres -d evalink -p 5132"SS_TAP(X_ENTER)"\\x auto"SS_TAP(X_ENTER));
    }
    SEQ_TWO_KEYS(KC_G, KC_P) {
      SEND_STRING("git push --set-upstream origin $(git branch --show-current)"SS_TAP(X_TAB));
    }
  }
}

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LW, _FN, _RS);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case M1:
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_E))));
        return false; break;
      case M2:
        SEND_STRING(SS_LSFT("ZQ"));
        return false; break;
      case M3:
        SEND_STRING(""SS_TAP(X_ENTER));
        return false; break;
      case M4:
        SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_RCTRL) SS_UP(X_LCTRL) SS_UP(X_RCTRL));
        return false; break;
      case M5:
        SEND_STRING(SS_TAP(X_F3) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_F3));
        return false; break;
      case M6:
        SEND_STRING(SS_TAP(X_F3) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_F3));
        return false; break;
    }
  }
  return true;
};

