cmake_minimum_required(VERSION 3.17)
project(dynamic_calculator)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES_FOR_DLL
        abstract_calc_object.h definitions.h error.h)

add_library(divide SHARED make_dll_operations_here/divide.cpp ${SOURCES_FOR_DLL})
add_library(sin SHARED make_dll_operations_here/sin.cpp ${SOURCES_FOR_DLL} )
add_library(pi SHARED make_dll_operations_here/pi.cpp ${SOURCES_FOR_DLL} )
add_library(power SHARED make_dll_operations_here/power.cpp ${SOURCES_FOR_DLL} )
add_library(minus_binary SHARED make_dll_operations_here/minus_binary.cpp ${SOURCES_FOR_DLL} )

set(SOURCES_FOR_CALCULATOR
        main.cpp abstract_calc_object.h definitions.h error.h
        basic_objects/number.h basic_operations/plus.h basic_operations/multiply.h
        basic_objects/bracket_open.h basic_objects/bracket_closed.h basic_operations/minus_unary.h
        operation_collection.cpp operation_collection.h
        calculator.cpp calculator.h)

add_executable(dynamic_calculator ${SOURCES_FOR_CALCULATOR})