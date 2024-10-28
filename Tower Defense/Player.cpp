#include "Player.h"

bool ingame;
Player player;
bool wingame;
bool losegame;
bool showcost;
bool isbreakmap1;
void Player::print_hp(int x, int y, int bcolor, int color)
{
	mu.lock();
	int end = player.get_hp();
	mu.unlock();

	mu.lock();
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	for (int i = 0; i < end; i++)
	{
		Screen::printVietnamese(L"█");
	}
	mu.unlock();
	Sleep(1000);
	mu.lock();
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	for (int i = 0; i < end; i++)
	{
		Screen::printVietnamese(L" ");
	}
	mu.unlock();

}

void Player::print_cost(int x, int y, int bcolor, int color)
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
	Sleep(1000);
	mu.lock();
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"    ");
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
	while (player.get_hp() > 0)
	{
		bool check;
		mu.lock();
		check = ingame;
		mu.unlock();
		if (check == false)
			return;
		thread p(&Player::print_hp, &player, x, y, bcolor, color);
		if (p.joinable())
		{
			p.join();
			Sleep(50);
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
	bool check = showcost;
	mu.unlock();
	while (check)
	{
		thread p(&Player::print_cost, &player, x, y, bcolor, color);
		if (p.joinable())
		{
			p.join();
			Sleep(50);
		}
		mu.lock();
		check = showcost;
		mu.unlock();
	}
}

void Player::check_win(int num_enemy)
{
	int count = 0;
	while (count < num_enemy)
	{
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