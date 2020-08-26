#include QMK_KEYBOARD_H
// Chord Prefixes

// QMK Layer Numbers
#define BASE 0
#define NUMPAD 1
#define MEDIA 2
#define USERMACROS 3

#include "lt/keymap_engine.h"

/* 	 	
 *  .---------------------------.
 *	| FP01 | FP02 | FP03 | FP04 | 
 *  |---------------------------|
 *	| FP11 | FP12 | FP13 | FP14 | 
 *  '---------------------------'
 */

#define EMPTY_LAYER LAYOUT_faunch(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

// Don't edit your keymap here! Do it in your dicts/ !
// Note: We're defining multiple layers that don't affect the bound keys (i.e. they're 100% transparent).
//       However, switching layers affects which chords will be triggered by processQuerty().
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_faunch( KC_1,  KC_2,  KC_3,  KC_4,
  										    KC_5,  KC_6,  KC_7,  KC_8),
  [NUMPAD] = EMPTY_LAYER,
  [MEDIA] = EMPTY_LAYER,
  [USERMACROS] = EMPTY_LAYER
};
// Don't fuck with this, thanks.
size_t keymapsCount  = sizeof(keymaps)/sizeof(keymaps[0]);
