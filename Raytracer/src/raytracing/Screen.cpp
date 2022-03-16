#include "Screen.h"

/*--------------------------------CONSTRUCTORS---------------------------------*/
Screen::Screen() { width = 640.0, height = 480.0; }
Screen::Screen(float w, float h) { width = w, height = h; }
Screen::Screen(const Screen &screen) { *this = screen; }
