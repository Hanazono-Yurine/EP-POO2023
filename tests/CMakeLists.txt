cmake_minimum_required(VERSION 3.27)

project(ep-poo LANGUAGES CXX VERSION 1.0.0)

Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(unit_test simple_unit_test.cpp)
target_link_libraries(unit_test PRIVATE amplificador sinal somador integrador persistenciademodulo)
target_link_libraries(unit_test PRIVATE Catch2::Catch2WithMain)
set_target_properties( unit_test
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
)
