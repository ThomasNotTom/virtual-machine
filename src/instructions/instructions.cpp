#include "./instructions.hpp"

Instructions::Instructions() {};

Instructions::Instructions(std::vector<Instruction> code)
    : code(std::move(code)) {};

bool Instructions::run(StackPointer& sp, Memory& memory) {
  bool halt = false;
  uint64_t i = 0;
  while (!halt) {
    if (sp.getAddress() >= this->code.size()) {
      return false;
    }
    Instruction& operation = this->code[sp.getAddress()];
    halt = operation.execute(sp, memory);
  }
  return true;
}