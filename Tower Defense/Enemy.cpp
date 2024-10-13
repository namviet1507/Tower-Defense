#include "Enemy.h"
#include "Controller.h"

void Enemy::showl(int x,int y,int bcolor, int color)
{

	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"░░█");
	Controller::gotoXY(x +5, y);
	Screen::printVietnamese(L"▒▒░");
	Controller::gotoXY(x , y +1);
	Screen::printVietnamese(L"██▓▓▓▓▓░");
	Controller::gotoXY(x, y +2);
	Screen::printVietnamese(L"█▓▓▓▓██░");
	Controller::gotoXY(x + 1, y + 3);
	Screen::printVietnamese(L"▓▓██▓▓");
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"▓▓▒▒▓▓▒▒▒▒░░");
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"▓▓████");
	Controller::gotoXY(x + 1, y + 6);
	Screen::printVietnamese(L"██");
	Controller::gotoXY(x + 5, y + 6);
	cout << char(254)<<char(254);
	//Screen::printVietnamese(L"▓▓");
}
void Enemy::showr(int x, int y, int bcolor, int color)
{

	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"░░█");
	Controller::gotoXY(x + 5, y);
	Screen::printVietnamese(L"▒▒░");
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"██▓▓▓▓▓░");
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"█▓▓▓▓██░");
	Controller::gotoXY(x + 1, y + 3);
	Screen::printVietnamese(L"▓▓██▓▓");
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"▓▓▒▒▓▓▒▒▒▒░░");
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"▓▓████");
	Controller::gotoXY(x + 1, y + 6);
	cout << char(254) << char(254);
	//Screen::printVietnamese(L"██");
	Controller::gotoXY(x + 5, y + 6);
	Screen::printVietnamese(L"▓▓");
}

void Enemy::delel(int x, int y)
{
	Controller::gotoXY(x, y);
	Screen::printVietnamese(L"   ");
	Controller::gotoXY(x + 5, y);
	Screen::printVietnamese(L"    ");
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"         ");
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"         ");
	Controller::gotoXY(x + 1, y + 3);
	Screen::printVietnamese(L"      ");
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"            ");
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"      ");
	Controller::gotoXY(x + 1, y + 6);
	Screen::printVietnamese(L"  ");
	Controller::gotoXY(x + 5, y + 6);
	Screen::printVietnamese(L"  ");
}
void Enemy::deler(int x, int y)
{
	Controller::gotoXY(x, y);
	Screen::printVietnamese(L"   ");
	Controller::gotoXY(x + 5, y);
	Screen::printVietnamese(L"    ");
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"         ");
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"         ");
	Controller::gotoXY(x + 1, y + 3);
	Screen::printVietnamese(L"      ");
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"            ");
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"      ");
	Controller::gotoXY(x + 5, y + 6);
	Screen::printVietnamese(L"  ");
	Controller::gotoXY(x + 1, y + 6);
	Screen::printVietnamese(L"  ");
}
void Enemy::move1(int num)
{
	for (int i = 0; i < 40; i++)
	{
		showl(10, 0 + 2 * i, 0, 11);
		Sleep(400);
		delel(10, 0 + 2 * i);
		Sleep(25);
		showr(10, 0 + 2 * i + 1, 0, 11);
		Sleep(400);
		deler(10, 0 + 2 * i + 1);
	}
}