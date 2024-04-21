#include <antelope.h>
#include <world.h>

antelope::antelope(int posX, int posY, world *w) : animal(posX, posY, w)
{
    this->strength = 4;
    this->initiative = 4;
}
void antelope::move()
{
    this->w->randomMove(&posX, &posY, 2);
}

void antelope::behave()
{
    move();
}