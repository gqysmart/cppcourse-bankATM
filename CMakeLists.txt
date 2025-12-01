cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")

project(ATM)

file(GLOB SOURCES "src/*.cpp")

add_executable(ATM ${SOURCES})
target_include_directories(ATM PUBLIC include)
target_link_libraries(ATM PRIVATE pthread)