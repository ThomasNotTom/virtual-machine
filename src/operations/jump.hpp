#pragma once

#include "../operator/operator.hpp"

class Jump : public Operator {
public:
  Jump(const Value& arg1) : Operator(arg1) {};

  bool operate(StackPointer& sp, Memory& memory, const Value& out) override {
    Value arg1Copy = this->arg1;

    while (arg1Copy.hop(memory))
      ;

    sp.setAddress(arg1Copy.getData());

    return false;
  }
};