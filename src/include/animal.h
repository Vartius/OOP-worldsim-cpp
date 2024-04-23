#pragma once

#include "entity.h"

class animal : public Entity
{
public:
    animal(int posX, int posY, world *w);
    void behave();
    void collision(std::vector<Entity *> entities, std::vector<std::pair<int, int>> &moves, int i);
    void attacked(Entity *attacker);
    void move();
    void reproduce(std::vector<Entity *> entities, std::vector<std::pair<int, int>> &moves, int i, int entityX, int entityY);

private:
    void createNewAnimal(int posX, int posY);
};