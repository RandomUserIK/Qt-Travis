cmake_minimum_required(VERSION 3.5)

project(TestLib3 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core REQUIRED)

add_library(TestLib3 SHARED
  TestLib3_global.h
  testlib3.cpp
  testlib3.hpp
)

target_link_libraries(TestLib3 PRIVATE Qt5::Core)

target_compile_definitions(TestLib3 PRIVATE TESTLIB3_LIBRARY)
