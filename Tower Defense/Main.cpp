#include "Game.h"
#include "Controller.h"
#include "Map.h"
#include "Enemy.h"
#include "Tower.h"
#include "Play.h"

int main() {

	Controller::setUpConsole();
	Menu::music_is_open = true;
	Menu::sound_is_open = true;
	Screen::printMainScreen();
	//Sleep(2000);
	//Map test;

	////test.createMap();

	//test.setMap("./Map/level1.txt");
	//test.printMap();
	//Controller::showCursor(false);
	//Enemy t;
	//t.move_x(1,0,1,24);
	//t.move_p(1, 24, 48, 24);
	//t.move_l(48, 24, 48, 0);
	//t.move_t(48, 0, 1, 0);

	//thread e(enemy_map1, 5);
	
	//vector<Enemy> e(5);
	//vector<thread> threads;
	//Enemy e1, e2;
	//thread th1(&Enemy::move_x, &e1, 10 + 0 * 40, 0, 10 + 0 * 30, 6);
	//thread th2(&Enemy::move_x, &e2, 10 + 1 * 40, 0, 10 + 1 * 30, 6);
	//th1.join();
	//th2.join();
	//cin.get();

	//Tower a;
	//a.drawTowerLevel1(0, 26, 0, 15);
	//a.tower_bullet_level1(0, 26);

	//play_map1();
	return 0;
}