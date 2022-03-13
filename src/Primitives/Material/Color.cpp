/*---------------------------------CLASS DEFINITION--------------------------------*/
class Color {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    float R, G, B;

    /*----------------------------------FUNCTIONS----------------------------------*/
    //Print info
    void print(){ cout<<"["<<R<<" "<<G<<" "<<B<<"]";}
    //Add
    Color operator+ (const Color &c) const
            { return Color((R + c.R),(G + c.G),(B + c.B));}
    //Substract
    Color operator- (const Color &c) const
            { return Color((R - c.R),(G - c.G),(B - c.B));}
    //Scale
    Color operator* (const float &v) const
            { return Color((R * v),(G * v),(B * v));}

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Color(){R = 0; G = 0; B = 0;}
    Color(float R, float G, float B) : R(R), G(G), B(B) {}
    Color(const Color &color) { *this = color;}
};
