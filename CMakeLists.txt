#Cmake standards
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)
#Project name and version
project(Manifold VERSION 0.0.1)

#-------------------------Build Type Setup-----------------------------------------------------------------------------------------
IF(NOT CMAKE_BUILD_TYPE)
SET(CMAKE_BUILD_TYPE Debug)
ENDIF(NOT CMAKE_BUILD_TYPE)
message("* Current Cmake Build type is: ${CMAKE_BUILD_TYPE}")
message("* Building with ${CMAKE_CXX_COMPILER_ID} VERSION: ${CMAKE_CXX_COMPILER_VERSION} For ${CMAKE_SYSTEM_NAME},${CMAKE_SYSTEM_PROCESSOR}")
#Setting up build type flags
SET(CMAKE_CXX_FLAGS_DEBUG "-Wall -O0 -g")
SET(CMAKE_CXX_FLAGS_RELEASE "-O3")
#Output Directory Name
set(OUTPUT_DIR MANIFOLD-${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_CXX_COMPILER_ID}-${CMAKE_CXX_COMPILER_VERSION})
#----------------------------------------------------------------------------------------------------------------------------------



#-------------------------Build Manifold Library-----------------------------------------------------------------------------------

file(GLOB MANIFOLD Manifold/src/Manifold/**.cpp)
#Creating the libManifold.so file
add_library(Manifold SHARED ${MANIFOLD})

#Including Application.h inside Aplication.cpp
target_include_directories(Manifold PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/Manifold/src/Manifold"
    "${CMAKE_CURRENT_SOURCE_DIR}/Manifold/vendor/spdlog/include/"
    )

set_target_properties(Manifold PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${OUTPUT_DIR}/Manifold"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${OUTPUT_DIR}/Manifold"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${OUTPUT_DIR}")
#----------------------------------------------------------------------------------------------------------------------------------


#-------------------------Build Sandbox Executable---------------------------------------------------------------------------------
#Create Sandbox executable
add_executable(Sandbox Sandbox/src/SandboxApp.cpp)
#Include Manifold.h in Sandbox.cpp
target_include_directories(Sandbox PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}/Manifold/src/"
"${CMAKE_CURRENT_SOURCE_DIR}/Manifold/vendor/spdlog/include/")
set_target_properties(Sandbox PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${OUTPUT_DIR}/Sandbox"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${OUTPUT_DIR}/Sandbox"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${OUTPUT_DIR}")
#Linking libManifold.so to Sandbox
target_link_libraries(Sandbox Manifold)
#----------------------------------------------------------------------------------------------------------------------------------