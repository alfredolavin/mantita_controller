#pragma once
#include <board.hpp>
#include <eduardino.hpp>
#include <genericIO.hpp>

union OneWireId_t {
  U64 u = 0;
  struct {
    u8 family;
    u8 serial [ 6 ];
    u8 crc; }; };

class oneWireBus_c: public genericIO_c<oneWireBus_c>, public AddressOperatorMixin<oneWireBus_c, OneWireId_t> {

public:
  enum cmds : cu8 {
    SearchROM= 0xF0,
    ReadROM= 0x33,
    MatchROM= 0x55,
    SkipROM= 0xCC };

  enum timming : cu16 {
    Reset= 480, };

  u8 lastDiscrepancy;

  void Tx ( cu8 b ) {
    writeBits ( b ); }

  u8 Rx ( ) {
    return readBits ( ); }

  oneWireBus_c & operator () ( cu8 c, bool romSkip= false ) {
    cmd ( c, romSkip );
    return mSelf; }

  void romSelect ( OneWireId_t & newID ) {
    mSelf[newID]; };

  void begin() {
    ow_pin.inpinPullUp();
    while( ow_pin.isLo() ); }

  void reset(void) {
    ow_pin.oupinLo();
    _delay_us(480);
    ow_pin.inpinPullUp();
    _delay_us(480); }

  void writeBits(u8 send, u8 bits = 8) {
    while(bits--) {
      _delay_us(5);
      ow_pin.oupinLo();
      if( send  & 0b1) {
        _delay_us(5);
        ow_pin.inpinPullUp();
        _delay_us(55); }
      else {
        _delay_us(55);
        ow_pin.inpinPullUp();
        _delay_us(5); }
      send>>=1; } }

  u8 readBits(u8 bits = 8) {
    u8 recive = 0;
    u8 mask = 0b1;

    while(bits--) {
      ow_pin.oupinLo();
      _delay_us(5);
      ow_pin.inpinPullUp();
      _delay_us(15);

      if (ow_pin) {
        recive |= mask; }

      _delay_us(55);

      mask <<= 1; }

    return recive; }

  void cmd(cu8 c, bool romSkip) {

    reset();

    if( romSkip ) {
      mSelf << cmds::SkipROM; }
    else {
      mSelf << cmds::MatchROM;
      mSelf << targetID; }
    mSelf << c; }

  OneWireId_t & romRead() {
    mSelf << cmds::ReadROM;
    mSelf >> targetID;
    return targetID; }

  bool romSearchNext() {
    bool searchDirection;
    bool cur_bit, n_cur_bit, lastBit;

    reset();

    mSelf << cmds::SearchROM;
    for( iRange(64) ) {

      cur_bit= readBits(1);
      n_cur_bit= readBits(1);

      if( (cur_bit == n_cur_bit) == 1 ) {
        return false; }

      if( cur_bit != n_cur_bit ) {
        searchDirection= cur_bit; }
      else {
        if( i < lastDiscrepancy ) {
          searchDirection= lastBit; }
        else {
          searchDirection= (i == lastDiscrepancy); } }

      targetID.u[i]= searchDirection;
      writeBits(searchDirection, 1);
      lastBit= cur_bit; }
    return true; }

 } static ow_bus;

