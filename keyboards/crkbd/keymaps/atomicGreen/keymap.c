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
#define _MACRO 4
#define _GAME 5
#define _GAMENUM 6

enum custom_keycodes {
  COMM_PN = SAFE_RANGE,
  RGBTIME,
  RGBSTYL,
  MA_UNDO,
  MA_REDO,
};

// Mod-tap shortened keycodes
// for qwerty
#define LALT_A LALT_T(KC_A)
#define LGUI_S LGUI_T(KC_S)
#define LCTL_D LCTL_T(KC_D)
#define LSFT_F LSFT_T(KC_F)

#define RSFT_J RSFT_T(KC_J)
#define RCTL_K RCTL_T(KC_K)
#define RGUI_L RGUI_T(KC_L)
#define RALT_QT RALT_T(KC_QUOTE)

// for symbols
#define LALT_GV LALT_T(KC_GRAVE)
#define LGUI_FO LGUI_T(KC_4)
#define LCTL_FV LCTL_T(KC_5)
#define LSFT_SX LSFT_T(KC_6)

#define RSFT_MN RSFT_T(KC_MINUS)
#define RCTL_MT RCTL_T(KC_KP_ASTERISK)
#define RGUI_SL RGUI_T(KC_SLASH)
#define RALT_EQ RALT_T(KC_EQUAL)

// for arrows and layers above
#define TG_MACR TG(_MACRO)
#define TG_FUNC TG(_FUNC)
#define TG_GAME TG(_GAME)
#define TG_GNUM TG(_GAMENUM)

// Black magic layer switching
#define T_SYM LT(_SYMBOL, KC_BSPC)
#define T_ARROW TT(_ARROW)

#define TO_SYMB TO(_SYMBOL)
#define TO_AROW TO(_ARROW)

// enum combos here
enum combos {
   //QWERTY
   QR_ESC,
   UP_TAB,
   ZV_CPLK,
   MQUEST_ENT,
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
   MACROFTWO_ESC,
   HOMEPAGEUP_TAB,
   STOPPLAY_CAPS,
};

// define combo constants here
//qwerty
const uint16_t PROGMEM qr_combo[]         = {KC_Q, KC_R, COMBO_END};
const uint16_t PROGMEM up_combo[]         = {KC_U, KC_P, COMBO_END};
const uint16_t PROGMEM zv_combo[]         = {KC_Z, KC_V, COMBO_END};
const uint16_t PROGMEM mquest_combo[]     = {KC_M, KC_QUES, COMBO_END};
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
const uint16_t PROGMEM macroftwo_combo[]  = {TG_MACR, KC_F2, COMBO_END};
const uint16_t PROGMEM homepageup_combo[] = {KC_HOME, KC_PGUP, COMBO_END};
const uint16_t PROGMEM stopplay_combo[]   = {KC_MSTP, KC_MPLY, COMBO_END};

// define what the combo does
combo_t key_combos[COMBO_COUNT] = {
  [QR_ESC]          = COMBO(qr_combo, KC_ESC),
  [UP_TAB]          = COMBO(up_combo, KC_TAB),
  [ZV_CPLK]         = COMBO(zv_combo, KC_CAPSLOCK),
  [MQUEST_ENT]      = COMBO(mquest_combo, KC_ENTER),

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

  [MACROFTWO_ESC]   = COMBO(macroftwo_combo, KC_ESC),
  [HOMEPAGEUP_TAB]  = COMBO(homepageup_combo, KC_TAB),
  [STOPPLAY_CAPS]   = COMBO(stopplay_combo, KC_CAPSLOCK),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,  LALT_A,  LGUI_S,  LCTL_D,  LSFT_F,    KC_G,                         KC_H,  RSFT_J,  RCTL_K,  RGUI_L, RALT_QT,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, COMM_PN,  KC_DOT, KC_QUES,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          RGBTIME, KC_BSPC,  KC_SPC,      T_SYM, T_ARROW,  KC_DEL \
                                      //`--------------------------'  `--------------------------'

  ),

  [_SYMBOL] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_TILD,    KC_7,    KC_8,    KC_9, KC_PIPE,                      KC_CIRC,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, LALT_GV, LGUI_FO, LCTL_FV, LSFT_SX, KC_BSLS,                      KC_PLUS, RSFT_MN, RCTL_MT, RGUI_SL, RALT_EQ,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_AMPR,    KC_1,    KC_2,    KC_3, KC_UNDS,                      KC_COMM, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_BSPC,  KC_SPC,    KC_TRNS, KC_TRNS,  KC_DEL \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ARROW] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, TG_MACR, TG_FUNC, TG_GAME,   KC_F2, KC_VOLU,                      RGB_VAI, KC_HOME,   KC_UP,  KC_END, KC_PGUP,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, KC_VOLD,                      RGB_VAD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_MSTP, KC_MPRV, KC_MNXT, KC_MPLY, KC_MUTE,                      RGBSTYL, MA_UNDO, MA_REDO,  KC_APP, KC_SLCK,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_BSPC,  KC_SPC,     KC_TRNS, KC_TRNS,  KC_DEL \
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_PSCR,                      KC_PAUS,  KC_F21,  KC_F22,  KC_F23,  KC_F24,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_INS,                      KC_NLCK,  KC_F17,  KC_F18,  KC_F19,  KC_F20,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                      XXXXXXX,  KC_F13,  KC_F14,  KC_F15,  KC_F16,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_BSPC,  KC_SPC,    XXXXXXX, TG_FUNC,  KC_DEL \
                                      //`--------------------------'  `--------------------------'
  ),

  [_MACRO] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_BSPC,  KC_SPC,    XXXXXXX, TG_MACR,  KC_DEL \
                                      //`--------------------------'  `--------------------------'
  ),

  [_GAME] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,                      XXXXXXX, TG_GAME, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, TG_GNUM,  KC_SPC,    XXXXXXX, XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_GAMENUM] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_4,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_TRNS,    KC_5,    KC_6,    KC_7,    KC_8,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_TRNS,  KC_SPC,    XXXXXXX, XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  )
};

int currentRGBMode;
int rgbDayNight;
bool leftShifted;
bool rightShifted;
bool isKCMPressed;
bool isQUESPressed;
bool entered;

// Code that is run once the keyboard has fully initialized.
void keyboard_post_init_user(void) {
   rgb_matrix_sethsv_noeeprom(HSV_GREEN);
   rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
   currentRGBMode = 0;
   rgbDayNight = 0;  // 0 means day, 1 means night.
   leftShifted = false;
   rightShifted = false;
   isKCMPressed = false;
   isQUESPressed = false;
   entered = false;
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// mod-tap timing controls
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case T_ARROW:
      return TAPPING_TERM + 100;  // < ideal < 200
    case T_SYM:
      return TAPPING_TERM + 100;

    case LALT_A:
      return TAPPING_TERM + 200;
    case LGUI_S:
      return TAPPING_TERM + 350; // 300 < ideal <
    case LCTL_D:
      return TAPPING_TERM + 100;
    case LSFT_F:
      return TAPPING_TERM + 12; // 0 < ideal < 25
    case RSFT_J:
      return TAPPING_TERM + 12;
    case RCTL_K:
      return TAPPING_TERM + 100;
    case RGUI_L:
      return TAPPING_TERM + 350; // 300 < ideal <
    case RALT_QT:
      return TAPPING_TERM + 200;

    case LALT_GV:
      return TAPPING_TERM + 200;
    case LGUI_FO:
      return TAPPING_TERM + 350; // 300 < ideal <
    case LCTL_FV:
      return TAPPING_TERM + 100;
    case LSFT_SX:
      return TAPPING_TERM + 12;
    case RSFT_MN:
      return TAPPING_TERM + 12;
    case RCTL_MT:
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
   switch (keycode) {
    case RGBSTYL:
      if (record->event.pressed) {
        // do something when pressed
        rgb_matrix_step(); // TODO: Warning! This updates the eeprom! Use mode no eeprom and a switch to cycle through desired effects.
      }
      return false; // Skip all further processing of this key.

    // macros for ; : !
   case LSFT_F:
      if (record->event.pressed) {
         leftShifted = true;
      }
      else {
         leftShifted = false;
      }
      return true;
   case RSFT_J:
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
   case KC_M:
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
               tap_code(KC_M);
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

    // undo and redo macros.
   case MA_UNDO:
      if (record->event.pressed) {
         isKCMPressed = true;
         if (isQUESPressed) {
            tap_code(KC_ENTER);
            entered = true;
         }
      }
      else {
         if (!entered) {
            SEND_STRING(SS_LCTL("z"));
         }
         if (!isQUESPressed) {
            entered = false;
         }
         isKCMPressed = false;
      }
      return false;
   case MA_REDO:
      if (record->event.pressed) {
         SEND_STRING(SS_LCTL("y"));
      }
      return false;
   case KC_SLCK:
      if (record->event.pressed) {
         isQUESPressed = true;
         if (isKCMPressed) {
            tap_code(KC_ENTER);
            entered = true;
         }
      }
      else {
         isQUESPressed = false;
         if (!entered) {
            tap_code(KC_SLCK);
         }
         if (!isKCMPressed) {
            entered = false;
         }
         isQUESPressed = false;
      }
      return false;

   case RGBTIME:
      if (record->event.pressed) {
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
      return false;

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

         case _MACRO:
            rgb_matrix_sethsv_noeeprom(240, 255, rgb_matrix_get_val());
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
   return state;
}


// RGB Status stuff (caps lock, num lock, scroll lock)
void rgb_matrix_indicators_user(void) {
   HSV hsv = {0, 0, rgb_matrix_get_val()};
   RGB rgb = hsv_to_rgb(hsv);
   led_t led_state = host_keyboard_led_state();
   if (led_state.caps_lock) {
      for (int i = 2; i <= 4; i++) {
         rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
      }
   }
   // TODO: LEDs on the right side don't work
   if (led_state.num_lock) {
      for (int i = 20; i <= 22; i++) {
         rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
      }
   }
   if (led_state.scroll_lock) {
      rgb_matrix_set_color(30, rgb.r, rgb.g, rgb.b);
      rgb_matrix_set_color(34, rgb.r, rgb.g, rgb.b);
      rgb_matrix_set_color(35, rgb.r, rgb.g, rgb.b);
   }
   // TODO: Add nighttime layer state indicators. red lights on 0, 1, 7 and 18, 19, 25
}

// TODO: Update RGBSTYL System.

// TODO: Fix the enter key on the arrow level

// TODO: Figure out what is causing the master pro micro to occasionally flash the red LED.
