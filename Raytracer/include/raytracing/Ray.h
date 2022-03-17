#pragma once

/*-----------------------------------LIBRARIES-------------------------------------*/
#include "Vector.h"

/*-----------------------------------CONSTANTS-------------------------------------*/
#define PI 3.14159265
#define MAXCHAR 100
#define SKY 100000

/*---------------------------------CLASS DEFINITION--------------------------------*/
class Ray {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    Vector origin;
    Vector direction;
    float distance;
    Vector P;          //P = o + d(distance)

    /*----------------------------------FUNCTIONS----------------------------------*/
    void setP();
    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Ray();
    Ray(const Ray &ray);
    Ray(Vector o, Vector d, float distance);
    Ray(Vector o, Vector d);
};
