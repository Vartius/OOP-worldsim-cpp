#include <guarana.h>
#include <world.h>

guarana::guarana(int posX, int posY, world *w) : plant(posX, posY, w)
{
    this->symbol = 'G';
}

void guarana::attacked(Entity *attacker)
{
    attacker->setPosition(this->posX, this->posY);
    attacker->increaseStrength(3);
    int attackerPosX, attackerPosY;
    attacker->getPosition(attackerPosX, attackerPosY);
    w->logf(6, "%c at (%d, %d) increased its strength, now %d", attacker->getSymbol(), attackerPosX, attackerPosY, attacker->getStrength());
    w->deleteEntity(this);
}