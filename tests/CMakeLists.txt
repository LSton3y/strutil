# Copyright (c) 2026 LSton3y
# SPDX-License-Identifier: MIT

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(TEST_SOURCES
    test_case.cpp
    test_align.cpp
    test_affix.cpp
    test_find.cpp
    test_is.cpp
    test_partition.cpp
    test_split.cpp
    test_strip.cpp
    test_other.cpp
)

add_executable(strutil_tests ${TEST_SOURCES})
target_link_libraries(strutil_tests PRIVATE strutil GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(strutil_tests)