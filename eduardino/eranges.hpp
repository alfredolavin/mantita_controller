#pragma once
#include <ranges>

inline auto constexpr range(
  uint16_t from_count,
  uint16_t to_count,
  uint16_t step) {
    
  struct Iter {
    uint16_t count;
    uint16_t step;
    bool operator!=(const uint16_t &rhs) const {
      return count<=rhs; } // oh!!!
    void operator++() {
      count+=step; }
    auto operator*() const {
      return count; } };

  struct Enumerate {
    uint16_t from_count;
    uint16_t to_count;
    uint16_t step;
    auto begin() {
      return Iter{from_count, step }; }
    auto end() {
      return to_count; } };


  return Enumerate{std::min(from_count, to_count),
                   std::max(from_count, to_count),
                   step }; }