# cmake_minimum_required(VERSION 4.2.0)
# project(google_test)

# # GoogleTest requires at least C++17
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

# include_directories(include)

# option(BUILD_TESTS "Build the tests" OFF)

# if(BUILD_TESTS)

#     include(FetchContent)
#     FetchContent_Declare(
#     googletest
#     URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
#     )
#     # For Windows: Prevent overriding the parent project's compiler/linker settings
#     set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#     FetchContent_MakeAvailable(googletest)

#     enable_testing()

#     set(PROJECT_TEST_NAME test_${PROJECT_NAME})

#     # file(GLOB_RECURSE TEST_SRC_FILES "${PROJECT_SOURCE_DIR}/tests/*.cpp""${PROJECT_SOURCE_DIR}/src/*.cpp")
#     file(GLOB_RECURSE TEST_SRC_FILES "${PROJECT_SOURCE_DIR}/tests/*.cpp")
#     add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
#     target_compile_options(${PROJECT_TEST_NAME} PRIVATE -Wall -Wextra -pedantic -Wno-enum-compare -Wno-maybe-uninitialized -Wno-uninitialized -Wno-unused-parameter)
#     target_link_libraries(${PROJECT_TEST_NAME} GTest::gtest_main)

#     include(GoogleTest)
#     gtest_discover_tests(${PROJECT_TEST_NAME})

# endif()


cmake_minimum_required(VERSION 3.20)
project(google_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------------------------
# BOOST
# ---------------------------------------
set(BOOST_ROOT "C:/Program Files/Boost/boost_1_89_0/boost_1_89_0")
set(BOOST_INCLUDEDIR "${BOOST_ROOT}")
# set(BOOST_LIBRARYDIR "${BOOST_ROOT}/lib64-msvc-14.3")

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

# ---------------------------------------
# APP (your main program)
# ---------------------------------------
# add_executable(app main.cpp)
# target_link_libraries(app Boost::boost)

# ---------------------------------------
# TESTS
# ---------------------------------------
option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    include(FetchContent)

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()

    file(GLOB_RECURSE TEST_SOURCES tests/*.cpp)

    add_executable(tests ${TEST_SOURCES})
    target_link_libraries(tests GTest::gtest_main Boost::boost)

    include(GoogleTest)
    gtest_discover_tests(tests)
endif()
