#include <entity.h>
#include <cstdlib>
#include <vector>
#include <world.h>
#include <ncurses.h>
#include <mainInclude.h>
#include <algorithm>

world::world(int width, int height)
{
    this->width = width;
    this->height = height;
    map = std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
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

int countDigits(int num)
{
    int numWidth = 0;
    while (num > 0)
    {
        num /= 10;
        numWidth++;
    }
    return numWidth;
}

void world::printWorld()
{
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
    int consoleWidth,
        consoleHeight;
    getmaxyx(stdscr, consoleHeight, consoleWidth);
    int x = (consoleWidth - width * 4) / 2;
    int y = (consoleHeight - height * 2) / 2;

    for (int i = 0; i < height; i++)
    {
        mvhline(y + i * 2, x, '-', width * 4 + 1);
    }

    mvhline(y + height * 2, x, '-', width * 4 + 1);

    for (int i = 0; i < width + 1; i++)
    {
        mvvline(y, x + i * 4, '|', height * 2 + 1);
    }

    for (int i = 0; i < entities.size(); i++)
    {
        int entityX, entityY;
        entities[i]->getPosition(entityX, entityY);
        attron(A_BOLD);

        if (dynamic_cast<wolf *>(entities[i]))
        {
            attron(COLOR_PAIR(1));
            mvprintw(y + entityY * 2 + 1, x + entityX * 4 + 2, "W");
            attroff(COLOR_PAIR(1));
        }
        else if (dynamic_cast<sheep *>(entities[i]))
        {
            attron(COLOR_PAIR(7));
            mvprintw(y + entityY * 2 + 1, x + entityX * 4 + 2, "S");
            attroff(COLOR_PAIR(7));
        }
        else if (dynamic_cast<fox *>(entities[i]))
        {
            attron(COLOR_PAIR(1));
            mvprintw(y + entityY * 2 + 1, x + entityX * 4 + 2, "F");
            attroff(COLOR_PAIR(1));
        }
        else if (dynamic_cast<antelope *>(entities[i]))
        {
            attron(COLOR_PAIR(1));
            mvprintw(y + entityY * 2 + 1, x + entityX * 4 + 2, "A");
            attroff(COLOR_PAIR(1));
        }
        else if (dynamic_cast<turtle *>(entities[i]))
        {
            attron(COLOR_PAIR(1));
            mvprintw(y + entityY * 2 + 1, x + entityX * 4 + 2, "T");
            attroff(COLOR_PAIR(1));
        }
        else if (dynamic_cast<dandelion *>(entities[i]))
        {
            attron(COLOR_PAIR(2));
            mvprintw(y + entityY * 2 + 1, x + entityX * 4 + 2, "D");
            attroff(COLOR_PAIR(2));
        }
        else if (dynamic_cast<grass *>(entities[i]))
        {
            attron(COLOR_PAIR(2));
            mvprintw(y + entityY * 2 + 1, x + entityX * 4 + 2, "G");
            attroff(COLOR_PAIR(2));
        }
        else if (dynamic_cast<guarana *>(entities[i]))
        {
            attron(COLOR_PAIR(2));
            mvprintw(y + entityY * 2 + 1, x + entityX * 4 + 2, "g");
            attroff(COLOR_PAIR(2));
        }
        else if (dynamic_cast<wolfberries *>(entities[i]))
        {
            attron(COLOR_PAIR(2));
            mvprintw(y + entityY * 2 + 1, x + entityX * 4 + 2, "w");
            attroff(COLOR_PAIR(2));
        }
        else if (dynamic_cast<heracleum *>(entities[i]))
        {
            attron(COLOR_PAIR(2));
            mvprintw(y + entityY * 2 + 1, x + entityX * 4 + 2, "h");
            attroff(COLOR_PAIR(2));
        }
        else if (dynamic_cast<human *>(entities[i]))
        {
            attron(COLOR_PAIR(3));
            mvprintw(y + entityY * 2 + 1, x + entityX * 4 + 2, "H");
            attroff(COLOR_PAIR(3));
        }
        else
        {
            attron(COLOR_PAIR(1));
            mvprintw(y + entityY * 2 + 1, x + entityX * 4 + 2, "O");
            attroff(COLOR_PAIR(1));
        }
        attroff(A_BOLD);
    }

    // numuration
    int numWidth = countDigits(width);
    for (int i = 0; i < width; i++)
    {
        mvprintw(y - 1, x + i * 4 + 2, "%d", i);
        mvprintw(y + i * 2 + 1, x - numWidth, "%d", i);
    }
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
    for (int i = 0; i < entities.size(); i++)
    {
        entities[i]->behave();
        clear();
        printWorld();
    }
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
    // for (int i = 0; i < entities.size(); i++)
    // {
    //     int entityX, entityY;
    //     entities[i]->getPosition(entityX, entityY);
    //     for (int j = 0; j < moves.size(); j++)
    //     {
    //         if (entityX == moves[j].first && entityY == moves[j].second)
    //         {
    //             moves.erase(moves.begin() + j);
    //             j--;
    //         }
    //     }
    // }
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
    case 'D':
        return 5;
    case 'G':
        return 6;
    case 'g':
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

void deleteWithLargerStrength(std::vector<Entity *> &entities, Entity *entity, std::vector<std::pair<int, int>> &moves)
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

void world::randomMove(Entity *entity, int distance)
{
    std::vector<std::pair<int, int>> moves;
    int x, y;
    entity->getPosition(x, y);

    if (getPossiblePoses(x, y, distance, moves))
    {
        if (dynamic_cast<fox *>(entity)){
            deleteWithLargerStrength(entities, entity, moves);
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