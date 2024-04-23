#pragma once

#include "entity.h"

class plant : public Entity
{
public:
    plant(int posX, int posY, world *w);
    void behave();
    void collision(std::vector<Entity *> entities, std::vector<std::pair<int, int>> &moves, int i);
    void print();
};
