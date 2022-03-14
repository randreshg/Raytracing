#pragma once

/*---------------------------------CLASS DEFINITION--------------------------------*/
class Color {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    float R, G, B;

    /*----------------------------------FUNCTIONS----------------------------------*/
    //Add
    Color operator+ (const Color &c);
    //Substract
    Color operator- (const Color &c);
    //Scale
    Color operator* (const float &v);

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Color();
    Color(float R, float G, float B);
    Color(const Color &color);
};
