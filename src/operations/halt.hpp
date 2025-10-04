#pragma once

#include "../operator/operator.hpp"

class Halt : public Operator {
public:
  Halt() : Operator() {};

  bool operate(StackPointer& sp, Memory& memory, const Value& out) override {
    return true;
  }
};