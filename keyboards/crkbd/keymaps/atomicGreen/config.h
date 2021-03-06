/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */

#define MASTER_LEFT
// Master should always be left.

#define USE_SERIAL_PD2

// Code added by me (Wolf Icefang)
#define FORCE_NKRO

#define TAPPING_TERM 100  // 200 was too high
#define TAPPING_TERM_PER_KEY
#undef PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define DYNAMIC_MACRO_NO_NESTING

#define COMBO_COUNT 18
#define COMBO_TERM 100

#define TAPPING_TOGGLE 2 // number of times a layer must be tapped in order to activate it.
// Setting value to 1 causes issues.

// I haven't set up my macros yet so I don't know if this is going to be useful.
// #define TAP_CODE_DELAY 100 // delay between a register and unregister "tap" action in macros.

// End of code added by Wolf Icefang

// Code for running RGB
/* Default RGB settings to change are in:
qmk_firmware\keyboards\crkbd\rev1 (line 61) #define RGBLED_NUM 54 (change to 36) */
#ifdef RGB_MATRIX_ENABLE

	// #define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
	// #define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
   #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120 // Limits maximum brightness of LEDs to 120 out of 255. Higher may cause the controller to crash
   #define RGB_MATRIX_HUE_STEP 8
   #define RGB_MATRIX_SAT_STEP 8
   #define RGB_MATRIX_VAL_STEP 8
   #define RGB_MATRIX_SPD_STEP 10
   #define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended

   // Effect packages to enable:
   #define RGB_MATRIX_KEYPRESSES

   /* Disable the animations you don't want/need.  You will need to disable a good number of these    *
	* because they take up a lot of space.  Disable until you can successfully compile your firmware. */

   #define DISABLE_RGB_MATRIX_ALPHAS_MODS
   #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
   #define DISABLE_RGB_MATRIX_BREATHING
   #define DISABLE_RGB_MATRIX_BAND_SAT
   #define DISABLE_RGB_MATRIX_BAND_VAL
   #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
   #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
   #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
   #define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
   #define DISABLE_RGB_MATRIX_CYCLE_ALL
   #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
   #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
   #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
   #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
   #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
   #define DISABLE_RGB_MATRIX_DUAL_BEACON
   #define DISABLE_RGB_MATRIX_RAINBOW_BEACON
   #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
   #define DISABLE_RGB_MATRIX_RAINDROPS
   #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
   #define DISABLE_RGB_MATRIX_TYPING_HEATMAP
   #define DISABLE_RGB_MATRIX_DIGITAL_RAIN // warning: Digital Matrix Rain ignores maximum brightness value!
   #define DISABLE_RGB_MATRIX_SOLID_REACTIVE
   //#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
   #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
   #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
   #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
   #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
   #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
   #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
   #define DISABLE_RGB_MATRIX_SPLASH
   #define DISABLE_RGB_MATRIX_MULTISPLASH
   #define DISABLE_RGB_MATRIX_SOLID_SPLASH
   #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH

#endif
