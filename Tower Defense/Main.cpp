#include "Game.h"
#include "Controller.h"
#include "Map.h"
#include "Enemy.h"
#include "Tower.h"
#include "Play.h"

int main() {

	Play::play_map(".\\Map\\level4_enemy.txt", ".\\Map\\level4_map.txt");



	//Controller::setUpConsole();
	//Menu::music_is_open = true;
	//Menu::sound_is_open = true;
	//Screen::printMainScreen();

	return 0;
}