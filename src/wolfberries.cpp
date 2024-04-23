#include <wolfberries.h>
#include <world.h>

wolfberries::wolfberries(int posX, int posY, world *w) : plant(posX, posY, w)
{
    this->strength = 99;
    this->symbol = 'w';
}

void wolfberries::attacked(Entity *attacker)
{
    w->deleteEntity(attacker);
    w->deleteEntity(this);
}