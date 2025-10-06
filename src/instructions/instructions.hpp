#pragma once

#include <vector>

#include "../instruction/instruction.hpp"
#include "../operator/operator.hpp"

class Instructions {
private:
  std::vector<Instruction> code;
  StackPointer sp = {0};

public:
  Instructions(std::vector<Instruction> code);
  Instructions();

  bool run(StackPointer& sp, Memory& memory);
};