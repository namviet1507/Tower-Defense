#include "Game.h"
#include "Controller.h"
#include "Map.h"

int main() {
	Controller::setUpConsole();
	//Menu::music_is_open = true;
	//Menu::sound_is_open = true;
	//Screen::printMainScreen();
	Sleep(1000);
	Map test;

	test.setMap("./Map/level1.txt");
	test.printMap();

	system("PAUSE");

	return 0;
}