#pragma once

#include "entity.h"
#include <cstdlib>

class animal : public Entity
{
public:
    animal(int posX, int posY, world *w);
    void behave();
    void collision();
    void print();
    void move();
    void reproduce(animal *otherAnimal);

private:
    void createNewAnimal(int posX, int posY);
};