#pragma once

/*-----------------------------------LIBRARIES------------------------------------*/
#include "Primitive.h"
#include "Vector.h"
#include "Light.h"
#include <vector>
#define Array std::vector

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
    void print();
    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Scene();
    Scene(Color bg, Array<Primitive*> primitives, Array<Light> lights);
    Scene(const Scene &s);
    ~Scene() = default;
};
