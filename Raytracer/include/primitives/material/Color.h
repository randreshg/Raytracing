#pragma once

/*-----------------------------------LIBRARIES------------------------------------*/
#include <iostream>

/*---------------------------------CLASS DEFINITION--------------------------------*/
class Color {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    float R, G, B;

    /*----------------------------------FUNCTIONS----------------------------------*/
    void print();
    //Add
    Color operator+ (const Color &c) const;
    //Substract
    Color operator- (const Color &c) const;
    //Scale
    Color operator* (const float &v) const;

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Color();
    Color(float R, float G, float B);
    Color(const Color &color);
};
