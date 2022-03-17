#include "Cylinder.h"

/*----------------------------------FUNCTIONS----------------------------------*/
void Cylinder::rayIntersection(Ray *ray, Primitive **object) {
    float a, b, c, RV;
    RV = (ray->direction).dotPoint(v);
    Vector Vocb = (ray->origin) - cb;
    float VocbDotv = Vocb.dotPoint(v);
    a = 1 - RV*RV;
    b = 2*((ray->direction).dotPoint(Vocb) - RV*VocbDotv);
    c = Vocb.dotPoint(Vocb) - VocbDotv*VocbDotv - r*r;
    quadraticSolution(a, b, c, &(ray->distance));

    if(ray->distance != SKY) {
        m = ((ray->direction)*(ray->distance)).dotPoint(v) + VocbDotv;
        if(m>0 && m<maxm) {
            *object = this;
            ray->setP();
        }
        else
            ray->distance = SKY;
    }
}

Vector Cylinder::getNormal(Vector P) {
    Vector cp = cb + v*m;
    Vector N(P, cp);
    N.normalize();
    return N;
}

void Cylinder::print() { 
    std::cout<<"Cylinder ct["; ct.print();
    std::cout<<"], cb["; cb.print();
    std::cout<<"], r "<<r<<std::endl;
}

/*--------------------------------CONSTRUCTORS---------------------------------*/
Cylinder::Cylinder() {};
Cylinder::Cylinder(Vector ct,Vector cb, float r, Properties p) : 
                    ct(ct), cb(cb), r(r){    
    Vector v = (ct - cb); 
    this->maxm = v.lenght();
    v.normalize(); this->v = v;
    this->m = 0;
    this->properties = p;
}
Cylinder::Cylinder(const Cylinder &cln) {*this = cln;}
