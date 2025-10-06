#pragma once

#include "../operator/operator.hpp"

class Halt : public Operator {
public:
  Halt();

  bool operate(StackPointer& sp, Memory& memory, const Value& out) override;
};