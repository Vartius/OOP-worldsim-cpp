#include <entity.h>

Entity::Entity(int posX, int posY, world *w)
{
    this->posX = posX;
    this->posY = posY;
    this->w = w;
}
