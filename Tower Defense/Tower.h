
#pragma once
#include "Cell.h"
#include "Controller.h"
#include  "Library.h"
#include "Enemy.h"
#include "Point.h"

using namespace std;

class Bullet
{
private:
    int indexOfBulletFollowX;
    int indexOfBulletFollowY;
public:
    void wayBulletOfLevel1_Up(int x, int y, int x_end, int y_end);
    void wayBulletOfLevel1_Left(int x, int y, int x_end, int y_end);
    void wayBulletOfLevel1_Right(int x, int y, int x_end, int y_end);
    void wayBulletOfLevel1_Down(int x, int y, int x_end, int y_end);

    void wayBulletOfLevel3_Up(int x, int y, int x_end, int y_end);
    void wayBulletOfLevel3_Left(int x, int y, int x_end, int y_end);
    void wayBulletOfLevel3_Right(int x, int y, int x_end, int y_end);
    void wayBulletOfLevel3_Down(int x, int y, int x_end, int y_end);

    void wayBulletOfLevel2_Up(int x, int y, int x_end, int y_end);
    void wayBulletOfLevel2_Left(int x, int y, int x_end, int y_end);
    void wayBulletOfLevel2_Right(int x, int y, int x_end, int y_end);
    void wayBulletOfLevel2_Down(int x, int y, int x_end, int y_end);

    int getIndexOfBulletFollowX();
    int getIndexOfBulletFollowY();
};

class Tower : public Bullet
{
private:
    int dame;
    int numberOfBullet;
    int indexOfTowerFollowX;
    int indexOfTowerFollowY;

    int level;
    int dir; // dir: direction chiều, hướng, 1: up; 2: left; 3: down; 4: right
    /*Point pos;*/
    int x;
    int y;
    int price;
public:
    Tower() {

    }
    Tower(const Tower& t) {
        dame = t.dame;
        numberOfBullet = t.numberOfBullet;
        indexOfTowerFollowX = t.indexOfTowerFollowX;
        indexOfTowerFollowY = t.indexOfTowerFollowY;
        level = t.level;
        dir = t.dir;
        x = t.x;
        y = t.y;
    }

    void setPos(int x, int y);
    int getX();
    int getY();
    int getLevel();
    int getDir();
    int getPrice();
    void setLevel(int level);
    void setDir(int dir);

    void drawTowerLevel1_Up(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level1_Up(int x, int y, int x_end, int y_end);
    void drawTowerLevel1_Left(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level1_Left(int x, int y, int x_end, int y_end);
    void drawTowerLevel1_Right(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level1_Right(int x, int y, int x_end, int y_end);
    void drawTowerLevel1_Down(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level1_Down(int x, int y, int x_end, int y_end);

    void drawTowerLevel3_Up(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level3_Up(int x, int y, int x_end, int y_end);
    void drawTowerLevel3_Left(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level3_Left(int x, int y, int x_end, int y_end);
    void drawTowerLevel3_Right(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level3_Right(int x, int y, int x_end, int y_end);
    void drawTowerLevel3_Down(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level3_Down(int x, int y, int x_end, int y_end);

    void drawTowerLevel2_Up(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level2_Up(int x, int y, int x_end, int y_end);
    void drawTowerLevel2_Left(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level2_Left(int x, int y, int x_end, int y_end);
    void drawTowerLevel2_Right(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level2_Right(int x, int y, int x_end, int y_end);
    void drawTowerLevel2_Down(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level2_Down(int x, int y, int x_end, int y_end);

    int getIndexOfTowerFollowX();
    int getIndexOfTowerFollowY();

    void draw_tower(int bcolor, int color);
    void tower_bullet();
};