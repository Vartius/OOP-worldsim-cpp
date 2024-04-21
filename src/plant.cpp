#include <plant.h>
#include <world.h>
#include <ncurses.h>

plant::plant(int power, int initiative, int posX, int posY, world *w) : Entity(power, initiative, posX, posY, w)
{
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

void plant::getPosition(int &x, int &y)
{
    x = this->posX;
    y = this->posY;
}

void plant::getInitiative(int &initiative)
{
    initiative = this->initiative;
}