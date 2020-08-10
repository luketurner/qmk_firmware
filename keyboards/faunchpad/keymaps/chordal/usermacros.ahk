; This is an example Autohotkey program for capturing the keypresses of the USERMACROS layer of the faunchpad:chordal keymap.
; Note that this will prevent the F13 key from working normally, if that's a problem for you.

F13 & 1::Send, FP01
F13 & 2::Send, FP02
F13 & 3::Send, FP03
F13 & 4::Send, FP04
F13 & 5::Send, FP11
F13 & 6::Send, FP12
F13 & 7::Send, FP13

F13 & q::Send, FP01 | FP11
F13 & w::Send, FP02 | FP12
F13 & e::Send, FP03 | FP13
F13 & r::Send, FP04 | FP14

F13 & a::Send, FP01 | FP02
F13 & s::Send, FP02 | FP03
F13 & d::Send, FP03 | FP04
F13 & z::Send, FP11 | FP12
F13 & x::Send, FP12 | FP13
F13 & c::Send, FP13 | FP14
