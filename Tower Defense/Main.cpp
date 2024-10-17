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

	//Map test;

	//test.createMap();
	//test.setMap("./Map/Easy/level1.bin");
	//test.printMap();

	return 0;
}