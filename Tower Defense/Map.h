#pragma once
#include "Cell.h"

class Map {
	vector<vector<Cell>> map;
	int width;
	int height;

	static const int top = 1;
	static const int left = 2;
public:
	void setSize(int, int);
	void setMap(string);
	void printMap();
};