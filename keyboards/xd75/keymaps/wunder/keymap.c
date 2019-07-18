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

enum custom_layers {
  _QW,
  _LW,
  _FN,
  _GAME,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  M1,
  M2,
  M3,
  M4,
  M5,
  M6,
  M7,
  M8,
  M9,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

// Fillers to make layering more clear
#define ______ KC_TRNS
#define M1_S DYN_REC_START1
#define M2_S DYN_REC_START2
#define M1_R DYN_MACRO_PLAY1
#define M2_R DYN_MACRO_PLAY2
#define M_STOP DYN_REC_STOP

#define FN_SPC LT(_FN, KC_SPC)
#define FN_BSP LT(_FN, KC_BSPC)
#define CTL_ESC CTL_T(KC_ESC)
#define SFT_MEH SFT_T(KC_PAUSE)
#define SFT_MIN MT(MOD_RSFT, KC_MINS)
#define CTL_QT MT(MOD_RCTL, KC_QUOT)
#define LW_SPC LT(_LW, KC_SPC)
#define FGUI GUI_T(KC_F2)
#define GUIGO GUI_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QW] = { /* QWERTY */
  { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   ______,  ______,  KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_EQL,  KC_END  },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   M8,      M9,      KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_BSLS, KC_PGUP },
  { CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   M7,      M6,      KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, CTL_QT,  KC_PGDN },
  { SFT_MEH, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   ______,  ______,  KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, SFT_MIN, KC_BSLS },
  { KC_PAUS, KC_F23,  KC_F15,  FGUI,    FN_BSP,  LW_SPC, KC_LALT, KC_RALT, LW_SPC, FN_SPC, GUIGO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT },
 },

 [_FN] = { /* FUNCTION */
  { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   ______,  ______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   ______ },
  { KC_CAPS, KC_BTN4, KC_BTN5, KC_BTN3, ______,  ______,  ______,  ______,  KC_HOME, KC_END,  KC_LBRC, KC_RBRC, ______,  KC_DEL,   ______ },
  { ______,  M1_S,    M2_S,    M1_R,    M2_R,    M_STOP,  ______,  ______,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS, ______,   ______ },
  { ______,  M1,      M2,      M3,      M4,      M5,      ______,  ______,  KC_PGUP, KC_PGDN, KC_EQL,  ______,  ______,  ______,   ______ },
  { ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,   ______ },
 },

 [_LW] = { /* LOWER */
  { ______,  ______,  ______,  KC_INS,  KC_SLCK, KC_PAUS, GAME,   ______, KC_PSCR, ______, ______, ______, ______, ______, ______ },
  { ______,  ______,  ______,  ______,  ______,  ______,  RESET,  ______, ______,  ______, ______, ______, ______, ______, ______ },
  { ______,  KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_MPLY, ______, BL_ON,  KC_LEFT, KC_DOWN,KC_UP,  KC_RGHT,KC_BSLS,______, ______ },
  { ______,  ______,  ______,  ______,  ______,  ______,  ______, BL_OFF, ______,  ______, ______, ______, ______, ______, ______ },
  { ______,  ______,  ______,  ______,  ______,  ______,  ______, ______, ______,  ______, ______, ______, ______, ______, ______ },
 },

 // BL_STEP for backlight levels

 [_GAME] = { /* GAMEZZ */
  { CTL_ESC, KC_1,    KC_2,    KC_3,  KC_4,    KC_5,  QWERTY, ______,  KC_6,  KC_7,   KC_8,    KC_9,    KC_0,    KC_HOME, KC_END  },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,  KC_R,    KC_T,  ______, ______,  KC_Y,  KC_U,   KC_I,    KC_O,    KC_P,    KC_BSLS, KC_PGUP },
  { KC_GRV,  KC_A,    KC_S,    KC_D,  KC_F,    KC_G,  ______, ______,  KC_H,  KC_J,   KC_K,    KC_L,    KC_SCLN, CTL_QT,  KC_PGDN },
  { SFT_MEH, KC_Z,    KC_X,    KC_C,  KC_V,    KC_B,  ______, ______,  KC_N,  KC_M,   KC_COMM, KC_DOT,  KC_SLSH, SFT_MIN, KC_F2   },
  { KC_PAUS, KC_F23,  KC_F15,  KC_F5, KC_BSPC, KC_F4, KC_F1,  KC_RALT, KC_F3, FN_SPC, GUIGO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT },
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
        SEND_STRING(""SS_TAP(X_ENTER));
        return false; break;
      case M4:
        SEND_STRING(SS_LSFT("ZQ"));
        return false; break;
      case M5:
        SEND_STRING(SS_LSFT("ZZ"));
        return false; break;
      case M6:
        SEND_STRING(SS_TAP(X_F2)SS_TAP(X_J));
        return false; break;
      case M7:
        SEND_STRING(SS_TAP(X_F2)SS_TAP(X_K));
        return false; break;
      case M8:
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_P)))SS_TAP(X_F));
        return false; break;
      case M9:
        SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_RSHIFT) SS_UP(X_LSHIFT) SS_UP(X_RSHIFT));
        return false; break;
      case GAME:
        if (record->event.pressed) {
          layer_off(_FN);
          layer_off(_LW);
          layer_on(_GAME);
        } return false; break;
      case QWERTY:
        if (record->event.pressed) {
          layer_off(_GAME);
        } return false; break;
    }
  }
  return true;
};
