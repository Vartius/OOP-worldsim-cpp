#include <antelope.h>
#include <world.h>

antelope::antelope(int power, int initiative, int posX, int posY, world *w) : animal(power, initiative, posX, posY, w)
{
}
void antelope::move()
{
    this->w->randomMove(&posX, &posY, 2);
}

void antelope::behave()
{
    move();
}