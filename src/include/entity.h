#pragma once

class world;

// abstract class
class Entity
{
protected:
    int strength;
    int initiative;
    int posX;
    int posY;
    bool stun = false;
    int birthRound;
    int reproductionStun = 0;
    char symbol;
    world *w;

public:
    Entity(int posX, int posY, world *w);
    virtual void behave() = 0;
    virtual void collision() = 0;
    virtual void print() = 0;
    void getPosition(int &x, int &y);
    int getInitiative();
    int getStrength();
    int getBirthRound();
    void setPosition(int x, int y);
    char getSymbol();
    void setStun(bool stun);
    void setReproductionStun(int reproductionStun);
    int getReproductionStun();
    virtual ~Entity(){};
};
