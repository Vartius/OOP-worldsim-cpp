#include <animal.h>
#include <cstdlib>
#include <world.h>
#include <mainInclude.h>
#include <ncurses.h>
#include <vector>
#include <entity.h>

animal::animal(int posX, int posY, world *w) : Entity(posX, posY, w)
{
}

void animal::move()
{
    w->randomMove(this, 1);
}

void animal::createNewAnimal(int posX, int posY)
{
}

void animal::behave()
{
    if (this->stun)
    {
        this->stun = false;
        return;
    }
    move();
}

void eraseSameEntitesFromMoves(std::vector<std::pair<int, int>> &moves, std::vector<Entity *> entities, char symbol)
{
    for (int i = 0; i < entities.size(); i++)
    {
        int entityX, entityY;
        entities[i]->getPosition(entityX, entityY);
        if (entities[i]->getSymbol() == symbol)
        {
            for (int j = 0; j < moves.size(); j++)
            {
                if (entityX == moves[j].first && entityY == moves[j].second)
                {
                    moves.erase(moves.begin() + j);
                    j--;
                }
            }
        }
    }
}

void eraseEnitiesFromMoves(std::vector<std::pair<int, int>> &moves, std::vector<Entity *> entities)
{
    for (int i = 0; i < entities.size(); i++)
    {
        int entityX, entityY;
        entities[i]->getPosition(entityX, entityY);
        for (int j = 0; j < moves.size(); j++)
        {
            if (entityX == moves[j].first && entityY == moves[j].second)
            {
                moves.erase(moves.begin() + j);
                j--;
            }
        }
    }
}

void animal::reproduce(std::vector<Entity *> entities, std::vector<std::pair<int, int>> &moves, int i, int entityX, int entityY)
{
    if (this->getReproductionStun() > 0)
    {
        this->setReproductionStun(this->getReproductionStun() - 1);
        eraseSameEntitesFromMoves(moves, entities, this->getSymbol());
    }
    else
    {
        std::vector<std::pair<int, int>> moves2;
        if (this->w->getPossiblePoses(entityX, entityY, 1, moves2))
        {
            eraseEnitiesFromMoves(moves2, entities);
            if (moves2.size() == 0 || rand() % 5 == 0)
            {
                entities[i]->setReproductionStun(1);
                this->setReproductionStun(1);
                entities[i]->setStun(true);
                return;
            }
            std::pair<int, int> res2 = moves2[rand() % moves2.size()];
            this->w->addEntity(res2.first, res2.second, this->w->symbolEnum(this->getSymbol()));
            entities.back()->setStun(true);
            entities[i]->setStun(true);
            this->setReproductionStun(3);
            entities.back()->setReproductionStun(10);
            entities[i]->setReproductionStun(3);
            return;
        }
    }
}

void animal::collision(std::vector<Entity *> entities, std::vector<std::pair<int, int>> &moves, int i)
{
    int entityX, entityY;
    entities[i]->getPosition(entityX, entityY);
    //reproduce
    if (this->getSymbol() == entities[i]->getSymbol())
    {
        reproduce(entities, moves, i, entityX, entityY);
    } else // fight
    {
        entities[i]->attacked(this);
    }
}

void animal::attacked(Entity *attacker)
{
    if (this->getStrength() >= attacker->getStrength())
    {
        if (attacker->getSymbol() == 'H')
        {
            mvprintw(0, 0, "Game over! You lost! Press any key to exit.");
            getch();
            this->w->setGameOver(true);
            return;
        }
        this->w->deleteEntity(attacker);
    }
    else
    {
        int x, y;
        this->getPosition(x, y);
        attacker->setPosition(x, y);
        if (this->getSymbol() == 'H')
        {
            mvprintw(0, 0, "Game over! You lost! Press any key to exit.");
            getch();
            this->w->setGameOver(true);
            return;
        }
        this->w->deleteEntity(this);
    }
}