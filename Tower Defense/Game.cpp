#include "Game.h"
#include "Play.h"

int Game::mode = 0;
bool Game::isPlaying = false;
bool Game::isPause = false;
bool Game::Flag_Pause = false;
int Game::num_enemy = 16;

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

void Game::printBoard() {
	Controller::SetColor(BRIGHT_WHITE, LIGHT_PURPLE);
	Screen::printRectangle(130, 1, 24, 39);

	Controller::SetColor(BRIGHT_WHITE, GREEN);
	Controller::gotoXY(140, 3);
	Screen::printVietnamese(L" ╔╦╦╦╗  ");
	Controller::gotoXY(140, 4);
	Screen::printVietnamese(L" █████  ");
	Controller::gotoXY(140, 5);
	Screen::printVietnamese(L"  █■█   ");
	Controller::gotoXY(140, 6);
	Screen::printVietnamese(L" █▓█▓█  ");
	Controller::gotoXY(140, 7);
	Screen::printVietnamese(L"███████ ");

	// ▀ █ ▄ ▐ ▌

	Controller::gotoXY(132, 35);
	Controller::SetColor(BRIGHT_WHITE, LIGHT_BLUE);
	if (Screen::isVie) {
		Screen::printVietnamese(L"Bấm ESC dừng trò chơi!");
	}
	else {
		cout << "Enter ESC to pause game!";
	}

	Controller::SetColor(BRIGHT_WHITE, BLACK);
	Controller::gotoXY(140, 9);
	wcout << player.getName();

	int t = (int)(Enemy::count * 1.0 / Game::num_enemy) * 15;
	Controller::gotoXY(135 + t, 13);
	Controller::SetColor(BRIGHT_WHITE, BLACK);
	Screen::printVietnamese(L"|");
	Controller::SetColor(BRIGHT_WHITE, RED);
	Screen::printVietnamese(L"▀");

	Controller::SetColor(BRIGHT_WHITE, BLACK);
	Controller::gotoXY(135, 14);
	for (int i = 0; i < 16; i++) {
		if (i == 0 || i == 15)
			Screen::printVietnamese(L"█");
		else
			Screen::printVietnamese(L"▄");
	}
}

void Game::printNumEnemy() {
	mu.lock();
	bool check = ingame;
	mu.unlock();

	mu.lock();
	bool isPause = Game::isPause;
	int last_count = Enemy::count;
	mu.unlock();


	while (check)
	{
		
		mu.lock();
		check = ingame;
		mu.unlock();
		mu.lock();
		isPause = Game::isPause;
		mu.unlock();

		if (isPause) continue;

		mu.lock();
		int cur_count = Enemy::count;
		mu.unlock();

		if (cur_count != last_count) {
			mu.lock();
			int last_t = (int)((last_count * 1.0 / Game::num_enemy) * 15);
	
			Controller::gotoXY(135 + last_t, 13);
			Controller::SetColor(BRIGHT_WHITE, BRIGHT_WHITE);
			Screen::printVietnamese(L"|");
			Controller::SetColor(BRIGHT_WHITE, BRIGHT_WHITE);
			Screen::printVietnamese(L"▀");

			mu.unlock();

			mu.lock();
			int t = (int)((cur_count * 1.0 / Game::num_enemy) * 15);

			Controller::gotoXY(135 + t, 13);
			Controller::SetColor(BRIGHT_WHITE, BLACK);
			Screen::printVietnamese(L"|");
			Controller::SetColor(BRIGHT_WHITE, RED);
			Screen::printVietnamese(L"▀");
			mu.unlock();
			
			last_count = cur_count;
		}

	}
}