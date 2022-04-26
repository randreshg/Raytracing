#pragma once

/*---------------------------------CLASS DEFINITION--------------------------------*/
class Screen {
    public:
    /*----------------------------------ATTRIBUTES---------------------------------*/
    float width, height;

    /*--------------------------------CONSTRUCTORS---------------------------------*/
    Screen();
    Screen(float w, float h);
    Screen(const Screen &screen);
    ~Screen() = default;
};
