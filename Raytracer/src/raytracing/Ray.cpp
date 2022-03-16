#include "Ray.h"

/*----------------------------------FUNCTIONS----------------------------------*/
void Ray::setP() {}

/*--------------------------------CONSTRUCTORS---------------------------------*/
Ray::Ray() { distance = SKY;}
Ray::Ray(const Ray &ray) { *this = ray; }
Ray::Ray(Vector o, Vector d, float distance) : 
         origin(o), direction(d), distance(distance) { 
    P = origin + direction*(distance);
}
Ray::Ray(Vector o, Vector d) : origin(o) {
    distance = SKY; 
    Vector v(d,o); v.normalize();
    this->direction = v; 
}
