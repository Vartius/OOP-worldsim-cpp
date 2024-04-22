#include <wolf.h>

wolf::wolf(int posX, int posY, world *w) : animal(posX, posY, w)
{
    this->strength = 9;
    this->initiative = 5;
    this->symbol = 'W';
}