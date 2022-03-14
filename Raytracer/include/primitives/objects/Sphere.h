/*---------------------------------CLASS DEFINITION--------------------------------*/
class Sphere: public Primitive {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    Vector center;      //Center
    float r;            //Ratio

    /*----------------------------------FUNCTIONS----------------------------------*/
    //Find intersection betweern a ray and sphere
    void rayIntersection(Ray *ray, Primitive **object);
    //Get normal given an intersection point
    Vector getNormal(Vector P);

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Sphere();
    Sphere(Vector c, float r, Properties p);
    Sphere(const Sphere &sph);
};
