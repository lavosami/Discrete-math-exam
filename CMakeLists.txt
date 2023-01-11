cmake_minimum_required(VERSION 3.10)

project(Discrete_math_exam)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cpp)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/file.txt
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/pleasurs.txt
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR})