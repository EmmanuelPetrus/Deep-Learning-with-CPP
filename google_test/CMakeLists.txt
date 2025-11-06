cmake_minimum_required(VERSION 4.2.0)
project(google_test)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

option(BUILD_TESTS "Build the tests" OFF)

if(BUILD_TESTS)

    include(FetchContent)
    FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()

    set(PROJECT_TEST_NAME test_${PROJECT_NAME})

    # file(GLOB_RECURSE TEST_SRC_FILES "${PROJECT_SOURCE_DIR}/tests/*.cpp""${PROJECT_SOURCE_DIR}/src/*.cpp")
    file(GLOB_RECURSE TEST_SRC_FILES "${PROJECT_SOURCE_DIR}/tests/*.cpp")
    add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
    target_compile_options(${PROJECT_TEST_NAME} PRIVATE -Wall -Wextra -pedantic -Wno-enum-compare -Wno-maybe-uninitialized -Wno-uninitialized -Wno-unused-parameter)
    target_link_libraries(${PROJECT_TEST_NAME} GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(${PROJECT_TEST_NAME})

endif()