/*---------------------------------CLASS DEFINITION--------------------------------*/
class Sphere: public Primitive {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    Vector center;      //Center
    float r;            //Ratio

    /*----------------------------------FUNCTIONS----------------------------------*/
    //Find intersection betweern a ray and sphere
    void rayIntersection(Ray *ray, Primitive **object) {
        float a, b, c;
        Vector voc = (ray->origin) - (center);
        a = 1;
        b = 2*(ray->direction).dotPoint(voc);
        c = voc.dotPoint(voc) - r*r;
        quadraticSolution(a,b,c,&(ray->distance));
        if(ray->distance != SKY){ 
            ray->setP(); 
            *object = this;
        }
    }

    //Get normal given an intersection point
    Vector getNormal(Vector P) {
        Vector N(P,center); 
        N.normalize();
        return N;
    }

	/*--------------------------------CONSTRUCTORS---------------------------------*/
    Sphere(){};
    Sphere(Vector c, float r, Properties p): center(c), r(r), properties(p) {}
    Sphere(const Sphere &sph) { *this = sph; }
};
