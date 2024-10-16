#include "Play.h"

void play_map1()
{
	Tower t1,t2;
	t1.drawTowerLevel2_Down(85, 0, 0, 15);
	t2.drawTowerLevel2_Right(0, 17, 0, 15);
	thread tow(&Tower::tower_bullet_level2_Down, &t1, 85, 0);
	thread tow1(&Tower::tower_bullet_level2_Right, &t2, 0, 17);

	thread te(enemy_map1, 5);

	tow.join();
	tow1.join();
	te.join();



	cin.get();
}