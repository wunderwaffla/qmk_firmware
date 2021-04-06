/* Copyright 2018
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

enum custom_layers {
  _QW,
  _AUDACT,
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
#define ______ KC_NO
#define M1_S DYN_REC_START1
#define M2_S DYN_REC_START2
#define M1_R DYN_MACRO_PLAY1
#define M2_R DYN_MACRO_PLAY2
#define M_STOP DYN_REC_STOP

#define FN_SPC LT(_FN, KC_SPC)
#define PLAY LT(_FN, KC_ENT)
#define FN_BSP LT(_FN, KC_BSPC)
#define CTL_ESC CTL_T(KC_ESC)
#define SFT_MEH SFT_T(KC_PAUSE)
#define SFT_MIN MT(MOD_RSFT, KC_MINS)
#define CTL_QT MT(MOD_RCTL, KC_QUOT)
#define LW_SPC LT(_LW, KC_SPC)
#define LW_BSP LT(_LW, KC_BSPC)
#define FGUI GUI_T(KC_F2)
#define LOLT ALT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_QW] = {
  { KC_F1,   M5,      ______, ______, ______, },
  { M7,      M4,      KC_DEL, M1_R,   M2_R,   },
  { CTL_ESC, SFT_MEH, LOLT,   KC_S,   M1    },
  { M3,      ______,  ______, FGUI,   M2,     },
  { ______,  ______,  ______, FN_BSP, PLAY   },
 },

 [_FN] = {
  { RESET,  ______, ______, ______, M_STOP, },
  { ______, ______, ______, M1_S,   M2_S,   },
  { ______, ______, ______, ______, ______, },
  { ______, ______, ______, ______, ______, },
  { ______, ______, ______, ______, ______  },
 },

};

uint16_t macro_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }
  switch(keycode) {
    // undo
    case M1:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTRL(SS_TAP(X_Z)));
      } else {
      }
      break;
    // delete everything in a time selection
    case M2:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTRL(SS_LSFT("a")));
      } else {
      }
      break;
    case M3:
      if (record->event.pressed) {
          SEND_STRING(SS_LALT("d"));
      } else {
      }
      break;
    // ripple editing on/off
    case M4:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTRL(SS_LSFT("j")));
          macro_timer = timer_read();
      } else {
          if (timer_elapsed(macro_timer) > 150) {
              SEND_STRING(SS_LCTRL(SS_LSFT("j")));
          }
      }
      break;
    // snap on/off
    case M5:
      if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_F5));
          macro_timer = timer_read();
      } else {
          if (timer_elapsed(macro_timer) > 150) {
              SEND_STRING(SS_TAP(X_F5));
          }
      }
      break;
    case M6:
      break;
    // remove empty space to the next item
    case M7:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u")));
      } else {
      }
      break;
    case M8:
      break;
    case M9:
      break;
  }
  return true;
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}
void led_set_user(uint8_t usb_led) {
}
