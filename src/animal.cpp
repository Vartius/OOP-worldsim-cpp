#include <animal.h>
#include <world.h>
#include <ncurses.h>

animal::animal(int power, int initiative, int posX, int posY, world *w) : Entity(power, initiative, posX, posY, w)
{
}

void animal::move()
{
    int worldWidth, worldHeight, x, y;
    w->getWorldSize(worldWidth, worldHeight);
    if (posX == 0)
        x = rand() % 2;
    else if (posX == worldWidth - 1)
        x = rand() % 2 - 1;
    else
        x = rand() % 3 - 1;

    if (posY == 0)
        y = rand() % 2;
    else if (posY == worldHeight - 1)
        y = rand() % 2 - 1;
    else
        y = rand() % 3 - 1;

    posX += x;
    posY += y;
}

void animal::reproduce(animal *otherAnimal)
{
}

void animal::createNewAnimal(int posX, int posY)
{
}

void animal::behave()
{
    move();
}

void animal::collision()
{
}

void animal::print()
{
}

void animal::getPosition(int &x, int &y)
{
    x = this->posX;
    y = this->posY;
}