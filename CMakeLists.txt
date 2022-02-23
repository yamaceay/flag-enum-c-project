cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_C_STANDARD 99)

project(reflag VERSION 1.4.0 DESCRIPTION "modern flags & enums")

add_library (
    reflag SHARED src/bool.c src/flag.c src/enum.c 
    src/renum.c include/reflag.h include/bool.h 
    include/flag.h include/enum.h include/renum.h
)
include_directories(include)
include_directories(src)
set_target_properties(
    reflag PROPERTIES 
    VERSION ${PROJECT_VERSION}
    PUBLIC_HEADER include/reflag.h
)

include(GNUInstallDirs)

install(TARGETS reflag
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

configure_file(reflag.pc.in reflag.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/reflag.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

add_executable(input src/input.c include/input.h)
target_link_libraries(input PUBLIC reflag)
set_target_properties(input PROPERTIES OUTPUT_NAME output/input)

function(make_test test_file)
    add_executable(${test_file}-test test/${test_file}_test.c)
    target_link_libraries(${test_file}-test PUBLIC reflag)
    set_target_properties(${test_file}-test PROPERTIES 
        OUTPUT_NAME output/${test_file}_test)
endfunction()

function(build_test test_file is_flag wdir) 
    add_custom_target(
        ${test_file}-test-run
        COMMAND make input
        COMMAND output/input ${is_flag} ${wdir}
        COMMAND make ${test_file}-test
        COMMENT Run ${test_file} Test
    )
endfunction()

set(test_files flag ; enum ; renum)
set(are_flags t ; f ; f)

list(LENGTH test_files num_test_files)
math(EXPR len "${num_test_files} - 1")

foreach(val RANGE ${len})
    list(GET test_files ${val} test_file)
    list(GET are_flags ${val} is_flag)
    make_test(${test_file})
    build_test(${test_file} ${is_flag} .)
endforeach()