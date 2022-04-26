#include "Plane.h"

/*----------------------------------FUNCTIONS----------------------------------*/
void Plane::rayIntersection(Ray *ray, Primitive **object) {
    Vector voc = (ray->origin) - (c);
    float dv = (ray->direction).dotPoint(v);
    float vocv = voc.dotPoint(v); 
    if(dv != 0) {
        ray->distance = -(vocv)/dv;
        if(ray->distance < 0)
            ray->distance = SKY;
        else {
            *object = this;
            ray->setP();
        }
    }
}

Vector Plane::getNormal(Vector P) { return v; }

void Plane::print(){ 
    std::cout<<"Plane ct["; c.print();
    std::cout<<"], v["; v.print();
    std::cout<<"]"<<std::endl;
}

/*--------------------------------CONSTRUCTORS---------------------------------*/
Plane::Plane() {};
Plane::Plane(Vector c,Vector v, Properties p) : c(c), v(v) { this->properties = p;}
Plane::Plane(Vector c,Vector v) : c(c), v(v) {}
Plane::Plane(const Plane &cln) { *this = cln; }
