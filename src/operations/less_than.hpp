#pragma once

#include "../operator/operator.hpp"

class LessThan : public Operator {
public:
  LessThan(const Value& arg1, const Value& arg2) : Operator(arg1, arg2) {};

  bool operate(StackPointer& sp, Memory& memory, const Value& out) override;
};