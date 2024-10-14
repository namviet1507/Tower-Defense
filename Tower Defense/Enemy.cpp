#include "Enemy.h"
#include "Controller.h"
mutex mu;

void Enemy::showl_x(int x,int y,int bcolor, int color)
{
	mu.lock();

	Controller::gotoXY(x-1, y - 2);
	Controller::SetColor(bcolor, 12);
	for (int i = 0; i < hp; i++)
		Screen::printVietnamese(L"█");

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
		Screen::printVietnamese(L"█");

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
		Screen::printVietnamese(L"█");

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
		Screen::printVietnamese(L"█");

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
	mu.unlock();

	x_e = x + 3;
	y_e = y + 3;
}

void Enemy::dele_l(int x, int y)
{
	mu.lock();

	Controller::gotoXY(x-1, y - 2);
	Controller::SetColor(0, 12);
	for (int i = 0; i < hp; i++)
		Screen::printVietnamese(L" ");

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
	mu.unlock();

	x_e = x + 3;
	y_e = y + 3;
}

void Enemy::showl_p(int x, int y, int bcolor, int color)
{
	mu.lock();

	Controller::gotoXY(x-1, y - 2);
	Controller::SetColor(bcolor, 12);
	for (int i = 0; i < hp/2; i++)
		Screen::printVietnamese(L"█");

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
	mu.unlock();

	x_e = x + 1;
	y_e = y + 3;
}

void Enemy::showr_p(int x, int y, int bcolor, int color)
{
	mu.lock();

	Controller::gotoXY(x-1, y - 2);
	Controller::SetColor(bcolor, 12);
	for (int i = 0; i < hp / 2; i++)
		Screen::printVietnamese(L"█");

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
	mu.unlock();

	x_e = x + 1;
	y_e = y + 3;
}

void Enemy::dele_p(int x, int y)
{
	mu.lock();

	Controller::gotoXY(x-1, y - 2);
	Controller::SetColor(0, 12);
	for (int i = 0; i < hp/2; i++)
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

void Enemy::showl_t(int x, int y, int bcolor, int color)
{
	mu.lock();

	Controller::gotoXY(x-1, y - 2);
	Controller::SetColor(bcolor, 12);
	for (int i = 0; i < hp / 2; i++)
		Screen::printVietnamese(L"█");

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
	for (int i = 0; i < hp / 2; i++)
		Screen::printVietnamese(L"█");

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
	for (int i = 0; i < hp/2; i++)
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
	for (int i = 0; i < step; i++)
	{
		if (hp <= 0) break;
		showl_l(x_start, y_start - 2 * i, 0, 11);
		Sleep(400);
		dele_l(x_start, y_start - 2 * i);
		Sleep(25);
		showr_l(x_start, y_start - 2 * i - 1, 0, 11);
		Sleep(400);
		dele_l(x_start, y_start - 2 * i - 1);
	}
}

mutex mu_e2;
void Enemy::move_x(int x_start, int y_start, int x_end, int y_end)
{
	int step = (y_end - y_start) / 2;
	for (int i = 0; i < step; i++)
	{
		if (hp <= 0) break;
		mu_e2.lock();
		showl_x(x_start, y_start + 2 * i, 0, 11);
		mu_e2.unlock();
		Sleep(400);
		mu_e2.lock();
		dele_x(x_start, y_start + 2 * i);
		mu_e2.unlock();
		Sleep(25);
		mu_e2.lock();
		showr_x(x_start, y_start + 2 * i + 1, 0, 11);
		mu_e2.unlock();
		Sleep(400);
		mu_e2.lock();
		dele_x(x_start, y_start + 2 * i + 1);
		mu_e2.unlock();
	}
}

void Enemy::move_p(int x_start, int y_start, int x_end, int y_end)
{
	int step = (x_end - x_start) / 2;
	for (int i = 0; i < step; i++)
	{
		if (hp <= 0) break;
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
		if (hp <= 0) break;
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
	move_x(10, 3, 10, 14);
	move_p(27, 14, 58, 14);
	//move_l(58, 14, 58, 0);
	//move_t(35, 3, 1, 3);
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
	e_global.resize(num);
	vector<thread> threads;

	for (int i = 0; i < num; i++)
	{
		threads.push_back(thread([i]() {
			mu_global.lock();  
			Enemy& e = e_global[i];
			mu_global.unlock(); 
			e.move_map1();      
			}));
		Sleep(5000);
	}

	for (auto& th : threads)
	{
		if (th.joinable()) th.join();
	}
}