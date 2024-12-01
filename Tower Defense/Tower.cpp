#include "Tower.h"
#include "Controller.h"
#include "Library.h"
#include "Game.h"
#include <mutex>

mutex mu_global2;
void Bullet::wayBulletOfLevel1_Up(int x, int y, int x_end, int y_end)
{
    int i = 0;
    while (y - 1 - i > y_end)
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

        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }


        mu.lock();
        Controller::gotoXY(x + 3, y - 1 - i);
        Controller::SetColor(LIGHT_YELLOW, RED);
        Screen::printVietnamese(L"■");
        //cout <<" " << indexOfBulletFollowX << "," << indexOfBulletFollowY;
        mu.unlock();

        indexOfBulletFollowX = x + 2;      //To process conlision with enemy
        indexOfBulletFollowY = y - 1 - i;  // To process conlision with enemy

        Sleep(150);

        mu.lock();
        Controller::gotoXY(x + 3, y - 1 - i);
        Controller::SetColor(LIGHT_YELLOW, LIGHT_YELLOW);
        cout << " ";
        mu.unlock();

        i += 1;
        bool flag = false;

        mu_global2.lock();
        for (auto& enemy : e_global)  // Duyệt qua danh sách các enemy
        {
            if (enemy.get_hp() > 0)
            {
                if (Enemy::get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 5)
                {
                    if (Menu::sound_is_open)
                        thread(Controller::playSound, DIE_SOUND).detach();
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
    //Controller::gotoXY(x + 2, y);
    //Controller::SetColor(colorFirst, colorSecond);
    //Screen::printVietnamese(L"▓");
    //Controller::gotoXY(x + 2, y + 1);
    //Screen::printVietnamese(L"▓");
    //Controller::gotoXY(x, y + 2);
    //Screen::printVietnamese(L"▓▓▓▓▓");
    //Controller::gotoXY(x, y + 3);
    //Screen::printVietnamese(L"▓▓▓▓▓");

    //╔╦╦▐╦╦╦╗
    //╠▓▄▐ ▄▓╣
    //╠▓████▓╣
    //╠▓████▓╣
    //╚╩╩╩╩╩╩╝

    Controller::SetColor(colorFirst, colorSecond);
    Controller::gotoXY(x, y);
    Screen::printVietnamese(L"╔╦╦▐╦╦╦╗");
    Controller::gotoXY(x, y + 1);
    Screen::printVietnamese(L"╠▓▄▐ ▄▓╣");    // 3 
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"╠▓████▓╣"); // 5
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"╠▓████▓╣"); // 9
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"╚╩╩╩╩╩╩╝");

    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.

}
void Tower::tower_bullet_level1_Up(int x, int y, int x_end, int y_end)
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

        mu.lock();
        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }

        vector<Bullet> magazine(5);
        vector<thread> t_bullet;
        for (int i = 0; i < 5; i++) {
            t_bullet.push_back(thread(&Bullet::wayBulletOfLevel1_Up, &magazine[i], x, y, x_end, y_end));
            Sleep(1500);
        }
        
        for (int i = 0; i < 5; i++) {
            if (t_bullet[i].joinable())
            {
                t_bullet[i].join();
            }
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
        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }
        mu.lock();

        Controller::gotoXY(x - 5 - i, y + 2);
        Controller::SetColor(LIGHT_YELLOW, RED);
        Screen::printVietnamese(L"■");
        mu.unlock();
        indexOfBulletFollowX = x - 5 - i;      //To process conlision with enemy
        indexOfBulletFollowY = y + 2;  // To process conlision with enemy
        Sleep(150);
        mu.lock();
        Controller::gotoXY(x - 5 - i, y + 2);
        Controller::SetColor(LIGHT_YELLOW, LIGHT_YELLOW);
        Screen::printVietnamese(L" ");
        mu.unlock();
        i += 1;

        bool flag = false;

        mu_global2.lock();
        for (auto& enemy : e_global)  // Duyệt qua danh sách các enemy
        {
            if (enemy.get_hp() > 0)
            {
                if (Enemy::get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 5)
                {
                    if (Menu::sound_is_open)
                        thread(Controller::playSound, DIE_SOUND).detach();
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
    /*Controller::SetColor(colorFirst, colorSecond);

    Controller::gotoXY(x + 3, y + 2);
    Screen::printVietnamese(L"▓▓▓▓▓");
    Controller::gotoXY(x + 3, y + 3);
    Screen::printVietnamese(L"▓▓▓▓▓");
    Controller::gotoXY(x + 3, y + 4);
    Screen::printVietnamese(L"▓▓▓▓▓");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"▓▓▓");*/

   // ╔╦╦╦╦╦╗
   // ╠▓▄▄▄▄╣
   //■■■■███╣
   // ╠▓▀▀▀▀╣
   // ╚╩╩╩╩╩╝

    Controller::SetColor(colorFirst, colorSecond);

    Controller::gotoXY(x + 1, y);
    Screen::printVietnamese(L"╔╦╦╦╦╦╗");
    Controller::gotoXY(x + 1, y + 1);
    Screen::printVietnamese(L"╠▓▄▄▄▄╣");
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"■■■■███╣");
    Controller::gotoXY(x + 1, y + 3);
    Screen::printVietnamese(L"╠▓▀▀▀▀╣");
    Controller::gotoXY(x + 1, y + 4);
    Screen::printVietnamese(L"╚╩╩╩╩╩╝");


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
        mu.lock();
        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }

        vector<Bullet> magazine(5);
        vector<thread> t_bullet;
        for (int i = 0; i < 5; i++) {
            t_bullet.push_back(thread(&Bullet::wayBulletOfLevel1_Left, &magazine[i], x, y, x_end, y_end));
            Sleep(3000);
        }

        for (int i = 0; i < 5; i++) {
            if (t_bullet[i].joinable())
            {
                t_bullet[i].join();
            }
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
        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }

        mu.lock();
        Controller::gotoXY(x + 8 + i, y + 2);
        Controller::SetColor(LIGHT_YELLOW, RED);
        Screen::printVietnamese(L"■");
        mu.unlock();

        indexOfBulletFollowX = x + 8 + i;     //To process conlision with enemy
        indexOfBulletFollowY = y + 2;  // To process conlision with enemy

        Sleep(150);

        mu.lock();
        Controller::gotoXY(x + 8 + i, y + 2);
        Controller::SetColor(LIGHT_YELLOW, LIGHT_YELLOW);
        cout << " ";
        mu.unlock();
        i += 1;

        bool flag = false;

        mu_global2.lock();
        for (auto& enemy : e_global)  // Duyệt qua danh sách các enemy
        {
            if (enemy.get_hp() > 0)
            {
                if (Enemy::get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 6)
                {
                    if (Menu::sound_is_open)
                        thread(Controller::playSound, DIE_SOUND).detach();
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
    //Controller::SetColor(colorFirst, colorSecond);
    //Controller::gotoXY(x, y + 2);
    //Screen::printVietnamese(L"▓▓▓▓▓");
    //Controller::gotoXY(x, y + 3);
    //Screen::printVietnamese(L"▓▓▓▓▓");
    //Controller::gotoXY(x, y + 4);
    //Screen::printVietnamese(L"▓▓▓▓▓");
    //Controller::gotoXY(x + 5, y + 3);
    //Screen::printVietnamese(L"===");

    //╔╦╦╦╦╦╗
    //╠▓▄▄▄▄╣
    //╠▓██■■■■
    //╠▓▀▀▀▀╣
    //╚╩╩╩╩╩╝

    Controller::SetColor(colorFirst, colorSecond);

    Controller::gotoXY(x, y);
    Screen::printVietnamese(L"╔╦╦╦╦╦╗");
    Controller::gotoXY(x, y + 1);
    Screen::printVietnamese(L"╠▓▄▄▄▄╣");
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"╠▓██■■■■");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"╠▓▀▀▀▀╣");
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"╚╩╩╩╩╩╝");

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
        mu.lock();
        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }

        vector<Bullet> magazine(5);
        vector<thread> t_bullet;
        for (int i = 0; i < 5; i++) {
            t_bullet.push_back(thread(&Bullet::wayBulletOfLevel1_Right, &magazine[i], x, y, x_end, y_end));
            Sleep(3000);
        }

        for (int i = 0; i < 5; i++) {
            if (t_bullet[i].joinable())
            {
                t_bullet[i].join();
            }
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
        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }


        mu.lock();
        Controller::gotoXY(x + 3, y + 6 + i);
        Controller::SetColor(LIGHT_YELLOW, RED);
        Screen::printVietnamese(L"■");
        mu.unlock();

        indexOfBulletFollowX = x + 2; // To process conlision with enemy
        indexOfBulletFollowY = y + 6 + i;  //To process conlision with enemy

        Sleep(150);

        mu.lock();
        Controller::gotoXY(x + 3, y + 6 + i);
        Controller::SetColor(LIGHT_YELLOW, LIGHT_YELLOW);
        Screen::printVietnamese(L" ");
        mu.unlock();
        i += 1;

        bool flag = false;

        mu_global2.lock();
        for (auto& enemy : e_global)  // Duyệt qua danh sách các enemy
        {
            if (enemy.get_hp() > 0)
            {
                if (Enemy::get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 6)
                {
                    if (Menu::sound_is_open)
                        thread(Controller::playSound, DIE_SOUND).detach();
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
    //╔╦╦╦╦╦╦╗
    //╠▓████▓╣
    //╠▓████▓╣
    //╠▓▀▐ ▀▓╣
    //╚╩╩▐╩╩╩╝

    Controller::SetColor(colorFirst, colorSecond);
    Controller::gotoXY(x, y);
    Screen::printVietnamese(L"╔╦╦╦╦╦╦╗");
    Controller::gotoXY(x, y + 1);
    Screen::printVietnamese(L"╠▓████▓╣");    // 3 
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"╠▓████▓╣"); // 5
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"╠▓▀▐ ▀▓╣"); // 5
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"╚╩╩▐╩╩╩╝"); // 9
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
        mu.lock();
        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }

        vector<Bullet> magazine(5);
        vector<thread> t_bullet;
        for (int i = 0; i < 5; i++) {
            t_bullet.push_back(thread(&Bullet::wayBulletOfLevel1_Down, &magazine[i], x, y, x_end, y_end));
            Sleep(1500);
        }

        for (int i = 0; i < 5; i++) {
            if (t_bullet[i].joinable())
            {
                t_bullet[i].join();
            }
        }
    }
}

void Bullet::wayBulletOfLevel2_Up(int x, int y, int x_end, int y_end)
{
    mu.lock();
    int i = 0;
    mu.unlock();
    while (y - 1 - i > y_end)
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

        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }


        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, RED);
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L"■");
        Controller::gotoXY(x + 4, y - 1 - i);
        Screen::printVietnamese(L"■");
        mu.unlock();

        indexOfBulletFollowX = x + 2; // To process conlision with enemy
        indexOfBulletFollowY = y - 1 - i;  //To process conlision with enemy

        Sleep(120);

        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, LIGHT_YELLOW);
        Controller::gotoXY(x + 2, y - 1 - i);
        cout << " ";
        Controller::gotoXY(x + 4, y - 1 - i);
        cout << " ";
        i += 1;
        mu.unlock();


        bool flag = false;

        mu_global2.lock();
        for (auto& enemy : e_global)  // Duyệt qua danh sách các enemy
        {
            if (enemy.get_hp() > 0)
            {
                if (Enemy::get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 5)
                {
                    if (Menu::sound_is_open)
                        thread(Controller::playSound, DIE_SOUND).detach();
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
    //  ▐ ▐
    //╔╦▐╦▐╦╦╗
    //╠██████╣
    //╠██████╣
    //╚╩╩╩╩╩╩╝
    Controller::SetColor(colorFirst, colorSecond);
    Controller::gotoXY(x, y);
    Screen::printVietnamese(L"  ▐ ▐");
    Controller::gotoXY(x, y + 1);
    Screen::printVietnamese(L"╔╦▐╦▐╦╦╗");
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"╠██████╣");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"╠██████╣");
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"╚╩╩╩╩╩╩╝");

    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.

}
void Tower::tower_bullet_level2_Up(int x, int y, int x_end, int y_end)
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

        mu.lock();

        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }

        vector<Bullet> magazine(5);
        vector<thread> t_bullet;
        for (int i = 0; i < 5; i++) {
            t_bullet.push_back(thread(&Bullet::wayBulletOfLevel2_Up, &magazine[i], x, y, x_end, y_end));
            Sleep(1500);
        }

        for (int i = 0; i < 5; i++) {
            if (t_bullet[i].joinable())
            {
                t_bullet[i].join();
            }
        }
    }
}

void Bullet::wayBulletOfLevel2_Left(int x, int y, int x_end, int y_end)
{
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

        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }


        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, RED);
        Controller::gotoXY(x - 5 - i, y + 3);
        Screen::printVietnamese(L"■");
        mu.unlock();
        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, RED);
        Controller::gotoXY(x - 5 - i, y + 2);
        Screen::printVietnamese(L"■");
        mu.unlock();
        indexOfBulletFollowX = x - 5 - i;      //To process conlision with enemy
        indexOfBulletFollowY = y + 2;  // To process conlision with enemy
        Sleep(120);
        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, LIGHT_YELLOW);
        Controller::gotoXY(x - 5 - i, y + 3);
        Screen::printVietnamese(L" ");
        mu.unlock();
        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, LIGHT_YELLOW);
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
                if (Enemy::get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 5)
                {
                    if (Menu::sound_is_open)
                        thread(Controller::playSound, DIE_SOUND).detach();
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
  //  ╔╦╦╦╦╗
  //▄▄▄████╣
  //  ╠████╣
  //▀▀▀████╣
  //  ╚╩╩╩╩╝
    Controller::SetColor(colorFirst, colorSecond);
    Controller::gotoXY(x, y);
    Screen::printVietnamese(L"  ╔╦╦╦╦╗");
    Controller::gotoXY(x, y + 1);
    Screen::printVietnamese(L"▄▄▄████╣");
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"  ╠████╣");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"▀▀▀████╣");
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"  ╚╩╩╩╩╝");

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

        mu.lock();

        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }

        vector<Bullet> magazine(5);
        vector<thread> t_bullet;
        for (int i = 0; i < 5; i++) {
            t_bullet.push_back(thread(&Bullet::wayBulletOfLevel2_Left, &magazine[i], x, y, x_end, y_end));
            Sleep(3000);
        }

        for (int i = 0; i < 5; i++) {
            if (t_bullet[i].joinable())
            {
                t_bullet[i].join();
            }
        }
    }
}

void Bullet::wayBulletOfLevel2_Right(int x, int y, int x_end, int y_end)
{
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

        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }


        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, RED);
        Controller::gotoXY(x + 8 + i, y + 2);
        Screen::printVietnamese(L"■");
        mu.unlock();
        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, RED);
        Controller::gotoXY(x + 8 + i, y + 3);
        Screen::printVietnamese(L"■");
        mu.unlock();

        indexOfBulletFollowX = x + 8 + i;     //To process conlision with enemy
        indexOfBulletFollowY = y + 2;  // To process conlision with enemy

        Sleep(120);

        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, LIGHT_YELLOW);
        Controller::gotoXY(x + 8 + i, y + 2);
        Screen::printVietnamese(L" ");
        mu.unlock();
        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, LIGHT_YELLOW);
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
                if (Enemy::get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 6)
                {
                    if (Menu::sound_is_open)
                        thread(Controller::playSound, DIE_SOUND).detach();
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
  //  ╔╦╦╦╦╗
  //▄▄▄████╣
  //  ╠████╣
  //▀▀▀████╣
  //  ╚╩╩╩╩╝
    Controller::SetColor(colorFirst, colorSecond);
    Controller::gotoXY(x, y);
    Screen::printVietnamese(L"  ╔╦╦╦╦╗");
    Controller::gotoXY(x, y + 1);
    Screen::printVietnamese(L"▄▄▄████╣");


    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"  ╠████╣");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"▀▀▀████╣");

    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"  ╚╩╩╩╩╝");

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

        mu.lock();

        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }

        vector<Bullet> magazine(5);
        vector<thread> t_bullet;
        for (int i = 0; i < 5; i++) {
            t_bullet.push_back(thread(&Bullet::wayBulletOfLevel2_Right, &magazine[i], x, y, x_end, y_end));
            Sleep(3000);
        }

        for (int i = 0; i < 5; i++) {
            if (t_bullet[i].joinable())
            {
                t_bullet[i].join();
            }
        }
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

        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }


        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, RED);
        Controller::gotoXY(x + 2, y + 6 + i);
        Screen::printVietnamese(L"■");
        Controller::gotoXY(x + 4, y + 6 + i);
        Screen::printVietnamese(L"■");
        mu.unlock();

        indexOfBulletFollowX = x + 2; // To process conlision with enemy
        indexOfBulletFollowY = y + 6 + i;  //To process conlision with enemy

        Sleep(120);

        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, LIGHT_YELLOW);
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
                if (Enemy::get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 6)
                {
                    if (Menu::sound_is_open)
                        thread(Controller::playSound, DIE_SOUND).detach();
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
    //╔╦╦╦╦╦╦╗
    //╠██████╣
    //╠██████╣
    //╚╩╩▌▐╩╩╝
    //   ▌▐
    Controller::SetColor(colorFirst, colorSecond);
    Controller::gotoXY(x, y);
    Screen::printVietnamese(L"╔╦╦╦╦╦╦╗");
    Controller::gotoXY(x, y + 1);
    Screen::printVietnamese(L"╠██████╣");
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"╠██████╣");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"╚╩╩▌▐╩╩╝");
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"   ▌▐");

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

        mu.lock();

        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }

        vector<Bullet> magazine(5);
        vector<thread> t_bullet;
        for (int i = 0; i < 5; i++) {
            t_bullet.push_back(thread(&Bullet::wayBulletOfLevel2_Down, &magazine[i], x, y, x_end, y_end));
            Sleep(1500);
        }

        for (int i = 0; i < 5; i++) {
            if (t_bullet[i].joinable())
            {
                t_bullet[i].join();
            }
        }
    }
}

void Bullet::wayBulletOfLevel3_Up(int x, int y, int x_end, int y_end)
{
    Controller::showCursor(false);
    int i = 0;
    while (y - 1 - i > y_end)
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

        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }


        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, RED);
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L"■");
        Controller::gotoXY(x + 4, y - 1 - i);
        Screen::printVietnamese(L"■");
        Controller::gotoXY(x + 6, y - 1 - i);
        Screen::printVietnamese(L"■");
        indexOfBulletFollowX = x + 2; // To process conlision with enemy
        indexOfBulletFollowY = y - 1 - i; // To process conlision with enemy
        mu.unlock();
        Sleep(100);

        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, LIGHT_YELLOW);
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
                if (Enemy::get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 6)
                {
                    if (Menu::sound_is_open)
                        thread(Controller::playSound, DIE_SOUND).detach();
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
    //  ▌▐▌▐
    //╔╦▌▐▌▐╦╗
    //╠██████╣
    //╠██████╣
    //╚╩╩╩╩╩╩╝
    Controller::SetColor(colorFirst, colorSecond);
    Controller::gotoXY(x, y);
    Screen::printVietnamese(L"  ▌▐▌▐");
    Controller::gotoXY(x, y + 1);
    Screen::printVietnamese(L"╔╦▌▐▌▐╦╗");
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"╠██████╣");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"╠██████╣");
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"╚╩╩╩╩╩╩╝");

    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.
}
void Tower::tower_bullet_level3_Up(int x, int y, int x_end, int y_end)
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

        mu.lock();

        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }

        vector<Bullet> magazine(5);
        vector<thread> t_bullet;
        for (int i = 0; i < 5; i++) {
            t_bullet.push_back(thread(&Bullet::wayBulletOfLevel3_Up, &magazine[i], x, y, x_end, y_end));
            Sleep(1500);
        }

        for (int i = 0; i < 5; i++) {
            if (t_bullet[i].joinable())
            {
                t_bullet[i].join();
            }
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

        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }


        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, RED);
        Controller::gotoXY(x - 5 - i, y + 4);
        Screen::printVietnamese(L"■");
        mu.unlock();
        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, RED);
        Controller::gotoXY(x - 5 - i, y + 3);
        Screen::printVietnamese(L"■");
        mu.unlock();
        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, RED);
        Controller::gotoXY(x - 5 - i, y + 2);
        Screen::printVietnamese(L"■");
        mu.unlock();
        indexOfBulletFollowX = x - 5 - i;      //To process conlision with enemy
        indexOfBulletFollowY = y + 2;  // To process conlision with enemy
        Sleep(100);
        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, LIGHT_YELLOW);
        Controller::gotoXY(x - 5 - i, y + 4);
        Screen::printVietnamese(L" ");
        mu.unlock();
        mu.lock();
        //Controller::SetColor(14, BLACK);
        Controller::gotoXY(x - 5 - i, y + 3);
        Screen::printVietnamese(L" ");
        mu.unlock();
        mu.lock();
        //Controller::SetColor(14, BLACK);
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
                if (Enemy::get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 5)
                {
                    if (Menu::sound_is_open)
                        thread(Controller::playSound, DIE_SOUND).detach();
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
  //  ╔╦╦╦╦╗
  //▄▄▄████╣
  //■■■████╣
  //▀▀▀████╣
  //  ╚╩╩╩╩╝
    Controller::SetColor(colorFirst, colorSecond);
    Controller::gotoXY(x, y);
    Screen::printVietnamese(L"  ╔╦╦╦╦╗");
    Controller::gotoXY(x, y + 1);
    Screen::printVietnamese(L"▄▄▄████╣");
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"■■■████╣");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"▀▀▀████╣");
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"  ╚╩╩╩╩╝");

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

        mu.lock();

        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }

        vector<Bullet> magazine(5);
        vector<thread> t_bullet;
        for (int i = 0; i < 5; i++) {
            t_bullet.push_back(thread(&Bullet::wayBulletOfLevel3_Left, &magazine[i], x, y, x_end, y_end));
            Sleep(3000);
        }

        for (int i = 0; i < 5; i++) {
            if (t_bullet[i].joinable())
            {
                t_bullet[i].join();
            }
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

        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }


        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, RED);
        Controller::gotoXY(x + 8 + i, y + 2);
        Screen::printVietnamese(L"■");
        mu.unlock();
        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, RED);
        Controller::gotoXY(x + 8 + i, y + 3);
        Screen::printVietnamese(L"■");
        mu.unlock();
        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, RED);
        Controller::gotoXY(x + 8 + i, y + 4);
        Screen::printVietnamese(L"■");
        mu.unlock();
        indexOfBulletFollowX = x + 8 + i;     //To process conlision with enemy
        indexOfBulletFollowY = y + 2;  // To process conlision with enemy

        Sleep(100);

        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, LIGHT_YELLOW);
        Controller::gotoXY(x + 8 + i, y + 2);
        Screen::printVietnamese(L" ");
        mu.unlock();
        mu.lock();
        Controller::SetColor(14, BLACK);
        Controller::gotoXY(x + 8 + i, y + 3);
        Screen::printVietnamese(L" ");
        mu.unlock();
        mu.lock();
        Controller::SetColor(14, BLACK);
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
                if (Enemy::get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 6)
                {
                    if (Menu::sound_is_open)
                        thread(Controller::playSound, DIE_SOUND).detach();
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
    //╔╦╦╦╦╗
    //╠████▄▄▄
    //╠████■■■
    //╠████▀▀▀
    //╚╩╩╩╩╝
    Controller::SetColor(colorFirst, colorSecond);
    Controller::gotoXY(x, y);
    Screen::printVietnamese(L"╔╦╦╦╦╗");
    Controller::gotoXY(x, y + 1);
    Screen::printVietnamese(L"╠████▄▄▄");
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"╠████■■■");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"╠████▀▀▀");
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"╚╩╩╩╩╝");

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

        mu.lock();

        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }

        vector<Bullet> magazine(5);
        vector<thread> t_bullet;
        for (int i = 0; i < 5; i++) {
            t_bullet.push_back(thread(&Bullet::wayBulletOfLevel3_Right, &magazine[i], x, y, x_end, y_end));
            Sleep(3000);
        }

        for (int i = 0; i < 5; i++) {
            if (t_bullet[i].joinable())
            {
                t_bullet[i].join();
            }
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

        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }


        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, RED);
        Controller::gotoXY(x + 2, y + 6 + i);
        Screen::printVietnamese(L"■");
        mu.unlock();
        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, RED);
        Controller::gotoXY(x + 4, y + 6 + i);
        Screen::printVietnamese(L"■");
        mu.unlock();
        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, RED);
        Controller::gotoXY(x + 6, y + 6 + i);
        Screen::printVietnamese(L"■");
        mu.unlock();

        indexOfBulletFollowX = x + 2; // To process conlision with enemy
        indexOfBulletFollowY = y + 6 + i;  //To process conlision with enemy

        Sleep(100);

        mu.lock();
        Controller::SetColor(LIGHT_YELLOW, LIGHT_YELLOW);
        Controller::gotoXY(x + 2, y + 6 + i);
        Screen::printVietnamese(L" ");
        mu.unlock();
        mu.lock();
        //Controller::SetColor(14, BLACK);
        Controller::gotoXY(x + 4, y + 6 + i);
        Screen::printVietnamese(L" ");
        mu.unlock();
        mu.lock();
        //Controller::SetColor(14, BLACK);
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
                if (Enemy::get_distance(indexOfBulletFollowX, indexOfBulletFollowY, enemy.get_x(), enemy.get_y()) <= 6)
                {
                    if (Menu::sound_is_open)
                        thread(Controller::playSound, DIE_SOUND).detach();
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
    //╔╦╦╦╦╦╦╗
    //╠██████╣
    //╠██████╣
    //╚╩▌▐▌▐╩╝
    //  ▌▐▌▐
    Controller::SetColor(colorFirst, colorSecond);
    Controller::gotoXY(x, y);
    Screen::printVietnamese(L"╔╦╦╦╦╦╦╗");
    Controller::gotoXY(x, y + 1);
    Screen::printVietnamese(L"╠██████╣");
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"╠██████╣");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"╚╩▌▐▌▐╩╝");
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"  ▌▐▌▐");

    indexOfTowerFollowX = x; // To process LOAD GAME.
    indexOfTowerFollowY = y; // To process LOAD GAME.
    //cout << "\n\n\n\n";
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

        mu.lock();

        bool isPause = Game::isPause;
        mu.unlock();

        if (isPause) {
            continue;
        }

        vector<Bullet> magazine(5);
        vector<thread> t_bullet;
        for (int i = 0; i < 5; i++) {
            t_bullet.push_back(thread(&Bullet::wayBulletOfLevel3_Down, &magazine[i], x, y, x_end, y_end));
            Sleep(1500);
        }

        for (int i = 0; i < 5; i++) {
            if (t_bullet[i].joinable())
            {
                t_bullet[i].join();
            }
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