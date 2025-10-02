#pragma once

#include <cstdint>

class StackPointer {
private:
  uint64_t address;

public:
  StackPointer(uint64_t address) : address(address) {};
  StackPointer() : address(0) {};

  uint64_t getAddress() const { return this->address; };
  void setAddress(uint64_t newAddress) { this->address = newAddress; };
  void increment() { this->address++; }
};