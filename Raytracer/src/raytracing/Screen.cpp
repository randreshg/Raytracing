/*---------------------------------CLASS DEFINITION--------------------------------*/
class Screen {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    float width, height;

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Screen(){ width = 640.0; height = 480.0; }
    Screen(float w, float h){ width = w; height = h; }
    Screen(const Screen &screen) { *this = screen; }
};
