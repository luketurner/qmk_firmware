#include QMK_KEYBOARD_H

#include "sten.h"
/* 	
 *  .---------------------------.
 *	| FP01 | FP02 | FP03 | FP04 | 
 *  |---------------------------|
 *	| FP11 | FP12 | FP13 | FP14 | 
 *  '---------------------------'
 */

// QMK Layer Numbers
#define BASE 0
#define NUMPAD 1
#define MEDIA 2
#define USERMACROS 3

uint32_t processQwerty(bool lookup) {

    P( FP01 | FP02 | FP03 | FP04 | FP11 | FP12 | FP13 | FP14, layer_clear());
    P( FP14, layer_clear());

    if (layer_state_is(NUMPAD)) {
      P( FP11 | FP04, SEND_STRING("numpad"));

      P(FP01,         SEND(KC_KP_1));
      P(FP02,         SEND(KC_KP_2));
      P(FP03,         SEND(KC_KP_3));
      P(FP01 | FP11,  SEND(KC_KP_4));
      P(FP02 | FP12,  SEND(KC_KP_5));
      P(FP03 | FP13,  SEND(KC_KP_6));
      P(FP11,         SEND(KC_KP_7));
      P(FP12,         SEND(KC_KP_8));
      P(FP13,         SEND(KC_KP_9));
      P(FP01 | FP02,  SEND(KC_KP_0));
      P(FP04,         SEND(KC_NUMLOCK));

      return 0;
    }
    
    if (layer_state_is(MEDIA)) {
      P( FP11 | FP04, SEND_STRING("media"));

      P(FP01, SEND(KC_MPRV));
      P(FP02, SEND(KC_MNXT));
      P(FP03, SEND(KC_MPLY));
      P(FP04, SEND(KC_MSEL));
      P(FP11, SEND(KC_VOLD));
      P(FP12, SEND(KC_VOLU));
      P(FP13, SEND(KC_MUTE));

      return 0;
    }

    if (layer_state_is(USERMACROS)) {
      P( FP11 | FP04, SEND_STRING("usermacros"));

      P(FP01, SEND(KC_F13); SEND(KC_1));
      P(FP02, SEND(KC_F13); SEND(KC_2));
      P(FP03, SEND(KC_F13); SEND(KC_3));
      P(FP04, SEND(KC_F13); SEND(KC_4));
      P(FP11, SEND(KC_F13); SEND(KC_5));
      P(FP12, SEND(KC_F13); SEND(KC_6));
      P(FP13, SEND(KC_F13); SEND(KC_7));

      P(FP01 | FP11, SEND(KC_F13); SEND(KC_Q));
      P(FP02 | FP12, SEND(KC_F13); SEND(KC_W));
      P(FP03 | FP13, SEND(KC_F13); SEND(KC_E));
      P(FP04 | FP14, SEND(KC_F13); SEND(KC_R));

      P(FP01 | FP02, SEND(KC_F13); SEND(KC_A));
      P(FP02 | FP03, SEND(KC_F13); SEND(KC_S));
      P(FP03 | FP04, SEND(KC_F13); SEND(KC_D));
      P(FP11 | FP12, SEND(KC_F13); SEND(KC_Z));
      P(FP12 | FP13, SEND(KC_F13); SEND(KC_X));
      P(FP13 | FP14, SEND(KC_F13); SEND(KC_C));

      return 0;
    }

    // Keybinds down here are only active when BASE is the highest layer
    
    P( FP11 | FP04, SEND_STRING("base"));

    // Switch to other layers from the base layer with a single button
    P( FP01, layer_move(NUMPAD));
    P( FP02, layer_move(MEDIA));
    P( FP03, layer_move(USERMACROS));

    return 0;
}

#define EMPTY_LAYER LAYOUT_faunch(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

// Do not change QMK Layer BASE! This is your main keyboard.
// Note: We're defining multiple layers that don't affect the bound keys (i.e. they're 100% transparent).
//       However, switching layers affects which chords will be triggered by processQuerty().
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_faunch(STN_S1,  STN_TL,  STN_PL,  STN_HL, 
   											 STN_S2,  STN_KL,  STN_WL,  STN_RL),
  [NUMPAD] = EMPTY_LAYER,
  [MEDIA] = EMPTY_LAYER,
  [USERMACROS] = EMPTY_LAYER
};

// Don't fuck with this, thanks.
size_t keymapsCount  = sizeof(keymaps)/sizeof(keymaps[0]);
