#include "./memory.hpp"

Memory::Memory(uint64_t size) { data.resize(size); };

bool Memory::get8(const uint64_t location, uint8_t& out) const {
  if (location > this->data.size()) {
    return false;
  }

  out = this->data[location];

  return true;
}