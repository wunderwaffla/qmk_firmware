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
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
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
#define LW_BSP LT(_LW, KC_BSPC)
#define FGUI GUI_T(KC_F2)
#define GUIGO GUI_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QW] = { /* QWERTY */
  { RGB_TOG, RGB_HUI, RGB_HUD, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______ },
  { RGB_MOD, RGB_SAI, RGB_SAD, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______ },
  { ______,  RGB_VAI, RGB_VAD, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______ },
  { ______,  ______,  ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______ },
  { RESET,   ______,  ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______ },
 },

 // BL_STEP for backlight levels

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
        SEND_STRING(SS_LCTRL(SS_TAP(X_Z)));
        return false; break;
      case M2:
        SEND_STRING(SS_LCTRL(SS_LSFT("k"))SS_TAP(X_BSPACE));
        return false; break;
      case M3:
        SEND_STRING(SS_LCTRL(SS_LSFT("s")));
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
    }
  }
  return true;
};
