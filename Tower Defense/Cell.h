#pragma once
#include "Library.h"
#include "Menu.h"
#include "Controller.h"
#include "Point.h"

class Cell {
	int width;
	int height;
	Point pos; // position (top left corner)
	int color;
	bool can_build;
	bool is_tower;
	bool is_road;
public:
	void setColor(int);
	void setPos(int, int);
	void setArea(int, int);
	void setFlagBuild(bool);
	void setFlagTower(bool);
	void setFlagRoad(bool);
	int getColor();
	void printCell();
};