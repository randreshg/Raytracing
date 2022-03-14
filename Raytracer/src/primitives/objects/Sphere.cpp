#include "Sphere.h"

/*----------------------------------FUNCTIONS----------------------------------*/
void Sphere::rayIntersection(Ray *ray, Primitive **object) {
    float a, b, c;
    Vector voc = (ray->origin) - (center);
    a = 1;
    b = 2*(ray->direction).dotPoint(voc);
    c = voc.dotPoint(voc) - r*r;
    quadraticSolution(a,b,c,&(ray->distance));
    if(ray->distance != SKY){ 
        ray->setP(); 
        *object = this;
    }
}

Vector Sphere::getNormal(Vector P) {
    Vector N(P,center); 
    N.normalize();
    return N;
}

/*--------------------------------CONSTRUCTORS---------------------------------*/
Sphere::Sphere() {};
Sphere::Sphere(Vector c, float r, Properties p): center(c), r(r), properties(p) {}
Sphere::Sphere(const Sphere &sph) { *this = sph; }