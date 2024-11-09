#include "Game.h"
#include "Controller.h"
#include "Map.h"
#include "Enemy.h"
#include "Tower.h"
#include "Play.h"

int main() {

	//Map test;
	//Controller::SetColor(BRIGHT_WHITE, BLACK);
	//system("cls");
	//test.setMap("./Map/Easy/level1_map.txt");
	//test.printMap();

	//Game::printBoard();

	//cin.get();

	Controller::setUpConsole();
	Menu::music_is_open = true;
	Menu::sound_is_open = true;
	Screen::printMainScreen();

	return 0;
}