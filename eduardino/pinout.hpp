#pragma once
#include <device/device.hpp>

/* pins */
#define pin_B(number) (pin_t){(const volatile pin_t::GPIO_t&)PINB, number};

#define pin_0(name) static pin_t name = pin_B(0)
#define pin_1(name) static pin_t name = pin_B(1)
#define pin_2(name) static pin_t name = pin_B(2)
#define pin_3(name) static pin_t name = pin_B(3)
#define pin_4(name) static pin_t name = pin_B(4)
#define pin_5(name) static pin_t name = pin_B(5)

/* adc */
pin_5(adc_0_pin);
pin_2(adc_1_pin);
pin_4(adc_2);
pin_3(adc_3);

/**/

/* i2c */
pin_0(sda);
pin_2(scl);

/* spi */
pin_0(spi_miso_pin);
pin_1(spi_mosi_pin);
pin_2(spi_clk_pin);



