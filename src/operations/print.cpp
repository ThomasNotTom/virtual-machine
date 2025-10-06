#include "./print.hpp"

Print::Print(const Value& arg1) : Operator(arg1) {};

bool Print::operate(StackPointer& sp, Memory& memory, const Value& out) {
  Value arg1Copy = this->arg1;

  while (arg1Copy.hop(memory))
    ;

  std::cout << (uint64_t)arg1Copy.getData() << std::endl;

  sp.increment();

  return false;
}