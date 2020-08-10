#include QMK_KEYBOARD_H

#include "sten.h"
/* 	
 *  .---------------------------.
 *	| FP01 | FP02 | FP03 | FP04 | 
 *  |---------------------------|
 *	| FP11 | FP12 | FP13 | FP14 | 
 *  '---------------------------'
 */

/*

# Chordal Keymap for Faunchpad

This is a fairly simply keymap that (ab)uses QMK's layer feature to implement "modal chords" (hence "Chordal".)

The Faunchpad starts out in a default mode, which has no functionality except as a "menu" to other modes:

  - FP01 selects NUMPAD mode.
  - FP02 selects MEDIA mode.
  - FP03 selects MACROS mode.

Once you select a mode, the macropad stays in that mode until you return to BASE (menu) mode with FP14.
Returing to BASE can also be done by pressing EVERY key at once.
Pressing FP04 + FP11 at any time will type out the name of the current mode.

## Numpad mode

The numpad mode emulates a full numpad, using the keys FP01-FP03 and FP11-FP13 to represent the 10 digits.
Because it uses "true numpad" keys, numbers are only emitted when NUMLOCK is enabled. The FP04 key toggles NUMLOCK.

## Media mode

The media mode has basic playback and volume control keys.

## (TODO) Macros mode

This mode will be user to interface with a "userspace" macro tool like Autohotkey. Ideally it'll work by sending some
key combinations that are otherwise unused, but can be captured with any macro tool and acted on.

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
      P( FP11 | FP04, SEND_STRING("macros"));

      // TODO

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
