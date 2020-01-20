/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum custom_layers {
  _QW,
};


#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QW] = LAYOUT(
     KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,              KC_Y, KC_U, KC_I,    KC_O,     KC_P,    KC_BSLS,
     KC_ESC,  KC_A, KC_S, KC_D, KC_F, KC_G,              KC_H, KC_J, KC_K,    KC_L,     KC_SCLN, KC_ENT,
     KC_1,    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_1,  KC_2, KC_N, KC_M, KC_COMM, KC_DOT,   KC_SLSH, KC_1,
                          KC_3, KC_4, KC_5, KC_6,  KC_7, KC_8, KC_9, KC_0,
                                KC_1, KC_2, KC_3,  KC_4, KC_5, KC_6
  ),
};
