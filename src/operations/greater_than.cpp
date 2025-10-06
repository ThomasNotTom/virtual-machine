#include "./greater_than.hpp"

GreaterThan::GreaterThan(const Value& arg1, const Value& arg2)
    : Operator(arg1, arg2) {};

bool GreaterThan::operate(StackPointer& sp, Memory& memory, const Value& out) {
  Value arg1Copy = this->arg1;
  Value arg2Copy = this->arg2;

  while (arg1Copy.hop(memory))
    ;
  while (arg2Copy.hop(memory))
    ;

  bool gt = arg1Copy.getData() > arg2Copy.getData();
  Value _;
  memory.set8(out.getData(), gt ? 1 : 0, _);

  sp.increment();

  return false;
}