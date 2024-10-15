#include "Tower.h"
#include "Controller.h"
#include "Library.h"
#include <mutex>

mutex mu_global2;
void Bullet::wayBulletOfLevel1(int x, int y)
{
    Controller::showCursor(false);
    int i = 0;
    while (y - 1 - i > 0)
    {
        mu.lock();
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L"^");
        //cout <<" " << indexOfBulletFollowX << "," << indexOfBulletFollowY;
        mu.unlock();

        indexOfBulletFollowX = x + 2;      //To process conlision with enemy
        indexOfBulletFollowY = y - 1 - i;  // To process conlision with enemy

        Sleep(50);

        mu.lock();
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L"    ");
        mu.unlock();

        i += 1;
        bool flag = false;

        mu_global2.lock();
        for (auto& enemy : e_global)  // Duyệt qua danh sách các enemy
        {
            if (get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 5)
            {
                enemy.sub_hp();
                flag = true;
                break;
            }
        }
        mu_global2.unlock();

        if (flag) break;
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

}
void Tower::tower_bullet_level1(int x, int y)
{
    while (true)
    {
        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel1, &bullet, x, y);
        Sleep(50);
        bullet_firt.join();
    }
}

void Bullet::wayBulletOfLevel2(int x, int y)
{
    Controller::showCursor(false);
    int i = 0;
    while (y - 1 - i > 0)
    {
        mu.lock();
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L"^");
        Controller::gotoXY(x + 4, y - 1 - i);
        Screen::printVietnamese(L"^");
        indexOfBulletFollowX = x + 2; // To process conlision with enemy
        indexOfBulletFollowY = y - 1 - i;  //To process conlision with enemy
        mu.unlock();

        Sleep(30);

        mu.lock();
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L"    ");
        Controller::gotoXY(x + 4, y - 1 - i);
        Screen::printVietnamese(L"    ");
        mu.unlock();
        i += 1;

    }
}
void Tower::drawTowerLevel2(int x, int y, int colorFirst, int colorSecond)
{
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

    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.

}
void Tower::tower_bullet_level2(int x, int y)
{
    while (true)
    {
        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel2, &bullet, x, y);
        Sleep(30);
        bullet_firt.join();
    }
}


void Bullet::wayBulletOfLevel3(int x, int y)
{
    Controller::showCursor(false);
    int i = 0;
    while (y - 1 - i > 0)
    {
        mu.lock();
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L"^");
        Controller::gotoXY(x + 4, y - 1 - i);
        Screen::printVietnamese(L"^");
        Controller::gotoXY(x + 6, y - 1 - i);
        Screen::printVietnamese(L"^");
        indexOfBulletFollowX = x + 2; // To process conlision with enemy
        indexOfBulletFollowY = y - 1 - i; // To process conlision with enemy
        mu.unlock();
        Sleep(20);

        mu.lock();
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L"    ");
        Controller::gotoXY(x + 4, y - 1 - i);
        Screen::printVietnamese(L"    ");
        mu.unlock();
        i += 1;
    }
}
void Tower::drawTowerLevel3(int x, int y, int colorFirst, int colorSecond)
{
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

    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.
}
void Tower::tower_bullet_level3(int x, int y)
{
    while (true)
    {
        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel3, &bullet, x, y);
        Sleep(20);
        bullet_firt.join();
    }
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