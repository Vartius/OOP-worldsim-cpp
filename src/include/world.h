#pragma once

#include <ncurses.h>
#include <string>
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
    int round = 0;
    bool gameOver = false;
    int line = 0;
    WINDOW *logWindow;
    WINDOW *worldWindow;

public:
    world(int width, int height);
    void nextEpoch();
    void printWorld();
    void getWorldSize(int &width, int &height);
    void addEntity(int posX, int posY, int type);
    void deleteEntity(Entity *entity);
    void randomMove(Entity *entity, int distance);
    void setGameOver(bool gameOver);
    bool getPossiblePoses(int x, int y, int distance, std::vector<std::pair<int, int>> &moves);
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
};