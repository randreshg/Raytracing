#pragma once

/*-----------------------------------LIBRARIES-------------------------------------*/
#include <math.h>

/*---------------------------------CLASS DEFINITION--------------------------------*/
class Vector {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    float x,y,z;

    /*----------------------------------FUNCTIONS----------------------------------*/

    //Vector lenght
    float lenght(){ return sqrt(x*x + y*y + z*z); }
    
    //Normalize info
    void normalize() { *this = *this/lenght(); }

    //Dot
    float dotPoint(Vector v) const
            { return ((x*v.x)+(y*v.y)+(z*v.z));}
    //Scale
    Vector operator* (const float &v) const
            { return Vector((x*v),(y*v),(z*v));}
    //Divide
    Vector operator/ (const float &v) const
            { return Vector((x/v),(y/v),(z/v));}
    //Add
    Vector operator+ (const Vector &v) const
            { return Vector((x+v.x),(y+v.y),(z+v.z));}
    //Substract
    Vector operator- (const Vector &v) const
            { return Vector((x-v.x),(y-v.y),(z-v.z));}
    //Cross
    Vector cross(Vector v) const
            { return Vector(((y*v.z)-(z*v.y)),((z*v.x)-(x*v.z)),((x*v.y)-(y*v.x)));}
    //Equal than
    int operator== (const Vector &v) const
            { return ((x==v.x) && (y==v.y) && (z==v.z)); }
    //Less than
    int operator< (const Vector &v) const
            { return ((x<v.x) && (y<v.y) && (z<v.z)); }
    //Less or equal
    int operator<= (const Vector &v) const
            { return ((x<=v.x) && (y<=v.y) && (z<=v.z)); }
    //greater than
    int operator> (const Vector &v) const
            { return ((x>v.x) && (y>v.y) && (z>v.z)); }
    //greater or equal
    int operator>= (const Vector &v) const
            { return ((x>=v.x) && (y>=v.y) && (z>=v.z)); }
    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Vector(){ x = 0; y = 0; z = 0; }
    Vector(float x, float y, float z) : x(x), y(y), z(z) {}
    Vector(const Vector &v) { *this = v;}
    Vector(Vector a, Vector b) { *this = a - b;}
};
