#include "./jump.hpp"

Jump::Jump(const Value& arg1) : Operator(arg1) {};

bool Jump::operate(StackPointer& sp, Memory& memory, const Value& out) {
  Value arg1Copy = this->arg1;

  while (arg1Copy.hop(memory))
    ;

  sp.setAddress(arg1Copy.getData());

  return false;
}