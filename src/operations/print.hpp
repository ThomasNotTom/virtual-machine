#pragma once

#include "../operator/operator.hpp"

class Print : public Operator {
public:
  Print(const Value& arg1) : Operator(arg1) {};

  bool operate(StackPointer& sp, Memory& memory, const Value& out) override {
    Value arg1Copy = this->arg1;

    while (arg1Copy.hop(memory))
      ;

    std::cout << (uint64_t)arg1Copy.getData() << std::endl;

    sp.increment();

    return false;
  }
};