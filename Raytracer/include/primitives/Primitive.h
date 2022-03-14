#pragma once

/*-----------------------------------LIBRARIES------------------------------------*/
#include "Vector.h"
#include "Ray.h"

/*---------------------------------CLASS DEFINITION--------------------------------*/
class Primitive {
    public:
    Properties properties;
    /*----------------------------------FUNCTIONS----------------------------------*/
    //Find intersection between a ray and primitive
    virtual void rayIntersection(Ray *ray, Primitive **object)=0;
    //Get normal given an intersection point
    virtual Vector getNormal(Vector P)=0;
    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Primitive(){};
    ~Primitive(){};
};
