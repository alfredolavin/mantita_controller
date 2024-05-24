#pragma once
#include <eduardino.hpp>
#include <avr/interrupt.h>

template <const pin_t & pin, u16 len>
struct WS2812b {
  void send(const u24 * color) {
    u16 v_len = len;
    ow_pin.oupinLo();
    cli();      //disable interrupts
    //Sends LEDS count times
    while(v_len--) {
      //Sends a color to a single LED
      //increments 'colors' pointer to colors->next
      asm volatile(
        "ld __tmp_reg__, %a0+\n"        // Read the green component and leave pointer at red
        "rcall send_led_strip_byte%=\n" // Send green component
        "ld __tmp_reg__, %a0+\n"        // Read the red component and leave pointer at blue
        "rcall send_led_strip_byte%=\n" // Send red component
        "ld __tmp_reg__, %a0\n"         // Read the blue component
        "rcall send_led_strip_byte%=\n" // Send blue component
        "rjmp led_strip_asm_end%=\n"    //Jump past the assembly subroutines.

        // send_led_strip_byte subroutine:  Sends a byte to the LED strip.
        "send_led_strip_byte%=:\n"
        "rcall send_led_strip_bit%=\n"  // Send most-significant bit (bit 7).
        "rcall send_led_strip_bit%=\n"
        "rcall send_led_strip_bit%=\n"
        "rcall send_led_strip_bit%=\n"
        "rcall send_led_strip_bit%=\n"
        "rcall send_led_strip_bit%=\n"
        "rcall send_led_strip_bit%=\n"
        "rcall send_led_strip_bit%=\n"  // Send least-significant bit (bit 0).
        "ret\n"

        // send_led_strip_bit subroutine:  Sends single bit to the LED strip by driving the data line
        // high for some time.  The amount of time the line is high depends on whether the bit is 0 or 1,
        // but this function always takes the same time (2 us).
        "send_led_strip_bit%=:\n"
#if F_CPU == 8000000
        "rol __tmp_reg__\n"                      // Rotate left through carry.
#endif
        "sbi %[port], %[pin]\n"                           // Drive the line high.
#if F_CPU != 8000000
        "rol __tmp_reg__\n"                      // Rotate left through carry.
#endif

#if F_CPU == 16000000
        "nop\n" "nop\n"
#elif F_CPU == 20000000
        "nop\n" "nop\n" "nop\n" "nop\n"
#endif

        "brcs .+2\n"
        "cbi %[port], %[pin]\n"              // If the bit to send is 0, drive the line low now.

#if F_CPU == 8000000
        "nop\n" "nop\n"
#elif F_CPU == 16000000
        "nop\n" "nop\n" "nop\n" "nop\n" "nop\n"
#elif F_CPU == 20000000
        "nop\n" "nop\n" "nop\n" "nop\n" "nop\n"
        "nop\n" "nop\n"
#endif
        "brcc .+2\n" "cbi %[port], %[pin]\n"              // If the bit to send is 1, drive the line low now.
        "ret\n"
        "led_strip_asm_end%=:"
        :
        : 
		[col] "z" (color),
        [port] "I" (&pin.GPIO.PORTX - __SFR_OFFSET),
        [pin] "I" (pin.pin)
      ); }
    sei();      //re-enable interrupts
  } };

