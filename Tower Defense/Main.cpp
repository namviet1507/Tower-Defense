#include "Game.h"
#include "Controller.h"
#include "Map.h"
#include "Enemy.h"
#include "Tower.h"
#include "Play.h"

void print() {
	cout << "Hello world";
}

int main() {
	//Tower tower;
	//tower.setDir(1);
	//tower.setLevel(1);
	//tower.draw_tower(1, 1, RED, GRAY);

	Controller::setUpConsole();
	//Menu::music_is_open = true;
	//Menu::sound_is_open = true;
	//Screen::printMainScreen();



	Tower tower;
	tower.setLevel(1);
	tower.setDir(1);
	tower.setPos(15, 10);
	tower.draw_tower(BLACK, WHITE);

	thread t(&Tower::tower_bullet_level1_Up, &tower, 15, 30);
	t.join();

	//temp.join();
	//cin.get();

	/*Tower test;
	test.setLevel(1);
	test.setDir(3);
	test.setPos(3, 0);

	Controller::gotoXY(10, 1);
	cout << "hello";
	test.draw_tower(BLACK, WHITE);

	test.drawTowerLevel2_Left(20, 1, BLACK, WHITE);

	cin.get();*/

	//while (true)
	//{
	//	int mode/* = Screen::printMainScreen()*/;
	//	if (mode == 0)
	//	{
	//		isbreakmap1 = false;
	//		while (!isbreakmap1)
	//		{
	//			play_map1();
	//		}

	//	}
	//	else
	//	{
	//		system("cls");
	//		cout << "shitttttttttttttttttttttttttttttttttt";
	//	}
	//}
	return 0;
}