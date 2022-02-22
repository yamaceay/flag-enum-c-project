cmake_minimum_required(VERSION 3.5.1)
project(Flags)

set(CMAKE_C_STANDARD 99)

add_executable(Renum-test tests/renum_test.c src/renum.c src/flag.c src/bool.c)
add_executable(Enum-test tests/enum_test.c src/enum.c src/flag.c src/bool.c)
add_executable(Flag-test tests/flag_test.c src/flag.c src/bool.c)

target_include_directories(Renum-test PRIVATE include)
target_include_directories(Enum-test PRIVATE include)
target_include_directories(Flag-test PRIVATE include)

set_target_properties(Renum-test PROPERTIES OUTPUT_NAME "Outputs/Renum-out")
set_target_properties(Enum-test PROPERTIES OUTPUT_NAME "Outputs/Enum-out")
set_target_properties(Flag-test PROPERTIES OUTPUT_NAME "Outputs/Flag-out")

