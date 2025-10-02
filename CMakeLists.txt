cmake_minimum_required(VERSION 3.10)
project(alpha)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")


file(GLOB_RECURSE ALL_SRC_CPP CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)
file(GLOB_RECURSE ALL_SRC_HPP CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
)

list(FILTER ALL_SRC_CPP EXCLUDE REGEX ".*main\\.cpp$")
set(SRC_FILES ${ALL_SRC_CPP} ${ALL_SRC_HPP})

add_executable(main ${SRC_FILES} "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include(FetchContent)

FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.7.0
)

FetchContent_MakeAvailable(catch2)

file(GLOB_RECURSE TEST_SRC CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp"
)

add_executable(tests ${SRC_FILES} ${TEST_SRC})

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

set_target_properties(tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)


include(CTest)
include(Catch)
catch_discover_tests(tests)