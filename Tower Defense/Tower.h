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
    void wayBulletOfLevel1(int x, int y);
    void wayBulletOfLevel2(int x, int y);
    void wayBulletOfLevel3(int x, int y);
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
public:
    void drawTowerLevel1(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level1(int x, int y);
    void drawTowerLevel2(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level2(int x, int y);
    void drawTowerLevel3(int x, int y, int colorFirst, int colorSecond);
    void tower_bullet_level3(int x, int y);

    int getIndexOfTowerFollowX();
    int getIndexOfTowerFollowY();

};