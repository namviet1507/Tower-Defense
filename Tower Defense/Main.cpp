#include "Game.h"
#include "Controller.h"
#include "Map.h"

int main() {
	Controller::setUpConsole();
	Menu::music_is_open = true;
	Menu::sound_is_open = true;
	Screen::printMainScreen();
	system("PAUSE");
	return 0;
}