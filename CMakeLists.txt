include("./cmake/CMakeColors.txt")
cmake_minimum_required(VERSION 3.10)

# project name and version
project(Raytracing VERSION 1.0)
message_green( "=== Project Raytracing ===")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#OpenMP
find_package(OpenMP REQUIRED)
if(OpenMP_FOUND)
    # ... <- the steps below will be placed here
    # list(APPEND CXX_BASIC_FLAGS "-g3" "-O1")
else()
    message_red(STATUS "OpenMP not found")
endif()

# Options 
#option(USE_MYMATH "Use tutorial provided math implementation" OFF)

# add the Raytracer library
message_green("=> Starting Raytracing environment")
add_subdirectory(Raytracer)

# Executable
message_green("=> Generating executable")
add_executable(rt main.cpp)

# Specify that this library depends upon rtl
message_green("=> Linking libraries")
target_link_libraries(rt rtl m)
# add the binary tree to the search path for include files
# target_include_directories(rt PUBLIC
#                           raytracer
#                           "${PROJECT_BINARY_DIR}"
#                           "${EXTRA_INCLUDES}"
#                           )

# add the MathFunctions library
# if(USE_MYMATH)
#   add_definitions(-DUSE_MYMATH)
#   add_subdirectory(MathFunctions)
#   list(APPEND EXTRA_LIBS MathFunctions)
#   list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
#   message(STATUS "MathFunctions added")
# endif()

# Finished
message_green( "=== Process done ===")