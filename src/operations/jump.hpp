#pragma once

#include "../operator/operator.hpp"

class Jump : public Operator {
public:
  Jump(const Value& arg1);

  bool operate(StackPointer& sp, Memory& memory, const Value& out) override;
};