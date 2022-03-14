/*---------------------------------CLASS DEFINITION--------------------------------*/
class Light {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    Color color;
    Vector position;

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Light();
    Light(const Light &light);
    Light(Color c, Vector p);
};
