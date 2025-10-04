#pragma once

#include "../memory/memory.hpp"
#include "../stack_pointer/stack_pointer.hpp"

#include "../value/value.hpp"

class Operator {
protected:
  const Value arg1;
  const Value arg2;

public:
  Operator() : arg1({}), arg2({}) {};
  Operator(const Value& arg1) : arg1(arg1), arg2({}) {};
  Operator(const Value& arg1, const Value& arg2) : arg1(arg1), arg2(arg2) {};
  virtual bool operate(StackPointer& sp, Memory& memory, const Value& out) = 0;
  virtual ~Operator() = default;
};