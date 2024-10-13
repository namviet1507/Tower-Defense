#pragma once
#include "Cell.h"
#include "Controller.h"
#include  "Library.h"

using namespace std;

class Tower {
private:
	int dame;
	int numberOfBullet;
public:
	void drawTowerLevel1(int x, int y, int colorFirst, int colorSecond);
	void drawTowerLevel2(int x, int y, int colorFirst, int colorSecond);
	void drawTowerLevel3(int x, int y, int colorFirst, int colorSecond);
};