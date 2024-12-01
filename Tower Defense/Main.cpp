#include "Game.h"
#include "Controller.h"
#include "Map.h"
#include "Enemy.h"
#include "Tower.h"
#include "Play.h"

int main() {
	Sleep(100);
	Controller::setUpConsole();
	Menu::music_is_open = true;
	Menu::sound_is_open = true;
	Screen::printMainScreen();

	//Map test;
	//test.createMap();

	//Controller::SetColor(BLACK, WHITE);
	//system("cls");

	//test.createMap();

	return 0;
}