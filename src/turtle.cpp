#include <cstdlib>
#include <turtle.h>
#include <world.h>

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
        w->logf(4, "Turtle on %d %d did not move", this->posX, this->posY);
        return;
    }
    if (this->stun)
    {
        this->stun = false;
        return;
    }
    move();
}



void turtle::attacked(Entity *attacker)
{
    if (attacker->getStrength() < 5)
    {
        return;
    } else {
        this->w->deleteEntity(this);
    }
}