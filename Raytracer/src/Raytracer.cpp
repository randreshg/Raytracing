#include "Raytracer.h"

#include <omp.h>
#ifndef NT
#define NT 14
#endif
/*----------------------------------FUNCTIONS----------------------------------*/
void RayTracer::trace() {
    Primitive *object;
    int xResolution = screen.width, 
        yResolution = screen.height;
    image = new Color[xResolution*yResolution];

    //Time taken by the program
    double time = omp_get_wtime();
#ifdef OPENMP
    printf("-OpenMP Version\n");
    //#pragma omp parallel for private(xPixel, yPixel, object, pixelCounter)
    #pragma omp parallel for collapse(2) private(object) num_threads(NT)
    for(int i=0; i<yResolution; i++) {
        for(int j=0; j<xResolution; j++) {
            Ray primaryRay(observer.from, (sItr.scanLine - (sItr.pixelHeight*i)) + (sItr.pixelWidth*j)); 
            intersectionTest(&primaryRay, &object);
            image[i*xResolution + j] = shading(primaryRay, object, 0)*(255);
        }
    }
#else
    printf("-Sequential Version\n");
    int pixelCounter = 0;
    //Screen iterator
    Vector xPixel, yPixel;
    for(int i=0; i<yResolution; i++) {
        yPixel = (sItr.pixelHeight*i);
        pixelCounter = i*xResolution;
        for(int j=0; j<xResolution; j++) {
            xPixel = sItr.pixelWidth*j;
            Ray primaryRay(observer.from, (sItr.scanLine - yPixel) + xPixel); 
            intersectionTest(&primaryRay, &object);
            image[pixelCounter + j] = shading(primaryRay, object, 0)*(255);
        }
    }
#endif
    //Time taken by the program
    time = omp_get_wtime() - time;
    printf("The process took %f seconds to execute \n", time);
    imageToPPM();
} 

void RayTracer::imageToPPM() {
    //PPM file
    FILE *fp = fopen("Output/file.ppm", "w+");
    if (fp!=NULL) {
        fprintf(fp, "P3\n%d %d\n255\n", (int)screen.width, (int)screen.height);
        //Write pixel information
        auto pixels = screen.width * screen.height;
        for(auto i=0; i<pixels; i++)
            fprintf(fp, "%d %d %d ",(int)image[i].R, (int)image[i].G, (int)image[i].B);
        fclose (fp);
    }
    else {
        printf("'Output' folder doesn't exist\n");
    }
}

void RayTracer::intersectionTest(Ray *primaryRay, Primitive **object) {
    Primitive *obj;
    Ray ray = *primaryRay;
    static unsigned int primitivesSize = scene.primitives.size();
    for(unsigned int i=0; i<primitivesSize; i++) {
        (scene.primitives[i])->rayIntersection(&ray, &obj);
        if((ray.distance) < (primaryRay->distance)) {
            *primaryRay = ray;
            *object = obj;
        }
    }
} 

Color RayTracer::shading(Ray ray, Primitive *object, int depth) {
    Color b = scene.background;
    if(ray.distance == SKY)
        return b;
    else
        return colorContribution(ray, object, depth);
}

Color RayTracer::colorContribution(Ray ray, Primitive *object, int depth) {
    Vector P = ray.P;
    Vector N = object->getNormal(P);
    Vector V = ray.direction*(-1);
    return fullScale(P, N, V, object, depth);
}

Color RayTracer::fullScale(Vector P, Vector N, Vector V, Primitive *object, int depth) {
    //Primitive properties
    Color objectColor = (object->properties).objectColor;
    float shine = (object->properties).shine;
    float kd = (object->properties).kd;
    float ks = (object->properties).ks;
    //Aux variables
    Color color;
    static Array<Light> lights = scene.lights;
    static unsigned int lightsSize = lights.size();
    Primitive *shadowObject;
    Vector offsetPoint;
    float diffuse, specular;
    static float intensity = 1/sqrt(lightsSize);
    /*-----------------------Light contribution-------------------------*/
    for(unsigned int i=0; i<lightsSize; i++) {
        Vector L(lights[i].position, P); L.normalize();
        offsetPoint = P + L*(10e-4);
        /*------------------------Shadow ray----------------------------*/
        //Add a small offset to avoid the ray to hit the same sphere
        Ray shadowRay(offsetPoint, L, SKY);
        intersectionTest(&shadowRay, &shadowObject);
        /*-----------------------------Shade----------------------------*/
        if(shadowRay.distance == SKY) {
            /*-------------------Diffuse component----------------------*/
            diffuse = kd*fmax(0, L.dotPoint(N));
            /*-------------------Specular component---------------------*/
            Vector R = L*(-1) + N*(2*(N.dotPoint(L)));
            R.normalize();
            specular = ks*pow(fmax(0, R.dotPoint(V)), shine);
            /*-------------------Light contribution---------------------*/
            color.R += ((diffuse*objectColor.R) + specular)*(intensity);
            color.G += ((diffuse*objectColor.G) + specular)*(intensity);
            color.B += ((diffuse*objectColor.B) + specular)*(intensity);                                      
        }
    }
    if(depth<5 && ks>0) {
        Primitive *hitObject;
        Vector R = V*(-1) + N*(2*(N.dotPoint(V)));
        R.normalize();
        offsetPoint = P + R*(10e-4);
        Ray reflectedRay(offsetPoint, R);
        intersectionTest(&reflectedRay, &hitObject);
        Color reflectedColor = shading(reflectedRay, hitObject, depth + 1);
        color.R += (reflectedColor.R)*(ks);
        color.G += (reflectedColor.G)*(ks);
        color.B += (reflectedColor.B)*(ks);
    }
    return color;
}

void RayTracer::setScreenItr() {
    Vector w(observer.lookAt, observer.from); w.normalize();
    Vector u = w.cross(observer.up); u.normalize();
    Vector v = u.cross(w);
    float tanFOV = tan((observer.angle/2)*PI/180.0);
    float aspectRatio = screen.width/screen.height;
    float cameraheight = tanFOV*2;  
    float camerawidth  = aspectRatio*cameraheight;
    float pixelH = cameraheight/screen.height; sItr.pixelHeight = v*pixelH;
    float pixelW = camerawidth/screen.width;   sItr.pixelWidth = u*pixelW;         
    Vector xComponent = u; xComponent = xComponent*((screen.width*pixelW)/2);
    Vector yComponent = v; yComponent = yComponent*((screen.height*pixelH)/2);
    Vector corner = observer.from + w - xComponent + yComponent;
    sItr.scanLine =  corner - (sItr.pixelHeight)*(1/2) + (sItr.pixelWidth)*(1/2);
}

/*--------------------------------CONSTRUCTORS---------------------------------*/
RayTracer::RayTracer() {};
RayTracer::RayTracer(const RayTracer &s){ *this = s;}
RayTracer::RayTracer(Scene scene, Observer observer, Screen screen) : 
                     scene(scene), observer(observer), screen(screen) {}