#pragma once
#include <device/device.hpp>

class analog_c{
public:
	void begin() {
	  ADCSRA = aden;
	  ADMUX = refs1 + mux0 + mux1 + mux2 + mux3;}

	u16 internalTemp() {
		const u8 samples = 10;
		u16 accum = 0;
		for(iRange(samples)){
			accum += doMeasurement();}
		accum /= samples;

		return accum;}

protected:
	u16 doMeasurement() {
		ADCSRAfields.adsc= 1;

		while(ADCSRAfields.adsc);

		return ADCL | (ADCH << 8);}
} static analog;
