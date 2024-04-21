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
            attron(COLOR_PAIR(2));
            mvprintw(y + entityY * 2 + 1, x + entityX * 4 + 2, "S");
            attroff(COLOR_PAIR(2));
        }
        else if (dynamic_cast<fox *>(entities[i]))
        {
            attron(COLOR_PAIR(3));
            mvprintw(y + entityY * 2 + 1, x + entityX * 4 + 2, "F");
            attroff(COLOR_PAIR(3));
        }
        else if (dynamic_cast<antilope *>(entities[i]))
        {
            attron(COLOR_PAIR(4));
            mvprintw(y + entityY * 2 + 1, x + entityX * 4 + 2, "A");
            attroff(COLOR_PAIR(4));
        }
        else if (dynamic_cast<turtle *>(entities[i]))
        {
            attron(COLOR_PAIR(5));
            mvprintw(y + entityY * 2 + 1, x + entityX * 4 + 2, "T");
            attroff(COLOR_PAIR(5));
        }
        else
        {
            attron(COLOR_PAIR(6));
            mvprintw(y + entityY * 2 + 1, x + entityX * 4 + 2, "O");
            attroff(COLOR_PAIR(6));
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