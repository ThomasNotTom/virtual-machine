#pragma once

#include <cstdint>
#include <iostream>
#include <vector>

#include "../value/value.hpp"

class Memory {
private:
  std::vector<uint8_t> data;

public:
  Memory(uint64_t size);
  bool get8(const uint64_t location, uint8_t& out) const;
  bool set8(const uint64_t location, const uint8_t in, Value& value);

  bool get16(const uint64_t location, uint16_t& out) const;
  bool set16(const uint64_t location, const uint16_t in);

  bool get32(const uint64_t location, uint32_t& out) const;
  bool set32(const uint64_t location, const uint32_t in);

  bool get64(const uint64_t location, uint64_t& out) const;
  bool set64(const uint64_t location, const uint64_t in);

  void print() const;
};