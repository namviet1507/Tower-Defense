#include "Map.h"


void Map::setSize(int width, int height) {
	this->width = width;
	this->height = height;
}

void Map::setMap(string fileMap) {
	fstream fin;
	fin.open(fileMap.c_str(), ios::in);

	int cell_width;
	int cell_height;

	fin >> cell_height >> cell_width >> height >> width;
	map.resize(height);

	int x = left;
	int y = top;

	for (int i = 0; i < height; ++i) {
		map[i].resize(width);
		for (int j = 0; j < width; ++j) {
			int color;
			fin >> color;
			// color 
			map[i][j].setColor(color);
			map[i][j].setArea(cell_height, cell_width);
			map[i][j].setPos(x, y);
			x = x + cell_width;
		}
		x = left;
		y = y + cell_height;
	}

	fin.close();
}

void Map::printMap() {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			map[i][j].printCell();
		}
	}
}