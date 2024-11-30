#include "Enemy.h"
#include "Controller.h"
mutex mu;

void Enemy::showl_x(int x, int y, int bcolor, int color)
{
	mu.lock();

	Controller::gotoXY(x - 1, y - 2);
	Controller::SetColor(bcolor, 12);
	for (int i = 0; i < hp; i++)
		cout << char(254);

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
	Screen::printVietnamese(L"██");

	Controller::gotoXY(x + 5, y + 6);
	cout << char(254) << char(254);
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

	Controller::gotoXY(x - 1, y - 2);
	Controller::SetColor(LIGHT_YELLOW, LIGHT_RED);
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

	Controller::gotoXY(x - 1, y - 2);
	Controller::SetColor(bcolor, 12);
	for (int i = 0; i < hp; i++)
		cout << char(254);


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

	Controller::gotoXY(x - 1, y - 2);
	Controller::SetColor(bcolor, 12);
	for (int i = 0; i < hp; i++)
		cout << char(254);

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

	Controller::gotoXY(x - 1, y - 2);
	Controller::SetColor(LIGHT_YELLOW, LIGHT_RED);
	for (int i = 0; i < 10; i++)
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

	Controller::gotoXY(x - 1, y - 2);
	Controller::SetColor(bcolor, 12);
	if (hp == 1)
		cout << char(254);
	for (int i = 0; i < hp / 2; i++)
		cout << char(254);


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

	Controller::gotoXY(x, y + 6);
	Screen::printVietnamese(L"██");
	mu.unlock();

	x_e = x + 1;
	y_e = y + 3;
}

void Enemy::showr_p(int x, int y, int bcolor, int color)
{
	mu.lock();

	Controller::gotoXY(x - 1, y - 2);
	Controller::SetColor(bcolor, 12);
	if (hp == 1)
		cout << char(254);
	for (int i = 0; i < hp / 2; i++)
		cout << char(254);

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

	Controller::gotoXY(x + 2, y + 6);
	Screen::printVietnamese(L"██");

	Controller::gotoXY(x, y + 6);
	cout << char(254);
	mu.unlock();

	x_e = x + 1;
	y_e = y + 3;
}

void Enemy::dele_p(int x, int y)
{
	mu.lock();

	Controller::gotoXY(x - 1, y - 2);
	Controller::SetColor(14, 12);

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

void Enemy::showl_t(int x, int y, int bcolor, int color)
{
	mu.lock();

	Controller::gotoXY(x - 1, y - 2);
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

	Controller::gotoXY(x - 1, y - 2);
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

	Controller::gotoXY(x - 1, y - 2);
	Controller::SetColor(LIGHT_YELLOW, LIGHT_RED);

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
	if (true)
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
				break;
			}
			showl_l(x_start, y_start - 2 * i, 14, 11);
			Sleep(200);
			dele_l(x_start, y_start - 2 * i);
			//Sleep(25);
			showr_l(x_start, y_start - 2 * i - 1, 14, 11);
			Sleep(200);
			dele_l(x_start, y_start - 2 * i - 1);
		}
	}
}

mutex mu_e2;
void Enemy::move_x(int x_start, int y_start, int x_end, int y_end)
{
	int step = (y_end - y_start) / 2;
	if (true)
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
				break;
			}
			mu_e2.lock();
			showl_x(x_start, y_start + 2 * i, 14, 11);
			mu_e2.unlock();
			Sleep(200);
			mu_e2.lock();
			dele_x(x_start, y_start + 2 * i);
			mu_e2.unlock();
			//Sleep(25);
			mu_e2.lock();
			showr_x(x_start, y_start + 2 * i + 1, 14, 11);
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
	if (true)
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
				break;
			}
			showl_p(x_start + 2 * i, y_start, 14, 11);
			Sleep(200);
			dele_p(x_start + 2 * i, y_start);
			//Sleep(25);
			showr_p(x_start + 2 * i + 1, y_start, 14, 11);
			Sleep(200);
			dele_p(x_start + 2 * i + 1, y_start);
		}
	}

}

void Enemy::move_t(int x_start, int y_start, int x_end, int y_end)
{
	int step = (x_start - x_end) / 2;
	if (true)
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
				break;
			}
			showl_t(x_start - 2 * i, y_start, 14, 11);
			Sleep(200);
			dele_t(x_start - 2 * i, y_start);
			//Sleep(25);
			showr_t(x_start - 2 * i - 1, y_start, 14, 11);
			Sleep(200);
			dele_t(x_start - 2 * i - 1, y_start);
		}
	}

}


vector<Enemy> e_global(0);

double Enemy::get_distance(int x, int y, int a, int b)
{
	int tx = x - a;
	int ty = y - b;

	return sqrt(double(pow(tx, 2)) + double(pow(ty, 2)));
}



//
//void Enemy::MOVE(string fileName)
//{
//	Map other;
//	other.setMap(fileName);
//	vector< vector<int> > toMove;
//	other.browerMap(toMove);
//
//	for (int i = 0; i < toMove.size(); i++)
//	{
//		int WAY, start_X, start_Y, end_X, end_Y;
//		WAY = toMove[i][0];
//		start_X = toMove[i][1];
//		start_Y = toMove[i][2];
//		end_X = toMove[i][3];
//		end_Y = toMove[i][7];
//		if (WAY == 0)
//		{
//			move_l(start_X, start_Y, end_X, end_Y);
//		}
//		if (WAY == 1)
//		{
//			move_x(start_X, start_Y, end_X, end_Y);
//		}
//		if (WAY == 2)
//		{
//			move_t(start_X, start_Y, end_X, end_Y);
//		}
//		if (WAY == 3)
//		{
//			move_p(start_X, start_Y, end_X, end_Y);
//		}
//	}
//
//}