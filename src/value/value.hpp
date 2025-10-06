#pragma once

#include <cstdint>

class Memory;

class Value {
private:
  uint64_t hops;
  uint8_t data;

public:
  Value() : data(0), hops(0) {};
  Value(uint8_t data) : data(data), hops(0) {};
  Value(uint8_t data, uint64_t hops) : data(data), hops(hops) {};

  bool hop(const Memory& memory);

  uint8_t getData() const { return this->data; }
};