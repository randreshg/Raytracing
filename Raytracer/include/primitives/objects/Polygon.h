/*---------------------------------CLASS DEFINITION--------------------------------*/
class Polygon: public Primitive {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    int nVertices;                    //Point
    Vector *vertices;                 //Vertices
    Vector N;                         //Normal

    /*----------------------------------FUNCTIONS----------------------------------*/
    //Find intersection between a ray and Polygon
    void rayIntersection(Ray *ray, Primitive **object);
    //Return Normal of Polygon
    Vector getNormal(Vector P) { return N; }

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Polygon(){};
    Polygon(int nVertices, Vector *vert, Properties p);
    Polygon(const Polygon &cln);
};
