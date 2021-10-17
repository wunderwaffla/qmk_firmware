#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( \
    KC_GRV,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                       KC_Y,  KC_U,  KC_I,   KC_O,   KC_P,    M4,\
    /* CTL_ESC, KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                       KC_H,  KC_J,  KC_K,   KC_L,   KC_SCLN, CTL_QT,\ */
    KC_ESC, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,    KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,\
    KC_BSLS, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                       KC_N,  KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,\
                                  FROW,  NAV, KC_PAUS,      SFT_BSP, NUM, SYS \
  ),

  [_NAV] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                       KC_CAPS, KC_HOME, KC_END,  KC_LBRC, KC_RBRC, _______,\
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  _______,\
    _______, _______, _______, _______, _______, _______,                       KC_INS,  KC_PGDN, KC_PGUP, _______, _______, _______,\
                                        _______, _______, _______,     _______, _______, _______ \
  ),

  [_FROW] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,\
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                       _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,\
    _______, _______, _______, _______, _______, _______,                       _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,\
                                        _______, _______, _______,     _______, _______, _______ \
  ),

  [_NUM] = LAYOUT( \
    _______, _______, KC_7,    KC_8,    KC_9,    KC_0,                          _______, _______, _______, _______, _______, _______,\
    _______, _______, KC_4,    KC_5,    KC_6,    KC_EQL,                        _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,\
    _______, _______, KC_1,    KC_2,    KC_3,    KC_DOT,                        _______, _______, _______, _______, _______, _______,\
                                        _______, _______, _______,     _______, _______, _______ \
  ),

  [_SYS] = LAYOUT( \
    _______, _______, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,                       _______, _______, _______, _______, _______, _______,\
    _______, _______, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                       _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,\
    _______, _______, KC_EXLM, KC_AT,   KC_HASH, KC_DOT,                        _______, _______, _______, _______, _______, _______,\
                                        _______, _______, _______,     _______, _______, _______ \
  ),

  [_RS] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                       M5,      M6,      _______, _______, _______, _______,\
    _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,                       _______, _______, _______, _______, _______, _______,\
    RESET,   _______, _______, _______, _______, KC_PSCR,                       _______, _______, _______, _______, _______, _______,\
                                        _______, _______, _______,     _______, _______, _______ \
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

// LEADER_EXTERNS();

void matrix_scan_user(void) {
//   LEADER_DICTIONARY() {
//     leading = false;
//     leader_end();
//     SEQ_ONE_KEY(KC_RBRC) {
//       /* DYN_MACRO_PLAY1; */
//       /* register_code(DYN_MACRO_PLAY1); */
//       /* unregister_code(DYN_MACRO_PLAY1); */
//     }
//     SEQ_TWO_KEYS(KC_RBRC, KC_RBRC) {
//       /* SEND_STRING(SS_TAP(DYN_REC_START1)); */
//       /* register_code(DYN_REC_START1); */
//       /* unregister_code(DYN_REC_START1); */
//     }
//     SEQ_THREE_KEYS(KC_RBRC, KC_RBRC, KC_RBRC) {
//       /* SEND_STRING(SS_TAP(DYN_REC_STOP)); */
//       /* register_code(DYN_REC_STOP); */
//       /* unregister_code(DYN_REC_STOP); */
//     }
//     SEQ_TWO_KEYS(KC_D, KC_E) {
//       SEND_STRING("docker logs -f $(dock"SS_TAP(X_TAB)" ps --filter='name=evalink_backend' --format='{{.Names}}') ");
//     }
//     SEQ_TWO_KEYS(KC_D, KC_P) {
//       SEND_STRING("docker exe"SS_TAP(X_TAB)"-it $(dock"SS_TAP(X_TAB)" ps --filter='name=evalink_postgres' --format='{{.Names}}') bash"SS_TAP(X_ENTER)"psql -U postgres -d evalink -p 5132"SS_TAP(X_ENTER)"\\x auto"SS_TAP(X_ENTER));
//     }
//     SEQ_TWO_KEYS(KC_G, KC_P) {
//       SEND_STRING("git push --set-upstream origin $(git branch --show-current)"SS_TAP(X_TAB));
//     }
//   }
}

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _NAV, _NUM, _RS);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* if (!process_record_dynamic_macro(keycode, record)) { */
  /*   return false; */
  /* } */

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
        /* SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_RCTRL) SS_UP(X_LCTRL) SS_UP(X_RCTRL)); */
        SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_DOWN(X_K) SS_UP(X_K) SS_UP(X_LCTRL) SS_UP(X_LALT));
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
