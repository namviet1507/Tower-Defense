#pragma once
#include "Library.h"
#include "Menu.h"
#include "Controller.h"
#include "Point.h"
#include "Library.h"
#include <vector>

using namespace std;

extern mutex mu;

class Enemy
{
	int hp;
	int x_e;
	int y_e;
public:
	Enemy() { hp = 10; x_e = 0; y_e = 0; }

	int get_x() { return x_e; }
	int get_y() { return y_e; }
	void sub_hp() { hp--; }

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

extern vector<Enemy> e_global;
double get_distance(int x, int y, int a, int b);

void enemy_map1(int num);