#include <world.h>
#include <ncurses.h>
#include <mainInclude.h>

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

void world::addEntity(Entity *entity)
{
    entities.push_back(entity);
}

void world::nextEpoch()
{
    for (int i = 0; i < entities.size(); i++)
    {
        entities[i]->behave();
    }
    // for (int i = 0; i < entities.size(); i++)
    // {
    //     entities[i]->collision();
    // }
    // for (int i = 0; i < entities.size(); i++)
    // {
    //     entities[i]->print();
    // }
}

bool world::getPossiblePoses(int *x, int *y, int distance, std::vector<std::pair<int, int>> &moves)
{
    moves.clear();
    for (int i = -distance; i <= distance; i++)
    {
        for (int j = -distance; j <= distance; j++)
        {
            if (abs(i) + abs(j) > distance || (*x + i < 0) || (*x + i >= width) || (*y + j < 0) || (*y + j >= height))
            {
                continue;
            }
            moves.push_back({*x + i, *y + j});
        }
    }
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
    if (moves.size() == 0)
    {
        return false;
    }
    return true;
}

void world::randomMove(int *x, int *y, int distance)
{
    std::vector<std::pair<int, int>> moves;

    if (getPossiblePoses(x, y, distance, moves))
    {
        std::pair<int, int> res = moves[rand() % moves.size()];
        *x = res.first;
        *y = res.second;
    }
}