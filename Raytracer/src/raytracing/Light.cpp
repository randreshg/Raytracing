#include "Light.h"

/*--------------------------------CONSTRUCTORS---------------------------------*/
Light::Light() {};
Light::Light(const Light &light) { *this = light;}
Light::Light(Color c, Vector p) : color(c), position(p) {}
