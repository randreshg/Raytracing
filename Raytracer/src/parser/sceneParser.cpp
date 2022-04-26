#include "sceneParser.h"
#define NEXT inputFile>>tok

/*----------------------------------FUNCTIONS----------------------------------*/
int readFile(std::string filename, RayTracer *RT) {
    // Open file
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr<< "Could not open the file - '"
                 << filename << "'" << std::endl;
        return 0;
    }
    //Aux variables
    Scene scene; Screen screen; Observer observer; Properties p;
    std::string tok;
    // Iterate file
    while (inputFile>>tok) {
        if(tok.compare("b") == 0)
            readBackground(inputFile, &scene);
        else if(tok.compare("resolution") == 0)
            readScreen(inputFile, &screen);
        else if(tok.compare("l") == 0)
            readLight(inputFile, &scene);
        else if(tok.compare("s") == 0)
            readSphere(inputFile, &scene, p);
        else if(tok.compare("c") == 0)
            readCylinder(inputFile, &scene, p);
        else if(tok.compare("p") == 0)
            readPolygon(inputFile, &scene, p);
        else if(tok.compare("f") == 0)
            p = readProperties(inputFile);
        else if(tok.compare("v") == 0)
            readObserver(inputFile, &observer);
    }
    // Close file
    inputFile.close();
    // Save data in RayTracer object
    RT->observer = observer;
    RT->screen = screen;
    RT->scene = scene;
    RT->setScreenItr(); //Set Screen iterator info
    std::cout<<"FILE READ"<<std::endl;
    return 1;

}

void readBackground(std::ifstream &inputFile, Scene *scene) {
    Color color; inputFile>>color.R>>color.B>>color.G;
    scene->background = color;
}

void readLight(std::ifstream &inputFile, Scene *scene) {
    std::string token, line; 
    getline(inputFile, line);
    //Line stream  
    std::vector<std::string> tokens;  
    std::istringstream iss(line);
    while (iss >> token) 
        tokens.push_back(token);
    //Copy data
    Vector point;
    point.x = std::stof(tokens[0]);
    point.y = std::stof(tokens[1]);
    point.z = std::stof(tokens[2]);
    Color color;
    if(tokens.size() == 6){
        color.R = std::stof(tokens[3]);
        color.G = std::stof(tokens[4]);
        color.B = std::stof(tokens[5]);
    }
    else {
        color.R = 1, color.G = 1, color.B = 1;
    }
    Light l(color, point);
    scene->addLight(l);
}

void readCylinder(std::ifstream &inputFile, Scene *scene, Properties p) {
    Vector ct, cb; float r;
    inputFile>>ct.x>>ct.y>>ct.z>>r;
    inputFile>>cb.x>>cb.y>>cb.z>>r;
    scene->addPrimitive(new Cylinder(ct, cb, r, p));
}

void readPolygon(std::ifstream &inputFile, Scene *scene, Properties p) {
    int nVertices; inputFile>>nVertices;
    Vector *vertices = new Vector[nVertices];
    for(int i=0; i<nVertices; i++) 
        inputFile>>vertices[i].x>>vertices[i].y>>vertices[i].z;
    scene->addPrimitive(new Polygon(nVertices, vertices, p));
}

void readSphere(std::ifstream &inputFile, Scene *scene, Properties p) {
    Vector point; float r;
    inputFile>>point.x>>point.y>>point.z>>r;
    scene->addPrimitive(new Sphere(point, r, p));
}

void readObserver(std::ifstream &inputFile, Observer *observer) {
    std::string tok;
    //Read from
    Vector from; NEXT;
    inputFile>>from.x>>from.y>>from.z;
    observer->from = from;
    //Read at
    Vector lookAt; NEXT;
    inputFile>>lookAt.x>>lookAt.y>>lookAt.z;
    observer->lookAt = lookAt;
    //Read up
    Vector up; NEXT;
    inputFile>>up.x>>up.y>>up.z;
    observer->up = up;
    //Read angle
    NEXT;
    inputFile>>observer->angle;
}

void readScreen(std::ifstream &inputFile, Screen *s) {
    inputFile>>s->width>>s->height;
}

Properties readProperties(std::ifstream &inputFile) {
    Color color; 
    inputFile>>color.R>>color.G>>color.B;
    float kd, ks, shine, t, iof;
    inputFile>>kd>>ks>>shine>>t>>iof;
    Properties p(color, kd, ks, shine, t, iof);
    return p;
}