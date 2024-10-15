#include "Tower.h"
#include "Controller.h"
#include "Library.h"
#include <mutex>

mutex mu_global2;
void Bullet::wayBulletOfLevel1_Up(int x, int y)
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
            if (enemy.get_hp() > 0)
            {
                if (get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 5)
                {
                    enemy.sub_hp(2);
                    flag = true;
                    break;
                }
            }
        }
        mu_global2.unlock();

        if (flag) break;
    }
}
void Tower::drawTowerLevel1_Up(int x, int y, int colorFirst, int colorSecond)
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
void Tower::tower_bullet_level1_Up(int x, int y)
{
    while (true)
    {
        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel1_Up, &bullet, x, y);
        Sleep(50);
        bullet_firt.join();
    }
}

void Bullet::wayBulletOfLevel2_Up(int x, int y)
{
    Controller::showCursor(false);
    mu.lock();
    int i = 0;
    mu.unlock();
    while (y - 1 - i > 0)
    {
        mu.lock();
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L"^");
        mu.unlock();
        mu.lock();
        Controller::gotoXY(x + 4, y - 1 - i);
        Screen::printVietnamese(L"^");
        mu.unlock();

        indexOfBulletFollowX = x + 2; // To process conlision with enemy
        indexOfBulletFollowY = y - 1 - i;  //To process conlision with enemy

        Sleep(90);

        mu.lock();
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L"    ");
        mu.unlock();
        mu.lock();
        Controller::gotoXY(x + 4, y - 1 - i);
        Screen::printVietnamese(L"    ");
        i += 1;
        mu.unlock();


        bool flag = false;

        mu_global2.lock();
        for (auto& enemy : e_global)  // Duyệt qua danh sách các enemy
        {
            if (enemy.get_hp() > 0)
            {
                if (get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 5)
                {
                    enemy.sub_hp(2);
                    flag = true;
                    break;
                }
            }
        }
        mu_global2.unlock();

        if (flag) break;
    }
}
void Tower::drawTowerLevel2_Up(int x, int y, int colorFirst, int colorSecond)
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
void Tower::tower_bullet_level2_Up(int x, int y)
{
    while (true)
    {
        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel2_Up, &bullet, x, y);
        Sleep(90);
        bullet_firt.join();
    }
}


void Bullet::wayBulletOfLevel3_Up(int x, int y)
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
        Sleep(100);

        mu.lock();
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L"    ");
        Controller::gotoXY(x + 4, y - 1 - i);
        Screen::printVietnamese(L"    ");
        mu.unlock();
        i += 1;


        bool flag = false;

        mu_global2.lock();
        for (auto& enemy : e_global)  // Duyệt qua danh sách các enemy
        {
            if (enemy.get_hp() > 0)
            {
                if (get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 6)
                {
                    enemy.sub_hp(3);
                    flag = true;
                    break;
                }
            }
        }
        mu_global2.unlock();

        if (flag) break;
    }
}
void Tower::drawTowerLevel3_Up(int x, int y, int colorFirst, int colorSecond)
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
void Tower::tower_bullet_level3_Up(int x, int y)
{
    while (true)
    {
        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel3_Up, &bullet, x, y);
        Sleep(100);
        bullet_firt.join();
    }
}

void Bullet::wayBulletOfLevel2_Left(int x, int y)
{
    Controller::showCursor(false);
    int newX = x, i = 0;
    //while (true)
    //{
    while (x - 5 - i > 0)
    {
        mu.lock();
        Controller::gotoXY(x - 5 - i, y + 3);
        Screen::printVietnamese(L"<");
        mu.unlock();
        mu.lock();
        Controller::gotoXY(x - 5 - i, y + 2);
        Screen::printVietnamese(L"<");
        mu.unlock();
        indexOfBulletFollowX = x - 5 - i;      //To process conlision with enemy
        indexOfBulletFollowY = y + 2;  // To process conlision with enemy
        Sleep(30);
        mu.lock();
        Controller::gotoXY(x - 5 - i, y + 3);
        Screen::printVietnamese(L" ");
        mu.unlock();
        mu.lock();
        Controller::gotoXY(x - 5 - i, y + 2);
        Screen::printVietnamese(L" ");
        mu.unlock();
        i += 1;

        bool flag = false;

        mu_global2.lock();
        for (auto& enemy : e_global)  // Duyệt qua danh sách các enemy
        {
            if (enemy.get_hp() > 0)
            {
                if (get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 6)
                {
                    enemy.sub_hp(3);
                    flag = true;
                    break;
                }
            }
        }
        mu_global2.unlock();

        if (flag) break;
    }
    //x = newX, i = 0;
//}
}
void Tower::drawTowerLevel2_Left(int x, int y, int colorFirst, int colorSecond)
{
    Controller::gotoXY(x - 1, y + 2);
    Controller::SetColor(colorFirst, colorSecond);
    Screen::printVietnamese(L"=");
    Controller::gotoXY(x - 1, y + 3);
    Screen::printVietnamese(L"=");

    Controller::gotoXY(x - 2, y + 2);
    Controller::SetColor(colorFirst, colorSecond);
    Screen::printVietnamese(L"=");
    Controller::gotoXY(x - 2, y + 3);
    Screen::printVietnamese(L"=");

    Controller::gotoXY(x - 3, y + 2);
    Controller::SetColor(colorFirst, colorSecond);
    Screen::printVietnamese(L"=");
    Controller::gotoXY(x - 3, y + 3);
    Screen::printVietnamese(L"=");

    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"▓▓▓▓▓");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"▓▓▓▓▓");

    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.

    //Bullet::bulletPointsLeft(x, y);
}
void Tower::tower_bullet_level2_Left(int x, int y)
{
    while (true)
    {
        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel2_Left, &bullet, x, y);
        Sleep(30);
        bullet_firt.join();
    }
}


void Bullet::wayBulletOfLevel2_Right(int x, int y)
{
    Controller::showCursor(false);
    int i = 0, a = 81;
    while (a--)
    {
        mu.lock();
        Controller::gotoXY(x + 8 + i, y + 2);
        Screen::printVietnamese(L">");
        mu.unlock();
        mu.lock();
        Controller::gotoXY(x + 8 + i, y + 3);
        Screen::printVietnamese(L">");
        mu.unlock();

        indexOfBulletFollowX = x + 8 + i;     //To process conlision with enemy
        indexOfBulletFollowY = y + 2;  // To process conlision with enemy

        Sleep(30);

        mu.lock();
        Controller::gotoXY(x + 8 + i, y + 2);
        Screen::printVietnamese(L" ");
        mu.unlock();
        mu.lock();
        Controller::gotoXY(x + 8 + i, y + 3);
        Screen::printVietnamese(L" ");
        mu.unlock();
        i += 1;

        bool flag = false;

        mu_global2.lock();
        for (auto& enemy : e_global)  // Duyệt qua danh sách các enemy
        {
            if (enemy.get_hp() > 0)
            {
                if (get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 6)
                {
                    enemy.sub_hp(3);
                    flag = true;
                    break;
                }
            }
        }
        mu_global2.unlock();

        if (flag) break;
    }
}
void Tower::drawTowerLevel2_Right(int x, int y, int colorFirst, int colorSecond)
{
    Controller::SetColor(colorFirst, colorSecond);
    Controller::gotoXY(x + 5, y + 2);
    Screen::printVietnamese(L"=");
    Controller::gotoXY(x + 6, y + 2);
    Screen::printVietnamese(L"=");


    Controller::gotoXY(x + 5, y + 3);
    Screen::printVietnamese(L"=");
    Controller::gotoXY(x + 6, y + 3);
    Screen::printVietnamese(L"=");

    Controller::gotoXY(x + 7, y + 3);
    Screen::printVietnamese(L"=");
    Controller::gotoXY(x + 7, y + 2);
    Screen::printVietnamese(L"=");

    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"▓▓▓▓▓");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"▓▓▓▓▓");

    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.
}
void Tower::tower_bullet_level2_Right(int x, int y)
{
    while (true)
    {
        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel2_Right, &bullet, x, y);
        Sleep(30);
        bullet_firt.join();
    }
}

void Bullet::wayBulletOfLevel2_Down(int x, int y)
{
    int i = 0, a = 24;
    Controller::showCursor(false);
    while (a--)
    {
        mu.lock();
        Controller::gotoXY(x + 2, y + 6 + i);
        Screen::printVietnamese(L"v");
        Controller::gotoXY(x + 4, y + 6 + i);
        Screen::printVietnamese(L"v");
        mu.unlock();

        indexOfBulletFollowX = x + 2; // To process conlision with enemy
        indexOfBulletFollowY = y + 6 + i;  //To process conlision with enemy

        Sleep(50);

        mu.lock();
        Controller::gotoXY(x + 2, y + 6 + i);
        Screen::printVietnamese(L" ");
        Controller::gotoXY(x + 4, y + 6 + i);
        Screen::printVietnamese(L" ");
        mu.unlock();
        i += 1;

        bool flag = false;

        mu_global2.lock();
        for (auto& enemy : e_global)  // Duyệt qua danh sách các enemy
        {
            if (enemy.get_hp() > 0)
            {
                if (get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 6)
                {
                    enemy.sub_hp(3);
                    flag = true;
                    break;
                }
            }
        }
        mu_global2.unlock();

        if (flag) break;
    }
}
void Tower::drawTowerLevel2_Down(int x, int y, int colorFirst, int colorSecond)
{
    Controller::gotoXY(x + 2, y + 4);
    Controller::SetColor(colorFirst, colorSecond);
    Screen::printVietnamese(L"▓ ▓");
    Controller::gotoXY(x + 2, y + 5);
    Screen::printVietnamese(L"▓ ▓");
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"░░░░░░░");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"░░░░░░░");
    Controller::gotoXY(x, y + 1);
    Screen::printVietnamese(L"░░░░░░░");

    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.

}
void Tower::tower_bullet_level2_Down(int x, int y)
{
    while (true)
    {
        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel2_Down, &bullet, x, y);
        Sleep(50);
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