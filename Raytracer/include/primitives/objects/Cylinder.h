#pragma once

/*---------------------------------CLASS DEFINITION--------------------------------*/
class Cylinder: public Primitive {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    Vector ct;          //Top cap
    Vector cb;          //Botton cap
    float r;            //Radio
    Vector v;           //Axys direction
    float maxm;         //Cilynder 
    float m;            //Closest point to intersection point over axys direction

    /*----------------------------------FUNCTIONS----------------------------------*/
    //Find intersection between a ray and Cilynder
    void rayIntersection(Ray *ray, Primitive **object);
    //Get normal given an intersection point
    Vector getNormal(Vector P);

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Cylinder();
    Cylinder(Vector ct, Vector cb, float r, Properties p);
    Cylinder(const Cylinder &cln);
};
