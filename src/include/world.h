#pragma once

#include <vector>
#include <entity.h>

class Entity;

class world
{
private:
    std::vector<std::vector<int>> map;
    std::vector<Entity *> entities;
    int width;
    int height;

public:
    world(int width, int height);
    void nextEpoch();
    void printWorld();
    void getWorldSize(int &width, int &height);
    void addEntity(Entity *entity);
    void randomMove(int *x, int *y, int distance);
};