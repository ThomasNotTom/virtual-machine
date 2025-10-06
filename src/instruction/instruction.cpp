#include "./instruction.hpp"

Instruction::Instruction(std::unique_ptr<Operator> op, Value output)
    : op(std::move(op)), output(output) {};

bool Instruction::execute(StackPointer& sp, Memory& memory) {
  return this->op->operate(sp, memory, output);
};