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


	return 0;
}