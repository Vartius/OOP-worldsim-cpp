#include <fox.h>

fox::fox(int posX, int posY, world *w) : animal(posX, posY, w)
{
    this->strength = 3;
    this->initiative = 7;
    this->symbol = 'F';
}

void fox::behave()
{
    if (this->stun)
    {
        this->stun = false;
        return;
    }
    move();
}