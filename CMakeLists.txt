cmake_minimum_required(VERSION 3.14)
project(strutil LANGUAGES CXX)

add_library(strutil INTERFACE)
target_include_directories(strutil INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(strutil INTERFACE cxx_std_20)

option(STRUTIL_BUILD_TESTS "Build strutil tests" ON)
if(STRUTIL_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()