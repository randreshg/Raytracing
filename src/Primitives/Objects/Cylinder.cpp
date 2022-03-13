/*---------------------------------CLASS DEFINITION--------------------------------*/
class Cylinder: public Primitive {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    Vector ct;          //Top cap
    Vector cb;          //Botton cap
    float r;            //Radio
    Vector v;           //Axys direction
    float maxm;         // Cilynder 
    float m;            //Closest point to intersection point over axys direction

    /*----------------------------------FUNCTIONS----------------------------------*/
    //Find intersection between a ray and Cilynder
    void rayIntersection(Ray *ray, Primitive **object) {
        float a,b,c,RV;
        RV = (ray->direction).dotPoint(v);
        Vector Vocb = (ray->origin) - cb;
        float VocbDotv = Vocb.dotPoint(v);
        a = 1 - RV*RV;
        b = 2*((ray->direction).dotPoint(Vocb) - RV*VocbDotv);
        c = Vocb.dotPoint(Vocb) - VocbDotv*VocbDotv- r*r;
        quadraticSolution(a,b,c,&(ray->distance));

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
            
    //Get normal given an intersection point
    Vector getNormal(Vector P) {
        Vector cp = cb+ v*m;
        Vector N(P,cp); N.normalize();
        return N;
    }

	/*--------------------------------CONSTRUCTORS---------------------------------*/
    Cylinder(){};
    Cylinder(Vector ct,Vector cb, float r, Properties p) : 
             ct(ct), cb(cb), r(r), p(p) {
        Vector v = (ct-cb); 
        this.maxm = v.lenght();
        v.normalize(); 
        this->v = v; this.m = 0;
    } 
    Cylinder(const Cylinder &cln) {*this = cln;}
};
