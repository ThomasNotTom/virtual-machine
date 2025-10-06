#pragma once

#include "../operator/operator.hpp"

class Addition : public Operator {
public:
  Addition(const Value& arg1, const Value& arg2);

  bool operate(StackPointer& sp, Memory& memory, const Value& out) override;
};