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

int Entity::getBirthRound()
{
    return this->birthRound;
}

int Entity::getStrength()
{
    return this->strength;
}

int Entity::getInitiative()
{
    return this->initiative;
}

void Entity::getPosition(int &x, int &y)
{
    x = this->posX;
    y = this->posY;
}

void Entity::setPosition(int x, int y)
{
    this->posX = x;
    this->posY = y;
}