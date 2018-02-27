#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

#define TAPPING_TOGGLE 1

//extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LW 1
#define _FN 2
#define _ADJUST 16

//enum custom_keycodes {
//  QWERTY = SAFE_RANGE,
//  LW,
//  FN,
//  ADJUST,
//};


#define KC_ KC_TRNS
#define _______ KC_TRNS

//#define KC_LOWR LOWER
//#define KC_RASE RAISE
//#define KC_RST RESET
//#define KC_BL_S BL_STEP
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
         ,    ,    ,INS ,SLCK,PAUS,               PSCR,NLCK,PSLS,PAST,P0  ,    ,
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
      F1 , F2 , F3 , F4 , F5 , F6,                 F7 , F8 , F9 ,F10 ,F11 , F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,VOLU,MPLY,MNXT,    ,               PGUP,HOME,LBRC,RBRC,BSLS,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,VOLD,MSTP,MPRV,    ,               LEFT,DOWN,UP  ,RGHT,    ,BSLS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,PGDN,END, EQL ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,    
  //                  `----+----+----'        `----+----+----'
  ),

//  [_ADJUST] = KEYMAP(
//  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
//      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
//      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,                            _______, _______, _______, _______, _______, _______,
//  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
//      _______, DEBUG  , RGB_HUD, RGB_SAD, RGB_VAD, _______,                            _______, _______, _______, _______, _______, _______,
//  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
//      BL_STEP, RESET  , _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
//  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
//                                      _______, _______, _______,                  _______, _______, _______
//  //                                `--------+--------+--------'                `--------+--------+--------'
//  )

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

//void persistent_default_layer_set(uint16_t default_layer) {
//  eeconfig_update_default_layer(default_layer);
//  default_layer_set(default_layer);
//}

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  switch (keycode) {
//    case QWERTY:
//      if (record->event.pressed) {
//        #ifdef AUDIO_ENABLE
//          PLAY_SONG(tone_qwerty);
//        #endif
//        persistent_default_layer_set(1UL<<_QWERTY);
//      }
//      return false;
//      break;
//    case LW:
//      if (record->event.pressed) {
//        layer_on(_LW);
//        update_tri_layer(_LW, _FN, _ADJUST);
//      } else {
//        layer_off(_LW);
//        update_tri_layer(_LW, _FN, _ADJUST);
//      }
//      return false;
//      break;
//    case FN:
//      if (record->event.pressed) {
//        layer_on(_FN);
//        update_tri_layer(_LW, _FN, _ADJUST);
//      } else {
//        layer_off(_FN);
//        update_tri_layer(_LW, _FN, _ADJUST);
//      }
//      return false;
//      break;
//    case ADJUST:
//      if (record->event.pressed) {
//        layer_on(_ADJUST);
//      } else {
//        layer_off(_ADJUST);
//      }
//      return false;
//      break;
//  }
//  return true;
//}
