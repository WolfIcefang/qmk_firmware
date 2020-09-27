#pragma once

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

typedef HSV (*reactive_f)(HSV hsv, uint16_t offset);

bool effect_runner_reactive(effect_params_t* params, reactive_f effect_func) {
	RGB_MATRIX_USE_LIMITS(led_min, led_max);

	HSV hsvGrad = rgb_matrix_config.hsv;
	uint8_t scaleGrad = scale8(64, rgb_matrix_config.speed);

	uint16_t max_tick = 65535 / rgb_matrix_config.speed;
	for (uint8_t i = led_min; i < led_max; i++) {
		RGB_MATRIX_TEST_LED_FLAGS();
		uint16_t tick = max_tick;
		// Reverse search to find most recent key hit
		for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
			if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < tick) {
				tick = g_last_hit_tracker.tick[j];
				break;
			}
		}

		uint16_t offset = scale16by8(tick, rgb_matrix_config.speed);
		hsvGrad.h = rgb_matrix_config.hsv.h + (scaleGrad * g_led_config.point[i].x >> 5);
		RGB rgb = hsv_to_rgb(effect_func(hsvGrad, offset));
		rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
	}
	return led_max < DRIVER_LED_TOTAL;
}

#endif  // RGB_MATRIX_KEYREACTIVE_ENABLED
