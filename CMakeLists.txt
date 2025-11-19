cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(ATM)

file(GLOB SOURCES "src/*.cpp")

add_executable(ATM ${SOURCES})
