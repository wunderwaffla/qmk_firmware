#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#include "dynamic_macro.h"

enum custom_layers {
  _QW,
  _NAV,
  _NUM,
  _SYS,
  _FROW,
  _RS,
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

#define M1_PLY DYN_REC_START1
#define M2_PLY DYN_REC_START2
#define M1_REC DYN_MACRO_PLAY1
#define M2_REC DYN_MACRO_PLAY2
#define M_STOP DYN_REC_STOP

#define FROW LT(_FROW, KC_TAB)
#define NAV LT(_NAV, KC_BSPC)
#define NUM LT(_NUM, KC_SPC)
#define SYS LT(_SYS, KC_ENT)
#define CTL_ESC CTL_T(KC_ESC)
#define CTL_QT MT(MOD_RCTL, KC_QUOT)
#define SFT_BSP SFT_T(KC_BSPC)

#define KC_MA LGUI_T(KC_A)
#define KC_MS LALT_T(KC_S)
#define KC_MD LCTL_T(KC_D)
#define KC_MF LSFT_T(KC_F)
#define KC_MJ RSFT_T(KC_J)
#define KC_MK RCTL_T(KC_K)
#define KC_ML RALT_T(KC_L)
#define KC_MC RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT(
    KC_GRV,   KC_Q,    KC_W,  KC_E,    KC_R,    KC_T, KC_Y, KC_U,    KC_I,    KC_O,    KC_P,    M4, M4,
    KC_ESC,  KC_MA,    KC_MS, KC_MD,   KC_MF,   KC_G, KC_H, KC_MJ,   KC_MK,   KC_ML,   KC_MC,   KC_QUOT,
    KC_BSLS,  KC_Z,    KC_X,  KC_C,    KC_V,    KC_B, KC_N, KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
    _______,  KC_PAUS, FROW,  _______, NAV,     NUM,  SYS,  KC_LEAD, KC_PAUS, _______
  ),

  [_NAV] = LAYOUT(
    _______,  _______, _______, _______, _______, _______, KC_CAPS, KC_HOME, KC_END,  KC_LBRC, KC_RBRC, _______,  _______,
    _______,  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  _______,
    _______,  _______, _______, _______, _______, _______, KC_INS,  KC_PGDN, KC_PGUP, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_FROW] = LAYOUT(
    _______,  _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,  KC_F4, _______,  _______,
    _______,  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, KC_F5,   KC_F6,   KC_F7,  KC_F8,  _______,
    _______,  _______, _______, _______, _______, _______, _______, KC_F9,   KC_F10,  KC_F11, KC_F12, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_NUM] = LAYOUT(
    _______,  _______, KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, KC_4,    KC_5,    KC_6,    KC_EQL,  _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
    _______,  _______, KC_1,    KC_2,    KC_3,    KC_DOT,  _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_SYS] = LAYOUT(
    _______,  _______, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
    _______,  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DOT,  _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_RS] = LAYOUT(
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______,
    RESET,    _______, _______, _______, _______, KC_PSCR, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

};
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    SEQ_TWO_KEYS(KC_LBRC, KC_LBRC) {
      register_code(KC_LSFT);
      register_code(KC_RBRC);
      unregister_code(KC_RBRC);
      unregister_code(KC_LSFT);
    }
     SEQ_TWO_KEYS(KC_G, KC_H) {
       SEND_STRING("git push --set-upstream origin $(git branch --show-current)"SS_TAP(X_TAB));
     }
     SEQ_TWO_KEYS(KC_G, KC_L) {
       SEND_STRING("git pull"SS_TAP(X_ENTER));
     }
     SEQ_THREE_KEYS(KC_G, KC_H, KC_F) {
       SEND_STRING("git push -fu");
     }
     SEQ_TWO_KEYS(KC_W, KC_H) {
       SEND_STRING(":tophat: ");
     }
  }
}

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _NAV, _NUM, _RS);
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
        SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_RSFT) SS_UP(X_LSFT) SS_UP(X_RSFT));
        return false; break;
    }
  }
  return true;
};
