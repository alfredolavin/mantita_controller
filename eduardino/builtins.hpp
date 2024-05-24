#pragma once
#include <avr/builtins.h>

static auto avrSei= 					__builtin_avr_sei;
static auto avrCli= 					__builtin_avr_cli;
static auto avrSleep= 				__builtin_avr_sleep;
static auto avrWdr= 					__builtin_avr_wdr;
static auto avrNibbleSwap= 	__builtin_avr_swap;
static auto avrFmul= 				__builtin_avr_fmul;
static auto avrFmuls= 				__builtin_avr_fmuls;
static auto avrFmulsu= 			__builtin_avr_fmulsu;
static auto avrDelay_cycles= __builtin_avr_delay_cycles;
