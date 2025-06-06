cmake_minimum_required(VERSION 3.14)
project(ArchitectureAndDesignPatterns_HW3_AbstractionsDefinition)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(
  AbstractionsDefinition

  source/AbstractionsDefinition.hpp
  source/AbstractionsDefinition.cpp

  source/test_AbstractionsDefinition.cpp
)
target_link_libraries(
  AbstractionsDefinition
  GTest::gtest_main
  GTest::gmock_main
)

include(GoogleTest GoogleMock)
gtest_discover_tests(AbstractionsDefinition)