#include <eduardino.hpp>
#include <device/analog/analog.hpp>
#include <device/i2c/SSD1306/ssd1306.hpp>
#include <device/onewire/ds18b20/ds18b20.hpp>

static DS18B20 tempSensor;
static SSD1306_C display;

void setup() {
	display.begin();
	tempSensor.begin(9);
	analog.begin();
	delay_ms(1000);
}

void loop() {
	for( auto x : generateRange(0, 10, 6) ) {
		delay_ms(x);
	}
}
