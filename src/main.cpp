#include <ncurses.h>
#include <mainInclude.h>

std::vector<int> getRandPoses(int count, int width, int height)
{
    std::vector<int> poses;
    while (poses.size() < count)
    {
        int x = rand() % width;
        int y = rand() % height;
        bool isUnique = true;
        for (int i = 0; i < poses.size(); i += 2)
        {
            if (poses[i] == x && poses[i + 1] == y)
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique)
        {
            poses.push_back(x);
            poses.push_back(y);
        }
    }
    return poses;
}

int main()
{
    srand(time(NULL));
    int wWidth, wHeight;
    wWidth = 20;
    wHeight = 20;
    initscr();
    world w(wWidth, wHeight);

    std::vector<int> poses = getRandPoses(10, wWidth, wHeight);
    for (int i = 0; i < poses.size(); i++)
    {
        // w.addEntity(new animal(1, 1, poses[i], poses[i + 1], &w));
        int animalType = rand() % 5;
        switch (animalType)
        {
        case 0:
            w.addEntity(new wolf(1, 1, poses[i], poses[i + 1], &w));
            break;
        case 1:
            w.addEntity(new sheep(2, 2, poses[i], poses[i + 1], &w));
            break;
        case 2:
            w.addEntity(new fox(3, 3, poses[i], poses[i + 1], &w));
            break;
        case 3:
            w.addEntity(new antilope(4, 4, poses[i], poses[i + 1], &w));
            break;
        case 4:
            w.addEntity(new turtle(5, 5, poses[i], poses[i + 1], &w));
            break;
        }
    }

    while (true)
    {
        // w.nextEpoch();
        w.printWorld();
        refresh();
        getch();
    }
    endwin();
    return 0;
}