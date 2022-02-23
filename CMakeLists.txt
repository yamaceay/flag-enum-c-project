cmake_minimum_required(VERSION 3.5.1)
project(Flags)

set(CMAKE_C_STANDARD 99)

add_executable(Input-lib src/input.c include/input.h)
target_include_directories(Input-lib PUBLIC include)
set_target_properties(Input-lib PROPERTIES OUTPUT_NAME "Outputs/Input-out")

add_executable(Flag-test tests/flag_test.c src/flag.c src/bool.c include/flag.h include/bool.h)
target_include_directories(Flag-test PUBLIC include)
add_dependencies(Flag-test Input-lib)
set_target_properties(Flag-test PROPERTIES OUTPUT_NAME "Outputs/Flag-out")

add_executable(Enum-test tests/enum_test.c src/enum.c src/flag.c src/bool.c include/enum.h include/flag.h include/bool.h)
target_include_directories(Enum-test PUBLIC include)
add_dependencies(Enum-test Input-lib)
set_target_properties(Enum-test PROPERTIES OUTPUT_NAME "Outputs/Enum-out")

add_executable(Renum-test tests/renum_test.c src/renum.c src/flag.c src/bool.c include/renum.h include/flag.h include/bool.h)
target_include_directories(Renum-test PUBLIC include)
add_dependencies(Renum-test Input-lib)
set_target_properties(Renum-test PROPERTIES OUTPUT_NAME "Outputs/Renum-out")

