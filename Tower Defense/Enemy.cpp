#include "Enemy.h"
#include "Controller.h"
mutex mu;

void Enemy::showl_x(int x,int y,int bcolor, int color)
{
	mu.lock();

	Controller::gotoXY(x-1, y - 2);
	Controller::SetColor(bcolor, 12);
	for (int i = 0; i < hp; i++)
		cout << char(254);
	mu.unlock();

	mu.lock();
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"░░█");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x +5, y);
	Screen::printVietnamese(L"▒▒░");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x , y +1);
	Screen::printVietnamese(L"██▓▓▓▓▓░");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y +2);
	Screen::printVietnamese(L"█▓▓▓▓██░");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 3);
	Screen::printVietnamese(L"▓▓██▓▓");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"▓▓▒▒▓▓▒▒▒▒░░");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"▓▓████");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 6);
	Screen::printVietnamese(L"██");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 5, y + 6);
	cout << char(254)<<char(254);
	mu.unlock();

	x_e = x + 3;
	y_e = y + 3;
}
void Enemy::showr_x(int x, int y, int bcolor, int color)
{
	mu.lock();

	Controller::gotoXY(x - 1, y - 2);
	Controller::SetColor(bcolor, 12);
	for (int i = 0; i < hp; i++)
		cout << char(254);
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"░░█");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 5, y);
	Screen::printVietnamese(L"▒▒░");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"██▓▓▓▓▓░");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"█▓▓▓▓██░");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 3);
	Screen::printVietnamese(L"▓▓██▓▓");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"▓▓▒▒▓▓▒▒▒▒░░");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"▓▓████");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 6);
	cout << char(254) << char(254);
	//Screen::printVietnamese(L"██");
	mu.unlock();
	mu.lock();

	Controller::gotoXY(x + 5, y + 6);
	Screen::printVietnamese(L"▓▓");
	mu.unlock();

	x_e = x + 3;
	y_e = y + 3;
}

void Enemy::dele_x(int x, int y)
{
	mu.lock();

	Controller::gotoXY(x-1, y - 2);
	Controller::SetColor(0, 12);
	for (int i = 0; i < 10; i++)
		Screen::printVietnamese(L" ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y);
	Screen::printVietnamese(L"   ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 5, y);
	Screen::printVietnamese(L"    ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"         ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"         ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 3);
	Screen::printVietnamese(L"      ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"            ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"      ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 6);
	Screen::printVietnamese(L"  ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 5, y + 6);
	Screen::printVietnamese(L"  ");
	mu.unlock();

	x_e = x + 3;
	y_e = y + 3;
}


void Enemy::showl_l(int x, int y, int bcolor, int color)
{
	mu.lock();

	Controller::gotoXY(x-1, y - 2);
	Controller::SetColor(bcolor, 12);
	for (int i = 0; i < hp; i++)
		cout << char(254);

	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"░▒▒");

	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 5, y);
	Screen::printVietnamese(L"█░░");

	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"░▓▓▓▓▓██");

	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"░▓▓▓▓▓▓█");

	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 3);
	Screen::printVietnamese(L"▓▓▓▓▓▓");

	mu.unlock();
	mu.lock();
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"░░▓▓▓▓▓▓▓▓▓");

	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"████▓▓");

	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 6);
	Screen::printVietnamese(L"▓▓");

	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 5, y + 6);
	cout << char(254) << char(254);
	mu.unlock();

	x_e = x + 3;
	y_e = y + 3;
}

void Enemy::showr_l(int x, int y, int bcolor, int color)
{
	mu.lock();

	Controller::gotoXY(x-1, y - 2);
	Controller::SetColor(bcolor, 12);
	for (int i = 0; i < hp; i++)
		cout << char(254);
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"░▒▒");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 5, y);
	Screen::printVietnamese(L"█░░");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"░▓▓▓▓▓██");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"░▓▓▓▓▓▓█");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 3);
	Screen::printVietnamese(L"▓▓▓▓▓▓");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"░░▓▓▓▓▓▓▓▓▓");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"████▓▓");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 5, y + 6);
	Screen::printVietnamese(L"██");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 6);
	cout << char(254) << char(254);
	mu.unlock();

	x_e = x + 3;
	y_e = y + 3;
}

void Enemy::dele_l(int x, int y)
{
	mu.lock();

	Controller::gotoXY(x-1, y - 2);
	Controller::SetColor(0, 12);
	for (int i = 0; i < 10; i++)
		Screen::printVietnamese(L" ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y);
	Screen::printVietnamese(L"   ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 5, y);
	Screen::printVietnamese(L"   ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"        ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"        ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 3);
	Screen::printVietnamese(L"      ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"           ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"      ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 6);
	Screen::printVietnamese(L"  ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 5, y + 6);
	Screen::printVietnamese(L"  ");
	mu.unlock();

	x_e = x + 3;
	y_e = y + 3;
}

void Enemy::showl_p(int x, int y, int bcolor, int color)
{
	mu.lock();

	Controller::gotoXY(x-1, y - 2);
	Controller::SetColor(bcolor, 12);
	if (hp == 1)
		cout << char(254);
	for (int i = 0; i < hp/2; i++)
		cout << char(254);
	mu.unlock();
	mu.lock();

	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"░░");

	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"██");

	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"██▓");

	mu.unlock();
	mu.lock();
	Controller::gotoXY(x - 1, y + 3);
	Screen::printVietnamese(L"▓▓▓▓▓");

	mu.unlock();
	mu.lock();
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"▓▓▓▓▓");

	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"▓▓");

	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 3, y + 6);
	cout << char(254);

	mu.unlock();
	mu.lock();
	Controller::gotoXY(x , y + 6);
	Screen::printVietnamese(L"██");
	mu.unlock();

	x_e = x + 1;
	y_e = y + 3;
}

void Enemy::showr_p(int x, int y, int bcolor, int color)
{
	mu.lock();

	Controller::gotoXY(x-1, y - 2);
	Controller::SetColor(bcolor, 12);
	if (hp == 1)
		cout << char(254);
	for (int i = 0; i < hp / 2; i++)
		cout << char(254);
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"░░");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"██");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"██▓");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x - 1, y + 3);
	Screen::printVietnamese(L"▓▓▓▓▓");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"▓▓▓▓▓");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"▓▓");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x+2, y + 6);
	Screen::printVietnamese(L"██");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x , y + 6);
	cout << char(254);
	mu.unlock();

	x_e = x + 1;
	y_e = y + 3;
}

void Enemy::dele_p(int x, int y)
{
	mu.lock();

	Controller::gotoXY(x-1, y - 2);
	Controller::SetColor(0, 12);
	if (hp == 1)
		cout << " ";
	for (int i = 0; i < 5; i++)
		Screen::printVietnamese(L" ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y);
	Screen::printVietnamese(L"  ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"  ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"   ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x - 1, y + 3);
	Screen::printVietnamese(L"     ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x - 1, y + 4);
	Screen::printVietnamese(L"     ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 1, y + 5);
	Screen::printVietnamese(L"  ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x, y + 6);
	Screen::printVietnamese(L"  ");
	mu.unlock();
	mu.lock();
	Controller::gotoXY(x + 2, y + 6);
	Screen::printVietnamese(L"  ");
	mu.unlock();

	x_e = x + 1;
	y_e = y + 3;
}

void Enemy::showl_t(int x, int y, int bcolor, int color)
{
	mu.lock();

	Controller::gotoXY(x-1, y - 2);
	Controller::SetColor(bcolor, 12);
	if (hp == 1)
		cout << char(254);
	for (int i = 0; i < hp / 2; i++)
		cout << char(254);

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
	mu.unlock();

	x_e = x + 1;
	y_e = y + 3;
}

void Enemy::showr_t(int x, int y, int bcolor, int color)
{
	mu.lock();

	Controller::gotoXY(x-1, y - 2);
	Controller::SetColor(bcolor, 12);
	if (hp == 1)
		cout << char(254);
	for (int i = 0; i < hp / 2; i++)
		cout << char(254);

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
	mu.unlock();

	x_e = x + 1;
	y_e = y + 3;
}

void Enemy::dele_t(int x, int y)
{
	mu.lock();

	Controller::gotoXY(x-1, y - 2);
	Controller::SetColor(0, 12);
	if (hp == 1)
		cout << " ";
	for (int i = 0; i < 5; i++)
		Screen::printVietnamese(L" ");

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
	mu.unlock();

	x_e = x + 1;
	y_e = y + 3;
}






void Enemy::move_l(int x_start, int y_start, int x_end, int y_end)
{
	int step = (y_start - y_end) / 2;
	if (hp > 0)
	{
		for (int i = 0; i < step; i++)
		{
			bool check;
			mu.lock();
			check = ingame;
			mu.unlock();
			if (check == false)
			{
				break;
			}
			if (hp <= 0)
			{
				mu.lock();
				player.in_cost(1);
				mu.unlock();
				break;
			}
			showl_l(x_start, y_start - 2 * i, 0, 11);
			Sleep(200);
			dele_l(x_start, y_start - 2 * i);
			Sleep(25);
			showr_l(x_start, y_start - 2 * i - 1, 0, 11);
			Sleep(200);
			dele_l(x_start, y_start - 2 * i - 1);
		}
	}
}

mutex mu_e2;
void Enemy::move_x(int x_start, int y_start, int x_end, int y_end)
{
	int step = (y_end - y_start) / 2;
	if (hp > 0)
	{
		for (int i = 0; i < step; i++)
		{
			bool check;
			mu.lock();
			check = ingame;
			mu.unlock();
			if (check == false)
			{
				break;
			}

			if (hp <= 0)
			{
				mu.lock();
				player.in_cost(1);
				mu.unlock();
				break;
			}
			mu_e2.lock();
			showl_x(x_start, y_start + 2 * i, 0, 11);
			mu_e2.unlock();
			Sleep(200);
			mu_e2.lock();
			dele_x(x_start, y_start + 2 * i);
			mu_e2.unlock();
			Sleep(25);
			mu_e2.lock();
			showr_x(x_start, y_start + 2 * i + 1, 0, 11);
			mu_e2.unlock();
			Sleep(200);
			mu_e2.lock();
			dele_x(x_start, y_start + 2 * i + 1);
			mu_e2.unlock();
		}
	}

}

void Enemy::move_p(int x_start, int y_start, int x_end, int y_end)
{
	int step = (x_end - x_start) / 2;
	if (hp > 0)
	{
		for (int i = 0; i < step; i++)
		{
			bool check;
			mu.lock();
			check = ingame;
			mu.unlock();
			if (check == false)
			{
				break;
			}

			if (hp <= 0)
			{
				mu.lock();
				player.in_cost(1);
				mu.unlock();
				break;
			}
			showl_p(x_start + 2 * i, y_start, 0, 11);
			Sleep(200);
			dele_p(x_start + 2 * i, y_start);
			Sleep(25);
			showr_p(x_start + 2 * i + 1, y_start, 0, 11);
			Sleep(200);
			dele_p(x_start + 2 * i + 1, y_start);
		}
	}

}

void Enemy::move_t(int x_start, int y_start, int x_end, int y_end)
{
	int step = (x_start - x_end) / 2;
	if (hp > 0)
	{
		for (int i = 0; i < step; i++)
		{
			bool check;
			mu.lock();
			check = ingame;
			mu.unlock();
			if (check == false)
			{
				break;
			}

			if (hp <= 0)
			{
				mu.lock();
				player.in_cost(1);
				mu.unlock();
				break;
			}
			showl_t(x_start - 2 * i, y_start, 0, 11);
			Sleep(200);
			dele_t(x_start - 2 * i, y_start);
			Sleep(25);
			showr_t(x_start - 2 * i - 1, y_start, 0, 11);
			Sleep(200);
			dele_t(x_start - 2 * i - 1, y_start);
		}
	}

}

void Enemy::move_map1()
{
	move_x(12, 3, 12, 30);
	move_p(28, 29, 55, 29);
	move_l(45, 19, 45, 9);
	move_p(61, 8, 109, 8);
	move_x(101, 18, 109, 30);
	move_t(92, 29, 73, 29);
	if (hp > 0)
	{
		mu.lock();
		player.de_hp(1);
		mu.unlock();
	}
	hp = 0;
}

vector<Enemy> e_global(0);

double get_distance(int x, int y, int a, int b)
{
	int tx = x - a;
	int ty = y - b;
	
	return sqrt(double(pow(tx, 2))+double (pow(ty, 2)));
}


mutex mu_global; 

void enemy_map1(int num)
{
	e_global.clear();
	e_global.resize(num);
	vector<thread> threads;

	for (int i = 0; i < num; i++)
	{
		bool check;
		mu.lock();
		check = ingame;
		mu.unlock();
		if (check == false)
		{
			break;
		}

		mu_global.lock();
		Enemy& e = e_global[i];
		mu_global.unlock();
		threads.push_back(thread(&Enemy::move_map1, &e) );
		Sleep(3000);
	}

	for (auto& th : threads)
	{
		if (th.joinable()) th.join();
	}
}