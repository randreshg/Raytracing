#include "Light.h"

/*----------------------------------FUNCTIONS----------------------------------*/
void Light::print() { 
    std::cout<<"["; position.print(); 
    std::cout<<", "; color.print(); 
    std::cout<<"]\n";
}

/*--------------------------------CONSTRUCTORS---------------------------------*/
Light::Light() {};
Light::Light(const Light &light) { *this = light;}
Light::Light(Color c, Vector p) : color(c), position(p) {}
