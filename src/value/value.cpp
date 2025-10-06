#include "./value.hpp"

#include "../memory/memory.hpp"

bool Value::hop(const Memory& memory) {
  if (this->hops == 0) {
    return false;
  }

  memory.get8(this->data, this->data);
  this->hops--;
  return true;
};