cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(Manifold VERSION 0.0.1)

add_library(Manifold SHARED Manifold/src/Test.cpp)

# configure_file(ManifoldConfig.h in ManifoldConfig.h)
target_include_directories(Manifold PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/Manifold/src/"
    "${PROJECT_BINARY_DIR}")

add_executable(Sandbox Sandbox/src/Application.cpp)
target_include_directories(Sandbox PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}/Manifold/src/"
"${PROJECT_BINARY_DIR}")
target_link_libraries(Sandbox Manifold)