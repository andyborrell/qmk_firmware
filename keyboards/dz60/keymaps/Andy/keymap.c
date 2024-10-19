#include QMK_KEYBOARD_H
#define ______ KC_TRNS
#define _______ KC_TRNS
#define ________ KC_TRNS
#define _________ KC_TRNS
#define __________ KC_TRNS
#define ___________ KC_TRNS
#define ____________ KC_TRNS
#define _____________ KC_TRNS

enum custom_keycodes {
    CUSTOM_LEFT_SHIFT = SAFE_RANGE,
    MAGIC_SCOLON,
    KC_SEND_SPECIAL_STR_1,
    KC_SEND_SPECIAL_STR_2,
    KC_SEND_SPECIAL_STR_3,
    KC_SEND_SPECIAL_STR_4,
    SHIFT_LEFT_KEYS,
    MAGIC_THUMB1,
    MAGIC_THUMB2,
    KC_U_Q = SHIFT_LEFT_KEYS + KC_Q,
    KC_U_W = SHIFT_LEFT_KEYS + KC_W,
    KC_U_E = SHIFT_LEFT_KEYS + KC_E,
    KC_U_R = SHIFT_LEFT_KEYS + KC_R,
    KC_U_T = SHIFT_LEFT_KEYS + KC_T,
    KC_U_A = SHIFT_LEFT_KEYS + KC_A,
    KC_U_S = SHIFT_LEFT_KEYS + KC_S,
    KC_U_D = SHIFT_LEFT_KEYS + KC_D,
    KC_U_F = SHIFT_LEFT_KEYS + KC_F,
    KC_U_G = SHIFT_LEFT_KEYS + KC_G,
    KC_U_Z = SHIFT_LEFT_KEYS + KC_Z,
    KC_U_X = SHIFT_LEFT_KEYS + KC_X,
    KC_U_C = SHIFT_LEFT_KEYS + KC_C,
    KC_U_V = SHIFT_LEFT_KEYS + KC_V,
    KC_U_B = SHIFT_LEFT_KEYS + KC_B,
    KC_U_1 = SHIFT_LEFT_KEYS + KC_1,
    KC_U_2 = SHIFT_LEFT_KEYS + KC_2,
    KC_U_3 = SHIFT_LEFT_KEYS + KC_3,
    KC_U_4 = SHIFT_LEFT_KEYS + KC_4,
    KC_U_5 = SHIFT_LEFT_KEYS + KC_5,

};
// Macro Declarations
enum {
    MACRO_PIPE         = 0,  // These macros can be replaced by LSFT(kc) etc..https://beta.docs.qmk.fm/reference/keycodes#modifiers
    MACRO_TILDE        = 1,
    MACRO_QUESTION     = 2,
    MACRO_SHINS        = 3,
    MACRO_LESS_THAN    = 4,
    MACRO_GREATER_THAN = 5,

    MACRO_NUM   = 10,
    MACRO_SHNUM = 20,
    // ..., the rest of your macros
};

#define _BL 0
#define _FL 1
#define _ML 2
#define _SL 3
#define _SL2 4
#define _BR 5
#define _BR2 6
#define _QM 7
#define _NUMKEYS 8
#define _NUM 9


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BL] = LAYOUT(
		KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_F14, KC_DEL, 
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_DEL, KC_BSPC,
		MO(_FL), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, MAGIC_SCOLON, KC_QUOT, KC_ENT,
		KC_LSFT, _______, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, ______, KC_UP, KC_F13,
		KC_LCTL, KC_LGUI, KC_LALT, MAGIC_THUMB1, MAGIC_THUMB2, KC_RCTL, KC_RALT, MO(_ML),KC_LEFT, KC_DOWN, KC_RGHT),

	 [_SL] = LAYOUT(
		_______, KC_U_1, KC_U_2, KC_U_3, KC_U_4, KC_U_5, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, KC_1, KC_2, KC_3, KC_4, KC_5, ______, M(MACRO_PIPE), KC_MINS, KC_PLUS, _______, _______, _______, _______,
		_______, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DOUBLE_QUOTE, KC_ENT, KC_UNDERSCORE, KC_EQL, _______, _______, _______, 
		_______, _______, KC_GRV, KC_DOT, M((MACRO_LESS_THAN)), M((MACRO_GREATER_THAN)), M(MACRO_QUESTION), KC_BSLS, KC_SLSH, ______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

	[_FL] = 	LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, KC_UP, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______, _______, _______, _______, 
        _______, KC_LEFT, KC_DOWN, KC_RGHT, M(MACRO_SHINS), _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_SCLN, _______, KC_ESC, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1,  KC_BTN2,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

[_QM] = 	LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, KC_BTN1, XXXXXXX, KC_BTN1, _______, _______, _______, _______, _______),                                  
[_NUMKEYS] = 	LAYOUT(
		_______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______, _______, _______,
		_______, KC_SEND_SPECIAL_STR_1, KC_SEND_SPECIAL_STR_2, KC_SEND_SPECIAL_STR_3, KC_SEND_SPECIAL_STR_4, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
[_ML] = 	LAYOUT(    
		RESET,  _______, _______, _______, _______, _______, _______, KC_P7, KC_P8, KC_P9, KC_P0, KC_PMNS, KC_PPLS, __________, KC_MUTE,
		_______, _______, _______, _______, _______, _______, _______, KC_P4, KC_P5, KC_P6, _______, _______, _______,  _______,
		__________, RGB_HUI,RGB_MOD, RGB_MODE_PLAIN,  RGB_VAI, _______, _______, KC_P1, KC_P2, KC_P3, _______,  _______, KC_PENT,
		BL_INC, _______, RGB_TOG, KC_PAST, KC_CALC, _______, _______, _______, KC_NLCK, KC_P0, KC_PDOT, KC_PSLS,  KC_VOLU, TG(_NUMKEYS),
		BL_DEC, BL_TOGG, TG(_QM), KC_MPLY, _______, _______, _______, _______,                           KC_MPRV, KC_VOLD, KC_MNXT),
    // [_NUMKEYS] = LAYOUT(1234567890-+000
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, //16 keys
    //     _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______, _______, _______, _______,                               //16 keys
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          // 15 keys
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   // 14 keys
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          // 15 keys
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______                                      // 12 keys
    //     ),
    // [_ML] = LAYOUT(
    //     RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE,
    //     _______, _______, _______, _______, _______, _______, _______, KC_P7, KC_P8, KC_P9, KC_P0, KC_PMNS, KC_PPLS, __________, _______, _______,
    //     ________, _______, _______, _______, RESET, _______, _______, KC_P4, KC_P5, KC_P6, _______, _______, _______, _______, BL_TOGG,        // 15 keys
    //     __________, _______, _______, _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, _______, _______, KC_PENT, BL_INC,              // 14 keys
    //     _______, _______, _______, KC_PAST, KC_CALC, _______, _______, _______, KC_NLCK, KC_P0, KC_PDOT, KC_PSLS, __________, KC_VOLU, BL_DEC, // 14 keys
    //     _______, _______, TG(_QM), KC_MPLY, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT                             // 10 keys
    //     )
	// LAYOUT(
	// 	KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_DEL,
	// 	KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_DEC, BL_TOGG, BL_INC, BL_STEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	// LAYOUT(
	// 	KC_TRNS, M(1), M(2), M(3), M(4), M(5), M(6), M(7), M(8), M(9), M(10), M(11), M(12), KC_TRNS, KC_TRNS,
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	// LAYOUT(
	// 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	// 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	// 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	// 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	// 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
};

#include "../../include/andy_util.h"