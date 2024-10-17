#include "Play.h"

void play_map1()
{
	//Controller::showCursor(false);

	Controller::setUpConsole();
	Map test;
	test.setMap("./Map/level1.txt");
	test.printMap();

	Tower t1,t2,t3,t4;
	t1.drawTowerLevel2_Up(14, 36, 6, 4);
	t2.drawTowerLevel2_Down(46, 0, 6, 4);
	t3.drawTowerLevel2_Right(34, 11, 6, 4);
	t4.drawTowerLevel2_Left(117, 31, 6, 4);

	thread tow(&Tower::tower_bullet_level2_Up, &t1, 14, 36);
	thread tow1(&Tower::tower_bullet_level2_Down, &t2, 46, 0, 46, 35);
	thread tow2(&Tower::tower_bullet_level2_Right, &t2, 34, 11, 114, 11);
	thread tow3(&Tower::tower_bullet_level2_Left, &t2, 117, 31, 73, 31);

	//thread te(enemy_map1, 5);

	tow.join();
	tow1.join();
	tow2.join();
	tow3.join();
	//te.join();


	cin.get();
}