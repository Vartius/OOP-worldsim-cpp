#include <entity.h>

Entity::Entity(int power, int initiative, int posX, int posY, world *w)
{
    this->power = power;
    this->initiative = initiative;
    this->posX = posX;
    this->posY = posY;
    this->w = w;
}
