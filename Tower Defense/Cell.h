#pragma once
#include "Library.h"
#include "Menu.h"
#include "Controller.h"
#include "Point.h"
#include "Tower.h"

class Cell {
	int row;
	int col;

	int width;
	int height;

	int color;
	int color_hover;

	bool can_build;
	bool is_tower;
	bool is_road;

	Point pos; // position (top left corner)
public:
	Cell() {
		row = 0;
		col = 0;
		width = 0;
		height = 0;
		color = BLACK;
		color_hover = LIGHT_YELLOW;
		pos.setX(0);
		pos.setY(0);
		can_build = false;
		is_tower = false;
		is_road = false;
	}

	void setRowCol(int, int);

	void setColor(int);
	void setColorHover();
	void setPos(int, int);
	void setArea(int, int);

	void setFlagBuild(bool);
	void setFlagTower(bool);
	void setFlagRoad(bool);

	bool getFlagBuild();
	bool getFlagTower();
	bool getFlagRoad();

	int getRow();
	int getCol();

	int getPosX();
	int getPosY();

	int getColor();
	int getHeight();
	int getWidth();

	void printCell();
	void hoverCell();
};