#include <cstdlib>
#include <turtle.h>

turtle::turtle(int posX, int posY, world *w) : animal(posX, posY, w)
{
    this->strength = 2;
    this->initiative = 1;
    this->symbol = 'T';
}


void turtle::behave()
{
    if (rand() % 4 != 0)
    {
        return;
    }
    if (this->stun)
    {
        this->stun = false;
        return;
    }
    move();
}