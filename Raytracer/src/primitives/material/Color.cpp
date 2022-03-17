#include "Color.h"

/*----------------------------------FUNCTIONS----------------------------------*/
//Print info
void Color::print() { std::cout<<"["<<R<<" "<<G<<" "<<B<<"]";}

Color Color::operator+ (const Color &c) const
        { return Color((R + c.R), (G + c.G), (B + c.B));}

Color Color::operator- (const Color &c) const
        { return Color((R - c.R), (G - c.G), (B - c.B));}

Color Color::operator* (const float &v) const
        { return Color((R * v),(G * v),(B * v));}

/*--------------------------------CONSTRUCTORS---------------------------------*/
Color::Color() { R = 0, G = 0, B = 0;}
Color::Color(float R, float G, float B) : R(R), G(G), B(B) {}
Color::Color(const Color &color) { *this = color;}