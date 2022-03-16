#pragma once

/*-----------------------------------LIBRARIES---------------------------------*/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

#include "Scene.h"
#include "Screen.h"
#include "Observer.h"
#include "Properties.h"
#include "Raytracer.h"

#include "Cylinder.h"
#include "Plane.h"
#include "Polygon.h"
#include "Sphere.h"

/*-----------------------------------CONSTANTS--------------------------------*/
#define MAXCHAR 100

/*----------------------------------FUNCTIONS----------------------------------*/
void readBackground(Scene *scene);
void readLight(Scene *scene);
void readCylinder(Scene *scene, Properties p);
void readPolygon(Scene *scene, Properties p, char *str, FILE *fp);
void readSphere(Scene *scene, Properties p);
Properties readProperties();
void readObserver(Observer *observer, char *str, FILE *fp);
void readScreen(Screen *s);
int readFile(char *name, RayTracer *RT);
