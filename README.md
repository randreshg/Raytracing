# RayTracing
Raytracing using OpenMP

Steps to install:
=================
1. Create a directory to build the source in the upper most directory
   $ mkdir build
2. Move into this directory
   $ cd build
3. Use Cmake to configure the build aiming at the top level CMakelist.txt
   $ cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang ..
4. Build
   $ make

Steps to execute:
=================
   $ ./build/rt SCENE
