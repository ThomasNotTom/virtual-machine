#pragma once

#include "../operator/operator.hpp"

class JumpIfTrue : public Operator {
public:
  JumpIfTrue(const Value& arg1, const Value& arg2);

  bool operate(StackPointer& sp, Memory& memory, const Value& out);
};