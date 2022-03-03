cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_C_STANDARD 99)

project(reflag VERSION 1.8.0 DESCRIPTION "modern flags & enums")

add_library (
    reflag SHARED src/bool.c src/flag.c
    src/renum.c include/reflag.h include/bool.h 
    include/flag.h include/renum.h
)
include_directories(include)
include_directories(src)
set_target_properties(
    reflag PROPERTIES 
    VERSION ${PROJECT_VERSION}
    PUBLIC_HEADER include/reflag.h
)

include(GNUInstallDirs)

configure_file(reflag.pc.in reflag.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/reflag.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

add_executable(input src/input.c include/input.h)
target_link_libraries(input PUBLIC reflag)
set_target_properties(input PROPERTIES OUTPUT_NAME output/input)

function(make_test test_file)
    add_executable(${test_file}-test test/${test_file}-test.c)
    target_link_libraries(${test_file}-test PUBLIC reflag)
    set_target_properties(${test_file}-test PROPERTIES 
        OUTPUT_NAME output/${test_file}-test)
endfunction()

function(build_test test_file wdir) 
    add_custom_target(
        ${test_file}-test-run
        COMMAND make input
        COMMAND output/input ${wdir}
        COMMAND make ${test_file}-test
        COMMENT Run ${test_file} Test
    )
endfunction()

set(test_files flag ; renum)

foreach(test_file ${test_files})
    make_test(${test_file})
    build_test(${test_file} .)
endforeach()