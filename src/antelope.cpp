#include <antelope.h>
#include <cstdlib>
#include <world.h>

antelope::antelope(int posX, int posY, world *w) : animal(posX, posY, w)
{
    this->strength = 4;
    this->initiative = 4;
    this->symbol = 'A';
}
void antelope::move()
{
    this->w->randomMove(this, 2);
}

void antelope::behave()
{
    if (this->stun)
    {
        this->stun = false;
        return;
    }
    move();
}

void antelope::attacked(Entity *attacker)
{
    if (rand() % 2 == 0)
    {
        move();
    } else {
    animal::attacked(attacker);
    }
}