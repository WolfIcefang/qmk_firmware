#include QMK_KEYBOARD_H


extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMBOL 1
#define _ARROW 2
#define _FUNC 3
#define _GAME 4
#define _GAMENUM 5

enum custom_keycodes {
	COMM_PN = SAFE_RANGE,
	GAMECLK,
	RGBTIME,
	SYMLK,
	ARROWLK
};

// Mod-tap shortened keycodes
// for qwerty
#define LALT_A LALT_T(KC_A)
#define LGUI_R LGUI_T(KC_R)
#define LSFT_S LSFT_T(KC_S)
#define LCTL_TT LCTL_T(KC_T)

#define RCTL_N RCTL_T(KC_N)
#define RSFT_E RSFT_T(KC_E)
#define RGUI_I RGUI_T(KC_I)
#define RALT_O RALT_T(KC_O)

// for symbols
#define LALT_GV LALT_T(KC_GRAVE)
#define LGUI_FO LGUI_T(KC_4)
#define LSFT_FV LSFT_T(KC_5)
#define LCTL_SX LCTL_T(KC_6)

#define RCTL_MN RCTL_T(KC_MINUS)
#define RSFT_MT RSFT_T(KC_KP_ASTERISK)
#define RGUI_SL RGUI_T(KC_SLASH)
#define RALT_EQ RALT_T(KC_EQUAL)

// for arrows and layers above
#define TG_FUNC TG(_FUNC)
#define TG_GNUM TG(_GAMENUM)

// Black magic layer switching
#define SPCONE LT(_SYMBOL, KC_SPC)
#define SPCTWO LT(_ARROW, KC_SPC)

#define BSPCONE LT(_SYMBOL, KC_BSPC)
#define BSPCTWO LT(_ARROW, KC_BSPC)

#define TO_SYMB TO(_SYMBOL)
#define TO_AROW TO(_ARROW)

// enum combos here
enum combos {
	//QWERTY
    QP_ESC,
	UQUOT_TAB,
	ZD_CPLK,
	HQUEST_ENT,
	//SYMBOL
	TILNINE_ESC,
	ATPER_TAB,
	ANDTHREE_CAPS,
	BRACKET_ENT,
	//SYMBOL Part two
	ONETWO_ZERO,
	TWOTHREE_DOT,
	ATHASH_LPAR,
	HASHDOLLAR_RPAR,
	SQUARE_LESS,
	SQCURL_GREAT,
	//ARROW
	PRINTNUM_ESC,
	HOMEPAGEUP_TAB,
	STOPPLAY_CAPS,
	MENUFTWO_ENT,
};

// define combo constants here
//qwerty
const uint16_t PROGMEM qp_combo[]         = {KC_Q, KC_P, COMBO_END};
const uint16_t PROGMEM uquot_combo[]         = {KC_L, KC_QUOT, COMBO_END};
const uint16_t PROGMEM zd_combo[]         = {KC_Z, KC_D, COMBO_END};
const uint16_t PROGMEM hquest_combo[]     = {KC_H, KC_QUES, COMBO_END};
//symbol standard
const uint16_t PROGMEM tilnine_combo[]    = {KC_TILD, KC_9, COMBO_END};
const uint16_t PROGMEM atper_combo[]      = {KC_AT, KC_PERC, COMBO_END};
const uint16_t PROGMEM andthree_combo[]   = {KC_AMPR, KC_3, COMBO_END};
const uint16_t PROGMEM bracket_combo[]    = {KC_LBRC, KC_RCBR, COMBO_END};
//symbol numpad
const uint16_t PROGMEM onetwo_combo[]     = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM twothree_combo[]   = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM athash_combo[]     = {KC_AT, KC_HASH, COMBO_END};
const uint16_t PROGMEM hashdollar_combo[] = {KC_HASH, KC_DLR, COMBO_END};
const uint16_t PROGMEM square_combo[]     = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM sqcurl_combo[]     = {KC_RBRC, KC_LCBR, COMBO_END};
//arrow
const uint16_t PROGMEM printnum_combo[]   = {KC_PSCREEN, KC_NUMLOCK, COMBO_END};
const uint16_t PROGMEM homepageup_combo[] = {KC_HOME, KC_PGUP, COMBO_END};
const uint16_t PROGMEM stopplay_combo[]   = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM menuftwo_combo[]   = {KC_APP, KC_F2, COMBO_END};

// define what the combo does
combo_t key_combos[COMBO_COUNT] = {
	[QP_ESC]          = COMBO(qp_combo, KC_ESC),
	[UQUOT_TAB]          = COMBO(uquot_combo, KC_TAB),
	[ZD_CPLK]         = COMBO(zd_combo, KC_CAPSLOCK),
	[HQUEST_ENT]      = COMBO(hquest_combo, KC_ENTER),

	[TILNINE_ESC]     = COMBO(tilnine_combo, KC_ESC),
	[ATPER_TAB]       = COMBO(atper_combo, KC_TAB),
	[ANDTHREE_CAPS]   = COMBO(andthree_combo, KC_CAPSLOCK),
	[BRACKET_ENT]     = COMBO(bracket_combo, KC_ENTER),

	[ONETWO_ZERO]     = COMBO(onetwo_combo, KC_0),
	[TWOTHREE_DOT]    = COMBO(twothree_combo, KC_DOT),
	[ATHASH_LPAR]     = COMBO(athash_combo, KC_LEFT_PAREN),
	[HASHDOLLAR_RPAR] = COMBO(hashdollar_combo, KC_RIGHT_PAREN),
	[SQUARE_LESS]     = COMBO(square_combo, KC_LEFT_ANGLE_BRACKET),
	[SQCURL_GREAT]    = COMBO(sqcurl_combo, KC_RIGHT_ANGLE_BRACKET),

	[PRINTNUM_ESC]    = COMBO(printnum_combo, KC_ESC),
	[HOMEPAGEUP_TAB]  = COMBO(homepageup_combo, KC_TAB),
	[STOPPLAY_CAPS]   = COMBO(stopplay_combo, KC_CAPSLOCK),
	[MENUFTWO_ENT]    = COMBO(menuftwo_combo, KC_ENTER),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
		KC_NO,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		KC_NO,  LALT_A,  LGUI_R,  LSFT_S, LCTL_TT,   KC_G,                         KC_K,   RCTL_N,  RSFT_E,  RGUI_I,  RALT_O,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		KC_NO,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_M,    KC_H, COMM_PN,  KC_DOT, KC_QUES,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
										  GAMECLK,  SPCTWO, BSPCONE,    BSPCONE,  SPCTWO, RGBTIME \
									  //`--------------------------'  `--------------------------'

  ),

  [_SYMBOL] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
		KC_NO, KC_TILD,    KC_7,    KC_8,    KC_9, KC_PIPE,                      KC_CIRC,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		KC_NO, LALT_GV, LGUI_FO, LSFT_FV, LCTL_SX, KC_BSLS,                      KC_PLUS, RCTL_MN, RSFT_MT, RGUI_SL, RALT_EQ,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		KC_NO, KC_AMPR,    KC_1,    KC_2,    KC_3, KC_UNDS,                      KC_COMM, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
										  DM_REC1,   SYMLK, KC_TRNS,    KC_TRNS,  SYMLK,  KC_DEL \
									  //`--------------------------'  `--------------------------'
  ),

  [_ARROW] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
		KC_NO, KC_PSCR, KC_SLCK, KC_PAUS, KC_NLCK, KC_VOLU,                      RGB_VAI, KC_HOME,   KC_UP,  KC_END, KC_PGUP,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		KC_NO, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, KC_VOLD,                      RGB_SPI, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		KC_NO, KC_MSTP, KC_MPRV, KC_MNXT, KC_MPLY, KC_MUTE,                      RGB_TOG,  KC_APP,  KC_INS, TG_FUNC,   KC_F2,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
										   KC_DEL, KC_TRNS, ARROWLK,    ARROWLK, KC_TRNS, DM_PLY1 \
									  //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
		KC_NO,   KC_F9,  KC_F10,  KC_F11,  KC_F12, TG_FUNC,                      TG_FUNC,  KC_F21,  KC_F22,  KC_F23,  KC_F24,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		KC_NO,   KC_F5,   KC_F6,   KC_F7,   KC_F8, TG_FUNC,                      TG_FUNC,  KC_F17,  KC_F18,  KC_F19,  KC_F20,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4, TG_FUNC,                      TG_FUNC,  KC_F13,  KC_F14,  KC_F15,  KC_F16,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
										   KC_DEL,  KC_SPC, KC_BSPC,    KC_BSPC, KC_BSPC,  KC_DEL \
									  //`--------------------------'  `--------------------------'
  ),

  [_GAME] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
		KC_NO,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		KC_NO, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		KC_NO, KC_LCTL,    KC_Z,    KC_X,    KC_C, TG_GNUM,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
										  GAMECLK,  KC_SPC,  KC_SPC,    XXXXXXX, XXXXXXX, XXXXXXX \
									  //`--------------------------'  `--------------------------'
  ),

  [_GAMENUM] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
		KC_NO, KC_TRNS,    KC_7,    KC_8,    KC_9, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		KC_NO, KC_TRNS,    KC_4,    KC_5,    KC_6, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		KC_NO, KC_TRNS,    KC_1,    KC_2,    KC_3, TG_GNUM,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
										  XXXXXXX,  KC_SPC,  KC_SPC,    XXXXXXX, XXXXXXX, XXXXXXX \
									  //`--------------------------'  `--------------------------'
  )
};

int rgbDayNight;
int currentLayer;
bool leftShifted;
bool rightShifted;
bool isKCMPressed;
bool isQUESPressed;
bool entered;
bool lockReady;
bool locking;
bool backspaceHeld;

// Code that is run once the keyboard has fully initialized.
void keyboard_post_init_user(void) {
	rgb_matrix_sethsv_noeeprom(HSV_GREEN);
	rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
	rgbDayNight = 0;  // 0 means day, 1 means night.
	currentLayer = 0;
	leftShifted = false;
	rightShifted = false;
	isKCMPressed = false;
	isQUESPressed = false;
	entered = false;
	lockReady = false;
	locking = false;
	backspaceHeld = false;
}

void persistent_default_layer_set(uint16_t default_layer) {
	eeconfig_update_default_layer(default_layer);
	default_layer_set(default_layer);
}

// mod-tap timing controls
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	    case SPCONE:
	    case SPCTWO:
	        return TAPPING_TERM + 100;
	    case BSPCONE:
	    case BSPCTWO:
	        return TAPPING_TERM + 100;

		case LALT_A:
			return TAPPING_TERM + 200;
		case LGUI_R:
	  return TAPPING_TERM + 350; // 300 < ideal <
	case LCTL_TT:
	  return TAPPING_TERM + 100;
	case LSFT_S:
	  return TAPPING_TERM + 12; // 0 < ideal < 25
	case RSFT_E:
	  return TAPPING_TERM + 12;
	case RCTL_N:
	  return TAPPING_TERM + 100;
	case RGUI_I:
	  return TAPPING_TERM + 350; // 300 < ideal <
	case RALT_O:
	  return TAPPING_TERM + 200;

	case LALT_GV:
	  return TAPPING_TERM + 200;
	case LGUI_FO:
	  return TAPPING_TERM + 350; // 300 < ideal <
	case LCTL_SX:
	  return TAPPING_TERM + 100;
	case LSFT_FV:
	  return TAPPING_TERM + 12;
	case RSFT_MT:
	  return TAPPING_TERM + 12;
	case RCTL_MN:
	  return TAPPING_TERM + 100;
	case RGUI_SL:
	  return TAPPING_TERM + 350; // 300 < ideal <
	case RALT_EQ:
	  return TAPPING_TERM + 200;

	default:
	  return TAPPING_TERM;
  }
}

// Custom keycode controls (Custom keycodes and Macros are the same thing!)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
static uint16_t key_timer;
// space_timer = timer_read();
	switch (keycode) {
	    case BSPCONE:
	    case SPCTWO:
	        if (record->event.pressed) {
	            lockReady = true;
	        }
	        else {
	            lockReady = false;
	        }
	        return true;
	    case SYMLK:
	        if (record->event.pressed) {
	            if (lockReady) {
	                locking = true;
	            }
	            else {
	                register_code(KC_SPC);
	                backspaceHeld = true;
	            }
	        }
	        else {
	            if (locking) {
	                layer_on(_SYMBOL);
	                locking = false;
	            }
	            else if (backspaceHeld) {
	                unregister_code(KC_SPC);
	                backspaceHeld = false;
	            }
	            if (lockReady) {
	                tap_code(KC_SPC);
	            }
	        }
	    return false;
	    case ARROWLK:
	        if (record->event.pressed) {
	            if (lockReady) {
	                locking = true;
	            }
	            else {
	                register_code(KC_BSPC);
	                backspaceHeld = true;
	            }
	        }
	        else {
	            if (locking) {
	                layer_on(_ARROW);
	                locking = false;
	            }
	            else if (backspaceHeld) {
	                unregister_code(KC_BSPC);
	                backspaceHeld = false;
	            }
	            if (lockReady) {
	                tap_code(KC_BSPC);
	            }
	        }
	    return false;

		case GAMECLK:
			if (record->event.pressed) {
				key_timer = timer_read();
			}
			else {
				if (timer_elapsed(key_timer) > 1000) {
				layer_invert(_GAME);
				}
				else {
				    tap_code(KC_DEL);
				}
			}
		return false;
    	case RGBTIME:
    		if (record->event.pressed) {
    			key_timer = timer_read();
    		}
    		else if (timer_elapsed(key_timer) > 1000) {
    			if (0 == rgbDayNight) {
    				rgbDayNight = 1;
    				rgb_matrix_sethsv_noeeprom(0, 255, rgb_matrix_get_val() / 3);
    				rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    			}
    			else {
    				rgbDayNight = 0;
    				rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
    				rgb_matrix_sethsv_noeeprom(78, 255, rgb_matrix_get_val() * 3);
    			}
    		}
    		else {
    		    tap_code(KC_DEL);
    		}
    		return false;

	// macros for ; : !
   case LSFT_S:
	  if (record->event.pressed) {
		 leftShifted = true;
	  }
	  else {
		 leftShifted = false;
	  }
	  return true;
   case RSFT_E:
	  if (record->event.pressed) {
		 rightShifted = true;
	  }
	  else {
		 rightShifted = false;
	  }
	  return true;
   case COMM_PN:
	  if (get_mods() & MOD_MASK_SHIFT) {
		 if (record->event.pressed) {
			clear_mods(); // TODO: Figure out how to save and reset modifier keys. This is a quick and dirty solution.
			register_code(KC_SCOLON);
		 }
		 else {
			unregister_code(KC_SCOLON);
		 }
	  }
	  else {
		 if (record->event.pressed) {
			register_code(KC_COMM);
		 }
		 else {
			unregister_code(KC_COMM);
			unregister_code(KC_SCOLON);
		 }
	  }
	  if (leftShifted) {
		 register_code(KC_LSHIFT);
	  }
	  if (rightShifted) {
		 register_code(KC_RSHIFT);
	  }
	  return false;
   case KC_DOT:
	  if (get_mods() & MOD_MASK_SHIFT) {
		 if (record->event.pressed) {
			register_code(KC_SCOLON);
		 }
		 else {
			unregister_code(KC_SCOLON);
		 }
		 return false;
	  }
	  return true;
   case KC_H:
	  if (get_mods() & MOD_MASK_SHIFT) {
		 if (record->event.pressed) {
			isKCMPressed = true;
			if(isQUESPressed) {
			   tap_code(KC_ENTER);
			   entered = true;
			}
		 }
		 else {
			if (!entered) {
			   tap_code(KC_H);
			}
			if (!isQUESPressed) {
			   entered = false;
			}
			isKCMPressed = false;
		 }
		 return false;
	  }
	  entered = false;
	  isKCMPressed = false;
	  return true;
   case KC_QUES:
	  if (get_mods() & MOD_MASK_SHIFT) {
		 if (record->event.pressed) {
			isQUESPressed = true;
			if (isKCMPressed) {
			   tap_code(KC_ENTER);
			   entered = true;
			}
		 }
		 else {
			if (!entered) {
			   tap_code16(KC_EXCLAIM);
			}
			if (!isKCMPressed) {
			   entered = false;
			}
			isQUESPressed = false;
		 }
		 return false;
	  }
	  entered = false;
	  isQUESPressed = false;
	  return true;

	default:
		return true; // Process all other keycodes normally.
  }
}

// Things that happens when a layer is turned on.
layer_state_t layer_state_set_user(layer_state_t state) {
   isKCMPressed = false;
   isQUESPressed = false;
   entered = false;
   if (0 == rgbDayNight) {
	  switch (get_highest_layer(state)) {
		 case _SYMBOL:
			rgb_matrix_sethsv_noeeprom(135, 255, rgb_matrix_get_val());
			break;

		 case _ARROW:
			rgb_matrix_sethsv_noeeprom(11, 255, rgb_matrix_get_val());
			break;

		 case _FUNC:
			rgb_matrix_sethsv_noeeprom(100, 255, rgb_matrix_get_val());
			break;

		 case _GAME:
			rgb_matrix_sethsv_noeeprom(0, 255, rgb_matrix_get_val());
			break;

		 case _GAMENUM:
			rgb_matrix_sethsv_noeeprom(205, 255, rgb_matrix_get_val());
			break;

		 default: // For any other layers, or the base layer.
			// Make multiple shades of green
			rgb_matrix_sethsv_noeeprom(78, 255, rgb_matrix_get_val());
			break;
	  }
   }
	else {
		switch (get_highest_layer(state)) {

			case _SYMBOL:
				currentLayer = 1;
			break;
			case _ARROW:
				currentLayer = 2;
			break;
			case _FUNC:
				currentLayer = 3;
			break;
			case _GAME:
				currentLayer = 4;
			break;
			case _GAMENUM:
				currentLayer = 5;
			break;
			default:
				currentLayer = 0;
			break;
		}
	}
   return state;
}


// RGB Status stuff (caps lock, num lock, scroll lock)
void rgb_matrix_indicators_user(void) {
   HSV hsv = {0, 0, rgb_matrix_get_val()};
   RGB rgb = hsv_to_rgb(hsv);
   led_t led_state = host_keyboard_led_state();
	if (1 == rgbDayNight) {
		switch (currentLayer) {
			case 0:
				// illuminate everytning.
			break;
			case 1:
				rgb_matrix_set_color(6, 0, 0, 0);
				rgb_matrix_set_color(9, 0, 0, 0);
				rgb_matrix_set_color(14, 0, 0, 0);
			break;
			case 2: // TODO: move this to the right side once qmk supports it
				rgb_matrix_set_color(5, 0, 0, 0);
				rgb_matrix_set_color(10, 0, 0, 0);
				rgb_matrix_set_color(11, 0, 0, 0);
				rgb_matrix_set_color(13, 0, 0, 0);
			break;
			default:
				rgb_matrix_set_color(15, 0, 0, 0);
				rgb_matrix_set_color(16, 0, 0, 0);
				rgb_matrix_set_color(17, 0, 0, 0);
			break;
		}
	}
	if (led_state.caps_lock) {
		rgb_matrix_set_color(2, rgb.r, rgb.g, rgb.b);
		rgb_matrix_set_color(3, rgb.r, rgb.g, rgb.b);
		rgb_matrix_set_color(4, rgb.r, rgb.g, rgb.b);
	}
   // TODO: LEDs on the right side don't work
}

// TODO: Figure out what is causing the master pro micro to occasionally flash the red LED.
