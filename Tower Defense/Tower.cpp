#include "Tower.h"
#include "Controller.h"
#include "Library.h"
#include <mutex>

mutex global;
void Bullet::wayBulletOfLevel1(int x, int y)
{
    Controller::showCursor(false);
    int i = 0;
    while (y - 1 - i > 0)
    {
        Controller::gotoXY(x + 2, y - 1 - i);
        indexOfBulletFollowX = x + 2;      //To process conlision with enemy
        indexOfBulletFollowY = y - 1 - i; // To process conlision with enemy
        Screen::printVietnamese(L"^");
        Sleep(30);
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L"    ");
        i += 1;
    }

}
void Tower::drawTowerLevel1(int x, int y, int colorFirst, int colorSecond)
{
    Controller::gotoXY(x + 2, y);
    Controller::SetColor(colorFirst, colorSecond);
    Screen::printVietnamese(L"▓"); 
    Controller::gotoXY(x + 2, y + 1);
    Screen::printVietnamese(L"▓"); 
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"▓▓▓▓▓");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"▓▓▓▓▓");

    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.

    //Bullet::wayBulletOfLevel1(x, y);
}
void Tower::tower_bullet_level1(int x, int y)
{
    while (true)
    {
        Bullet* bullet = new Bullet();
        thread bullet_firt(&Bullet::wayBulletOfLevel1, &bullet, x, y);
        Sleep(400);
        bullet_firt.join();
    }
}
void Bullet::wayBulletOfLevel2(int x, int y)
{
    Controller::showCursor(false);
    int newY = y, i = 0;
    while (true)
    {
        while (y - 1 - i > 0)
        {
            Controller::gotoXY(x + 2, y - 1 - i);
            Screen::printVietnamese(L"^");
            Controller::gotoXY(x + 4, y - 1 - i);
            Screen::printVietnamese(L"^");
            indexOfBulletFollowX = x + 2; //To process conlision with enemy
            indexOfBulletFollowY = y - 1 - i;  //To process conlision with enemy
            Sleep(28);

            Controller::gotoXY(x + 2, y - 1 - i);
            Screen::printVietnamese(L"    ");
            Controller::gotoXY(x + 4, y - 1 - i);
            Screen::printVietnamese(L"    ");
            i += 1;
        }
        i = 0;
        y = newY;
    }
}
void Tower::drawTowerLevel2(int x, int y, int colorFirst, int colorSecond)
{
    global.lock();
    Controller::gotoXY(x + 2, y);
    Controller::SetColor(colorFirst, colorSecond);
    Screen::printVietnamese(L"▓ ▓");
    Controller::gotoXY(x + 2, y + 1);
    Screen::printVietnamese(L"▓ ▓");
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"░░░░░░░");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"░░░░░░░");
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"░░░░░░░");
    global.unlock();

    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.

    //Bullet::wayBulletOfLevel2(x, y);
}

void Bullet::wayBulletOfLevel3(int x, int y)
{
    Controller::showCursor(false);
    int newY = y, i = 0;
    while (true)
    {
        while (y - 1 - i > 0)
        {
            Controller::gotoXY(x + 2, y - 1 - i);
            Screen::printVietnamese(L"^");
            Controller::gotoXY(x + 4, y - 1 - i);
            Screen::printVietnamese(L"^");
            Controller::gotoXY(x + 6, y - 1 - i);
            Screen::printVietnamese(L"^");
            indexOfBulletFollowX = x + 2; // To process conlision with enemy
            indexOfBulletFollowY = y - 1 - i; // To process conlision with enemy
            Sleep(26);

            Controller::gotoXY(x + 2, y - 1 - i);
            Screen::printVietnamese(L"    ");
            Controller::gotoXY(x + 4, y - 1 - i);
            Screen::printVietnamese(L"    ");
            i += 1;
        }
        i = 0;
        y = newY;
    }
}
void Tower::drawTowerLevel3(int x, int y, int colorFirst, int colorSecond)
{
    global.lock();
    Controller::gotoXY(x + 2, y);
    Controller::SetColor(colorFirst, colorSecond);
    Screen::printVietnamese(L"▓ ▓ ▓");
    Controller::gotoXY(x + 2, y + 1);
    Screen::printVietnamese(L"▓ ▓ ▓");
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"█████████");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"█████████");
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"█████████");
    global.unlock();

    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.

    //Bullet::wayBulletOfLevel3(x, y);
}

int Tower::getIndexOfTowerFollowX()
{
    return indexOfTowerFollowX;
}
int Tower::getIndexOfTowerFollowY()
{
    return indexOfTowerFollowY;
}
int Bullet::getIndexOfBulletFollowX()
{
    return indexOfBulletFollowX;
}
int Bullet::getIndexOfBulletFollowY()
{
    return indexOfBulletFollowY;
}
