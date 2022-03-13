/*---------------------------------CLASS DEFINITION--------------------------------*/
class Properties {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    Color objectColor;      //Object color
    float shine;            //Phong cosine power for highlights
    float kd;               //Diffuse component
    float ks;               //Specular component
    float t;                //Transmittance (fraction of the transmitting ray)
    float iof;              //Index of refraction

	/*--------------------------------CONSTRUCTORS---------------------------------*/
    Properties(){}
    Properties(const Properties &prop){ *this = prop;}
    Properties(Color objectColor, float kd, float ks, float shine, float t, float iof)
        : objectColor(objectColor), kd(kd), ks(ks), shine(shine), t(t), iof(iof) {}
};
