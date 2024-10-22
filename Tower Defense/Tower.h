#pragma once
#include "Cell.h"
#include "Controller.h"
#include  "Library.h"
#include "Enemy.h"

using namespace std;

class Bullet
{
private:
    int indexOfBulletFollowX;
    int indexOfBulletFollowY;
public:
    void wayBulletOfLevel1_Up(int x, int y);
    void wayBulletOfLevel2_Up(int x, int y);
    void wayBulletOfLevel3_Up(int x, int y);
    int getIndexOfBulletFollowX();
    int getIndexOfBulletFollowY();

    void wayBulletOfLevel2_Left(int x, int y, int x_end, int y_end);
    void wayBulletOfLevel2_Right(int x, int y, int x_end, int y_end);
    void wayBulletOfLevel2_Down(int x, int y,int x_end,int y_end);
};

class Tower : public Bullet
{
private:
    int dame;
    int numberOfBullet;
    int indexOfTowerFollowX;
    int indexOfTowerFollowY;

    int level;
public:
    int getLevel();
    void setLevel(int level);

    void drawTowerLevel1_Up(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level1_Up(int x, int y);
    void drawTowerLevel2_Up(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level2_Up(int x, int y);
    void drawTowerLevel3_Up(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level3_Up(int x, int y);

    int getIndexOfTowerFollowX();
    int getIndexOfTowerFollowY();

    void drawTowerLevel2_Left(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level2_Left(int x, int y, int x_end, int y_end);
    void drawTowerLevel2_Right(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level2_Right(int x, int y, int x_end, int y_end);
    void drawTowerLevel2_Down(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level2_Down(int x, int y,int x_end,int y_end);

    void draw_tower(int x, int y, int x_end, int y_end);

};