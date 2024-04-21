#pragma once

#include "entity.h"
#include <cstdlib>

class animal : public Entity
{
public:
    animal(int power, int initiative, int posX, int posY, world *w);
    void behave();
    void collision();
    void print();
    void move();
    void reproduce(animal *otherAnimal);
    void getPosition(int &x, int &y);
    void getInitiative(int &initiative);

private:
    void createNewAnimal(int posX, int posY);
};