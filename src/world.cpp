#include "animal.h"
#include <entity.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <world.h>
#include <ncurses.h>
#include <mainInclude.h>
#include <algorithm>
#include <cstdarg> 

world::world(int width, int height)
{
    this->width = width;
    this->height = height;
    int consoleWidth,
        consoleHeight;
    getmaxyx(stdscr, consoleHeight, consoleWidth);
    int xSize = height * 2 + 2;
    int ySize = width * 4 + 3;
    int x = consoleHeight/2 - xSize/2;
    int y = consoleWidth/2 - ySize/2;
    worldWindow = newwin(xSize, ySize, x, y);
    logWindow = newwin(consoleHeight, y, 0, 0);
    scrollok(logWindow, TRUE);
    use_default_colors();
    start_color();
    init_pair(1, COLOR_RED, -1);
    init_pair(2, COLOR_GREEN, -1);
    init_pair(3, COLOR_BLUE, -1);
    init_pair(4, COLOR_YELLOW, -1);
    init_pair(5, COLOR_MAGENTA, -1);
    init_pair(6, COLOR_CYAN, -1);
    init_pair(7, COLOR_WHITE, -1);
    init_pair(8, COLOR_BLACK, -1);

    curs_set(0);
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
}

void world::getWorldSize(int &width, int &height)
{
    width = this->width;
    height = this->height;
}

bool world::getGameOver()
{
    return gameOver;
}

void world::cleanWorld()
{
    wclear(worldWindow);
}

void world::printWorld()
{
    // wclear(worldWindow);
    int xOffset = 2;
    int yOffset = 1;

    for (int i = 0; i < height; i++)
    {
        mvwhline(worldWindow, i * 2 + yOffset, xOffset, '-', width * 4 + 1);
    }

    mvwhline(worldWindow, height * 2 + yOffset, xOffset, '-', width * 4 + 1);

    for (int i = 0; i < width + 1; i++)
    {
        mvwvline(worldWindow, yOffset, i * 4 + xOffset, '|', height * 2 + 1);
    }

    for (int i = 0; i < entities.size(); i++)
    {
        int entityX, entityY;
        entities[i]->getPosition(entityX, entityY);
        wattron(worldWindow, A_BOLD);

        if (dynamic_cast<wolf *>(entities[i])){
            wattron(worldWindow, COLOR_PAIR(1));
            mvwprintw(worldWindow, entityY * 2 + yOffset + 1, entityX * 4 + 2 + xOffset, "W");
            wattroff(worldWindow, COLOR_PAIR(1));
        } else if (dynamic_cast<sheep *>(entities[i])){
            wattron(worldWindow, COLOR_PAIR(7));
            mvwprintw(worldWindow, entityY * 2 + yOffset + 1, entityX * 4 + 2 + xOffset, "S");
            wattroff(worldWindow, COLOR_PAIR(7));
        } else if (dynamic_cast<fox *>(entities[i])){
            wattron(worldWindow, COLOR_PAIR(1));
            mvwprintw(worldWindow, entityY * 2 + yOffset + 1, entityX * 4 + 2 + xOffset, "F");
            wattroff(worldWindow, COLOR_PAIR(1));
        } else if (dynamic_cast<antelope *>(entities[i])){
            wattron(worldWindow, COLOR_PAIR(1));
            mvwprintw(worldWindow, entityY * 2 + yOffset + 1, entityX * 4 + 2 + xOffset, "A");
            wattroff(worldWindow, COLOR_PAIR(1));
        } else if (dynamic_cast<turtle *>(entities[i])){
            wattron(worldWindow, COLOR_PAIR(1));
            mvwprintw(worldWindow, entityY * 2 + yOffset + 1, entityX * 4 + 2 + xOffset, "T");
            wattroff(worldWindow, COLOR_PAIR(1));
        } else if (dynamic_cast<dandelion *>(entities[i])){
            wattron(worldWindow, COLOR_PAIR(2));
            mvwprintw(worldWindow, entityY * 2 + yOffset + 1, entityX * 4 + 2 + xOffset, "d");
            wattroff(worldWindow, COLOR_PAIR(2));
        } else if (dynamic_cast<grass *>(entities[i])){
            wattron(worldWindow, COLOR_PAIR(2));
            mvwprintw(worldWindow, entityY * 2 + yOffset + 1, entityX * 4 + 2 + xOffset, "g");
            wattroff(worldWindow, COLOR_PAIR(2));
        } else if (dynamic_cast<guarana *>(entities[i])){
            wattron(worldWindow, COLOR_PAIR(2));
            mvwprintw(worldWindow, entityY * 2 + yOffset + 1, entityX * 4 + 2 + xOffset, "G");
            wattroff(worldWindow, COLOR_PAIR(2));
        } else if (dynamic_cast<wolfberries *>(entities[i])){
            wattron(worldWindow, COLOR_PAIR(2));
            mvwprintw(worldWindow, entityY * 2 + yOffset + 1, entityX * 4 + 2 + xOffset, "w");
            wattroff(worldWindow, COLOR_PAIR(2));
        } else if (dynamic_cast<heracleum *>(entities[i])){
            wattron(worldWindow, COLOR_PAIR(2));
            mvwprintw(worldWindow, entityY * 2 + yOffset + 1, entityX * 4 + 2 + xOffset, "h");
            wattroff(worldWindow, COLOR_PAIR(2));
        } else if (dynamic_cast<human *>(entities[i])){
            wattron(worldWindow, COLOR_PAIR(3));
            mvwprintw(worldWindow, entityY * 2 + yOffset + 1, entityX * 4 + 2 + xOffset, "H");
            wattroff(worldWindow, COLOR_PAIR(3));
        }
        wattroff(worldWindow, A_BOLD);
    }

    for (int i = 0; i < width; i++)
    {
        mvwprintw(worldWindow, 0, i * 4 + 2 + xOffset, "%d", i);
        mvwprintw(worldWindow, i * 2 + 1 + yOffset, 0, "%d", i);
    }
    wrefresh(worldWindow);
}

void world::addEntity(int posX, int posY, int type)
{
    switch (type)
    {
    case 0:
        entities.push_back(new wolf(posX, posY, this));
        break;
    case 1:
        entities.push_back(new sheep(posX, posY, this));
        break;
    case 2:
        entities.push_back(new fox(posX, posY, this));
        break;
    case 3:
        entities.push_back(new antelope(posX, posY, this));
        break;
    case 4:
        entities.push_back(new turtle(posX, posY, this));
        break;
    case 5:
        entities.push_back(new dandelion(posX, posY, this));
        break;
    case 6:
        entities.push_back(new grass(posX, posY, this));
        break;
    case 7:
        entities.push_back(new guarana(posX, posY, this));
        break;
    case 8:
        entities.push_back(new wolfberries(posX, posY, this));
        break;
    case 9:
        entities.push_back(new heracleum(posX, posY, this));
        break;
    case 10:
        entities.push_back(new human(posX, posY, this));
        break;
    }
}

void world::deleteEntity(Entity *entity)
{
    for (int i = 0; i < entities.size(); i++)
    {
        if (entities[i] == entity)
        {
            entities.erase(entities.begin() + i);
            delete entity; 
            break;
        }
    }
}

void world::nextEpoch()
{
    logf(5, "Round %d", round);
    for (int i = 0; i < entities.size(); i++)
    {
        entities[i]->behave();
        if (gameOver)
        {
            return;
        }
    }
    
}

char world::getchar()
{
    return wgetch(worldWindow);
}

void world::setGameOver(bool gameOver)
{
    this->gameOver = gameOver;
}

bool world::getPossiblePoses(int x, int y, int distance, std::vector<std::pair<int, int>> &moves)
{
    moves.clear();
    for (int i = -distance; i <= distance; i++)
    {
        for (int j = -distance; j <= distance; j++)
        {
            if (abs(i) + abs(j) > distance || (x + i < 0) || (x + i >= width) || (y + j < 0) || (y + j >= height) || (i == 0 && j == 0))
            {
                continue;
            }
            moves.push_back({x + i, y + j});
        }
    }
    if (moves.size() == 0)
    {
        return false;
    }
    return true;
}

int world::symbolEnum(const char c)
{
    switch (c)
    {
    case 'W':
        return 0; 
    case 'S':
        return 1; 
    case 'F':
        return 2; 
    case 'A':
        return 3; 
    case 'T':
        return 4; 
    case 'd':
        return 5;
    case 'g':
        return 6;
    case 'G':
        return 7;
    case 'w':
        return 8;
    case 'h':
        return 9;
    case 'H':
        return 10;
    default:
        return -1;
    }
}

char world::typeEnum(int type)
{
    switch (type)
    {
    case 0:
        return 'W';
    case 1:
        return 'S';
    case 2:
        return 'F';
    case 3:
        return 'A';
    case 4:
        return 'T';
    case 5:
        return 'd';
    case 6:
        return 'g';
    case 7:
        return 'G';
    case 8:
        return 'w';
    case 9:
        return 'h';
    case 10:
        return 'H';
    default:
        return ' ';
    }
}

void world::deleteWithLargerStrength(Entity *entity, std::vector<std::pair<int, int>> &moves)
{
    for (int i = 0; i < entities.size(); i++)
    {
        int entityX, entityY;
        entities[i]->getPosition(entityX, entityY);
        for (int j = 0; j < moves.size(); j++)
        {
            if (entityX == moves[j].first && entityY == moves[j].second)
            {
                if (entities[i]->getStrength() > entity->getStrength())
                {
                    moves.erase(moves.begin() + j);
                    j--;
                }
            }
        }
    }
}

void world::eraseSameEntitesFromMoves(std::vector<std::pair<int, int>> &moves, char symbol)
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

void world::eraseEnitiesFromMoves(std::vector<std::pair<int, int>> &moves)
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

void world::randomMove(Entity *entity, int distance)
{
    std::vector<std::pair<int, int>> moves;
    int x, y;
    entity->getPosition(x, y);

    int theSameCounter = 0;
    for (int i = 0; i < entities.size(); i++)
    {
        int entityX, entityY;
        entities[i]->getPosition(entityX, entityY);
        for (int j = -1; j <= 1; j++)
        {
            for (int k = -1; k <= 1; k++)
            {
                if (entityX == x+j && entityY == y+k && entity->getSymbol() == entities[i]->getSymbol() && (j != 0 || k != 0))
                {
                    theSameCounter++;
                }
            }
        }
    }
    if (theSameCounter > 2){
        logf(5, "Entity %c died because of overpopulation", entity->getSymbol());
        deleteEntity(entity);
        return;
    }

    if (getPossiblePoses(x, y, distance, moves))
    {
        if (dynamic_cast<fox *>(entity)){
            deleteWithLargerStrength(entity, moves);
        }
        std::pair<int, int> res = moves[rand() % moves.size()];

        for (int i = 0; i < entities.size(); i++)
        {
            int entityX, entityY;
            entities[i]->getPosition(entityX, entityY);
            if (entityX == res.first && entityY == res.second)
            {
                entity->collision(entities, moves, i);
                return;
            }
        }
        entity->setPosition(res.first, res.second);
    }
}

void world::sortEntities()
{
    std::sort(entities.begin(), entities.end(), [](Entity *a, Entity *b)
              {
        if (a->getInitiative() == b->getInitiative())
        {
            return a->getBirthRound() > b->getBirthRound();
        }
        return a->getInitiative() > b->getInitiative(); });
}

int world::getRound()
{
    return round;
}

void world::updateRound()
{
    round++;
}



void world::logf(int color, const char* format, ...)
{
    wattron(logWindow, COLOR_PAIR(color));
    va_list args;
    va_start(args, format);
    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), format, args);

    std::string logMessage = std::string(buffer) + "\n";
    wprintw(logWindow, logMessage.c_str());
    wrefresh(logWindow);

    va_end(args);
    wattroff(logWindow, COLOR_PAIR(color));
}

void world::cleanLog()
{
    wclear(logWindow);
    wrefresh(logWindow);
}

Entity* world::getLastEntity()
{
    return entities.back();
}

void world::deleteAllAround(int x, int y, char symbol)
{
    int counter = 0;
    for (int i = 0; i < entities.size(); i++)
    {
        
        int entityX, entityY;
        entities[i]->getPosition(entityX, entityY);
        if (abs(entityX - x) <= 1 && abs(entityY - y) <= 1 && abs(entityX - x) + abs(entityY - y) != 0 && entities[i]->getSymbol() != symbol)
        {
            counter++;
            if (entities[i]->getSymbol() == 'H')
            {
                mvprintw(0, 0, "2Game over! You lost! Press any key to exit.");
                getch();
                setGameOver(true);
                return;
            }
            deleteEntity(entities[i]);
            i--;
        }
    }
    if (counter > 0)
        logf(5, "Entity %c (%d %d) killed %d entities", symbol, x, y, counter);
}