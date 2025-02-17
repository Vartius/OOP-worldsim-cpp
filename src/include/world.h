#pragma once

#include <ncurses.h>
#include <vector>
#include <entity.h>

class Entity;

class world
{
private:
    std::vector<Entity *> entities;
    int width;
    int height;
    int round = 0;
    bool gameOver = false;
    int line = 0;
    WINDOW *logWindow;
    WINDOW *worldWindow;
public:
    world(int width, int height);
    world();
    void nextEpoch();
    void printWorld();
    void getWorldSize(int &width, int &height);
    void addEntity(int posX, int posY, int type);
    void deleteEntity(Entity *entity);
    void randomMove(Entity *entity, int distance);
    void setGameOver(bool gameOver);
    bool getPossiblePoses(int x, int y, int distance, std::vector<std::pair<int, int>> &moves);
    Entity *getEntity(int x, int y);
    void sortEntities();
    int getRound();
    int symbolEnum(const char c);
    void updateRound();
    bool getGameOver();
    void logf(int color, const char *format, ...);
    void cleanLog();
    char typeEnum(int type);
    Entity* getLastEntity();
    void eraseEnitiesFromMoves(std::vector<std::pair<int, int>> &moves);
    void eraseSameEntitesFromMoves(std::vector<std::pair<int, int>> &moves, char symbol);
    void deleteWithLargerStrength(Entity *entity, std::vector<std::pair<int, int>> &moves);
    void deleteAllAround(int x, int y, char symbol);
    char getchar();
    void cleanWorld();
    void saveToFile(const char *filename);
    void setRound(int round);

    ~world();
};