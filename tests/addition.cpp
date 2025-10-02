#include <catch2/catch_test_macros.hpp>

#include <cstdint>

#include "../src/memory/memory.hpp"
#include "../src/operations/addition.hpp"

TEST_CASE("Add two 1 byte values", "[operator]") {
  const uint8_t TEST_VALUE_1 = 7;
  const uint8_t TEST_VALUE_2 = 11;

  Memory memory(1);
  Addition addition = {TEST_VALUE_1, TEST_VALUE_2};

  StackPointer stackPointer = {0};
  addition.operate(memory, stackPointer, {0});

  uint8_t value;
  memory.get8(0, value);

  const uint8_t TOTAL = TEST_VALUE_1 + TEST_VALUE_2;

  REQUIRE(value == TOTAL);
}