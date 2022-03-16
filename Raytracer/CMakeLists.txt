# Raytracer CMAKE
FILE(GLOB_RECURSE SOURCES src/*.cpp)

include_directories(INCLUDES
                    include/parser
                    include/primitives
                    include/primitives/material
                    include/primitives/objects
                    include/raytracing
                    include)

# Generate the STATIC library from the sources
add_library(rtl STATIC ${SOURCES})

# Specify that this library itself needs access to the folder "Message/include" and that any other
# target which depends on this also gets similar access - i.e. use 'PUBLIC'
target_include_directories(rtl PUBLIC ${INCLUDES} m)
