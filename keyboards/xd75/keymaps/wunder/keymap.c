/* Copyright 2017 wunder
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

// Fillers to make layering more clear
#define ______ KC_TRNS 
#define FN_SPC LT(_FN, KC_SPC)
#define TAPPING_TOGGLE 1
//#define ___T___ ______
//#define XXXXXXX ______

// Layer shorthand
#define _QW 0
#define _FN 1
#define _LW 2
#define _RS 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CTRL   | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LOWER  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | LOWER  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = { /* QWERTY */
  { KC_ESC,  KC_1,    KC_2,   KC_3,    KC_4,   KC_5,    KC_HOME, KC_UP,   KC_PGUP, KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    KC_QUOT},
  { KC_TAB,  KC_Q,    KC_W,   KC_E,    KC_R,   KC_T,    KC_BSLS, KC_RBRC, KC_LBRC, KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_BSPC},
  { KC_LCTL, KC_A,    KC_S,   KC_D,    KC_F,   KC_G,    KC_GRV,  KC_EQL,  KC_MINS, KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, CTL_T(KC_ENT)},
  { KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,    KC_END,  KC_DEL,  KC_PGDN, KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT },
  { TT(_LW), KC_LGUI, FN_SPC, KC_LALT, FN_SPC, FN_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, FN_SPC, FN_SPC, KC_RALT, FN_SPC, KC_RGUI, TT(_LW)},
 },

 [_FN] = { /* FUNCTION */
  { KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,  KC_PSCR, KC_SLCK, KC_PAUS, KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, KC_F12 },
  { ______, KC_VOLU, KC_MPLY, KC_MNXT, ______, ______, ______,  ______,  ______,  ______,  ______,  ______, ______,  ______, KC_DEL},
  { ______, KC_VOLD, KC_MSTP, KC_MPRV, ______, ______, ______,  ______,  ______,  KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, ______, ______},
  { ______, ______,  ______,  ______,  ______, ______, ______,  ______,  ______,  ______,  ______,  ______, ______,  ______, ______},
  { ______, ______,  ______,  ______,  ______, ______, ______,  ______,  ______,  ______,  ______,  ______, ______,  ______, ______},
 },

 [_LW] = { /* LOWERED */
  { ______, ______,  ______,  ______,  ______,  ______,  KC_NLCK, KC_CAPS, KC_SLCK, ______,  ______, KC_PSLS, KC_PAST, KC_P0,   ______},
  { ______, ______,  KC_BTN4, KC_MS_U, KC_BTN5, ______,  ______,  RESET,   ______,  KC_WH_U, KC_P7,  KC_P8,   KC_P9,   KC_PMNS, ______},
  { ______, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, RGB_TOG, ______,  RGB_MOD, KC_WH_D, KC_P4,  KC_P5,   KC_P6,   KC_PPLS, CTL_T(KC_ENT)},
  { ______, ______,  ______,  ______,  KC_BTN3, KC_BTN2, RGB_HUI, RGB_SAI, RGB_VAI, ______,  KC_P1,  KC_P2,   KC_P3,   KC_PDOT, ______},
  { ______, ______,  ______,  ______,  ______,  KC_BTN1, RGB_HUD, RGB_SAD, RGB_VAD, ______,  ______, ______,  ______,  ______,  ______},
 },

};

// const uint16_t PROGMEM fn_actions[] = {
// };

static uint16_t start;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) 
{
    switch(id) {
        case 0:   
        if (record->event.pressed) {
            start = timer_read();
            register_code(KC_LCTL);
        } else {
    	    uint8_t layer;
    	    layer = biton32(layer_state);  // get the current layer
            unregister_code(KC_LCTL);
            if (timer_elapsed(start) < 150 && layer != _LW) {
                layer_on(_LW);
            }
            if (timer_elapsed(start) < 150 && layer == _LW) {
                layer_off(_LW);
	    }
        }
        break;
    }
    return MACRO_NONE;
};

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
