#pragma once
#include <stdint.h>
#include <array>

#if defined(__INTELLISENSE__) || defined(__UINT24_MAX__)
#define __uint24 uint32_t
#define __int24 int32_t
#define __is_assignable
#endif

typedef uint8_t u8;
typedef uint16_t u16;
typedef __uint24 u24;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t s8;
typedef int16_t s16;
typedef __int24 s24;
typedef int32_t s32;
typedef int64_t s64;

typedef volatile uint8_t vu8;
typedef volatile uint16_t vu16;
typedef volatile __uint24 vu24;
typedef volatile uint32_t vu32;
typedef volatile uint64_t vu64;

typedef volatile int8_t vs8;
typedef volatile int16_t vs16;
typedef volatile __int24 vs24;
typedef volatile int32_t vs32;
typedef volatile int64_t vs64;

typedef const uint8_t cu8;
typedef const uint16_t cu16;
typedef const __uint24 cu24;
typedef const uint32_t cu32;
typedef const uint64_t cu64;

template<std::size_t N, class T>
constexpr std::size_t countof(T(&)[N]) { return N; }

#define _used_ __attribute__((used))
#define _packed_ __attribute__((packed))
#define _inline_ __attribute__((always_inline))
#define _no_return_ __attribute__((noreturn))
#define _transparent_union_ __attribute__((__transparent_union__))
#define _transparent_packed_union_ __attribute__((__transparent_union__, __packed__))

#define mNullPointer ((u8*)Null)
#define mSelf (*this)

#define define_range(x, letter, int_type) int_type letter = 0; letter < (x); letter++

#define iRange16(x) define_range(x, i, u16)
#define iRange32(x) define_range(x, i, u32)
#define iRange(x) define_range(x, i, u8)
#define jRange(x) define_range(x, j, u8)
#define kRange(x) define_range(x, k, u8)
#define xRange(_x) define_range(_x, x, u8)
#define yRange(x) define_range(x, y, u8)
#define zRange(x) define_range(x, z, u8)

#define iRangeLen(x) define_range(countof(x), i, u8)
#define jRangeLen(x) define_range(countof(x), j, u8)
#define kRangeLen(x) define_range(countof(x), k, u8)

#define iRangeLen16(x) define_range(countof(x), i, u16)
#define jRangeLen16(x) define_range(countof(x), j, u16)
#define kRangeLen16(x) define_range(countof(x), k, u16)

#define Nop() asm volatile ("nop\n\t")
#define Wdr() asm volatile ("wdr\n\t")

static constexpr bool Off = false;
static constexpr bool On = true;

constexpr auto mBv(cu8 bit) {
	return (1L << bit);}


