#include <wolfberries.h>

wolfberries::wolfberries(int posX, int posY, world *w) : plant(posX, posY, w)
{
    this->strength = 99;
    this->symbol = 'w';
}