#include "Game.h"
#include "Play.h"

int Game::mode = 0;
bool Game::isPlaying = false;
string Game::file_map = "";
string Game::file_enemy = "";

void Game::setupGame() {
	if (Game::mode == 3) {
		Menu::goBack();
		return;
	}
	Game::isPlaying = true;
	system("cls");
	system("color F0");

	string list_mode[3] = { "Easy", "Normal", "Difficult" };

	file_enemy = "./Map/" + list_mode[mode] + "/" + file_map + "_enemy.txt";
	file_map = "./Map/" + list_mode[mode] + "/" + file_map + "_map.txt";

	isbreakmap1 = false;
	while (!isbreakmap1)
		Play::play_map(file_enemy, file_map);
	
}