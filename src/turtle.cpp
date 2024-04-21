#include <turtle.h>

turtle::turtle(int posX, int posY, world *w) : animal(posX, posY, w)
{
    this->strength = 2;
    this->initiative = 1;
}