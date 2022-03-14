#include "Polygon.h"

/*----------------------------------FUNCTIONS----------------------------------*/
void Polygon::rayIntersection(Ray *ray, Primitive **object) {
    //Computes polygon plane
    Vector u = vertices[1] - vertices[0];
    Vector v = vertices[2] - vertices[0];
    N = u.cross(v); N.normalize();
    Plane *p1 = new Plane(vertices[0], N); 
    p1->rayIntersection(ray, object);
    delete p1;
    if(ray->distance != SKY) {
        *object = this;
        ray->setP();
        // compute base vectors (bx, by) in the plane
        Vector bx = u; bx.normalize();
        Vector by = N.cross(u); by.normalize();
        // Project the intersection point to the base coordinate system
        float pt[2], e0[2], e1[2];
        pt[0] = (ray->P).dotPoint(bx);
        pt[1] = (ray->P).dotPoint(by);
        // Project the first vertices to the base coordinate system
        e0[0] = vertices[nVertices - 1].dotPoint(bx);
        e0[1] = vertices[nVertices - 1].dotPoint(by);
        e1[0] = vertices[0].dotPoint(bx);
        e1[1] = vertices[0].dotPoint(by);
        
        int y0, y1,hit = 0;
        y0 = (e0[1]>=pt[1]);
        for(int i = 1; i< (nVertices+1); i++) {
            y1 = (e1[1] >= pt[1]);
            if(y0 != y1) {
                if( ((e1[1]-pt[1])*(e0[0]-e1[0]) >= (e1[0]-pt[0])*(e0[1]-e1[1])) == y1)
                    hit = !hit;
            }
            y0 = y1;
            e0[0] = e1[0]; e0[1] = e1[1];           // e0 = e1;
            e1[0] = vertices[i].dotPoint(bx);       // e1 = v[i]
            e1[1] = vertices[i].dotPoint(by);
        }
        if(!hit) ray->distance = SKY;
    }
}

Vector Polygon::getNormal(Vector P) { return N; }

/*--------------------------------CONSTRUCTORS---------------------------------*/
Polygon::Polygon(){};
Polygon::Polygon(int nVertices, Vector *vert, Properties p) : 
                    nVertices(nVertices), vertices(vert), properties(p) {}
Polygon::Polygon(const Polygon &cln) { *this = cln; }
