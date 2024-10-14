#include "Enemy.h"
#include "Controller.h"
mutex mu_e;
void Enemy::showl_x(int x,int y,int bcolor, int color)
{
	mu_e.lock();
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
	mu_e.unlock();
	//Screen::printVietnamese(L"▓▓");
}
void Enemy::showr_x(int x, int y, int bcolor, int color)
{
	mu_e.lock();
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
	mu_e.unlock();
}

void Enemy::dele_x(int x, int y)
{
	mu_e.lock();
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
	mu_e.unlock();
}


void Enemy::showl_l(int x, int y, int bcolor, int color)
{
	mu_e.lock();
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"░▒▒");
	Controller::gotoXY(x + 5, y);
	Screen::printVietnamese(L"█░░");
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"░▓▓▓▓▓██");
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"░▓▓▓▓▓▓█");
	Controller::gotoXY(x + 1, y + 3);
	Screen::printVietnamese(L"▓▓▓▓▓▓");
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"░░▓▓▓▓▓▓▓▓▓");
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"████▓▓");
	Controller::gotoXY(x + 1, y + 6);
	Screen::printVietnamese(L"▓▓");
	Controller::gotoXY(x + 5, y + 6);
	cout << char(254) << char(254);
	mu_e.unlock();
}

void Enemy::showr_l(int x, int y, int bcolor, int color)
{
	mu_e.lock();
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"░▒▒");
	Controller::gotoXY(x + 5, y);
	Screen::printVietnamese(L"█░░");
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"░▓▓▓▓▓██");
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"░▓▓▓▓▓▓█");
	Controller::gotoXY(x + 1, y + 3);
	Screen::printVietnamese(L"▓▓▓▓▓▓");
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"░░▓▓▓▓▓▓▓▓▓");
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"████▓▓");
	Controller::gotoXY(x + 5, y + 6);
	Screen::printVietnamese(L"██");
	Controller::gotoXY(x + 1, y + 6);
	cout << char(254) << char(254);
	mu_e.unlock();
}

void Enemy::dele_l(int x, int y)
{
	mu_e.lock();
	Controller::gotoXY(x, y);
	Screen::printVietnamese(L"   ");
	Controller::gotoXY(x + 5, y);
	Screen::printVietnamese(L"   ");
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"        ");
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"        ");
	Controller::gotoXY(x + 1, y + 3);
	Screen::printVietnamese(L"      ");
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"           ");
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"      ");
	Controller::gotoXY(x + 1, y + 6);
	Screen::printVietnamese(L"  ");
	Controller::gotoXY(x + 5, y + 6);
	Screen::printVietnamese(L"  ");
	mu_e.unlock();
}

void Enemy::showl_p(int x, int y, int bcolor, int color)
{
	mu_e.lock();
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"░░");
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"██");
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"██▓");
	Controller::gotoXY(x - 1, y + 3);
	Screen::printVietnamese(L"▓▓▓▓▓");
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"▓▓▓▓▓");
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"▓▓");
	Controller::gotoXY(x + 3, y + 6);
	cout << char(254);
	Controller::gotoXY(x , y + 6);
	Screen::printVietnamese(L"██");
	mu_e.unlock();
	//Controller::gotoXY(x+2, y + 6);
	//Screen::printVietnamese(L" ");

}

void Enemy::showr_p(int x, int y, int bcolor, int color)
{
	mu_e.lock();
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"░░");
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"██");
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"██▓");
	Controller::gotoXY(x - 1, y + 3);
	Screen::printVietnamese(L"▓▓▓▓▓");
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"▓▓▓▓▓");
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"▓▓");
	Controller::gotoXY(x+2, y + 6);
	Screen::printVietnamese(L"██");
	Controller::gotoXY(x , y + 6);
	cout << char(254);
	mu_e.unlock();
}

void Enemy::dele_p(int x, int y)
{
	mu_e.lock();
	Controller::gotoXY(x, y);
	Screen::printVietnamese(L"  ");
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"  ");
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"   ");
	Controller::gotoXY(x - 1, y + 3);
	Screen::printVietnamese(L"     ");
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"     ");
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"  ");
	Controller::gotoXY(x, y + 6);
	Screen::printVietnamese(L"  ");
	Controller::gotoXY(x + 2, y + 6);
	Screen::printVietnamese(L"  ");
	mu_e.unlock();
}

void Enemy::showl_t(int x, int y, int bcolor, int color)
{
	mu_e.lock();
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"░░");
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"░░");
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"░░▓");
	Controller::gotoXY(x - 1, y + 3);
	Screen::printVietnamese(L"▓▓▓▓▓");
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"▓░░▓▓");
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"██");
	Controller::gotoXY(x + 3, y + 6);
	cout << char(254);
	Controller::gotoXY(x, y + 6);
	Screen::printVietnamese(L"▓▓");
	Controller::gotoXY(x + 2, y + 6);
	Screen::printVietnamese(L" ");
	mu_e.unlock();
}

void Enemy::showr_t(int x, int y, int bcolor, int color)
{
	mu_e.lock();
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"░░");
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"░░");
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"░░▓");
	Controller::gotoXY(x - 1, y + 3);
	Screen::printVietnamese(L"▓▓▓▓▓");
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"▓░░▓▓");
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"██");
	Controller::gotoXY(x + 2, y + 6);
	Screen::printVietnamese(L"▓▓");
	Controller::gotoXY(x, y + 6);
	cout << char(254);
	mu_e.unlock();
}

void Enemy::dele_t(int x, int y)
{
	mu_e.lock();
	Controller::gotoXY(x, y);
	Screen::printVietnamese(L"  ");
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"  ");
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"   ");
	Controller::gotoXY(x - 1, y + 3);
	Screen::printVietnamese(L"     ");
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"     ");
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"  ");
	Controller::gotoXY(x, y + 6);
	Screen::printVietnamese(L"  ");
	Controller::gotoXY(x + 2, y + 6);
	Screen::printVietnamese(L"  ");
	mu_e.unlock();
}






void Enemy::move_l(int x_start, int y_start, int x_end, int y_end)
{
	int step = (y_start - y_end) / 2;
	for (int i = 0; i < step; i++)
	{
		showl_l(x_start, y_start - 2 * i, 0, 11);
		Sleep(400);
		dele_l(x_start, y_start - 2 * i);
		Sleep(25);
		showr_l(x_start, y_start - 2 * i - 1, 0, 11);
		Sleep(400);
		dele_l(x_start, y_start - 2 * i - 1);
	}
}


void Enemy::move_x(int x_start, int y_start, int x_end, int y_end)
{
	int step = (y_end - y_start) / 2;
	for (int i = 0; i < step; i++)
	{
		showl_x(x_start, y_start + 2 * i, 0, 11);
		Sleep(400);
		dele_x(x_start, y_start + 2 * i);
		Sleep(25);
		showr_x(x_start, y_start + 2 * i + 1, 0, 11);
		Sleep(400);
		dele_x(x_start, y_start + 2 * i + 1);
	}
}

void Enemy::move_p(int x_start, int y_start, int x_end, int y_end)
{
	int step = (x_end - x_start) / 2;
	for (int i = 0; i < step; i++)
	{
		showl_p(x_start + 2 * i, y_start , 0, 11);
		Sleep(400);
		dele_p(x_start + 2 * i, y_start);
		Sleep(25);
		showr_p(x_start + 2 * i + 1, y_start, 0, 11);
		Sleep(400);
		dele_p(x_start + 2 * i + 1, y_start);
	}
}

void Enemy::move_t(int x_start, int y_start, int x_end, int y_end)
{
	int step = (x_start - x_end) / 2;
	for (int i = 0; i < step; i++)
	{
		showl_t(x_start - 2 * i, y_start, 0, 11);
		Sleep(400);
		dele_t(x_start - 2 * i, y_start);
		Sleep(25);
		showr_t(x_start - 2 * i - 1, y_start, 0, 11);
		Sleep(400);
		dele_t(x_start - 2 * i - 1, y_start);
	}
}

void Enemy::move_map1()
{
	move_x(1, 0, 1, 24);
	move_p(17, 24, 48, 24);
	move_l(48, 24, 48, 0);
	move_t(35, 0, 1, 0);
}

void enemy_map1(int num)
{
	vector<Enemy> e(num);
	vector<thread> threads;

	for (int i = 0; i < num; i++)
	{
		threads.push_back(thread(&Enemy::move_map1, &e[i]));
		Sleep(5000);
	}
	
	for (auto &th : threads)
	{
		if (th.joinable()) th.join();
	}

	//Enemy e1, e2;
	//thread th1(&Enemy::move_x, &e1, 10 , 0, 10, 24);
	//Sleep(3800);
	//thread th2(&Enemy::move_x, &e2, 10, 0 , 10, 24);
	//th1.join();
	//th2.join();
}