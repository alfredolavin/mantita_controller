#pragma once
#include "../onewire.hpp"

struct DS18B20 {
public:
  enum cmds : cu8 {
    Convert_T = 0x44,/* Initiates temperature conversion. */
    Copy_Scratchpad = 0x48, /* Copies TH, TL, and configuration register data from the scratchpad to EEPROM. */
    Write_Scratchpad = 0x4E,
    Read_Power_Supply = 0xB4,/* Writes data into scratchpad bytes 2, 3, and 4 (TH, TL, and configuration registers). */
    Recall_E2 = 0xB8,/* Recalls TH, TL, and configuration register data from EEPROM to the scratchpad. */
    Read_Scratchpad = 0xBE, /* Reads the entire scratchpad including the CRC byte. */
    SearchAlarm = 0xEC };

  union scratchpad_t {
    u8 bytes[9];
    struct {
      s16 temperature;
      union {
        u8 scratchpadWrite[3];
        struct {
          s16 userRegister;
          struct {
            unsigned :5;
            unsigned R :2;
            unsigned :1; }; }; };
      u8 reserved[3];
      u8 crc; }; };

  u8 resolutionBits;
  scratchpad_t scratchpad;
  static constexpr oneWireBus_c &mOW = ow_bus;
  OneWireId_t myID;

  const u16 tConv = 93;

  void begin(cu8 _resolutionBits) {
    resolutionBits = _resolutionBits;
    ow_bus.begin();
    ow_bus.romSearchNext();
    myID = ow_bus.targetID;
    setResolution(resolutionBits); }

  s8 getTemp() {
    ow_bus[myID](cmds::Read_Scratchpad) >> scratchpad;
    ow_bus[myID](cmds::Convert_T);
    delay_ms(tConv	* ((resolutionBits-9) >> 2));
    ow_bus[myID](cmds::Read_Scratchpad) >> scratchpad;
    return u16(scratchpad.bytes[1] << 8 | scratchpad.bytes[0]) >> 4; }

  void setResolution ( cu8 bits ) {
    zeromem(scratchpad);
    if ((bits> 12) || (bits < 9)) {
      return; }

    scratchpad.R = bits - 9;
    ow_bus[myID](cmds::Write_Scratchpad) << scratchpad; } };

