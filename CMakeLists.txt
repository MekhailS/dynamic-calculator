cmake_minimum_required(VERSION 3.17)
project(dynamic_calc)

set(CMAKE_CXX_STANDARD 17)

add_library(divide SHARED make_dll_operations_here/divide.cpp abstract_calc_object.h definitions.h error.h)
add_library(sin SHARED make_dll_operations_here/sin.cpp abstract_calc_object.h definitions.h error.h )
add_library(pi SHARED make_dll_operations_here/pi.cpp abstract_calc_object.h definitions.h error.h )
add_library(minus_binary SHARED make_dll_operations_here/minus_binary.cpp abstract_calc_object.h definitions.h error.h )

add_executable(dynamic_calc main.cpp abstract_calc_object.h definitions.h error.h
        basic_objects/number.h basic_operations/plus.h basic_operations/multiply.h
        basic_objects/bracket_open.h basic_objects/bracket_closed.h basic_operations/minus_unary.h
        operation_collection.cpp operation_collection.h
        calculator.cpp calculator.h)