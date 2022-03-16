#include "Observer.h"

/*--------------------------------CONSTRUCTORS---------------------------------*/
Observer::Observer() {};
Observer::Observer(const Observer &obs) { *this = obs; }
Observer::Observer(Vector from, Vector lookAt, Vector up, float angle) :
                   from(from), lookAt(lookAt), up(up), angle(angle) {}
