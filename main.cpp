#include "src/dependencies.h"
int parseArguments(int, char **);

int main(int argc, char *argv[]) {
    RayTracer RT;
    string folder("Scenes/");
    string extension(".nff");
    string name = folder + argv[1] + extension;
    char file[name.size()+1];
    strcpy(file,name.c_str());
    cout<<"FILE: "<<file<<endl;
    if (!readFile(file,&RT)) return 0;
    RT.trace();
} 