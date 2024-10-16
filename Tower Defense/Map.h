#pragma once
#include "Cell.h"

class Map {
	int width;
	int height;

	static const int top = 1;
	static const int left = 2;
<<<<<<< HEAD
public:
	Map() {
		width = 0;
		height = 0;
	}
=======

>>>>>>> bkhoa
	vector<vector<Cell>> map;
public:
	Map() {
		width = 0;
		height = 0;
	}
	int getHeight();
	int getWidth();

	void setSize(int, int);
	void setMap(string);
	void printMap();
	int getWidth();
	int getHeight();

	vector<Cell>& operator[] (int);

	void createMap();
};