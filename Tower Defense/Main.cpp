#include "Game.h"
#include "Controller.h"
#include "Map.h"
#include "Enemy.h"

int main() {
	Controller::setUpConsole();
	Menu::music_is_open = true;
	Menu::sound_is_open = true;
	Screen::printMainScreen();
	

	//Sleep(2000);
	//_game.setupGame();
	//Map test;
	//test.createMap();
	//test.setMap("./Map/level1.txt");
	//test.printMap();

	//test.setMap("./Map/level1.txt");
	//test.printMap();
	//Controller::showCursor(false);
	//Enemy t;
	//t.move_x(1,0,1,24);
	//t.move_p(1, 24, 48, 24);
	//t.move_l(48, 24, 48, 0);
	//t.move_t(48, 0, 1, 0);
	system("PAUSE");

	return 0;
}