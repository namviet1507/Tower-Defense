#include "Player.h"


void Player::print_hp(int x, int y, int bcolor, int color)
{

	mu.lock();
	int end = hp;
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

	//mu.lock();
	//Controller::gotoXY(x, y);
	//Controller::SetColor(bcolor, color);
	//cout << hp;
	//mu.unlock();
	//Sleep(400);
	//mu.lock();
	//Controller::gotoXY(x, y);
	//Controller::SetColor(bcolor, color);
	//cout << "  ";
	//mu.unlock();
}

void print_hp_player(int x, int y, int bcolor, int color)
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
			Sleep(20);
		}
	}
	mu.lock();
	ingame = false;
	losegame = true;
	mu.unlock();
}


bool ingame;
Player player;
bool wingame;
bool losegame;

void check_win(int num_enemy)
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
	mu.unlock();
}