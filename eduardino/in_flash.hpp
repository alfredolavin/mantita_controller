#pragma once
#include "eduardino_int_types.hpp"
#include "eduardino_defines.hpp"
#include <avr/pgmspace.h>
#include <type_traits>
#include <stdlib.h>
#include <array>

#define readFlash(a) pgm_read_byte(&(a))

template <typename T, size_t array_size>
struct inFlashArray {
  using array_element_t = std::remove_const_t<T>;
  cu8 * base_addr;
  constexpr static size_t size = sizeof(array_element_t);

  inFlashArray(T(&base)[array_size])
    :base_addr((cu8*)&base) {};

  _inline_ array_element_t operator[](const u8 index) {
    const u8 * flash_p = base_addr + size * index;
    array_element_t holder;
    memcpy_P(&holder, flash_p, size);
    return holder; } };


const u16 P_flag = mBv(8*sizeof(u16)-2);
#define P(s) (__extension__({static const char __c[] PROGMEM = (s); (const char*)((u16)(&__c[0]) | P_flag);}))
#define Is_P(s) ((u16)s & P_flag)
#define De_P(s) (const char*)((u16)s & ~P_flag)
#define mInFlash( name ) static const name PROGMEM

