/*---------------------------------CLASS DEFINITION--------------------------------*/
class Scene {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    Color background;
    Array<Primitive*> primitives;
    Array<Light> lights;
	
    /*----------------------------------FUNCTIONS----------------------------------*/
    void addPrimitive(Primitive *p){ primitives.push_back(p); }
    void addLight(Light l){ lights.push_back(l); }

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Scene(){};
    Scene(Color bg, Array<Primitive*> primitives, Array<Light> lights) :
          background(bg), primitives(primitives), lights(lights) {}

    Scene(const Scene &s) {
        background = s.background;
        primitives = s.primitives;
        lights = s.lights;
    }
};
