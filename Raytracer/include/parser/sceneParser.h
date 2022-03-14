#pragma once

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
