#pragma once
#include "Library.h"
#include "Menu.h"
#include "Controller.h"
#include "Point.h"

using namespace std;
class Enemy
{
	int hp;
public:
	void showl_x(int x,int y,int bcolor,int color);
	void showr_x(int x, int y, int bcolor, int color);
	void dele_x(int x, int y);

	void showl_l(int x, int y, int bcolor, int color);
	void showr_l(int x, int y, int bcolor, int color);
	void dele_l(int x, int y);

	void showl_p(int x, int y, int bcolor, int color);
	void showr_p(int x, int y, int bcolor, int color);
	void dele_p(int x, int y);

	void showl_t(int x, int y, int bcolor, int color);
	void showr_t(int x, int y, int bcolor, int color);
	void dele_t(int x, int y);

	void move_x(int x_start, int y_start, int x_end, int y_end);
	void move_l(int x_start, int y_start, int x_end, int y_end);
	void move_p(int x_start, int y_start, int x_end, int y_end);
	void move_t(int x_start, int y_start, int x_end, int y_end);

	void move_map1();
};

void enemy_map1(int num);