#pragma once

#include "../operator/operator.hpp"

class Instruction {
private:
  std::unique_ptr<Operator> op;
  Value output;

public:
  Instruction(std::unique_ptr<Operator> op, Value output)
      : op(std::move(op)), output(output) {}

  bool execute(StackPointer& sp, Memory& memory) {
    return this->op->operate(sp, memory, output);
  }
};