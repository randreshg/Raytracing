/*---------------------------------CLASS DEFINITION--------------------------------*/
class Scene {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    Color background;
    Array<Primitive*> primitives;
    Array<Light> lights;
	
    /*----------------------------------FUNCTIONS----------------------------------*/
    void addPrimitive(Primitive *p);
    void addLight(Light l);

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Scene();
    Scene(Color bg, Array<Primitive*> primitives, Array<Light> lights);
    Scene(const Scene &s);
};
