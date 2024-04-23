#include <antelope.h>
#include <cstdlib>
#include <world.h>

antelope::antelope(int posX, int posY, world *w) : animal(posX, posY, w)
{
    this->strength = 4;
    this->initiative = 4;
    this->symbol = 'A';
}


void antelope::collision(std::vector<Entity *> entities, std::vector<std::pair<int, int>> &moves, int i)
{
    int entityX, entityY;
    entities[i]->getPosition(entityX, entityY);
    //reproduce
    if (this->getSymbol() == entities[i]->getSymbol())
    {
        reproduce(entities, moves, i, entityX, entityY);
    } else // fight
    {
        if (rand() % 2 == 0)
        {
            w->logf(6, "Antelope on %d %d avoided battle", this->posX, this->posY);
            move();
        } else {
            entities[i]->attacked(this);
        }
    }
}

void antelope::move()
{
    this->w->randomMove(this, 2);
}

void antelope::behave()
{
    if (this->stun)
    {
        w->logf(5, "%c unstunned", this->getSymbol());
        this->stun = false;
        return;
    }
    move();
}

void antelope::attacked(Entity *attacker)
{
    if (rand() % 2 == 0)
    {
        w->logf(6, "Antelope on %d %d avoided battle", this->posX, this->posY);
        move();
    } else {
    animal::attacked(attacker);
    }
}