#pragma once

#include "../operator/operator.hpp"

class GreaterThan : public Operator {
public:
  GreaterThan(const Value& arg1, const Value& arg2);

  bool operate(StackPointer& sp, Memory& memory, const Value& out) override;
};