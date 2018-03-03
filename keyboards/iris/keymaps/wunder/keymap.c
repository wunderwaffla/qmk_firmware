#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

#define _QWERTY 0
#define _LW 1
#define _FN 2

enum custom_keycodes {
    KC_M1 = SAFE_RANGE,
    KC_M2,
    KC_M3,
    KC_M4
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

#define KC_M1_S DYN_REC_START1
#define KC_M2_S DYN_REC_START2
#define KC_M1_R DYN_MACRO_PLAY1
#define KC_M2_R DYN_MACRO_PLAY2
#define KC_M_STOP DYN_REC_STOP

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_FN_SPC LT(_FN, KC_SPC)
#define KC_FN_BSP LT(_FN, KC_BSPC)
#define KC_CTL_ESC CTL_T(KC_ESC)
#define KC_SFT_MEH SFT_T(KC_F14)
#define KC_SFT_MIN MT(MOD_RSFT, KC_MINS)
#define KC_CTL_ENT MT(MOD_RCTL, KC_ENT)
#define KC_CTL_PENT MT(MOD_RCTL, KC_PENT)
#define KC_LW TT(_LW)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GRV , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,QUOT,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CTL_ESC , A  , S  , D  , F  , G  ,            H  , J  , K  , L  ,SCLN,CTL_ENT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     SFT_MEH, Z  , X  , C  , V  , B  ,LALT,  RALT, N  , M  ,COMM,DOT ,SLSH,SFT_MIN,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,FN_BSP,LW,          LW,FN_SPC,RGUI
  //                  `----+----+----'        `----+----+----'
  ),

  [_LW] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,INS ,SLCK,PAUS,               PSCR,NLCK,PSLS,PAST, P0 ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CAPS,BTN4,MS_U,BTN5,WH_U,    ,                   , P7 , P8 , P9 ,PMNS,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,MS_L,MS_D,MS_R,WH_D,    ,                   , P4 , P5 , P6 ,PPLS,CTL_PENT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,WH_L,WH_R,BTN3,BTN2,    ,         ,BTN1, P1 , P2 , P3 ,PDOT,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                            ,    ,    ,           ,    ,  
  //                  `----+----+----'        `----+----+----'
  ),

  [_FN] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      F1 , F2 , F3 , F4 , F5 , F6,                 F7 , F8 , F9 ,F10 ,F11 ,F12 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,M1_S,M2_S,M1_R,M2_R,M_STOP,             PGUP,HOME,LBRC,RBRC,    ,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               LEFT,DOWN, UP ,RGHT,BSLS,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         , M1 , M2 , M3 , M4 ,    ,    ,         ,PGDN,END, EQL ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,    
  //                  `----+----+----'        `----+----+----'
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  if (record->event.pressed) {
    switch(keycode) {
      case KC_M1:
        SEND_STRING("1");
        return false; break;
      case KC_M2:
        SEND_STRING("2");
        return false; break;
      case KC_M3:
        SEND_STRING("3");
        return false; break;
      case KC_M4:
        SEND_STRING("4");
        return false; break;
    }
  }
  return true;
};
