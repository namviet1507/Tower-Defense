#include "Game.h"
#include "Play.h"

int Game::mode = 0;
bool Game::isPlaying = false;

void Game::setupGame() {
	if (Game::mode == 3) {
		Menu::goBack();
	}
	Game::isPlaying = true;
	system("cls");
	system("color F0");
	if (mode == 0)
	{
		isbreakmap1 = false;
		while (!isbreakmap1)
			Play::play_map(".\\Map\\level1_enemy.txt", ".\\Map\\level1_map.txt");
	}
	else if (mode == 1)
	{
		isbreakmap1 = false;
		while (!isbreakmap1)
			Play::play_map(".\\Map\\level2_enemy.txt", ".\\Map\\level2_map.txt");
	}
	else {
		isbreakmap1 = false;
		while (!isbreakmap1)
			Play::play_map(".\\Map\\level3_enemy.txt", ".\\Map\\level3_map.txt");
	}
}