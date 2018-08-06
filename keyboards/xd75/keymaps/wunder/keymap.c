/* Copyright 2017 wunder i.draenei@gmail.com
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
#include "xd75.h"

enum custom_keycodes {
    M1 = SAFE_RANGE,
    M2,
    M3,
    M4,
    M5
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV,
  DYNAMIC_MACRO_RANGE,
};
#include "dynamic_macro.h"

// Fillers to make layering more clear
#define ______ KC_TRNS
#define FN_SPC LT(_FN, KC_SPC)
#define FN_BSP LT(_FN, KC_BSPC)
#define CTL_ESC CTL_T(KC_ESC)
#define SFT_MEH SFT_T(KC_F14)
#define SFT_MIN MT(MOD_RSFT, KC_MINS)
#define CTL_ENT MT(MOD_RCTL, KC_ENT)
#define CTL_PENT MT(MOD_RCTL, KC_PENT)
#define M1_S DYN_REC_START1
#define M2_S DYN_REC_START2
#define M1_R DYN_MACRO_PLAY1
#define M2_R DYN_MACRO_PLAY2
#define M_STOP DYN_REC_STOP
#define F_GUI MT(MOD_RGUI, KC_F2)

// Layer shorthand
#define _QW 0
#define _FN 1
#define _LW 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `      | 1      | 2      | 3      | 4      | 5      | M1     | M1     | 6      | 7      | 8      | 9      | 0      | BSPC   | M_STOP |
 * |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
 * | TAB    | Q      | W      | E      | R      | T      | DM1_S  | DM2_S  | Y      | U      | I      | O      | P      | '      | F20    |
 * |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
 * | ECS    | A      | S      | D      | F      | G      | DM1_R  | DM2_R  | H      | J      | K      | L      | ;      | ENTER  | F21    |
 * |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
 * | SHIFT  | Z      | X      | C      | V      | B      | M3     | M4     | N      | M      | ,      | .      | /      | SHIFT  | F22    |
 * |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
 * | PAUSE  | F23    | F15    | SUPER  | BSPACE | LOWER  | ALT    | ALT    | LOWER  | SPACE  | SUPER  | F16    | F17    | F18    | F19    |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = { /* QWERTY */
  { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    ______,  ______,  KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_HOME, KC_END  },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    ______,  ______,  KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_QUOT, KC_PGUP },
  { CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    ______,  ______,  KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, CTL_ENT, KC_PGDN },
  { SFT_MEH, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    ______,  ______,  KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, SFT_MIN, KC_F22  },
  { KC_PAUS, KC_F23,  KC_F15,  KC_LGUI, FN_BSP,  TT(_LW), KC_LALT, KC_RALT, TT(_LW), FN_SPC, F_GUI,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT },
 },

 [_FN] = { /* FUNCTION */
  { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   ______,  ______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   ______ },
  { ______,  M1_S,    M2_S,    M1_R,    M2_R,    M_STOP,  ______,  ______,  KC_HOME, KC_END,  KC_LBRC, KC_RBRC, ______,  KC_DEL,   ______ },
  { ______,  KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_MPLY, ______,  ______,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS, ______,   ______ },
  { ______,  M1,      M2,      M3,      M4,      M5,      ______,  ______,  KC_PGUP, KC_PGDN, KC_EQL,  ______,  ______,  ______,   ______ },
  { ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,   ______ },
 },

 [_LW] = { /* LOWER */
  { ______,  ______,  ______,  KC_INS,  KC_SLCK, KC_PAUS, ______,  ______,  KC_PSCR, KC_NLCK, KC_PSLS, KC_PAST, KC_P0,   ______,   ______ },
  { KC_CAPS, KC_BTN4, KC_MS_U, KC_BTN5, KC_WH_U, ______,  RESET,   ______,  ______,  KC_P7,   KC_P8,   KC_P9,   KC_PMNS, ______,   ______ },
  { ______,  KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, ______,  ______,  ______,  ______,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS, CTL_PENT, ______ },
  { ______,  ______,  KC_WH_L, KC_WH_R, KC_BTN3, KC_BTN2, ______,  BL_STEP, KC_BTN1, KC_P1,   KC_P2,   KC_P3,   KC_PDOT, ______,   ______ },
  { ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,   ______ },
 },

};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// 	    return true;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  if (record->event.pressed) {
    switch(keycode) {
      case M1:
        SEND_STRING("gotogit"SS_TAP(X_ENTER));
        return false; break;
      case M2:
        SEND_STRING("@evalink.test");
        return false; break;
      case M3:
        SEND_STRING("1234Aa"SS_TAP(X_ENTER));
        return false; break;
      case M4:
        SEND_STRING(SS_LSFT("ZQ"));
        return false; break;
      case M5:
        SEND_STRING(SS_LSFT("ZZ"));
        return false; break;
    }
  }
  return true;
};

// const uint16_t PROGMEM fn_actions[] = {
// };

// static uint16_t start;

// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
// {
    // switch(id) {
        // case 0:
        // if (record->event.pressed) {
            // start = timer_read();
            // register_code(KC_LCTL);
        // } else {
    	    // uint8_t layer;
    	    // layer = biton32(layer_state);  // get the current layer
            // unregister_code(KC_LCTL);
            // if (timer_elapsed(start) < 150 && layer != _LW) {
                // layer_on(_LW);
            // }
            // if (timer_elapsed(start) < 150 && layer == _LW) {
                // layer_off(_LW);
	    // }
        // }
        // break;
    // }
    // return MACRO_NONE;
// };

//const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
//{
  // MACRODOWN only works in this function
      // switch(id) {
        // case 0:
          // if (record->event.pressed) {
            // register_code(KC_RSFT);
            // #ifdef BACKLIGHT_ENABLE
              // backlight_step();
            // #endif
          // } else {
            // unregister_code(KC_RSFT);
          // }
        // break;
      // }
    // return MACRO_NONE;
// };
