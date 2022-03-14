/*---------------------------------CLASS DEFINITION--------------------------------*/
class Light {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    Color color;
    Vector position;

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Light(){};
    Light(const Light &light) { *this = light;}
    Light(Color c, Vector p) : color(c), position(p) {}
};
