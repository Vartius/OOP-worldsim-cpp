#include <cstdlib>
#include <plant.h>
#include <world.h>
#include <ncurses.h>

plant::plant(int posX, int posY, world *w) : Entity(posX, posY, w)
{
    this->initiative = 0;
    this->strength = 0;
}

void plant::behave()
{
    if (rand() % 100 < 2)
    {
        reproduce();
    }
}

void plant::collision(std::vector<Entity *> entities, std::vector<std::pair<int, int>> &moves, int i)
{
}

void plant::attacked(Entity *attacker)
{
    attacker->setPosition(this->posX, this->posY);
    w->deleteEntity(this);
}

void plant::reproduce()
{
    std::vector<std::pair<int, int>> moves;
    w->getPossiblePoses(this->posX, this->posY, 1, moves);
    w->eraseEnitiesFromMoves(moves);
    if (moves.size() > 0)
    {
        w->logf(2, "Plant at (%d, %d) reproduced\n", this->posX, this->posY);
        int random = rand() % moves.size();
        w->addEntity(moves[random].first, moves[random].second, w->symbolEnum(this->symbol));
    }
}