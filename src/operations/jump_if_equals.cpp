#include "./jump_if_equals.hpp"

JumpIfTrue::JumpIfTrue(const Value& arg1, const Value& arg2)
    : Operator(arg1, arg2) {};

bool JumpIfTrue::operate(StackPointer& sp, Memory& memory, const Value& out) {
  Value arg1Copy = this->arg1;
  Value arg2Copy = this->arg2;

  while (arg1Copy.hop(memory))
    ;

  while (arg2Copy.hop(memory))
    ;

  if (arg1Copy.getData() == 1) {
    sp.setAddress(arg2Copy.getData());
  } else {
    sp.increment();
  }

  return false;
}