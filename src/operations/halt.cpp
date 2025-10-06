#include "./halt.hpp"

Halt::Halt() : Operator() {};

bool Halt::operate(StackPointer& sp, Memory& memory, const Value& out) {
  return true;
}