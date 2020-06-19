/* A standard layout for the Sparkle Keyboard */

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

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
    M5,
    M6,
    DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

#define XXXXXXX KC_NO

#define M1_REC DYN_REC_START1
#define M2_REC DYN_REC_START2
#define M1_PLY DYN_MACRO_PLAY1
#define M2_PLY DYN_MACRO_PLAY2
#define M_STOP DYN_REC_STOP

#define FN_SPC LT(_FN, KC_SPC)
#define FN_BSP LT(_FN, KC_BSPC)
#define CTL_ESC LCTL_T(KC_ESC)
#define GUI_MEH LGUI_T(KC_TAB)
#define SFT_SPC SFT_T(KC_SPC)
#define SFT_BSP SFT_T(KC_BSPC)
/* #define SFT_MIN MT(MOD_RSFT, KC_MINS) */
#define GUI_MIN RGUI_T(KC_MINS)
// #define GUI_QT MT(MOD_RGUI, KC_QUOT)
#define CTL_QT RCTL_T(KC_QUOT)
#define LW_SPC LT(_LW, KC_SPC)
#define LW_BSP LT(_LW, KC_BSPC)
#define CTL_BS CTL_T(KC_BSPC)
#define FGUI LGUI_T(KC_F2)
#define GUIGO RGUI_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYOUT_60_ansi_split_bs_rshift
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │0d │0e │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 * │10   │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d │1e   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │20    │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c │2d      │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 * │30      │32 │33 │34 │35 │36 │37 │38 │39 │3a │3b │3d    │3e │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬┴───┤
 * │40  │41  │43  │46                      │4a  │4b  │4d  │4e  │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
*/

// define LAYOUT_60_ansi_split_bs_rshift(

  [_QW] = LAYOUT_60_ansi_split_bs_rshift(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
    KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
    KC_CAPS,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_A,
    KC_LCTL, KC_LGUI,          KC_LALT,                   KC_SPC,                             KC_RALT, KC_RGUI,          MO(_FN), KC_RCTL
    ),

  [_FN] = LAYOUT_60_ansi_split_bs_rshift(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_DEL,
    KC_TRNS,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, RESET,
    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS,  KC_HOME, KC_PGUP, KC_TRNS,
    KC_TRNS,          KC_TRNS, KC_TRNS, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, KC_TRNS, KC_DEL,  KC_END,  KC_PGDN,          KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,          KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS
    )
};

//  [_LW] = LAYOUT(
//         KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
//         KC_GRV,  KC_1,    KC_2,  KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
// KC_F1,           KC_F2,   KC_F3, KC_F4,   KC_F5,   KC_F6, KC_1,          KC_2,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,          KC_F12,
//                                  _______, _______, _______, _______,     _______, _______, _______, _______,
//                                           _______, _______, _______,     _______, _______, _______
//  ),
//
//  [_RS] = LAYOUT(
//         _______, _______, _______, _______, M_STOP,  M1_REC,                        KC_INS,  _______, _______, _______, KC_SLCK, KC_PAUS,
//         _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, M2_REC,                        _______, _______, _______, _______, _______, _______,
// RESET,           _______, _______, _______, _______, KC_PSCR, KC_1,        KC_2,    _______, _______, _______, _______, _______,         _______,
//                                    _______, _______, _______, _______,     _______, _______, _______, _______,
//                                             _______, _______, _______,     _______, _______, _______
//  ),
//};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_J) {
      // Anything you can do in a macro.
      /* SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_LALT) SS_UP(X_LSHIFT) SS_UP(X_LALT)); */
    }
    SEQ_TWO_KEYS(KC_D, KC_E) {
      /* SEND_STRING("docker exe"SS_TAP(X_TAB)"-it eva"SS_TAP(X_TAB)"backe"SS_TAP(X_TAB)"sh"SS_TAP(X_ENTER)"tail -f -n 1000 $LOG_PORTAL"SS_TAP(X_ENTER)); */
      SEND_STRING("docker exe"SS_TAP(X_TAB)"-it $(dock"SS_TAP(X_TAB)" ps --filter='name=evalink_backend' --format='{{.Names}}') sh"SS_TAP(X_ENTER)"tail -f -n 1000 $LOG_PORTAL"SS_TAP(X_ENTER));
    }
    SEQ_TWO_KEYS(KC_D, KC_P) {
      SEND_STRING("docker exe"SS_TAP(X_TAB)"-it $(dock"SS_TAP(X_TAB)" ps --filter='name=evalink_postgres' --format='{{.Names}}') bash"SS_TAP(X_ENTER)"psql -U postgres -d evalink -p 5132"SS_TAP(X_ENTER)"\\x auto"SS_TAP(X_ENTER));
    }
    SEQ_TWO_KEYS(KC_E, KC_P) {
      SEND_STRING("@evalink.test"SS_TAP(X_TAB)""SS_TAP(X_ENTER));
      /* SEND_STRING(SS_LCTRL("a")SS_LCTRL("c")); */
    }
    SEQ_TWO_KEYS(KC_T, KC_P) {
      SEND_STRING("ssh -L 2050:localhost:5132 ");
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      /* SEND_STRING("https://start.duckduckgo.com"SS_TAP(X_ENTER)); */
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
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
        SEND_STRING(""SS_TAP(X_ENTER));
        return false; break;
      case M5:
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_P)))SS_TAP(X_F));
        return false; break;
      case M6:
        SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_RSHIFT) SS_UP(X_LSHIFT) SS_UP(X_RSHIFT));
        return false; break;
    }
  }
  return true;
};
