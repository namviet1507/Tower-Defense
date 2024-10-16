#pragma once
#include "Cell.h"

class Map {
	int width;
	int height;

	static const int top = 1;
	static const int left = 2;
<<<<<<< HEAD
<<<<<<< HEAD
=======

	vector<vector<Cell>> map;
>>>>>>> 402ceb1c2157c4dd679b17212af1c6f47cf24a0d
public:
	Map() {
		width = 0;
		height = 0;
	}
<<<<<<< HEAD
=======

>>>>>>> bkhoa
	vector<vector<Cell>> map;
public:
	Map() {
		width = 0;
		height = 0;
	}
=======
>>>>>>> 402ceb1c2157c4dd679b17212af1c6f47cf24a0d
	int getHeight();
	int getWidth();

	void setSize(int, int);
	void setMap(string);
	void printMap();

	vector<Cell>& operator[] (int);

	vector<Cell>& operator[] (int);

	void createMap();
};