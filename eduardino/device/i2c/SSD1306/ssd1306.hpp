#pragma once
#include "../i2c.hpp"
#include <eduardino.hpp>
#include "font.hpp"

struct SSD1306_C {

  static cu8 height = 32;
  static cu8 width = 64;
  const u8 mAddressI2C = 0x3C;

  enum mode:u8 {
    cmd = 0x80,
    dat = 0x40 };

  enum cmd:u8 {
    /* Fundamental */
    inverseDisplay = 0xA6,
    entireDisplay = 0xA4,
    powerDisplay = 0xAE,
    setContrast = 0x81,
    /* Scrolling Command Table */
    scrollActivate = 0x2E,
    SetVerticalScrollArea = 0xA3,
    /* Addressing */
    setHiColumnStartAdr = 0x10,
    setLoColumnStartAdr = 0x00,
    setPageStart = 0xB0,
    setMemAdrMode = 0x20,
    setColumnAdr = 0x21,
    setPageAdr = 0x22,
    /* Hardware */
    setComOutputScanDirection = 0xC0,
    setDisplayStartLine = 0x40,
    setSegmentRemap = 0xA0,
    setMultiplexRatio = 0xA8,
    setDisplayOffset = 0xD3,
    setComPinsHw = 0xDA,
    /* Timming & Driving */
    setVcomDeselectLevel = 0xDB,
    setDisplayClkDivide = 0xD5,
    setPreChargePeriod = 0xD9 };

  void send(const u8& arg) {
    mi2c.send_u8(arg); }

  template <typename... types> void command(const types&... args) {
    auto context = writeTransferContext(mi2c, mAddressI2C);
    mi2c.send_u8(mode::cmd);
    (send(args),...); }

public:
  enum color_e
    :u8 {
    black = 0,
    white = 1,
    inverse = 2 };

public:

  u8 nextX= 0, nextY= 0;

  u8 backBuffer[width * height / 8];
  color_e fgcolor = inverse;
  color_e bkcolor = black;

  I2C_c & mi2c = i2c_bus;

  font_s mFont = font5x7;

  void begin() {

    mi2c.begin();
    mInFlash(u8 startupSequence[]) = {
      0xA6, /* Normal Display */
      0xD5, 0x80, /* Display clock div */
      0xA8, 0x2F, /* Set Multiplex */
      0xD3, 0x00, /* Set display Offset*/
      0x40, /* Set Start Line */
      0x8D, 0x14, /* Enable ChargePump */
      0x20, 0x10, /* Horizontal memory mode */
      0xA1, /* Segment remap */
      0xC8, /* Scan direction*/
      0xDA, 0x12, /* Enable remap */
      0x81, 0xCF, /* Set contrast */
      0xD9, 0x22, /* Set prechrge */
      0xDB, 0x00, /* Set Vcom*/
      0x2E, /* Stop scroll */
      0xA4 };

    for(iRangeLen(startupSequence)) {
      command(pgm_read_byte(&startupSequence[i])); }

    delay_ms(100);
    setXY(0,0);
    clearDisplay();
    command(cmd::powerDisplay | true); }

  void update() {
    for( iRange(height/8) ) {
      setXY(0, i);
      auto context = writeTransferContext(mi2c, mAddressI2C);
      mi2c.send_u8(mode::dat);
      for (jRange(width)) {
        mi2c.send_u8(backBuffer[i*width+j]); } } }

  void setXY(u8 x, u8 y) {
    x += 0x20;
    y += 0x02;
    command(setHiColumnStartAdr | U8(x).nibbleH);
    command(setLoColumnStartAdr | U8(x).nibbleL);
    command(setPageStart | y); }

  void clearDisplay() {
    memset(backBuffer, bkcolor*0xFF); }

  void setColor(color_e newColor) {
    fgcolor = newColor; }

  void setPixel(u8 x, u8 y) {
    if( x > width || y > height ) {
      return; }

    switch( fgcolor ) {
    case white:
      ((U8)(backBuffer[x + (y >> 3) * width]))[y & 0x07] = 1;
      break;
    case black:
      ((U8)(backBuffer[x + (y >> 3) * width]))[y & 0x07] = 0;
      break;
    case inverse:
      ((U8)(backBuffer[x + (y >> 3) * width]))[y & 0x07] = 2;
      break; } }

  void print(const char * _text PROGMEM, u8 X, u8 Y) {
    u8 c, glyph;
    const char * text = _text;
    while((c = pgm_read_byte(text++), c)) {
      if( mFont.max>= c && c>= mFont.offset ) {
        c -= mFont.offset;
        for( xRange(mFont.width) ) {
          glyph= pgm_read_byte(&mFont.data[c * mFont.width + x]);
          for( yRange(mFont.height) ) {
            if( U8(glyph).LSB ) {
              setPixel(X + x, Y + y); }
            glyph>>=1; } }
        X += mFont.width + mFont.kerning + 1; } }
    nextX+= X + 2;
    nextY+= mFont.height + 1; }

  void drawLine(u8 x0, u8 y0, u8 x1, u8 y1) {
    u8 steep = abs(y1 - y0) > abs(x1 - x0);
    if( steep ) {
      std::swap(x0, y0);
      std::swap(x1, y1); }

    if( x0 > x1 ) {
      std::swap(x0, x1);
      std::swap(y0, y1); }

    s8 dx;
    u8 dy;
    dx = x1 - x0;
    dy = abs(y1 - y0);

    s8 err = dx / 2;
    s8 ystep;

    if( y0 < y1 ) {
      ystep = 1; }
    else {
      ystep = -1; }

    for( ; x0 <= x1; x0++ ) {
      if( steep ) {
        setPixel(y0, x0); }
      else {
        setPixel(x0, y0); }
      err -= dy;
      if( err < 0 ) {
        y0 += ystep;
        err += dx; } } }

  void drawRect(u8 x, u8 y, u8 width, u8 height) {
    drawHorizontalLine(x, y, width);
    drawVerticalLine(x, y, height);
    drawVerticalLine(x + width - 1, y, height);
    drawHorizontalLine(x, y + height - 1, width); }

  void fillRect(u8 xMove, u8 yMove, u8 width, u8 height) {
    for( u8 x = xMove; x < xMove + width; x++ ) {
      drawVerticalLine(x, yMove, height); } }

  void drawCircle(u8 x0, u8 y0, u8 radius) {
    u8 x = 0, y = radius;
    s8 dp = 1 - radius;
    do {
      if( dp < 0 )
        dp = dp + 2 * (++x) + 3;
      else
        dp = dp + 2 * (++x) - 2 * (--y) + 5;

      setPixel(x0 + x, y0 + y);     //For the 8 octants
      setPixel(x0 - x, y0 + y);
      setPixel(x0 + x, y0 - y);
      setPixel(x0 - x, y0 - y);
      setPixel(x0 + y, y0 + x);
      setPixel(x0 - y, y0 + x);
      setPixel(x0 + y, y0 - x);
      setPixel(x0 - y, y0 - x); }
    while( x < y );

    setPixel(x0 + radius, y0);
    setPixel(x0, y0 + radius);
    setPixel(x0 - radius, y0);
    setPixel(x0, y0 - radius); }

  void drawCircleQuads(u8 x0, u8 y0, u8 radius, u8 quads) {
    u8 x = 0, y = radius;
    s8 dp = 1 - radius;
    while( x < y ) {
      if( dp < 0 )
        dp = dp + 2 * (++x) + 3;
      else
        dp = dp + 2 * (++x) - 2 * (--y) + 5;
      if( quads & 0x1 ) {
        setPixel(x0 + x, y0 - y);
        setPixel(x0 + y, y0 - x); }
      if( quads & 0x2 ) {
        setPixel(x0 - y, y0 - x);
        setPixel(x0 - x, y0 - y); }
      if( quads & 0x4 ) {
        setPixel(x0 - y, y0 + x);
        setPixel(x0 - x, y0 + y); }
      if( quads & 0x8 ) {
        setPixel(x0 + x, y0 + y);
        setPixel(x0 + y, y0 + x); } }
    if( (quads & 0x1) && (quads & 0x8) ) {
      setPixel(x0 + radius, y0); }
    if( (quads & 0x4) && (quads & 0x8) ) {
      setPixel(x0, y0 + radius); }
    if( (quads & 0x2) && (quads & 0x4) ) {
      setPixel(x0 - radius, y0); }
    if( (quads & 0x1) && (quads & 0x2) ) {
      setPixel(x0, y0 - radius); } }

  void fillCircle(u8 x0, u8 y0, u8 radius) {
    u8 x = 0, y = radius;
    u8 dp = 1 - radius;
    do {
      if( dp < 0 )
        dp = dp + 2 * (++x) + 3;
      else
        dp = dp + 2 * (++x) - 2 * (--y) + 5;

      drawHorizontalLine(x0 - x, y0 - y, 2 * x);
      drawHorizontalLine(x0 - x, y0 + y, 2 * x);
      drawHorizontalLine(x0 - y, y0 - x, 2 * y);
      drawHorizontalLine(x0 - y, y0 + x, 2 * y); }
    while( x < y );
    drawHorizontalLine(x0 - radius, y0, 2 * radius); }

  void drawHorizontalLine(u8 x, u8 y, u8 length) {
    if( y < 0 || y >= height ) {
      return; }

    if( x < 0 ) {
      length += x;
      x = 0; }

    if( (x + length) > width ) {
      length = (width - x); }

    if( length <= 0 ) {
      return; }

    u8 * bufferPtr = (u8*) backBuffer;
    bufferPtr += (y >> 3) * width;
    bufferPtr += x;

    u8 drawBit = 1 << (y & 7);

    switch( fgcolor ) {
    case white:
      while( length-- ) {
        *bufferPtr++ |= drawBit; };
      break;
    case black:
      drawBit = ~drawBit;
      while( length-- ) {
        *bufferPtr++ &= drawBit; };
      break;
    case inverse:
      while( length-- ) {
        *bufferPtr++ ^= drawBit; };
      break; } }

  void drawVerticalLine(u8 x, u8 y, u8 length) {
    if( x < 0 || x >= width )
      return;

    if( y < 0 ) {
      length += y;
      y = 0; }

    if( (y + length) > height ) {
      length = (height - y); }

    if( length <= 0 )
      return;

    u8 yOffset = y & 7;
    u8 drawBit;
    u8 *bufferPtr = (u8*) backBuffer;

    bufferPtr += (y >> 3) * width;
    bufferPtr += x;

    if( yOffset ) {
      yOffset = 8 - yOffset;
      drawBit = ~(0xFF >> (yOffset));

      if( length < yOffset ) {
        drawBit &= (0xFF >> (yOffset - length)); }

      switch( fgcolor ) {
      case white:
        *bufferPtr |= drawBit;
        break;
      case black:
        *bufferPtr &= ~drawBit;
        break;
      case inverse:
        *bufferPtr ^= drawBit;
        break; }

      if( length < yOffset )
        return;

      length -= yOffset;
      bufferPtr += width; }

    if( length >= 8 ) {
      switch( fgcolor ) {
      case white:
      case black:
        drawBit = (fgcolor == white) ? 0xFF : 0x00;
        do {
          *bufferPtr = drawBit;
          bufferPtr += width;
          length -= 8; }
        while( length >= 8 );
        break;
      case inverse:
        do {
          *bufferPtr = ~(*bufferPtr);
          bufferPtr += width;
          length -= 8; }
        while( length >= 8 );
        break; } }

    if( length > 0 ) {
      drawBit = (1 << (length & 7)) - 1;
      switch( fgcolor ) {
      case white:
        *bufferPtr |= drawBit;
        break;
      case black:
        *bufferPtr &= ~drawBit;
        break;
      case inverse:
        *bufferPtr ^= drawBit;
        break; } } } };

