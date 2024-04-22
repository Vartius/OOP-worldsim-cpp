#include <plant.h>
#include <world.h>
#include <ncurses.h>

plant::plant(int posX, int posY, world *w) : Entity(posX, posY, w)
{
    this->initiative = 0;
}

void plant::behave()
{
}

void plant::collision()
{
}

void plant::print()
{
}