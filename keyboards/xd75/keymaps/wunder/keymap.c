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

#define TAPPING_TOGGLE 1

// Fillers to make layering more clear
#define ______ KC_TRNS 
#define FN_SPC LT(_FN, KC_SPC)
#define CTL_GRV CTL_T(KC_GRV)
#define SFT_MEH SFT_T(KC_F14)
#define SFT_MIN MT(MOD_RSFT, KC_MINS)
#define CTL_ENT MT(MOD_RCTL, KC_ENT)
#define CTL_PENT MT(MOD_RCTL, KC_PENT)

// Layer shorthand
#define _QW 0
#define _FN 1
#define _LW 2

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
 * | F14    | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | LOWER  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = { /* QWERTY */
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_HOME, KC_PGUP, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,  KC_F14},
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_RBRC, KC_LBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,  KC_BSLS},
  { CTL_GRV, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_GRV,  KC_MINS, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, CTL_ENT,  KC_EQL},
  { SFT_MEH, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_MIN,  KC_DEL},
  { KC_F14,  KC_LGUI, TT(_LW), KC_LALT, FN_SPC,  FN_SPC,  KC_LEFT, KC_RGHT, FN_SPC,  FN_SPC,  KC_RALT, TT(_LW), KC_RGUI, TT(_LW),  KC_DOWN},
 },

 [_FN] = { /* FUNCTION */
  { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   ______,  ______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   ______ },
  { ______,  ______,  KC_VOLU, KC_MPLY, KC_MNXT, ______,  ______,  ______,  KC_PGUP, KC_HOME, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,   ______ },
  { ______,  ______,  KC_VOLD, KC_MSTP, KC_MPRV, ______,  ______,  ______,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ______,  ______,   ______ },
  { ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  KC_PGDN, KC_END,  KC_EQL,  ______,  ______,  ______,   ______ },
  { ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,   ______ },
 },

 [_LW] = { /* LOWER */
  { ______,  ______,  ______,  ______,  KC_SLCK, KC_PAUS, ______,  ______,  KC_PSCR, KC_NLCK, KC_PSLS, KC_PAST, KC_P0,   ______,   ______ },
  { KC_CAPS, KC_BTN4, KC_MS_U, KC_BTN5, KC_WH_U, ______,  ______,  ______,  ______,  KC_P7,   KC_P8,   KC_P9,   KC_PMNS, ______,   RESET },
  { ______,  KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, ______,  RGB_TOG, RGB_MOD, ______,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS, CTL_PENT, ______ },
  { ______,  ______,  KC_WH_L, KC_WH_R, KC_BTN3, KC_BTN2, RGB_HUI, RGB_VAI, ______,  KC_P1,   KC_P2,   KC_P3,   KC_PDOT, ______,   RGB_SAI },
  { ______,  ______,  ______,  ______,  KC_BTN1, ______,  RGB_HUD, RGB_VAD, ______,  ______,  ______,  ______,  ______,  ______,   RGB_SAD },
 },

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
