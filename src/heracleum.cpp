#include <cstdlib>
#include <heracleum.h>
#include <world.h>

heracleum::heracleum(int posX, int posY, world *w) : plant(posX, posY, w)
{
    this->symbol = 'h';
}

void heracleum::behave()
{
    if (rand() % 100 < 2)
    {
        reproduce();
    }
    w->deleteAllAround(posX, posY, symbol);
}

void heracleum::attacked(Entity *attacker)
{
    if (attacker->getSymbol() == 'H')
    {
        mvprintw(0, 0, "1Game over! You lost! Press any key to exit.");
        getch();
        this->w->setGameOver(true);
        return;
    }
    w->deleteEntity(attacker);
    w->deleteEntity(this);
}