include("./cmake/CMakeColors.txt")
cmake_minimum_required(VERSION 3.10)

# project name and version
project(Raytracing VERSION 1.0)
message_green( "=== Project Raytracing ===")

# specify the C++ standard
set( CMAKE_CXX_STANDARD 17)
set( CMAKE_CXX_STANDARD_REQUIRED ON)

option(DEBUG "DEBUG" OFF)
if(DEBUG)
    message("Debug Version")
    set( CMAKE_BUILD_TYPE "DEBUG")
else()
    message("Release Version")
    set( CMAKE_BUILD_TYPE "RELEASE")
endif()
## Compiler flags
set( CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra -Wunused-macros" )
set( CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

#OpenMP
option(OPENMP "OPENMP" ON)
find_package(OpenMP REQUIRED)
if(OpenMP_FOUND)
    if(OPENMP)
        ADD_DEFINITIONS( -DOPENMP=1 )
        set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}" )
    endif()
else()
    message_red(STATUS "OpenMP not found")
endif()

# add the Raytracer library
message_green("=> Starting Raytracing environment")
add_subdirectory(Raytracer)

# Executable
message_green("=> Generating executable")
add_executable(rt main.cpp)

# Specify that this library depends upon rtl
message_green("=> Linking libraries")
target_link_libraries(rt rtl m)

# Finished
message_green( "=== Process done ===")