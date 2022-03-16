#pragma once

/*-----------------------------------LIBRARIES-------------------------------------*/
#include <fstream>

#include "Scene.h"
#include "Screen.h"
#include "Observer.h"
#include "Screen.h"
struct ScreenItr{ Vector scanLine, pixelWidth, pixelHeight;};

/*---------------------------------CLASS DEFINITION--------------------------------*/
class RayTracer {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    Scene scene;
    Screen screen;
    Observer observer;
    ScreenItr sItr;

    /*----------------------------------FUNCTIONS----------------------------------*/
    int trace();
    void intersectionTest(Ray *primaryRay, Primitive **object);
    Color shading(Ray ray, Primitive *object, int depth);
    Color colorContribution(Primitive *object, Ray ray, int depth);
    Color fullScale(Vector P, Vector N, Vector V, Primitive *object, int depth);
    void ScreenItrInfo();

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    RayTracer();
    RayTracer(const RayTracer &s);
    RayTracer(Scene scene, Observer observer, Screen screen);
};
