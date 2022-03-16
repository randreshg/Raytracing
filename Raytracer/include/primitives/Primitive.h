#pragma once

/*-----------------------------------LIBRARIES------------------------------------*/
#include "Properties.h"
#include "Vector.h"
#include "Ray.h"
#include "math.h"

/*---------------------------------MACRO FUNTION---------------------------------*/
#define quadraticSolution(a,b,c,d){                 \
float disc, t1, t2, dst;                            \
disc = b*b - 4*a*c;                                 \
if(disc<0.0)                                        \
    *d = SKY;                                       \
else{                                               \
    dst = sqrt(disc);                               \
    t1=(-b+(dst))/(2*a), t2=(-b-(dst))/(2*a);       \
    *d = (t1<0.0 ? SKY : (t2>0.0 ? t2 : t1));}}     \

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
