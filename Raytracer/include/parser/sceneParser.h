#pragma once

/*-----------------------------------LIBRARIES---------------------------------*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

#include "Scene.h"
#include "Screen.h"
#include "Observer.h"
#include "Properties.h"
#include "Raytracer.h"

#include "Cylinder.h"
#include "Plane.h"
#include "Polygon.h"
#include "Sphere.h"

/*----------------------------------FUNCTIONS----------------------------------*/
int readFile(std::string filename, RayTracer *RT);
void readBackground(std::ifstream &inputFile, Scene *scene);
void readLight(std::ifstream &inputFile, Scene *scene);
void readCylinder(std::ifstream &inputFile, Scene *scene, Properties p);
void readPolygon(std::ifstream &inputFile, Scene *scene, Properties p);
void readSphere(std::ifstream &inputFile, Scene *scene, Properties p);
void readObserver(std::ifstream &inputFile, Observer *observer);
void readScreen (std::ifstream &inputFile, Screen *s);
Properties readProperties(std::ifstream &inputFile);
