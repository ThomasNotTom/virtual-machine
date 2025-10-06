#pragma once

#include "../operator/operator.hpp"

class Addition : public Operator {
public:
  Addition(const Value& arg1, const Value& arg2) : Operator(arg1, arg2) {};

  bool operate(StackPointer& sp, Memory& memory, const Value& out) override {
    Value arg1Copy = this->arg1;
    Value arg2Copy = this->arg2;

    while (arg1Copy.hop(memory))
      ;
    while (arg2Copy.hop(memory))
      ;

    Value _;
    memory.set8(out.getData(), arg1Copy.getData() + arg2Copy.getData(), _);

    sp.increment();

    return false;
  }
};