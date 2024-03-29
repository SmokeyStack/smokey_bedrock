cmake_minimum_required(VERSION 3.12)
cmake_policy(SET CMP0048 NEW)
cmake_policy(SET CMP0074 NEW)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "In-source builds not allowed. Please run CMake from the './adk-build' directory. You may need to remove CMakeCache.txt.")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(adk VERSION 0.1 LANGUAGES CXX)

find_package(spdlog REQUIRED)

include_directories(include include/generator)
add_executable(adk
    Main.cpp
    Object.cpp
    Data.cpp
    Recipe.cpp
    Language.cpp
    GlobalRegistry.cpp
)

target_link_libraries(adk PRIVATE spdlog::spdlog)