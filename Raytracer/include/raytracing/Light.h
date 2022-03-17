#pragma once

/*-----------------------------------LIBRARIES------------------------------------*/
#include "Color.h"
#include "Vector.h"
#include <iostream>

/*---------------------------------CLASS DEFINITION--------------------------------*/
class Light {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    Color color;
    Vector position;

    /*----------------------------------FUNCTIONS----------------------------------*/
    void print();

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Light();
    Light(const Light &light);
    Light(Color c, Vector p);
};
