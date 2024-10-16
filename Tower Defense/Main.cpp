#include "Game.h"
#include "Controller.h"
#include "Map.h"
#include "Enemy.h"
#include "Tower.h"
#include "Play.h"

int main() {
	Controller::setUpConsole();
	//Menu::music_is_open = true;
	//Menu::sound_is_open = true;
	//Screen::printMainScreen();
	//Map test;

	//test.setMap("./Map/level1.txt");
	//test.printMap();
	play_map1();
	 
	//Map test;
	//test.createMap();
	//system("PAUSE");
	return 0;
}