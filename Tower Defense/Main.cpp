#include "Game.h"
#include "Controller.h"
#include "Map.h"
#include "Enemy.h"

int main() {
	//Controller::setUpConsole();
	//Menu::music_is_open = true;
	//Menu::sound_is_open = true;
	//Screen::printMainScreen();
	//Sleep(2000);
	//Map test;

	////test.createMap();

	//test.setMap("./Map/level1.txt");
	//test.printMap();
	Controller::showCursor(false);
	Enemy t;
	t.move1(20);

	system("PAUSE");

	return 0;
}