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
	void showl(int x,int y,int bcolor,int color);
	void showr(int x, int y, int bcolor, int color);
	void delel(int x, int y);
	void deler(int x, int y);
	void move1(int num);
};