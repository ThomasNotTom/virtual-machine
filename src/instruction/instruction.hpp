#include "../operator/operator.hpp"

template <typename T>

class Instruction {
private:
  T op;
  Value output;

public:
  Instruction(Value output, T op) : op(op), output(output) {}

  void execute(Memory& memory) { this->op.operate(memory, output); }
};