#include "Properties.h"

/*--------------------------------CONSTRUCTORS---------------------------------*/
Properties::Properties() {}
Properties::Properties(const Properties &prop) { *this = prop;}
Properties::Properties(Color objectColor, float kd, float ks, float shine, float t, float iof)
    : objectColor(objectColor), kd(kd), ks(ks), shine(shine), t(t), iof(iof) {}
