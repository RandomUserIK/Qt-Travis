cmake_minimum_required(VERSION 3.5)

project(TestLib2 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core REQUIRED)

add_library(TestLib2 SHARED
  TestLib2_global.h
  testlib2.cpp
  testlib2.hpp
)

target_link_libraries(TestLib2 PRIVATE Qt5::Core)

target_compile_definitions(TestLib2 PRIVATE TESTLIB2_LIBRARY)
