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
   
    Tower other_zero;
    other_zero.drawTowerLevel1(0, 26, 0, 15);

    Tower other_first;
    other_first.drawTowerLevel2(19, 25, 0, 15);

    Tower other_second;
    other_second.drawTowerLevel3(38, 25, 0, 15);

    thread t1(&Tower::tower_bullet_level1, &other_zero, 0, 26);
    thread t2(&Tower::tower_bullet_level2, &other_first, 19, 25);
    thread t3(&Tower::tower_bullet_level3, &other_second, 38, 25);

    t1.join();
    t2.join();
    t3.join(); 


    system("PAUSE");

    return 0;
}
