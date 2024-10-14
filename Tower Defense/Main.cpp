#include "Game.h"
#include "Controller.h"
#include "Map.h"
#include "Enemy.h"
#include "Tower.h"
#include "Library.h"
#include <windows.h>
#include <iostream>
#include <mutex>


int main() {
   
    Tower other;
    other.drawTowerLevel1(0, 26, 0, 15);
    //other.tower_bullet_level1(0, 26);

    //other.drawTowerLevel1(0, 26, 0, 15);

    /*thread s1(&Tower::drawTowerLevel1, &other, 0, 26, 0, 15);
    thread s2(&Tower::drawTowerLevel2, &other, 19, 25, 0, 15);
    thread s3(&Tower::drawTowerLevel3, &other, 38, 25, 0, 15);*/

    /*s1.join();
    s2.join();
    s3.join();*/

    system("PAUSE");

    return 0;
}
