#pragma once
#include "Cell.h"

class Map {
	int width;
	int height;

	static const int top = 1;
	static const int left = 2;
public:
	Map() {
		width = 0;
		height = 0;
	}
	vector<vector<Cell>> map;
	void setSize(int, int);
	void setMap(string);
	void printMap();
	int getWidth();
	int getHeight();

	void createMap();
};