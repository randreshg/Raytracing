cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Raytracing VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Options 
#option(USE_MYMATH "Use tutorial provided math implementation" OFF)

# add the Raytracer library
add_subdirectory(Raytracer)


# add the MathFunctions library
# if(USE_MYMATH)
#   add_definitions(-DUSE_MYMATH)
#   add_subdirectory(MathFunctions)
#   list(APPEND EXTRA_LIBS MathFunctions)
#   list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
#   message(STATUS "MathFunctions added")
# endif()

# add the executable
add_executable(rt main.cpp)

target_link_libraries(rt PUBLIC Raytracing ${EXTRA_LIBS})

# add the binary tree to the search path for include files
target_include_directories(rt PUBLIC
                          raytracer
                          "${PROJECT_BINARY_DIR}"
                          "${EXTRA_INCLUDES}"
                          )