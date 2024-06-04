#pragma once
#include "eduardino_defines.hpp"
#include <string.h>

template <typename base_t>
struct bitSelectorProxy_t {
  base_t &target;
  cu8 bitNumber;

  _inline_ bitSelectorProxy_t(base_t &_target, cu8 _bitNumber) : target(_target), bitNumber(_bitNumber) {}

  _inline_ constexpr void operator=(u8 to) {
    if constexpr (sizeof(target) == 1) {
      if (to == 0) {
        target &= ~mBv(bitNumber); }
      else if (to == 1) {
        target |= mBv(bitNumber); }
      else {
        target ^= mBv(bitNumber); } }
    else {
      if (to == 0) {
        ((u8 *)&target)[bitNumber >> 3] &= ~mBv(bitNumber & 0x07); }
      else if (to == 1) {
        ((u8 *)&target)[bitNumber >> 3] |= mBv(bitNumber & 0x07); }
      else {
        ((u8 *)&target)[bitNumber >> 3] ^= mBv(bitNumber & 0x07); } } }

  _inline_ operator bool() const {
    if (sizeof(target) == 1) {
      return (target & mBv(bitNumber)); }
    else {
      return ((((u8 *)&target)[bitNumber >> 3]) & mBv(bitNumber & 0x07)); } }

  _inline_ void Set() {
    mSelf = true; }

  _inline_ void Clear() {
    mSelf = false; }

  _inline_ void Hi() {
    Set(); }

  _inline_ void Lo() {
    Clear(); }

  _inline_ bool isHi() {
    return (mSelf == true); }

  _inline_ bool isLo() {
    return (mSelf == false); }

  _inline_ void Togle() {
    mSelf = !mSelf; } };

/*py: def printBitFields(bits): return ['unsigned bit_%d :1;'%i for i in range(bits)]*/

template <typename derived_t, typename base_type>
struct transformationMixin {

  constexpr base_type & getValue() {
    return (static_cast<derived_t *>(this))->value; }

  template <std::integral number_T>
  transformationMixin(number_T to_value = 0) {
    getValue() = to_value; }

  transformationMixin() {
    getValue() = 0; }

  _inline_ operator auto &&() {
    return getValue(); }

  _inline_ auto &operator=(const auto &&to_value) {
    getValue() = to_value;
    return (static_cast<derived_t *>(this)); }

  _inline_ auto operator[](cu8 bitN) const volatile {
    auto * temp = static_cast<const volatile derived_t*>(this);
    auto * temp2 = const_cast<derived_t*>(temp);
    return bitSelectorProxy_t<base_type>(temp2->value, bitN); } };

struct U8 : transformationMixin<U8, u8> {
  using transformationMixin::transformationMixin;
  union {
    /*py: bits = 8*/
    u8 value;

    struct {
      /*py: printBitFields(bits)*/ /* */
      unsigned bit_0 : 1;
      unsigned bit_1 : 1;
      unsigned bit_2 : 1;
      unsigned bit_3 : 1;
      unsigned bit_4 : 1;
      unsigned bit_5 : 1;
      unsigned bit_6 : 1;
      unsigned bit_7 : 1; };

    struct {
      unsigned LSB : 1; /*py: 'unsigned :%d;'%(bits-2)*/ /* */
      unsigned : 6;
      unsigned MSB : 1; };

    struct {
      unsigned nibbleL : 4;
      unsigned nibbleH : 4; };

    struct {
      unsigned low3 : 3;
      unsigned upper5 : 5; }; }; };

struct U16 : public transformationMixin<U16, u16> {
  using transformationMixin::transformationMixin;
  union {
    /*py: bits = 16*/
    u16 value;

    struct {
      /*py: printBitFields(bits)*/ /* */
      unsigned bit_0 : 1;
      unsigned bit_1 : 1;
      unsigned bit_2 : 1;
      unsigned bit_3 : 1;
      unsigned bit_4 : 1;
      unsigned bit_5 : 1;
      unsigned bit_6 : 1;
      unsigned bit_7 : 1;
      unsigned bit_8 : 1;
      unsigned bit_9 : 1;
      unsigned bit_10 : 1;
      unsigned bit_11 : 1;
      unsigned bit_12 : 1;
      unsigned bit_13 : 1;
      unsigned bit_14 : 1;
      unsigned bit_15 : 1; };

    struct {
      u8 low_byte;
      u8 hi_byte; };

    u8 bytes[2]; }; };

struct U24 : public transformationMixin<U24, u24> {
  using transformationMixin::transformationMixin;
  union {
    /*py: bits = 16*/
    u24 value;

    struct {
      /*py: printBitFields(bits)*/ /* */
      unsigned bit_0 : 1;
      unsigned bit_1 : 1;
      unsigned bit_2 : 1;
      unsigned bit_3 : 1;
      unsigned bit_4 : 1;
      unsigned bit_5 : 1;
      unsigned bit_6 : 1;
      unsigned bit_7 : 1;
      unsigned bit_8 : 1;
      unsigned bit_9 : 1;
      unsigned bit_10 : 1;
      unsigned bit_11 : 1;
      unsigned bit_12 : 1;
      unsigned bit_13 : 1;
      unsigned bit_14 : 1;
      unsigned bit_15 : 1;
      unsigned bit_16 : 1;
      unsigned bit_17 : 1;
      unsigned bit_18 : 1;
      unsigned bit_19 : 1;
      unsigned bit_20 : 1;
      unsigned bit_21 : 1;
      unsigned bit_22 : 1;
      unsigned bit_23 : 1; };

    struct {
      u8 low_byte;
      u8 med_byte;
      u8 hi_byte; };

    u8 bytes[sizeof(value)];
    U8 Ubytes[sizeof(value)]; }; };

struct U32 : public transformationMixin<U32, u32> {
  using transformationMixin::transformationMixin;
  union {

    /*py: bits = 32*/
    u32 value;

    struct {
      /*py: printBitFields(bits)*/ /* */
      unsigned bit_0 : 1;
      unsigned bit_1 : 1;
      unsigned bit_2 : 1;
      unsigned bit_3 : 1;
      unsigned bit_4 : 1;
      unsigned bit_5 : 1;
      unsigned bit_6 : 1;
      unsigned bit_7 : 1;
      unsigned bit_8 : 1;
      unsigned bit_9 : 1;
      unsigned bit_10 : 1;
      unsigned bit_11 : 1;
      unsigned bit_12 : 1;
      unsigned bit_13 : 1;
      unsigned bit_14 : 1;
      unsigned bit_15 : 1;
      unsigned bit_16 : 1;
      unsigned bit_17 : 1;
      unsigned bit_18 : 1;
      unsigned bit_19 : 1;
      unsigned bit_20 : 1;
      unsigned bit_21 : 1;
      unsigned bit_22 : 1;
      unsigned bit_23 : 1;
      unsigned bit_24 : 1;
      unsigned bit_25 : 1;
      unsigned bit_26 : 1;
      unsigned bit_27 : 1;
      unsigned bit_28 : 1;
      unsigned bit_29 : 1;
      unsigned bit_30 : 1;
      unsigned bit_31 : 1; };

    struct {
      u8 low_byte;
      u8 medlow_byte;
      u8 medhi_byte;
      u8 hi_byte; };

    struct {
      u16 low_word;
      u16 hi_word; };

    u8 bytes[4];
    u16 words[2]; }; };

struct U64 : public transformationMixin<U64, u64> {
  using transformationMixin::transformationMixin;
  union {
    /*py: bits = 64*/
    u64 value;
    struct {
      /*py: printBitFields(bits)*/ /* */
      unsigned bit_0 : 1;
      unsigned bit_1 : 1;
      unsigned bit_2 : 1;
      unsigned bit_3 : 1;
      unsigned bit_4 : 1;
      unsigned bit_5 : 1;
      unsigned bit_6 : 1;
      unsigned bit_7 : 1;
      unsigned bit_8 : 1;
      unsigned bit_9 : 1;
      unsigned bit_10 : 1;
      unsigned bit_11 : 1;
      unsigned bit_12 : 1;
      unsigned bit_13 : 1;
      unsigned bit_14 : 1;
      unsigned bit_15 : 1;
      unsigned bit_16 : 1;
      unsigned bit_17 : 1;
      unsigned bit_18 : 1;
      unsigned bit_19 : 1;
      unsigned bit_20 : 1;
      unsigned bit_21 : 1;
      unsigned bit_22 : 1;
      unsigned bit_23 : 1;
      unsigned bit_24 : 1;
      unsigned bit_25 : 1;
      unsigned bit_26 : 1;
      unsigned bit_27 : 1;
      unsigned bit_28 : 1;
      unsigned bit_29 : 1;
      unsigned bit_30 : 1;
      unsigned bit_31 : 1;
      unsigned bit_32 : 1;
      unsigned bit_33 : 1;
      unsigned bit_34 : 1;
      unsigned bit_35 : 1;
      unsigned bit_36 : 1;
      unsigned bit_37 : 1;
      unsigned bit_38 : 1;
      unsigned bit_39 : 1;
      unsigned bit_40 : 1;
      unsigned bit_41 : 1;
      unsigned bit_42 : 1;
      unsigned bit_43 : 1;
      unsigned bit_44 : 1;
      unsigned bit_45 : 1;
      unsigned bit_46 : 1;
      unsigned bit_47 : 1;
      unsigned bit_48 : 1;
      unsigned bit_49 : 1;
      unsigned bit_50 : 1;
      unsigned bit_51 : 1;
      unsigned bit_52 : 1;
      unsigned bit_53 : 1;
      unsigned bit_54 : 1;
      unsigned bit_55 : 1;
      unsigned bit_56 : 1;
      unsigned bit_57 : 1;
      unsigned bit_58 : 1;
      unsigned bit_59 : 1;
      unsigned bit_60 : 1;
      unsigned bit_61 : 1;
      unsigned bit_62 : 1;
      unsigned bit_63 : 1; };

    struct {
      u16 low_word;
      u16 medlow_word;
      u16 medhi_word;
      u16 hi_word; };

    struct {
      u32 low_dword;
      u32 hi_dword; };

    u8 bytes[8];
    u16 words[4];
    u32 dwords[2]; }; };

struct pin_t {
  struct GPIO_t {
    U8 PINX;
    U8 DDRX;
    U8 PORTX; } const volatile &GPIO;

  cu8 pin;

  _inline_ bool get() const {
    return GPIO.PINX[pin]; }

  _inline_ bool isHi() const {
    return get() == 1; }

  _inline_ bool isLo() const {
    return get() == 0; }

  _inline_ void Hi() const {
    GPIO.PORTX[pin].Hi(); }

  _inline_ void HiAndVerify() const {
    Hi();
    while (isLo())
      ; }

  _inline_ void Lo() const {
    GPIO.PORTX[pin].Lo(); }

  _inline_ void LoAndVerify() const {
    Lo();
    while (isHi())
      ; }

  _inline_ void pulse() const {
    toggle();
    Nop();
    toggle(); }

  _inline_ void set(bool _hi) const {
    if (_hi) {
      Hi(); }
    else {
      Lo(); } }

  _inline_ void oupin() const {
    GPIO.DDRX[pin].Hi(); }

  _inline_ void inpin() const {
    Lo();
    GPIO.DDRX[pin].Lo(); }

  _inline_ void toggle() const {
    GPIO.DDRX[pin].Hi(); }

  _inline_ void inpinPullUp() const {
    Hi();
    GPIO.DDRX[pin].Lo(); }

  _inline_ void oupinLo() const {
    Lo();
    oupin(); }

  _inline_ void oupinHi() const {
    Hi();
    oupin(); }

  _inline_ void operator=(bool _hi) const {
    set(_hi); }

  _inline_ operator bool() const {
    return get(); } };

struct bitFlag_t {
  const u8 mask;

  constexpr bitFlag_t(u8 _mask)
    : mask(_mask) {}

  constexpr bitFlag_t operator+(const bitFlag_t other) const {
    return bitFlag_t(other.mask | mask); }

  constexpr bitFlag_t operator-(const bitFlag_t other) const {
    return bitFlag_t(other.mask & ~mask); }

  constexpr operator u8() const {
    return mask; } };

template <typename derived_t>
struct FSRmixin {

  void operator=(auto to) volatile {
    static_cast<derived_t &>(mSelf) = to; }

  operator u8&() {
    return static_cast<derived_t &>(mSelf); } };








