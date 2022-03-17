#include "Raytracer.h"
#include "sceneParser.h"

// #ifdef USE_MYMATH
//     #include "MathFunctions.h"
// #endif
// #include "src/dependencies.h"

int main(int argc, char *argv[]) {
    // Read NFF scene
    std::string folder("Scenes/");
    std::string extension(".nff");
    std::string filename = folder + argv[1] + extension;
    std::cout<<"FILE: "<<filename<<std::endl;
    // Raytracing
    RayTracer RT;
    if (!readFile(filename, &RT)) return 0;
    //RT.scene.print();
    RT.trace();

    std::cout << "PROCESS FINISHED " <<std::endl;
    return 0;
} 
