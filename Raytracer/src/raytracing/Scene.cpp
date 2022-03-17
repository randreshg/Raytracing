#include "Scene.h"
#include <iostream>

/*----------------------------------FUNCTIONS----------------------------------*/
void Scene::addPrimitive(Primitive *p){ primitives.push_back(p); }
void Scene::addLight(Light l){ lights.push_back(l); }
void Scene::print() {
    std::cout<<"------------------------------------------------"<<std::endl;
    std::cout<<"SCENE INFO:"<<std::endl;
    std::cout<<"\n-Background color [R G B]: "; background.print(); std::cout<<std::endl;
    // std::cout<<"\n-Objects info:"<<std::endl;
    // for(unsigned int i= 0; i< primitives.size(); i++)
    //     primitives[i]->print();
    std::cout<<"\n-Lights sources info: "<<std::endl;
    for(unsigned int i= 0; i< lights.size(); i++)
        lights[i].print();
    std::cout<<"------------------------------------------------"<<std::endl;
}

/*--------------------------------CONSTRUCTORS---------------------------------*/
Scene::Scene() {};
Scene::Scene(Color bg, Array<Primitive*> primitives, Array<Light> lights) :
             background(bg), primitives(primitives), lights(lights) {}

Scene::Scene(const Scene &s) {
    background = s.background;
    primitives = s.primitives;
    lights = s.lights;
}
