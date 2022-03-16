#include "sceneParser.h"
#define NEXT inputFile>>tok
/*----------------------------------FUNCTIONS----------------------------------*/
int readFile(std::string filename, RayTracer *RT) {
    // Open file
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr<< "Could not open the file - '"
                 << filename << "'" << std::endl;
        return EXIT_FAILURE;
    }
    //Aux variables
    Scene scene; Screen screen; Observer observer; Properties p;
    std::string tok;
    // Iterate file
    while (inputFile >> tok) {
        if(tok.compare("b") == 0)
            readBackground(inputFile, &scene);
        // else if(tok.compare("resolution") == 0)
        //     readScreen(inputFile, &screen);
        // else if(tok.compare("l") == 0)
        //     readLight(inputFile, &scene);
        // // else if(tok.compare("s") == 0)
        // //     readSphere(&scene, p);
        // // else if(tok.compare("c") == 0)
        // //     readCylinder(&scene, p);
        // // else if(tok.compare("p") == 0)
        // //     readPolygon(&scene, p, str, fp);
        // // else if(tok.compare("f") == 0)
        // //     p = readProperties();
        else if(tok.compare("v") == 0)
            readObserver(inputFile, &observer);
        std::cout << "Token: " << tok << std::endl;
    }
    
    // std::string line;
    // while (getline(inputFile, line)){

    //     // Tokenizing w.r.t. space ' '
    //     while(getline(check1, intermediate, ' '))
    //     {
    //         tokens.push_back(intermediate);
    //     }
    // }
    // Close file
    inputFile.close();
    return EXIT_SUCCESS;
    // try {
    //     FILE *fp = fopen(name, "r");
    //     if (fp == NULL)
    //         throw 0;
        
    //     //Save data in RayTracer object
    //     RT->observer = observer;
    //     RT->screen = screen;
    //     RT->scene = scene;
    //     RT->ScreenItrInfo(); //Set Screen iterator info
    //     std::cout<<"FILE READ"<<std::endl;

}

void readBackground(std::ifstream &inputFile, Scene *scene) {
    std::string tok;
    Color color;
    NEXT, color.R = std::stof(tok);
    NEXT, color.G = std::stof(tok);
    NEXT, color.B = std::stof(tok);
    scene->background = color;
}

void readLight(std::ifstream &inputFile, Scene *scene) {
    std::string tok;
    Vector point;
    NEXT, point.x = std::stof(tok);
    NEXT, point.y = std::stof(tok);
    NEXT, point.z = std::stof(tok);
    Color color;
    color.R = std::stof(tok);
    color.G = std::stof(tok);
    color.B = std::stof(tok);
    
    color.R = 0.5, color.G = 0.5, color.B = 0.5;
    Light l(color, point);
    scene->addLight(l);
}

// void readCylinder(Scene *scene, Properties p) {
//     Vector ct,cb; float r;
//     ct.x = std::stof(tok);
//     ct.y = std::stof(tok);
//     ct.z = std::stof(tok);
//     r    = std::stof(tok);
//     cb.x = std::stof(tok);
//     cb.y = std::stof(tok);
//     cb.z = std::stof(tok);
//     r    = std::stof(tok);
//     scene->addPrimitive(new Cylinder(ct, cb, r, p));
// }

// void readPolygon(Scene *scene, Properties p, char *str, FILE *fp) {
//     int nVertices = std::stof(tok);
//     Vector *vertices = new Vector[nVertices];
    
//     for(int i=0; i<nVertices; i++) {
//         fgets(str, MAXCHAR, fp);
//         vertices[i].x   = std::stof()(strtok(str, " "));
//         vertices[i].y   = std::stof(tok);
//         vertices[i].z   = std::stof(tok);
//     }
//     scene->addPrimitive(new Polygon(nVertices,vertices,p));
// }

// void readSphere(Scene *scene, Properties p) {
//     Vector point; 
//     float r;
//     point.x = std::stof(tok);
//     point.y = std::stof(tok);
//     point.z = std::stof(tok);
//     r       = std::stof(tok);
//     scene->addPrimitive(new Sphere(point,r,p));
// }


// Properties readProperties() {
//     Color color;
//     float kd, ks, shine, t, iof;
//     color.R = std::stof(tok);
//     color.G = std::stof(tok);
//     color.B = std::stof(tok);
//     kd      = std::stof(tok);
//     ks      = std::stof(tok);
//     shine   = std::stof(tok);
//     t       = std::stof(tok);
//     iof     = std::stof(tok);
//     Properties p(color, kd, ks, shine, t, iof);
//     return p;
// }

void readObserver(std::ifstream &inputFile, Observer *observer) {
    std::string tok;
    //Read from
    Vector from; NEXT;
    NEXT, from.x = std::stof(tok);
    NEXT, from.y = std::stof(tok);
    NEXT, from.z = std::stof(tok);
    observer->from = from;
    //Read at
    Vector lookAt; NEXT;
    NEXT, lookAt.x = std::stof(tok);
    NEXT, lookAt.y = std::stof(tok);
    NEXT, lookAt.z = std::stof(tok);
    observer->lookAt = lookAt;
    std::cout << "Token at: " << tok << std::endl;
    //Read up
    Vector up; NEXT;
    NEXT, up.x = std::stof(tok);
    NEXT, up.y = std::stof(tok);
    NEXT, up.z = std::stof(tok);
    observer->up = up;
    //Read angle
    float angle; NEXT;
    NEXT, angle = std::stof(tok);
    observer->angle = angle;
}

void readScreen(std::ifstream &inputFile, Screen *s) {
    std::string tok;
    NEXT, s->width  = std::stof(tok);
    NEXT, s->height = std::stof(tok);
}
