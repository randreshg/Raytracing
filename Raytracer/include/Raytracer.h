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
    Observer observer;
    Screen screen;
    ScreenItr sItr;
    Color *image;

    /*----------------------------------FUNCTIONS----------------------------------*/
    void trace();
    void intersectionTest(Ray *primaryRay, Primitive **object);
    Color shading(Ray ray, Primitive *object, int depth);
    Color colorContribution(Ray ray, Primitive *object, int depth);
    Color fullScale(Vector P, Vector N, Vector V, Primitive *object, int depth);
    void setScreenItr();
    void imageToPPM();

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    RayTracer();
    RayTracer(const RayTracer &s);
    RayTracer(Scene scene, Observer observer, Screen screen);
    ~RayTracer() { delete image; };
};
