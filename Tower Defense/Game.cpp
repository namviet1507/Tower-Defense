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
	play_map1();
}