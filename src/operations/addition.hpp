#pragma once

#include "../operator/operator.hpp"

class Addition : Operator {
public:
  Addition(const Value& arg1, const Value& arg2) : Operator(arg1, arg2) {};

  uint64_t operate(Memory& memory, StackPointer& sp,
                   const Value& out) override {
    memory.set8(out.getData(), this->arg1.getData() + this->arg2.getData());
  }
};