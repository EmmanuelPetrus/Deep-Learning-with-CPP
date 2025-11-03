cmake_minimum_required(VERSION 4.2.0)

set(PROJECT_NAME eigen_premier)
project(${PROJECT_NAME} CXX)

# Default to Release build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# downloading and setting up Eigen
include(FetchContent)

FetchContent_Declare(
    Eigen3
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG 6e4d5d4832a1736ba2f6faa7087b61227dba8e7b
)
FetchContent_MakeAvailable(Eigen3)

add_executable(${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/src/main.cpp")

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
target_link_libraries(${PROJECT_NAME} Eigen3::Eigen)