#pragma once
/*-----------------------------------LIBRARIES-------------------------------------*/
#include "Color.h"

/*---------------------------------CLASS DEFINITION--------------------------------*/
class Properties {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    Color objectColor;      //Object color
    float kd;               //Diffuse component
    float ks;               //Specular component
    float shine;            //Phong cosine power for highlights
    float t;                //Transmittance (fraction of the transmitting ray)
    float iof;              //Index of refraction

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Properties();
    Properties(const Properties &prop);
    Properties(Color objectColor, float kd, float ks, float shine, float t, float iof);
    ~Properties() = default;
};
