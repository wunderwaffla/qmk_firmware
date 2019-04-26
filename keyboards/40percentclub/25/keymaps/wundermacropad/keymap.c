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
  { ______, ______, ______, M3,     M_STOP, },
  { ______, ______, ______, M1_R,   M2_R,   },
  { CTL_ESC,______, ______, M1,     KC_V,   },
  { ______, M4,     M5,     KC_ENT, M2,     },
  { SFT_MEH,______, ______, LW_BSP, FN_SPC  },
 },

 [_FN] = { /* FUNCTION */
  { KC_LEFT,KC_DOWN, KC_UP, KC_RGHT, ______, },
  { ______, ______,  ______, M1_S,   M2_S,   },
  { ______, ______,  ______, ______, ______, },
  { ______, ______,  ______, ______, ______, },
  { ______, ______,  ______, ______, ______  },
 },

 [_LW] = { /* LOWER */
  { ______, ______,  ______, ______, RESET,  },
  { KC_7,   KC_8,    KC_9,   ______, ______, },
  { KC_4,   KC_5,    KC_6,   ______, ______, },
  { KC_1,   KC_2,    KC_3,   ______, ______, },
  { KC_0,   ______,  ______, ______, ______  },
 },

  /* [0] = LAYOUT_macro( */
  /*   KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,  \ */
  /*   KC_GRV,   KC_Q,    KC_W,    KC_E,    KC_R,  \ */
  /*   KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,  \ */
  /*   KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,  \ */
  /*   KC_LCTL,  KC_LGUI, KC_LALT, KC_SPC,  KC_SPC \ */
  /* ), */
};

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
        SEND_STRING(SS_LCTRL(SS_TAP(X_C)));
        return false; break;
      case M5:
        SEND_STRING(SS_LCTRL(SS_TAP(X_V)));
        return false; break;
      case M6:
        SEND_STRING("pazoozoo");
        return false; break;
      case M7:
        SEND_STRING("pazoozoo");
        return false; break;
      case M8:
        SEND_STRING("pazoozoo");
        return false; break;
      case M9:
        SEND_STRING("pazoozoo");
        return false; break;
    }
  }
  return true;
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
