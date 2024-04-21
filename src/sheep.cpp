#include <sheep.h>

sheep::sheep(int posX, int posY, world *w) : animal(posX, posY, w)
{
    this->strength = 4;
    this->initiative = 4;
}