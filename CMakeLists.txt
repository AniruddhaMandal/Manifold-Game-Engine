#Cmake standards
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

#Set seperate path for `lib` and `bin` inside the `build`(${CMAKE_BINARY_DIR}) folder  
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#Project name and version
project(Manifold VERSION 0.0.1)



#Creating the libManifold.so file
add_library(Manifold SHARED Manifold/src/Manifold/Application.cpp)
#Including Application.h inside Aplication.cpp
target_include_directories(Manifold PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/Manifold/src/Manifold"
    "${CMAKE_CURRENT_SOURCE_DIR}/Manifold/vendor/spdlog/include/"
    )



#Creating the Library
add_library(Log SHARED Manifold/src/Manifold/Log.cpp)
#including header files
target_include_directories(Log PUBLIC
"${CMAKE_CURRENT_SOURCE_DIR}/Manifold/vendor/spdlog/include/")



#Create Sandbox executable
add_executable(Sandbox Sandbox/src/SandboxApp.cpp)
#Include Manifold.h in Sandbox.cpp
target_include_directories(Sandbox PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}/Manifold/src/"
"${CMAKE_CURRENT_SOURCE_DIR}/Manifold/vendor/spdlog/include/")
#Linking libManifold.so to Sandbox
target_link_libraries(Sandbox Manifold Log)