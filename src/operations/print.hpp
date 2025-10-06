#pragma once

#include "../operator/operator.hpp"

class Print : public Operator {
public:
  Print(const Value& arg1);

  bool operate(StackPointer& sp, Memory& memory, const Value& out) override;
};