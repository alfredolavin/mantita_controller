#include "ds18b20.hpp"

const u16 tConv = 93;

void DS18B20::begin(cu8 _resolutionBits){
	resolutionBits = _resolutionBits;
	ow_bus.begin();
	ow_bus.romSearchNext();
	myID = ow_bus.targetID;
	setResolution(resolutionBits);
}

s8 DS18B20::getTemp() {
	ow_bus[myID](cmds::Read_Scratchpad) >> scratchpad;
	ow_bus[myID](cmds::Convert_T);
	delay_ms(tConv	* ((resolutionBits-9) >> 2));
	ow_bus[myID](cmds::Read_Scratchpad) >> scratchpad;
	return u16(scratchpad.bytes[1] << 8 | scratchpad.bytes[0]) >> 4;
}

void DS18B20::setResolution ( cu8 bits ) {
	zeromem(scratchpad);
	if ((bits> 12) || (bits < 9)){
		return;}

	scratchpad.R = bits - 9;
	ow_bus[myID](cmds::Write_Scratchpad) << scratchpad;
}
