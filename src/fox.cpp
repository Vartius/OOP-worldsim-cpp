#include <world.h>
#include <fox.h>
#include <ncurses.h>

fox::fox(int posX, int posY, world *w) : animal(posX, posY, w)
{
    this->strength = 3;
    this->initiative = 7;
    this->symbol = 'F';
}

void fox::collision(std::vector<Entity *> entities, std::vector<std::pair<int, int>> &moves, int i)
{
    int entityX, entityY;
    entities[i]->getPosition(entityX, entityY);
    //reproduce
    if (this->getSymbol() == entities[i]->getSymbol())
    {
        reproduce(entities, moves, i, entityX, entityY);
    } else // fight
    {
        if (this->getStrength() >= entities[i]->getStrength())
        {
            this->setPosition(entityX, entityY);
            if (entities[i]->getSymbol() == 'H')
            {
                mvprintw(0, 0, "Game over! You lost! Press any key to exit.");
                getch();
                this->w->setGameOver(true);
                return;
            }
            this->w->deleteEntity(entities[i]);
        }
    }
}

void fox::behave()
{
    if (this->stun)
    {
        this->stun = false;
        return;
    }
    move();
}