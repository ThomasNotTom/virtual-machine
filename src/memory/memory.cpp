#include "./memory.hpp"

Memory::Memory(uint64_t size) { data.resize(size); };

bool Memory::get8(const uint64_t location, uint8_t& out) const {
  if (location > this->data.size()) {
    return false;
  }

  out = this->data[location];

  return true;
}

bool Memory::set8(const uint64_t location, const uint8_t in, Value& value) {
  if (location > this->data.size()) {
    return false;
  }

  this->data[location] = in;

  value = Value(location, 1);
  return true;
}

bool Memory::get16(const uint64_t location, uint16_t& out) const {
  if ((location + 1) > this->data.size()) {
    return false;
  }

  ((uint8_t*)&out)[0] = this->data[location];
  ((uint8_t*)&out)[1] = this->data[location + 1];

  return true;
}

bool Memory::set16(const uint64_t location, const uint16_t in) {
  if ((location + 1) > this->data.size()) {
    return false;
  }

  this->data[location] = ((uint8_t*)&in)[0];
  this->data[location + 1] = ((uint8_t*)&in)[1];
  return true;
}

bool Memory::get32(const uint64_t location, uint32_t& out) const {
  if ((location + 3) > this->data.size()) {
    return false;
  }

  ((uint8_t*)&out)[0] = this->data[location];
  ((uint8_t*)&out)[1] = this->data[location + 1];
  ((uint8_t*)&out)[2] = this->data[location + 2];
  ((uint8_t*)&out)[3] = this->data[location + 3];

  return true;
}

bool Memory::set32(const uint64_t location, const uint32_t in) {
  if ((location + 3) > this->data.size()) {
    return false;
  }

  this->data[location] = ((uint8_t*)&in)[0];
  this->data[location + 1] = ((uint8_t*)&in)[1];
  this->data[location + 2] = ((uint8_t*)&in)[2];
  this->data[location + 3] = ((uint8_t*)&in)[3];
  return true;
}

bool Memory::get64(const uint64_t location, uint64_t& out) const {
  if ((location + 7) > this->data.size()) {
    return false;
  }

  ((uint8_t*)&out)[0] = this->data[location];
  ((uint8_t*)&out)[1] = this->data[location + 1];
  ((uint8_t*)&out)[2] = this->data[location + 2];
  ((uint8_t*)&out)[3] = this->data[location + 3];
  ((uint8_t*)&out)[4] = this->data[location + 4];
  ((uint8_t*)&out)[5] = this->data[location + 5];
  ((uint8_t*)&out)[6] = this->data[location + 6];
  ((uint8_t*)&out)[7] = this->data[location + 7];

  return true;
}

bool Memory::set64(const uint64_t location, const uint64_t in) {
  if ((location + 7) > this->data.size()) {
    return false;
  }

  this->data[location] = ((uint8_t*)&in)[0];
  this->data[location + 1] = ((uint8_t*)&in)[1];
  this->data[location + 2] = ((uint8_t*)&in)[2];
  this->data[location + 3] = ((uint8_t*)&in)[3];
  this->data[location + 4] = ((uint8_t*)&in)[4];
  this->data[location + 5] = ((uint8_t*)&in)[5];
  this->data[location + 6] = ((uint8_t*)&in)[6];
  this->data[location + 7] = ((uint8_t*)&in)[7];
  return true;
}

void Memory ::print() const {
  std::cout << "-- Memory (" << this->data.size() << ") --" << std::endl;

  for (uint64_t i = 0; i < this->data.size(); i++) {
    std::cout << (uint16_t)this->data[i] << std::endl;
  }
}