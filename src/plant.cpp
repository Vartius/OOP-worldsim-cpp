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

void plant::collision(std::vector<Entity *> entities, std::vector<std::pair<int, int>> &moves, int i)
{
}

void plant::print()
{
}