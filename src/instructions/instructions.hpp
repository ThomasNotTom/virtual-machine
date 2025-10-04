#pragma once

#include <vector>

#include "../instruction/instruction.hpp"
#include "../operator/operator.hpp"

class Instructions {
private:
  std::vector<Instruction> code;
  StackPointer sp = {0};

public:
  Instructions(std::vector<Instruction> code) : code(std::move(code)) {}
  Instructions() {}

  bool run(StackPointer& sp, Memory& memory) {
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
};