#include <entity.h>
#include <world.h>

Entity::Entity(int posX, int posY, world *w)
{
    this->posX = posX;
    this->posY = posY;
    this->w = w;
    this->birthRound = w->getRound();
}

char Entity::getSymbol()
{
    return this->symbol;
}

void Entity::setStun(bool stun)
{
    this->stun = stun;
}

void Entity::setReproductionStun(int reproductionStun)
{
    this->reproductionStun = reproductionStun;
}

int Entity::getReproductionStun()
{
    return this->reproductionStun;
}