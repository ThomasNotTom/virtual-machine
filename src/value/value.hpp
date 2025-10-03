#pragma once

#include <cstdint>

#include "../memory/memory.hpp"

class Value {
private:
  uint64_t hops;
  uint64_t data;

public:
  Value(uint64_t data) : data(data), hops(0) {};
  Value(uint64_t data, uint64_t hops) : data(data), hops(hops) {};

  bool hop(const Memory& memory) {
    if (this->hops == 0) {
      return false;
    }

    memory.get64(this->data, this->data);
    this->hops--;
    return true;
  };

  uint64_t getData() const { return this->data; }
};