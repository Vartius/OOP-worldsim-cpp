#include <ncurses.h>
#include <mainInclude.h>

std::vector<int> getRandPoses(int count, int width, int height)
{
    std::vector<int> poses;
    poses.push_back(0);
    poses.push_back(0);
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
        if (i == 0)
        {
            w.addEntity(new human(5, 5, poses[i], poses[i + 1], &w));
            continue;
        }
        int animalType = rand() % 10;
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
            w.addEntity(new antelope(4, 4, poses[i], poses[i + 1], &w));
            break;
        case 4:
            w.addEntity(new turtle(5, 5, poses[i], poses[i + 1], &w));
            break;
        case 5:
            w.addEntity(new dandelion(0, 0, poses[i], poses[i + 1], &w));
            break;
        case 6:
            w.addEntity(new grass(0, 0, poses[i], poses[i + 1], &w));
            break;
        case 7:
            w.addEntity(new guarana(0, 0, poses[i], poses[i + 1], &w));
            break;
        case 8:
            w.addEntity(new wolfberries(0, 0, poses[i], poses[i + 1], &w));
            break;
        case 9:
            w.addEntity(new heracleum(0, 0, poses[i], poses[i + 1], &w));
            break;
        }
    }

    while (true)
    {
        clear();
        w.printWorld();
        w.nextEpoch();
        refresh();
    }
    endwin();
    return 0;
}