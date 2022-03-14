/*---------------------------------CLASS DEFINITION--------------------------------*/
class Ray
{
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    Vector origin;     
    Vector direction;  
    float distance;    
    Vector P;          //P = o + d(distance)

    /*----------------------------------FUNCTIONS----------------------------------*/
    void setP(){ }
    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Ray(){ distance = SKY;}
    Ray(const Ray &ray){ *this = ray; }
    Ray(Vector o, Vector d, float distance) : origin(o), direction(d), distance(distance) { 
        P = origin + direction*(distance);
    }
    Ray(Vector o, Vector d) : origin(o) {
        distance = SKY; 
        Vector v(d,o); v.normalize();
        this->direction = v; 
    }
};
