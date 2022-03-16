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
    std::string name = folder + argv[1] + extension;
    char file[name.size() + 1];
    strcpy(file, name.c_str());
    std::cout<<"FILE: "<<file<<std::endl;
    // Raytracing
    RayTracer RT;
    if (!readFile(file, &RT)) 
        return 0;
    RT.trace();
    // #ifdef USE_MYMATH
    //     std::cout << "MYMATH\n";
    //     const double outputValue = mysqrt(100);
    // #else
    //     std::cout << "NOT MYMATH\n";
    //     const double outputValue = 15;
    // #endif

    std::cout << "PROCESS FINISHED " <<std::endl;
    return 0;
} 