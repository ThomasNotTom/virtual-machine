#include "./instructions.hpp"

Instructions::Instructions() {};

Instructions::Instructions(std::vector<Instruction> code)
    : code(std::move(code)) {};

bool Instructions::run(StackPointer& sp, Memory& memory) {
  // Has recieved a halting instruction
  bool halt = false;
  while (!halt) {
    if (sp.getAddress() >= this->code.size()) {
      // Return a non-graceful finish
      return false;
    }
    Instruction& operation = this->code[sp.getAddress()];
    halt = operation.execute(sp, memory);
  }
  // Return a graceful finish
  return true;
}