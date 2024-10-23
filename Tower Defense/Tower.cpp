#include "Tower.h"
#include "Controller.h"
#include "Library.h"
#include <mutex>

mutex mu_global2;

void Tower::setPos(int x, int y) {
    this->x = x;
    this->y = y;
}

int Tower::getX() {
    return x;
}
int Tower::getY() {
    return y;
}

int Tower::getLevel() {
    return level;
}

void Tower::setLevel(int level) {
    this->level = level;
}

int Tower::getDir() {
    return dir;
}

void Tower::setDir(int dir) {
    this->dir = dir;
}

void Bullet::wayBulletOfLevel1_Up(int x, int y)
{
    Controller::showCursor(false);
    int i = 0;
    while (y - 1 - i > 0)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        mu.lock();
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L"^");
        //cout <<" " << indexOfBulletFollowX << "," << indexOfBulletFollowY;
        mu.unlock();

        indexOfBulletFollowX = x + 2;      //To process conlision with enemy
        indexOfBulletFollowY = y - 1 - i;  // To process conlision with enemy

        Sleep(150);

        mu.lock();
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L" ");
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
                    enemy.sub_hp(1);
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
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel1_Up, &bullet, x, y);
        if (bullet_firt.joinable())
        {
            bullet_firt.join();
            Sleep(150);
        }
    }
}

void Bullet::wayBulletOfLevel1_Left(int x, int y, int x_end, int y_end)
{
    Controller::showCursor(false);
    int i = 0;
    while ((x - 5 - i) > x_end)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }
        mu.lock();
        Controller::gotoXY(x - 5 - i, y + 3);
        Screen::printVietnamese(L"<");
        mu.unlock();
        indexOfBulletFollowX = x - 5 - i;      //To process conlision with enemy
        indexOfBulletFollowY = y + 2;  // To process conlision with enemy
        Sleep(150);
        mu.lock();
        Controller::gotoXY(x - 5 - i, y + 3);
        Screen::printVietnamese(L" ");
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
                    enemy.sub_hp(1);
                    flag = true;
                    break;
                }
            }
        }
        mu_global2.unlock();

        if (flag) break;
    }
}
void Tower::drawTowerLevel1_Left(int x, int y, int colorFirst, int colorSecond)
{
    Controller::SetColor(colorFirst, colorSecond);
    
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"▓▓▓▓▓");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"▓▓▓▓▓");
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"▓▓▓▓▓");
    Controller::gotoXY(x - 3, y + 3);
    Screen::printVietnamese(L"===");
    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.
}
void Tower::tower_bullet_level1_Left(int x, int y, int x_end, int y_end)
{
    while (true)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel1_Left, &bullet, x, y, x_end, y_end);
        if (bullet_firt.joinable())
        {
            bullet_firt.join();
            Sleep(150);
        }
    }
}

void Bullet::wayBulletOfLevel1_Right(int x, int y, int x_end, int y_end)
{
    Controller::showCursor(false);
    int i = 0;
    while ((x + 8 + i) < x_end)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        mu.lock();
        Controller::gotoXY(x + 8 + i, y + 2);
        Screen::printVietnamese(L">");
        mu.unlock();

        indexOfBulletFollowX = x + 8 + i;     //To process conlision with enemy
        indexOfBulletFollowY = y + 2;  // To process conlision with enemy

        Sleep(150);

        mu.lock();
        Controller::gotoXY(x + 8 + i, y + 2);
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
                    enemy.sub_hp(1);
                    flag = true;
                    break;
                }
            }
        }
        mu_global2.unlock();

        if (flag) break;
    }
}
void Tower::drawTowerLevel1_Right(int x, int y, int colorFirst, int colorSecond)
{
    Controller::SetColor(colorFirst, colorSecond);
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"▓▓▓▓▓");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"▓▓▓▓▓");
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"▓▓▓▓▓");
    Controller::gotoXY(x + 5, y + 3);
    Screen::printVietnamese(L"===");

    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.
}
void Tower::tower_bullet_level1_Right(int x, int y, int x_end, int y_end)
{
    while (true)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel1_Right, &bullet, x, y, x_end, y_end);
        if (bullet_firt.joinable())
        {
            bullet_firt.join();
            Sleep(150);
        }
    }
}

void Bullet::wayBulletOfLevel1_Down(int x, int y, int x_end, int y_end)
{
    int i = 0;
    Controller::showCursor(false);
    while ((y + 6 + i) < y_end)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        mu.lock();
        Controller::gotoXY(x + 2, y + 6 + i);
        Screen::printVietnamese(L"v");
        mu.unlock();

        indexOfBulletFollowX = x + 2; // To process conlision with enemy
        indexOfBulletFollowY = y + 6 + i;  //To process conlision with enemy

        Sleep(150);

        mu.lock();
        Controller::gotoXY(x + 2, y + 6 + i);
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
                    enemy.sub_hp(1);
                    flag = true;
                    break;
                }
            }
        }
        mu_global2.unlock();

        if (flag) break;
    }
}
void Tower::drawTowerLevel1_Down(int x, int y, int colorFirst, int colorSecond)
{
    Controller::SetColor(colorFirst, colorSecond);
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"▓▓▓▓▓");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"▓▓▓▓▓");
    Controller::gotoXY(x + 2, y + 4);
    Screen::printVietnamese(L"▓");
    Controller::gotoXY(x + 2, y + 5);
    Screen::printVietnamese(L"▓");
    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.
}
void Tower::tower_bullet_level1_Down(int x, int y, int x_end, int y_end)
{
    while (true)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel1_Down, &bullet, x, y, x_end, y_end);
        if (bullet_firt.joinable())
        {
            bullet_firt.join();
            Sleep(150);
        }
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

        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        mu.lock();
        Controller::SetColor(0, 4);
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L"^");
        Controller::gotoXY(x + 4, y - 1 - i);
        Screen::printVietnamese(L"^");
        mu.unlock();

        indexOfBulletFollowX = x + 2; // To process conlision with enemy
        indexOfBulletFollowY = y - 1 - i;  //To process conlision with enemy

        Sleep(120);

        mu.lock();
        Controller::SetColor(0, 4);
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L" ");
        Controller::gotoXY(x + 4, y - 1 - i);
        Screen::printVietnamese(L" ");
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
    Screen::printVietnamese(L"▓");
    Controller::gotoXY(x + 4, y);
    Screen::printVietnamese(L"▓");
    Controller::gotoXY(x + 2, y + 1);
    Screen::printVietnamese(L"▓");
    Controller::gotoXY(x + 4, y + 1);
    Screen::printVietnamese(L"▓");
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"▓▓▓▓▓▓▓");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"▓▓▓▓▓▓▓");
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"▓▓▓▓▓▓▓");

    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.

}
void Tower::tower_bullet_level2_Up(int x, int y)
{
    while (true)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel2_Up, &bullet, x, y);
        if (bullet_firt.joinable())
        {
            bullet_firt.join();
            Sleep(120);
        }
    }
}

void Bullet::wayBulletOfLevel2_Left(int x, int y, int x_end, int y_end)
{
    Controller::showCursor(false);
    int newX = x, i = 0;
    //while (true)
    //{
    while ((x - 5 - i) > x_end)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

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
        Sleep(120);
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
void Tower::tower_bullet_level2_Left(int x, int y, int x_end, int y_end)
{
    while (true)
    {

        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel2_Left, &bullet, x, y, x_end, y_end);
        if (bullet_firt.joinable())
        {
            bullet_firt.join();
            Sleep(120);
        }
    }
}

void Bullet::wayBulletOfLevel2_Right(int x, int y, int x_end, int y_end)
{
    Controller::showCursor(false);
    int i = 0, a = 81;
    while ((x + 8 + i) < x_end)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

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

        Sleep(120);

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
void Tower::tower_bullet_level2_Right(int x, int y, int x_end, int y_end)
{
    while (true)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel2_Right, &bullet, x, y, x_end, y_end);

        if (bullet_firt.joinable())
        {
            bullet_firt.join();
            Sleep(120);
        }

        //if(bullet_firt.joinable())
        //{
        //    Controller::gotoXY(125, 32);
        //    cout << "hi";
        //    Sleep(3000);
        //}
    }
}

void Bullet::wayBulletOfLevel2_Down(int x, int y, int x_end, int y_end)
{
    int i = 0, a = 24;
    Controller::showCursor(false);
    while ((y + 6 + i) < y_end)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        mu.lock();
        Controller::gotoXY(x + 2, y + 6 + i);
        Screen::printVietnamese(L"v");
        Controller::gotoXY(x + 4, y + 6 + i);
        Screen::printVietnamese(L"v");
        mu.unlock();

        indexOfBulletFollowX = x + 2; // To process conlision with enemy
        indexOfBulletFollowY = y + 6 + i;  //To process conlision with enemy

        Sleep(120);

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
void Tower::drawTowerLevel2_Down(int x, int y, int colorFirst, int colorSecond)
{
    Controller::gotoXY(x + 2, y + 4);
    Controller::SetColor(colorFirst, colorSecond);
    Screen::printVietnamese(L"▓ ▓");
    Controller::gotoXY(x + 2, y + 5);
    Screen::printVietnamese(L"▓ ▓");
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"▓▓▓▓▓▓▓");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"▓▓▓▓▓▓▓");
    Controller::gotoXY(x, y + 1);
    Screen::printVietnamese(L"▓▓▓▓▓▓▓");

    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.

}
void Tower::tower_bullet_level2_Down(int x, int y, int x_end, int y_end)
{
    while (true)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel2_Down, &bullet, x, y, x_end, y_end);
        if (bullet_firt.joinable())
        {
            bullet_firt.join();
            Sleep(120);
        }
    }
}

void Bullet::wayBulletOfLevel3_Up(int x, int y)
{
    Controller::showCursor(false);
    int i = 0;
    while (y - 1 - i > 0)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

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
        Screen::printVietnamese(L" ");
        Controller::gotoXY(x + 4, y - 1 - i);
        Screen::printVietnamese(L" ");
        Controller::gotoXY(x + 6, y - 1 - i);
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
void Tower::drawTowerLevel3_Up(int x, int y, int colorFirst, int colorSecond)
{
    Controller::SetColor(colorFirst, colorSecond);
    Controller::gotoXY(x + 2, y);
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
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel3_Up, &bullet, x, y);
        if (bullet_firt.joinable())
        {
            bullet_firt.join();
            Sleep(100);
        }
    }
}

void Bullet::wayBulletOfLevel3_Left(int x, int y, int x_end, int y_end)
{
    Controller::showCursor(false);
    int i = 0;
    while ((x - 5 - i) > x_end)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        mu.lock();
        Controller::gotoXY(x - 5 - i, y + 4);
        Screen::printVietnamese(L"<");
        mu.unlock();
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
        Sleep(100);
        mu.lock();
        Controller::gotoXY(x - 5 - i, y + 4);
        Screen::printVietnamese(L" ");
        mu.unlock();
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
                if (get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 5)
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
void Tower::drawTowerLevel3_Left(int x, int y, int colorFirst, int colorSecond)
{
    Controller::SetColor(colorFirst, colorSecond);
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"█████");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"█████");
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"█████");
    Controller::gotoXY(x - 3, y + 2);
    Screen::printVietnamese(L"===");
    Controller::gotoXY(x - 3, y + 3);
    Screen::printVietnamese(L"===");
    Controller::gotoXY(x - 3, y + 4);
    Screen::printVietnamese(L"===");

    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.
}
void Tower::tower_bullet_level3_Left(int x, int y, int x_end, int y_end)
{
    while (true)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel3_Left, &bullet, x, y, x_end, y_end);
        if (bullet_firt.joinable())
        {
            bullet_firt.join();
            Sleep(100);
        }
    }
}

void Bullet::wayBulletOfLevel3_Right(int x, int y, int x_end, int y_end) 
{
    Controller::showCursor(false);
    int i = 0;
    while ((x + 8 + i) < x_end)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        mu.lock();
        Controller::gotoXY(x + 8 + i, y + 2);
        Screen::printVietnamese(L">");
        mu.unlock();
        mu.lock();
        Controller::gotoXY(x + 8 + i, y + 3);
        Screen::printVietnamese(L">");
        mu.unlock();
        mu.lock();
        Controller::gotoXY(x + 8 + i, y + 4);
        Screen::printVietnamese(L">");
        mu.unlock();
        indexOfBulletFollowX = x + 8 + i;     //To process conlision with enemy
        indexOfBulletFollowY = y + 2;  // To process conlision with enemy

        Sleep(100);

        mu.lock();
        Controller::gotoXY(x + 8 + i, y + 2);
        Screen::printVietnamese(L" ");
        mu.unlock();
        mu.lock();
        Controller::gotoXY(x + 8 + i, y + 3);
        Screen::printVietnamese(L" ");
        mu.unlock();
        mu.lock();
        Controller::gotoXY(x + 8 + i, y + 4);
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
void Tower::drawTowerLevel3_Right(int x, int y, int colorFirst, int colorSecond) 
{
    Controller::SetColor(colorFirst, colorSecond);
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"█████");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"█████");
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"█████");
    Controller::gotoXY(x + 5, y + 2);
    Screen::printVietnamese(L"===");
    Controller::gotoXY(x + 5, y + 3);
    Screen::printVietnamese(L"===");
    Controller::gotoXY(x + 5, y + 4);
    Screen::printVietnamese(L"===");

    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME..
}
void Tower::tower_bullet_level3_Right(int x, int y, int x_end, int y_end) 
{
    while (true)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel3_Right, &bullet, x, y, x_end, y_end);
        if (bullet_firt.joinable())
        {
            bullet_firt.join();
            Sleep(100);
        }
    }
}

void Bullet::wayBulletOfLevel3_Down(int x, int y, int x_end, int y_end) 
{
    int i = 0;
    Controller::showCursor(false);
    while ((y + 6 + i) < y_end)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        mu.lock();
        Controller::gotoXY(x + 2, y + 6 + i);
        Screen::printVietnamese(L"v");
        mu.unlock();
        mu.lock();
        Controller::gotoXY(x + 4, y + 6 + i);
        Screen::printVietnamese(L"v");
        mu.unlock();
        mu.lock();
        Controller::gotoXY(x + 6, y + 6 + i);
        Screen::printVietnamese(L"v");
        mu.unlock();

        indexOfBulletFollowX = x + 2; // To process conlision with enemy
        indexOfBulletFollowY = y + 6 + i;  //To process conlision with enemy

        Sleep(100);

        mu.lock();
        Controller::gotoXY(x + 2, y + 6 + i);
        Screen::printVietnamese(L" ");
        mu.unlock();
        mu.lock();
        Controller::gotoXY(x + 4, y + 6 + i);
        Screen::printVietnamese(L" ");
        mu.unlock();
        mu.lock();
        Controller::gotoXY(x + 6, y + 6 + i);
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
void Tower::drawTowerLevel3_Down(int x, int y, int colorFirst, int colorSecond) 
{
    Controller::SetColor(colorFirst, colorSecond);
    Controller::gotoXY(x, y + 1);
    Screen::printVietnamese(L"█████████");
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"█████████");
    Controller::gotoXY(x , y + 3);
    Screen::printVietnamese(L"█████████");
    Controller::gotoXY(x + 2, y + 4);
    Screen::printVietnamese(L"▓ ▓ ▓");
    Controller::gotoXY(x + 2, y +  5);
    Screen::printVietnamese(L"▓ ▓ ▓");

    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.
    cout << "\n\n\n\n";
}
void Tower::tower_bullet_level3_Down(int x, int y, int x_end, int y_end) 
{
    while (true)
    {
        bool check;
        mu.lock();
        check = ingame;
        mu.unlock();
        if (check == false)
        {
            break;
        }

        Bullet bullet;
        thread bullet_firt(&Bullet::wayBulletOfLevel3_Down, &bullet, x, y, x_end, y_end);
        if (bullet_firt.joinable())
        {
            bullet_firt.join();
            Sleep(100);
        }
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

void Tower::draw_tower(int bcolor, int color) {
    if (level == 1) {
        if (dir == 1) drawTowerLevel1_Up(x, y, bcolor, color);
        else if (dir == 2) drawTowerLevel1_Left(x, y, bcolor, color);
        else if (dir == 3) drawTowerLevel1_Down(x, y, bcolor, color);
        else if (dir == 4) drawTowerLevel1_Right(x, y, bcolor, color);
    }
    else if (level == 2) {
        if (dir == 1) drawTowerLevel2_Up(x, y, bcolor, color);
        else if (dir == 2) drawTowerLevel2_Left(x, y, bcolor, color);
        else if (dir == 3) drawTowerLevel2_Down(x, y, bcolor, color);
        else if (dir == 4) drawTowerLevel2_Right(x, y, bcolor, color);
    }
    else if (level == 3) {
        if (dir == 1) drawTowerLevel3_Up(x, y, bcolor, color);
        else if (dir == 2) drawTowerLevel3_Left(x, y, bcolor, color);
        else if (dir == 3) drawTowerLevel3_Down(x, y, bcolor, color);
        else if (dir == 4) drawTowerLevel3_Right(x, y, bcolor, color);
    }
}

void Tower::tower_bullet() {
    int denta_x = 40;
    int denta_y = 15;
    if (level == 1) {
        if (dir == 1) tower_bullet_level1_Up(x, y);
        else if (dir == 2) tower_bullet_level1_Left(x, y, x - denta_x, y);
        else if (dir == 3) tower_bullet_level1_Down(x, y, x, y + denta_y);
        else if (dir == 4) tower_bullet_level1_Right(x, y, x + denta_x, y);
    }
    else if (level == 2) {
        if (dir == 1) tower_bullet_level2_Up(x, y);
        else if (dir == 2) tower_bullet_level2_Left(x, y, x - denta_x, y);
        else if (dir == 3) tower_bullet_level2_Down(x, y, x, y + denta_y);
        else if (dir == 4) tower_bullet_level2_Right(x, y, x + denta_x, y);
    }
    else if (level == 3) {
        if (dir == 1) tower_bullet_level3_Up(x, y);
        else if (dir == 2) tower_bullet_level3_Left(x, y, x - denta_x, y);
        else if (dir == 3) tower_bullet_level3_Down(x, y, x, y + denta_y);
        else if (dir == 4) tower_bullet_level3_Right(x, y, x + denta_x, y);
    }
}