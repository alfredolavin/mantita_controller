#pragma once
#include <eduardino.hpp>
#include <genericIO.hpp>
#include <device/device.hpp>

const u8 scl_clock_strech = 1;

struct I2C_c: public genericIO_c<I2C_c>, public AddressOperatorMixin<I2C_c, u8> {
		enum mode : u8 {
			read = 1,
			write = 0
		};

		bool ack;

		_inline_ void delay(){
		  _delay_us(4);}

		void sda_hi() {
			sda.inpinPullUp();}

		void sda_low() {
			sda.oupinLo();}

		void scl_hi() {
			scl.inpinPullUp();
			delay();}

		void scl_low() {
			scl.oupinLo();
			delay();}

		void begin() {
			sda_hi();
			scl_hi();}

		void send_ack() {
			sda_low();
			scl_tick();
			sda_hi();}

		void scl_tick() {
			scl.inpinPullUp();
			delay();
			scl.oupinLo();}

		void stop() {
			sda_low();
			scl_hi();
			sda_hi();}

		auto & start(mode m) {
			sda_low();
			scl_low();
			send_u8( ( targetID<<1 )|m);
			return mSelf;}

		auto & Rxs(u8 *data, const u8 sz) {
			start(mode::read);
			transmission_read(data, sz);
			stop();
			return mSelf;}

		auto & Txs(u8 *data, const u8 sz) {
			start(mode::write);
			transmission_write(data, sz);
			stop();
			return mSelf;}

		void transmission_write(u8 *data, u8 len) {
			for( iRange(len) ) {
				if( ack ) {
					break;}

				else {
					send_u8(data[i]);}
}
}

		void transmission_read(u8 *data, u8 len) {
			if( !ack ) {
				for( iRange(len) ) {
					data[i] = get_u8();
					send_ack();}
}
}

		u8 get_u8() {
			u8 buff = 0x00;

			for( u8 bitMask = 0x80; bitMask; bitMask >>= 1 ) {
					buff |= bitMask*sda;
				scl_tick();}

			check_ack();
			return buff;}

		void send_u8(cu8 data) {
			for( u8 bitMask = 0x80; bitMask; bitMask >>= 1 ) {
			  if( bitMask & data ) {
					sda_hi();}

				else {
					sda_low();}

				scl_tick();}

			check_ack();}

		void check_ack() {
			sda_hi();
			scl_hi();
			ack = sda;
			scl_low();}

} static i2c_bus;

template <I2C_c::mode mode>
struct _i2cTransferContext{
    I2C_c & myi2c;
    _i2cTransferContext(I2C_c & _myi2c, u8 address):
      myi2c(_myi2c) {
      myi2c[address];
      myi2c.start(mode);}

    ~_i2cTransferContext(){
      myi2c.stop();}};

typedef _i2cTransferContext<I2C_c::write> writeTransferContext;
typedef _i2cTransferContext<I2C_c::read> readTransferContext;

