#include <antelope.h>
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