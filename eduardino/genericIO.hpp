#pragma once
#include <eduardino_defines.hpp>

template <typename derived_t>
struct genericIO_c {
  auto & operator<<(const auto & data) {
    (static_cast<derived_t*>(this))->Txs((u8*)(&data), sizeof(data));
    return (static_cast<derived_t&>(mSelf)); }

  auto & operator>>(auto & data) {
    (static_cast<derived_t*>(this))->Rxs((u8*)(&data), sizeof(data));
    return (static_cast<derived_t&>(mSelf)); }

  auto & Rxs(u8 * data, const u8 sz) {
    for( iRange(sz) ) {
      (data)[i] = (static_cast<derived_t*>(this))->Rx(); }
    return (static_cast<derived_t&>(mSelf)); }

  auto & Txs(u8 * data, const u8 sz) {
    for( iRange(sz) ) {
      (static_cast<derived_t*>(this))->Tx(data[i]); };
    return (static_cast<derived_t&>(mSelf)); }

  void Tx(u8 b) {
    (static_cast<derived_t*>(this))->Tx(b); };
  u8 Rx() {
    return (static_cast<derived_t*>(this))->Rx(); };

};

template <typename derived_t, typename address_t>
struct AddressOperatorMixin {

  address_t targetID;

  derived_t & operator [] (const address_t & newID ) {
    targetID = newID;
    return (static_cast<derived_t&>(mSelf)); }

};
