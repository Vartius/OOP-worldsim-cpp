#include <animal.h>
#include <world.h>
#include <mainInclude.h>
#include <ncurses.h>

animal::animal(int posX, int posY, world *w) : Entity(posX, posY, w)
{
}

void animal::move()
{
    int x = 0;
    int y = 0;
    int waysCount = 0;

    bool *moves;
    // w->randomMove(&posX, &posY, 1);
    w->randomMove(this, 1);
}

void animal::reproduce(animal *otherAnimal)
{
}

void animal::createNewAnimal(int posX, int posY)
{
}

void animal::behave()
{
    if (dynamic_cast<turtle *>(this))
    {
        if (rand() % 4 != 0)
        {
            return;
        }
    }
    if (this->stun)
    {
        this->stun = false;
        return;
    }
    move();
}

void animal::collision()
{
}

void animal::print()
{
}