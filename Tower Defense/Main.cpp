#include "Game.h"
#include "Controller.h"
#include "Map.h"
#include "Enemy.h"
#include "Tower.h"
#include "Play.h"

int main() {
	//_game.printControlPanel();
	// remember below.

	Sleep(3000);
	_game.selectTower(1, 2);

	//Controller::setUpConsole();
	//Menu::music_is_open = true;
	//Menu::sound_is_open = true;
	

	//Screen::printMainScreen();

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