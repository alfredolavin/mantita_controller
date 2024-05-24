#pragma once
#include <eduardino_defines.hpp>
#include <eduardino_int_types.hpp>
#include <device/device.hpp>
#include <util/delay.h>
#include <stdint.h>
#include <stdlib.h>
#include <pinout.hpp>
#include <in_flash.hpp>
#include <limits>

void delay_us(u16 us);
void delay_ms(u16 ms);

//auto delay_ms = _delay_ms;
//auto delay_us = _delay_us;


void setup();
int main();
void loop();

inline u8 * memset(auto & what, cu8 to) {
	return (u8*) memset(&what, to, sizeof(what));}

inline u8 * zeromem(auto & what) {
	return (u8*) memset(what, 0x00);}
