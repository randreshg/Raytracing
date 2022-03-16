#pragma once

/*-----------------------------------LIBRARIES---------------------------------*/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

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
int readFile(std::string filename, RayTracer *RT);
void readBackground(std::ifstream &inputFile, Scene *scene);
void readLight(std::ifstream &inputFile, Scene *scene);
void readCylinder(Scene *scene, Properties p);
void readPolygon(Scene *scene, Properties p, char *str, FILE *fp);
void readSphere(Scene *scene, Properties p);
Properties readProperties();
void readObserver(std::ifstream &inputFile, Observer *observer);
void readScreen(std::ifstream &inputFile, Screen *s);
