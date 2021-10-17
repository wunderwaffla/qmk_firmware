#include QMK_KEYBOARD_H

enum custom_layers {
  _QW,
  _LW,
  _FN,
  _RS,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    M1,
    M2,
    M3,
    M4,
    DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

#define M1_REC DYN_REC_START1
#define M2_REC DYN_REC_START2
#define M1_PLY DYN_MACRO_PLAY1
#define M2_PLY DYN_MACRO_PLAY2
#define M_STOP DYN_REC_STOP

#define FN_SPC LT(_FN, KC_SPC)
#define CTL_ESC LCTL_T(KC_ESC)
#define SFT_F SFT_T(KC_BSLS)
#define SFT_MIN SFT_T(KC_MINS)
#define CTL_QT RCTL_T(KC_QUOT)
#define LW_BSP LT(_LW, KC_BSPC)
#define GUITAB LGUI_T(KC_TAB)
#define GUIGO RGUI_T(KC_ENT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QW] = LAYOUT(
    KC_GRV,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, M4,
    CTL_ESC,  LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,    KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), CTL_QT,
    SFT_F,    KC_Z,     KC_X,     KC_C,   KC_V,   KC_B,   KC_PAUS, KC_N,     KC_M, KC_COMM, KC_DOT,  KC_SLSH, SFT_MIN,
    KC_LCTL,  KC_LALT,                    GUITAB, LW_BSP,          FN_SPC,   GUIGO,                            KC_LEAD, M4
    ),

    [_FN] = LAYOUT(
    KC_CAPS, KC_BTN4, KC_ENT,  _______, _______, _______,          M1_PLY,  M2_PLY,  KC_HOME, KC_END,  _______, KC_RBRC, _______,
    _______, _______, _______, _______, _______, _______,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  _______,
    _______, _______, _______, _______, _______, _______, _______, M1,      M2,      KC_PGUP, KC_PGDN,      M3, _______,
    RESET,   _______,                   _______, _______,          _______, _______,                   _______, _______
    ),

    [_LW] = LAYOUT(
    KC_ENT,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS, _______,
    _______, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______,                   _______, _______,          _______,   _______,                 _______, _______
    ),

    [_RS] = LAYOUT(
    _______, _______, _______, _______, _______, M_STOP,           M1_REC,  M2_REC,  _______, _______, _______, KC_SLCK, _______,
    _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,          _______, _______, _______, _______, _______, _______,
    RESET,   _______, _______, _______, _______, KC_PSCR, _______, KC_INS, _______, _______, _______, _______, _______,
    _______, _______,                   _______, _______,          _______, _______,                   _______, _______
    )

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* case RCTL_T(KC_K): */
        /*     return TAPPING_TERM - 50; */
        /* case LCTL_T(KC_D): */
        /*     return TAPPING_TERM - 50; */
        case RSFT_T(KC_J):
            return TAPPING_TERM - 50;
        case LSFT_T(KC_F):
            return TAPPING_TERM - 50;
        case RGUI_T(KC_L):
            return TAPPING_TERM + 50;
        case LGUI_T(KC_S):
            return TAPPING_TERM + 50;
        case LALT_T(KC_A):
            return TAPPING_TERM + 50;
        case RALT_T(KC_SCLN):
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    SEQ_ONE_KEY(KC_J) {
      // Anything you can do in a macro.
      /* SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_LALT) SS_UP(X_LSHIFT) SS_UP(X_LALT)); */
    }
    SEQ_TWO_KEYS(KC_LBRC, KC_LBRC) {
      register_code(KC_LSFT);
      register_code(KC_RBRC);
      unregister_code(KC_RBRC);
      unregister_code(KC_LSFT);
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
    SEQ_TWO_KEYS(KC_E, KC_P) {
      SEND_STRING("@evalink.test"SS_TAP(X_TAB)""SS_TAP(X_ENTER));
      /* SEND_STRING(SS_LCTRL("a")SS_LCTRL("c")); */
    }
  }
}

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LW, _FN, _RS);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

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
    }
  }
  return true;
};

