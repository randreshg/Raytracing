#include "Color.h"

/*----------------------------------FUNCTIONS----------------------------------*/
Color::Color operator+ (const Color &c)
        { return Color((R + c.R), (G + c.G), (B + c.B));}

Color::Color operator- (const Color &c)
        { return Color((R - c.R), (G - c.G), (B - c.B));}

Color::Color operator* (const float &v)
        { return Color((R * v),(G * v),(B * v));}

/*--------------------------------CONSTRUCTORS---------------------------------*/
Color::Color() { R = 0, G = 0, B = 0;}
Color::Color(float R, float G, float B) : R(R), G(G), B(B) {}
Color::Color(const Color &color) { *this = color;}