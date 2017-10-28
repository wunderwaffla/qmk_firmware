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
  { KC_ESC,  KC_1,    KC_2,   KC_3,    KC_4,   KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC },
  { KC_TAB,  KC_Q,    KC_W,   KC_E,    KC_R,   KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_QUOT },
  //{ TG(_LW), KC_A,    KC_S,   KC_D,    KC_F,   KC_G,    KC_HOME, KC_DEL,  KC_PGUP, KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_ENT  },
  { M(0), KC_A,    KC_S,   KC_D,    KC_F,   KC_G,    KC_HOME, KC_DEL,  KC_PGUP, KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_ENT  },
  { KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,    KC_END,  KC_UP,   KC_PGDN, KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT },
  { KC_LCTL, KC_LGUI, KC_SPC, KC_LALT, KC_SPC, MO(_FN), KC_LEFT, KC_DOWN, KC_RGHT, MO(_FN), KC_SPC, KC_RALT, KC_SPC, KC_RGUI, KC_RCTL },
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   |        |        | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PR SCR |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   |        |        | P4     | P5     | P6     | +      |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   |        |        |        | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | RESET  |        |        | FN     |        |        | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_FN] = { /* FUNCTION */
  { KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_PSCR,KC_SLCK,KC_PAUS,KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,KC_F12 },
  { KC_TRNS,KC_VOLU,KC_MPLY,KC_MNXT,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS},
  { KC_TRNS,KC_VOLD,KC_MSTP,KC_MPRV,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_TRNS,KC_TRNS},
  { KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS},
  { KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS},
 },

/* LOWERED
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   |        |        | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PR SCR |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   |        |        | P4     | P5     | P6     | +      |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   |        |        |        | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | RESET  |        |        |        |        |        | P0     |        | P.     | PENT   | PENT   |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_LW] = { /* LOWERED */
  { KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_NLCK,KC_CAPS,KC_SLCK,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS},
  { KC_TRNS,KC_TRNS,KC_TRNS,KC_WH_L,KC_WH_U,KC_WH_R,KC_TRNS,RESET,  KC_TRNS,KC_TRNS,KC_TRNS,KC_MS_U,KC_TRNS,KC_TRNS,KC_TRNS},
  //{ TG(_LW),KC_TRNS,KC_TRNS,KC_BTN4,KC_WH_D,KC_BTN5,RGB_TOG,KC_TRNS,RGB_MOD,KC_TRNS,KC_MS_L,KC_MS_D,KC_MS_R,KC_TRNS,KC_TRNS},
  { M(0),KC_TRNS,KC_TRNS,KC_BTN4,KC_WH_D,KC_BTN5,RGB_TOG,KC_TRNS,RGB_MOD,KC_TRNS,KC_MS_L,KC_MS_D,KC_MS_R,KC_TRNS,KC_TRNS},
  { KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_BTN3,KC_BTN2,RGB_HUI,RGB_SAI,RGB_VAI,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS},
  { KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_BTN1,KC_TRNS,RGB_HUD,RGB_SAD,RGB_VAD,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS},
 },

/* RAISED
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   |        |        | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PR SCR |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   |        |        | P4     | P5     | P6     | +      |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   |        |        |        | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | RESET  |        |        |        |        |        | P0     |        | P.     | PENT   | PENT   |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_RS] = { /* RAISED */
  { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,  KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12 },
  { KC_MSEL, KC_CALC, KC_TRNS,   KC_MAIL, KC_SPC, KC_SPC, KC_HOME, KC_TRNS,   KC_PGUP, KC_MINS, KC_SPC, KC_SPC, KC_TRNS,  KC_TRNS,  KC_TRNS },
  { KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_SPC, KC_SPC, KC_TRNS,   KC_5,    KC_TRNS,   KC_PLUS, KC_SPC, KC_TRNS,  KC_SPC, KC_SPC, KC_SPC },
  { KC_TRNS,   KC_MUTE, KC_TRNS,   KC_APP,  KC_SPC, KC_SPC, KC_END,  KC_TRNS,   KC_PGDN, KC_TRNS,   KC_SPC, KC_SPC, KC_SPC, KC_TRNS,  KC_TRNS },
  { RESET,   KC_TRNS,   KC_TRNS,   KC_SPC,  KC_SPC, KC_SPC, KC_INS,  KC_TRNS,   KC_DEL,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS },
}
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
        //if (!record->event.pressed && timer_elapsed(start) < 150) {
            //layer_on(_LW);
        //}
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
