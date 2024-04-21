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

void plant::getPosition(int &x, int &y)
{
    x = this->posX;
    y = this->posY;
}

void plant::getInitiative(int &initiative)
{
    initiative = this->initiative;
}

void plant::getStrength(int &strength)
{
    strength = this->strength;
}

void plant::getBirthRound(int &birthRound)
{
    birthRound = this->birthRound;
}