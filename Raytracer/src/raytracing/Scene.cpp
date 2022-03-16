#include "Scene.h"

/*----------------------------------FUNCTIONS----------------------------------*/
void Scene::addPrimitive(Primitive *p){ primitives.push_back(p); }
void Scene::addLight(Light l){ lights.push_back(l); }

/*--------------------------------CONSTRUCTORS---------------------------------*/
Scene::Scene() {};
Scene::Scene(Color bg, Array<Primitive*> primitives, Array<Light> lights) :
             background(bg), primitives(primitives), lights(lights) {}

Scene::Scene(const Scene &s) {
    background = s.background;
    primitives = s.primitives;
    lights = s.lights;
}
