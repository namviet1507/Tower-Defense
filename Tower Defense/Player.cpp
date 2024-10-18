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
		thread p(&Player::print_hp, &player, x, y, bcolor, color);
		if (p.joinable())
		{
			p.join();
			Sleep(20);
		}
	}

}
	//Controller::gotoXY(x, y);
	////Controller::SetColor(bcolor, color);
	////for (int i = 0; i < hp; i++)
	////{
	////	Screen::printVietnamese(L"█");
	////}
	//cout << hp;



Player player;