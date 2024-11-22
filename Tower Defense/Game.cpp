#include "Game.h"
#include "Play.h"

int Game::mode = 0;
bool Game::isPlaying = false;
string Game::file_map = "";
string Game::file_enemy = "";
int Game::num_enemy = 20;

void Game::setupGame() {

	if (Game::mode == 3) {
		Menu::goBack();
		return;
	}
	Game::isPlaying = true;
	Controller::SetColor(BRIGHT_WHITE, BRIGHT_WHITE);
	system("cls");

	string list_mode[3] = { "Easy", "Normal", "Difficult" };

	file_enemy = "./Map/" + list_mode[mode] + "/" + file_map + "_enemy.txt";
	file_map = "./Map/" + list_mode[mode] + "/" + file_map + "_map.txt";

	printBoard();
	Enemy::count = 0;


	isbreakmap1 = false;
	while (!isbreakmap1)
		Play::play_map(file_enemy, file_map);
}

void Game::printBoard() {
	Controller::SetColor(BRIGHT_WHITE, LIGHT_PURPLE);
	Screen::printRectangle(130, 1, 24, 39);

	Controller::SetColor(BRIGHT_WHITE, LIGHT_BLUE);
	Screen::printRectangle(137, 36, 10, 2);
	Controller::gotoXY(140, 37);
	Controller::SetColor(BRIGHT_WHITE, LIGHT_BLUE);
	if (Screen::isVie)
		Screen::printVietnamese(L"THOÁT");
	else
		cout << "EXIT";

	// ▀ █ ▄ ▐ ▌

	Screen::printTower(132, 3);

	Controller::SetColor(BRIGHT_WHITE, BLACK);
	Controller::gotoXY(144, 4);
	Screen::printVietnamese(L"UNKNOWN");

	Controller::gotoXY(135, 9);
	Controller::SetColor(BRIGHT_WHITE, BLACK);
	Screen::printVietnamese(L"|");
	Controller::SetColor(BRIGHT_WHITE, RED);
	Screen::printVietnamese(L"▀");

	Controller::SetColor(BRIGHT_WHITE, BLACK);
	Controller::gotoXY(135, 10);
	for (int i = 0; i < 16; i++) {
		if (i % 5 == 0)
			Screen::printVietnamese(L"█");
		else
			Screen::printVietnamese(L"▄");
	}
}

void Game::runPlanEnemy() {
	int x = 135;
	int y = 9;
	int last = Enemy::count;

	while (Enemy::count < num_enemy) {

		if (Enemy::count != last) {
			mu.lock();
			int last_t = static_cast<int>((last) * (15 * 1.0 / num_enemy));
			mu.unlock();

			mu.lock();
			Controller::gotoXY(x + last_t, y);
			Controller::SetColor(BRIGHT_WHITE, BRIGHT_WHITE);
			Screen::printVietnamese(L"  ");
			mu.unlock();

			mu.lock();
			int t = static_cast<int>(Enemy::count * (15 * 1.0 / num_enemy));
			mu.unlock();

			mu.lock();
			Controller::gotoXY(x + t, y);
			Controller::SetColor(BRIGHT_WHITE, BLACK);
			Screen::printVietnamese(L"|");
			Controller::SetColor(BRIGHT_WHITE, RED);
			Screen::printVietnamese(L"▀");
			mu.unlock();


			mu.lock();
			last = Enemy::count;
			mu.unlock();

		}
	}
}