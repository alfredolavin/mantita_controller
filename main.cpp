#include <eduardino.hpp>
#include <device/analog/analog.hpp>
#include <device/onewire/ds18b20/ds18b20.hpp>
#include <device/WS2812b/WS2812b.h>
#include "colors.hpp"

const u8 n_leds = 9;

static DS18B20 tempSensor;
static WS2812b<led_pin, n_leds> leds;

void setup() {
	tempSensor.begin(9);
	led_pin.oupin();
	analog.begin();
}


color_t last_color;

void softUpdate(color_t new_color) {
	color_t intermediate;
	const u8 steps = 64;
	float r,g,b;

	float dr = (float)(new_color.r - last_color.r) / (float)steps;
	float dg = (float)(new_color.g - last_color.g) / (float)steps;
	float db = (float)(new_color.b - last_color.b) / (float)steps;

	r = last_color.r;
	g = last_color.g;
	b = last_color.b;
	for(iRange(steps)) {
		delay_ms(5);
		r += dr;
		g += dg;
		b += db;

		intermediate.r = g;
		intermediate.g = b;
		intermediate.b = r;

	  leds.send(&intermediate.value);
	}

	last_color = new_color;
}

void loop () {
  const s8 cero = 0;
  s8 temp = std::min(std::max(cero, tempSensor.getTemp()), (s8)(n_colors-1));
  color_t temp_color = (color_t)inFlashArray(colors)[temp];

  while(test--){
	softUpdate(temp_color);}

  delay_ms(50);
}

