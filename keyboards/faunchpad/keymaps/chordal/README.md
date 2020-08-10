# Chordal Keymap for Faunchpad

This is a fairly simply keymap that (ab)uses QMK's layer feature to implement "modal chords" (hence "Chordal".)

This README gives a general overview of the modes and the important keys/chords, but not all chords are documented.
Check the associated `keymap.c` file for a full list.

Faunchpad key layout:

```
.---------------------------.
| FP01 | FP02 | FP03 | FP04 | 
|---------------------------|
| FP11 | FP12 | FP13 | FP14 | 
'---------------------------'
```

## Base mode

The Faunchpad starts out in a default mode called BASE, which has no functionality except as a "menu" to other modes:

  - FP01 selects NUMPAD mode.
  - FP02 selects MEDIA mode.
  - FP03 selects USERMACROS mode.

Once you select a mode, the macropad stays in that mode until you return to BASE (menu) mode with FP14.
Returing to BASE can also be done by pressing EVERY key at once.
Pressing FP04 + FP11 at any time will type out the name of the current mode.

## Numpad mode

The numpad mode emulates a full numpad, using the keys FP01-FP03 and FP11-FP13 to represent the 10 digits.
Because it uses "true numpad" keys, numbers are only emitted when NUMLOCK is enabled. The FP04 key toggles NUMLOCK.

## Media mode

The media mode has basic playback and volume control keys.

## Usermacros mode

The USERMACROS mode is used to interface with a userland macro system like Autohotkey.
Using this approach, your macro buttons can do more than just send keys -- they can run programs, do I/O, and so forth.

When a button or chord is pressed, the macropad sends an F13 character and another key which corresponds to the buttons pressed.
The macro program can intercept these key combinations and trigger actions based on them.
Between single keys and a few simple chords, 17 macros can be sent. You could easily add more!

For example, pressing FP1 will send F13+1. You can intercept this in Autohotkey:

F13 & 1::Send, Macro detected!

An example Autohotkey script that captures all the USERMACRO keys is included at `./usermacros.ahk`.
Feel free to copy it and change it to define your own macros.

(Note, with Autohotkey, this workflow prevents the F13 key from working for any other use-case.
Normally, this is no problem, but if you use F13, you'll have to pick a different prefix key.)
