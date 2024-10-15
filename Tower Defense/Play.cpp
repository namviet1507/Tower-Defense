#include "Play.h"

void play_map1()
{
	Controller::showCursor(false);

	Tower t1;
	t1.drawTowerLevel1(10, 24, 0, 3);

	thread tow(&Tower::tower_bullet_level1, &t1, 10, 24);


	vector<Enemy> e12;
	thread te(enemy_map1, 5);

	tow.join();
	te.join();



	cin.get();
}