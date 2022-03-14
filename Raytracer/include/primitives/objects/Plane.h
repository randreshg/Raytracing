#pragma once

/*---------------------------------CLASS DEFINITION--------------------------------*/
class Plane: public Primitive {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    Vector c;           //Point
    Vector v;           //Normal plane

    /*----------------------------------FUNCTIONS----------------------------------*/
    //Find intersection between a ray and Plane
    void rayIntersection(Ray *ray, Primitive **object);
    //Get normal given an intersection point
    Vector getNormal(Vector P){ return v; }

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Plane();
    Plane(Vector c, Vector v, Properties p);
    Plane(Vector c, Vector v);
    Plane(const Plane &cln);
};
