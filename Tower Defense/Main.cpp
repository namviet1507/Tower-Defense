#include "Game.h"
#include "Controller.h"
#include "Map.h"
#include "Enemy.h"
#include "Tower.h"
#include "Play.h"

int main() {
	// remember below.
	Controller::setUpConsole();
	Menu::music_is_open = true;
	Menu::sound_is_open = true;
	int mode = Screen::printMainScreen();
	if (mode == 0)
		play_map1();
	else
	{
		system("cls");
		cout << "shitttttttttttttttttttttttttttttttttt";
	}

	return 0;
}