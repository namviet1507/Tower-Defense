#include "Player.h"
#include "Game.h"
#include "Play.h"
#include <chrono>

using namespace std::chrono;

bool ingame;
Player player;
bool wingame;
bool losegame;
bool showcost;
bool isbreakmap1;
bool isQuitGame;

void Player::setName(wstring name) {
	this->name = name;
}

wstring Player::getName() {
	return name;
}

void Player::print_hp(int x, int y, int bcolor, int color, int _hp)
{

	mu.lock();
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	for (int i = 0; i < _hp; i++)
	{
		Screen::printVietnamese(L"█");
	}
	mu.unlock();
	//Sleep(1000);
	/*mu.lock();
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	for (int i = 0; i < end; i++)
	{
		Screen::printVietnamese(L" ");
	}
	mu.unlock();*/
}

void Player::print_cost(int x, int y, int bcolor, int color)
{
	mu.lock();
	int cost = player.get_cost();
	mu.unlock();

	mu.lock();
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	cout << cost;
	Screen::printVietnamese(L" $");
	mu.unlock();
}

void Player::print_cost_first(int x, int y, int bcolor, int color)
{
	mu.lock();
	int h = player.get_cost();
	mu.unlock();

	mu.lock();
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	cout << h;
	Screen::printVietnamese(L" $");
	mu.unlock();
}

void Player::print_hp_player(int x, int y, int bcolor, int color)
{
	mu.lock();
	bool isPause = Game::isPause;
	mu.unlock();

	mu.lock();
	int last_hp = player.hp;
	mu.unlock();
	player.print_hp(x, y, bcolor, color, last_hp);

	while (player.get_hp() > 0)
	{
		bool check;
		mu.lock();
		check = ingame;
		mu.unlock();
		if (check == false)
			return;

		mu.lock();
		isPause = Game::isPause;
		mu.unlock();

		if (isPause) continue;


		mu.lock();
		int cur_hp = player.hp;
		mu.unlock();

		if (last_hp != cur_hp) {
			player.print_hp(x, y, bcolor, bcolor,last_hp);

			player.print_hp(x, y, bcolor, color, cur_hp);


			last_hp = cur_hp;
		}

		

	}
	mu.lock();
	ingame = false;
	losegame = true;
	showcost = false;
	mu.unlock();
}

void Player::print_cost_player(int x, int y, int bcolor, int color)
{
	mu.lock();
	bool check = ingame;
	mu.unlock();

	mu.lock();
	bool isPause = Game::isPause;
	int last_cost = player.cost;
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
		int cur_cost = player.cost;
		mu.unlock();

		if (last_cost != cur_cost) {
			player.print_cost(x, y, bcolor, bcolor);

			player.print_cost(x, y, bcolor, color);

			last_cost = cur_cost;
		}

	}
}

void Player::check_win(int num_enemy, vector<vector<int>> posTower, int _res[], bool choice[], string file_map, string file_enemy)
{
	int count = 0;
	auto start = 0;
	while (count < num_enemy)
	{
		int res = 0;
		if (_kbhit()) {
			mu.lock();
			int key = Controller::getConsoleInput();
			mu.unlock();

			if (key == 1) {
				mu.lock();
				Game::isPause = true;
				//auto start = high_resolution_clock::now();

				res = Play::printMenuPause(135, 15, BRIGHT_WHITE, LIGHT_PURPLE);
				mu.unlock();
			}
		}
		mu.lock();
		bool isPause = Game::isPause;
		mu.unlock();

		
		if (isPause) {
			if (res == 0) {
				mu.lock();
				Game::isPause = false;
				Game::Flag_Pause = true;
				mu.unlock();
			}
			else if (res == 1) {
				string filename = Play::getFileSave();



				ListFile::processSaveFile(filename, posTower, _res, choice, file_map, file_enemy);

				mu.lock();
				Game::isPause = false;
				mu.unlock();
			}
			else if (res == 2) {
				mu.lock();
				wingame = false;
				ingame = false;
				showcost = false;
				isQuitGame = true;
				mu.unlock();
				return;
			}
		}


		count = 0;
		bool check;
		mu.lock();
		check = ingame;
		mu.unlock();
		if (check == false)
			return;

		mu.lock();
		for (auto i : e_global)
		{
			if (i.get_hp() <= 0)
				count++;
		}
		mu.unlock();
	}
	mu.lock();
	wingame = true;
	ingame = false;
	showcost = false;
	mu.unlock();
}