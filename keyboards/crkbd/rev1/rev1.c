/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include "rev1.h"

#ifdef RGB_MATRIX_ENABLE

   // Logical Layout
   // Columns
   // Left
   // 0  1  2  3  4
   //                 ROWS
   // 18 13 12 05 04   0
   // 17 14 11 06 03   1
   // 16 15 10 07 02   2
   //       09 08 01   3
   //
   // 0  1  2  3  4
   //                 ROWS
   // 18 13 12 05 04   4
   // 17 14 11 06 03   5
   // 16 15 10 07 02   6
   //       09 08 01   7
   // Physical Layout
   // Columns
   // 0  1  2  3  4  5  6  7  8  9  10 11
   //                                     ROWS
   // 18 13 12 05 04       04 05 12 13 18  0
   // 17 14 11 06 03       03 06 11 14 17  1
   // 16 15 10 07 02       02 07 10 15 16  2
   //        09 08 01     01 08 09         3

led_config_t g_led_config = { {
	// Key Matrix to LED Index
	{ NO_LED,     17,     12,  11,  4,    3 },
	{ NO_LED,     16,     13,  10,  5,    2 },
	{ NO_LED,     15,     14,   9,  6,    1 },
	{ NO_LED, NO_LED, NO_LED,   8,  7,    0 },
	{ NO_LED,     35,     30,  29,  22,  21 },
	{ NO_LED,     34,     31,  28,  23,  20 },
	{ NO_LED,     33,     32,  27,  24,  19 },
	{ NO_LED, NO_LED, NO_LED,  26,  25,  18 }
}, {
	// LED Index to Physical location (on an X, Y coordinate grid)
	{  73,  63 },
	{  64,  39 }, {  64,  21 }, {  64,   4 },
	{  48,   2 }, {  48,  19 }, {  48,  37 },
	{  57,  58 }, {  41,  55 },
	{  32,  35 }, {  32,  13 }, {  32,   0 },
	{  16,   3 }, {  16,  20 }, {  16,  37 },
	{   0,  42 }, {   0,  24 }, {   0,   7 },
/*    { 151,  63 },
	{ 160,  39 }, { 160,  21 }, { 160,   4 },
	{ 176,   2 }, { 176,  19 }, { 176,  37 },
	{ 167,  58 }, { 183,  55 },
	{ 192,  35 }, { 192,  13 }, { 192,   0 },
	{ 208,   3 }, { 208,  20 }, { 208,  37 },
	{ 224,  42 }, { 224,  24 }, { 224,   7 }
	*/
	// TODO: This is temporary code that causes the right side colors to mirror the left side.
	// It causes issues for effects other than reactive simple.
	{  73,  63 },
	{  64,  39 }, {  64,  21 }, {  64,   4 },
	{  48,   2 }, {  48,  19 }, {  48,  37 },
	{  57,  58 }, {  41,  55 },
	{  32,  35 }, {  32,  13 }, {  32,   0 },
	{  16,   3 }, {  16,  20 }, {  16,  37 },
	{   0,  42 }, {   0,  24 }, {   0,   7 }
}, {
  // LED Index to Flag
	1, 4, 4, 4, 4, 4, 4,
	1, 1, 4, 4, 4, 4, 4,
	4, 4, 4, 4,
	1, 4, 4, 4, 4, 4, 4,
	1, 1, 4, 4, 4, 4, 4,
	4, 4, 4, 4,
} };
#endif

void matrix_init_kb(void) {

#ifdef RGB_MATRIX_ENABLE
	if (!isLeftHand) {
		g_led_config = (led_config_t){ {
			{ NO_LED,     35,     30,  29,  22,  21 },
			{ NO_LED,     34,     31,  28,  23,  20 },
			{ NO_LED,     33,     32,  27,  24,  19 },
			{ NO_LED, NO_LED, NO_LED,  26,  25,  18 },
			{ NO_LED,     17,     12,  11,  4,    3 },
			{ NO_LED,     16,     13,  10,  5,    2 },
			{ NO_LED,     15,     14,   9,  6,    1 },
			{ NO_LED, NO_LED, NO_LED,   8,  7,    0 }
		}, {
			/*
			{ 151,  63 },
			{ 160,  39 }, { 160,  21 }, { 160,   4 },
			{ 176,   2 }, { 176,  19 }, { 176,  37 },
			{ 167,  58 }, { 183,  55 },
			{ 192,  35 }, { 192,  13 }, { 192,   0 },
			{ 208,   3 }, { 208,  20 }, { 208,  37 },
			{ 224,  42 }, { 224,  24 }, { 224,   7 },
			*/

			{  73,  63 },
			{  64,  39 }, {  64,  21 }, {  64,   4 },
			{  48,   2 }, {  48,  19 }, {  48,  37 },
			{  57,  58 }, {  41,  55 },
			{  32,  35 }, {  32,  13 }, {  32,   0 },
			{  16,   3 }, {  16,  20 }, {  16,  37 },
			{   0,  42 }, {   0,  24 }, {   0,   7 },
			// TODO: Again, this is a quick and dirty way to mirror effects onto the right side
			{  73,  63 },
			{  64,  39 }, {  64,  21 }, {  64,   4 },
			{  48,   2 }, {  48,  19 }, {  48,  37 },
			{  57,  58 }, {  41,  55 },
			{  32,  35 }, {  32,  13 }, {  32,   0 },
			{  16,   3 }, {  16,  20 }, {  16,  37 },
			{   0,  42 }, {   0,  24 }, {   0,   7 }
		}, {
			1, 4, 4, 4, 4, 4, 4,
			1, 1, 4, 4, 4, 4, 4,
			4, 4, 4, 4,
			1, 4, 4, 4, 4, 4, 4,
			1, 1, 4, 4, 4, 4, 4,
			4, 4, 4, 4,
		} };
	}
#endif
	matrix_init_user();
}

#ifdef SSD1306OLED
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  return process_record_gfx(keycode,record) && process_record_user(keycode, record);
}
#endif
