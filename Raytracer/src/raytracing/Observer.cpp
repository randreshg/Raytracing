/*---------------------------------CLASS DEFINITION--------------------------------*/
class Observer {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    Vector from;        //Eye location in XYZ.
    Vector lookAt;      //A position to be at the center of the image
    Vector up;          //A vector defining which direction is up
    float angle;        //In degrees

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Observer(){};
    Observer(const Observer &obs) { *this = obs; }
    Observer(Vector from, Vector lookAt, Vector up, float angle) :
             from(from), lookAt(lookAt), up(up), angle(angle) {}

};
