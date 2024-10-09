#include "Map.h"


void Map::setSize(int width, int height) {
	this->width = width;
	this->height = height;
}

void Map::setMap(string fileMap) {
	fstream fin;
	fin.open(fileMap.c_str(), ios::in);

	fin.close();
}

void Map::printMap() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j].printCell();
		}
	}
}