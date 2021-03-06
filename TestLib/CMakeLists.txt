cmake_minimum_required(VERSION 3.5)

project(TestLib
    VERSION 0.1.0
    LANGUAGES CXX
    DESCRIPTION "TestLib"
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(
    TEST_LIB_ENABLE_TESTS
    "Specifies if unit tests should be built and added to ctest"
    ON
)

option(
    TEST_LIB_ENABLE_COVERAGE
    "Specifies if coverage files should be generated. Only works on Linux, with tests turned on."
    ON
)

set(ENABLE_TESTS ${TEST_LIB_ENABLE_TESTS})
set(ENABLE_COVERAGE ${TEST_LIB_ENABLE_COVERAGE})

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(OpenCV REQUIRED COMPONENTS opencv_core
                                        opencv_imgproc
                                        opencv_imgcodecs
                                        opencv_highgui)
find_package(ArrayFire REQUIRED)

add_library(projectwarnings INTERFACE)

if (MSVC)
    target_compile_options(
        projectwarnings
        INTERFACE
        /W4 # all reasonable warnings
    )
else()
    target_compile_options(
        projectwarnings
        INTERFACE
        -Wall
        -Wextra # reasonable and standard
        -Wshadow # warn the user if a variable declaration shadows one from a parent context
        -Wnon-virtual-dtor # warn the user if a class with virtual functions has a non-virtual destructor
        -Wold-style-cast # warn for c-style casts
        -Wcast-align # warn for potential performance problem casts
        -Wunused # warn on anything being unused
        -Woverloaded-virtual # warn if you overload (not override) a virtual function
        -Wpedantic # warn if non-standard C++ is used
        -Wconversion # warn on type conversions that may lose data
        -Wsign-conversion # warn on sign conversions
        -Wnull-dereference # warn if a null dereference is detected
        -Wdouble-promotion # warn if float is implicit promoted to double
        -Wformat=2 # warn on security issues around functions that format output
     )
endif()

set(TEST_LIB_SOURCES
    src/testlib.cpp
)

add_library(testlib SHARED ${TEST_LIB_SOURCES})
target_include_directories(testlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)

# projectwarnings
target_link_libraries(testlib PRIVATE projectwarnings)

# Qt
target_link_libraries(testlib PRIVATE Qt5::Core)
target_link_libraries(testlib PRIVATE Qt5::Gui)

# OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(testlib PRIVATE ${OpenCV_LIBS})

# ArrayFire
include_directories(${ArrayFire_INCLUDE_DIRS})
target_link_libraries(testlib PRIVATE ${ArrayFire_LIBRARIES})

target_compile_definitions(testlib PRIVATE TESTLIB_LIBRARY)

if (ENABLE_TESTS)

    set(TEST_LIB_TEST_SOURCES
        test/libtestlib/testlib.cpp
        test/main.cpp
    )
    add_subdirectory(external/Catch2)
    add_executable(unittests ${TEST_LIB_TEST_SOURCES})

    target_include_directories(unittests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
    target_include_directories(unittests PUBLIC ${ArrayFire_INCLUDE_DIRS})
    target_include_directories(unittests PUBLIC ${OpenCV_INCLUDE_DIRS})

    target_link_libraries(unittests testlib
                                    Catch2::Catch2
                                    ${OpenCV_LIBS}
                                    ${ArrayFire_LIBRARIES})

    include(CTest)
    enable_testing()

    list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/external/Catch2/contrib")
    include(Catch)
    catch_discover_tests(unittests)

    if (ENABLE_COVERAGE)
#        add_subdirectory(external/CMake-codecov)
#        list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/external/CMake-codecov/cmake")
#        find_package(codecov)
#
#        add_coverage(testlib)
#        add_coverage(unittests)
#
#        list(APPEND LCOV_REMOVE_PATTERNS "/usr/")
#        list(APPEND LCOV_REMOVE_PATTERNS "'${PROJECT_SOURCE_DIR}/test/*'")
#        list(APPEND LCOV_REMOVE_PATTERNS "'${PROJECT_SOURCE_DIR}/external/*'")
#
#        coverage_evaluate()

        # set(CMAKE_CXX_FLAGS "--coverage")

        add_library(coverage_config INTERFACE)

        target_compile_options(coverage_config INTERFACE
        -O0        # no optimization
        -g         # generate debug info
        --coverage # sets all required flags
        )

        if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
            target_link_options(coverage_config INTERFACE --coverage)
        else()
            target_link_libraries(coverage_config INTERFACE --coverage)
        endif()

    endif()
endif()
