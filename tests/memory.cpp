#include <catch2/catch_test_macros.hpp>

#include <cstdint>

#include "../src/memory/memory.hpp"

TEST_CASE("Memory set and get 1 byte value", "[memory]") {
  const uint8_t TEST_VALUE = UINT8_MAX;
  Memory memory(1);
  memory.set8(0, TEST_VALUE);
  uint8_t value;
  memory.get8(0, value);
  REQUIRE(value == TEST_VALUE);
}

TEST_CASE("Memory set and get 2 byte value", "[memory]") {
  const uint16_t TEST_VALUE = UINT16_MAX;
  Memory memory(1);
  memory.set16(0, TEST_VALUE);
  uint16_t value;
  memory.get16(0, value);
  REQUIRE(value == TEST_VALUE);
}