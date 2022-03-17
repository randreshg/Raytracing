#pragma once

/*-----------------------------------LIBRARIES------------------------------------*/
#include "Properties.h"
#include "Primitive.h"
#include "Vector.h"
#include "Plane.h"
#include "Ray.h"

/*---------------------------------CLASS DEFINITION--------------------------------*/
class Polygon: public Primitive {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    int nVertices;                    //Point
    Vector *vertices;                 //Vertices
    Vector N;                         //Normal

    /*----------------------------------FUNCTIONS----------------------------------*/
    void print();
    //Find intersection between a ray and Polygon
    void rayIntersection(Ray *ray, Primitive **object);
    //Return Normal of Polygon
    Vector getNormal(Vector P);

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Polygon();
    Polygon(int nVertices, Vector *vert, Properties p);
    Polygon(const Polygon &cln);
};
