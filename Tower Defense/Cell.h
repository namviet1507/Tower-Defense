#pragma once
#include "Library.h"
#include "Menu.h"
#include "Controller.h"
#include "Point.h"

class Cell {
	static const int Area = 2; // X = 2, Y = 1
	Point pos; // position (top left corner)
	int color;
public:
	void setColor(int);
	int getColor();
	void printCell();
};