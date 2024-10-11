#pragma once
#include "Cell.h"

class Map {
	int width;
	int height;

	static const int top = 1;
	static const int left = 2;
public:
	vector<vector<Cell>> map;
	void setSize(int, int);
	void setMap(string);
	void printMap();

	void createMap();
};