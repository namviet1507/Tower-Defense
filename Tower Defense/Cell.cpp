#include "Cell.h"

void Cell::setColor(int color) {
	this->color = color;
}

void Cell::setPos(int x, int y) {
	pos.setX(x);
	pos.setY(y);
}

void Cell::setArea(int height, int width) {
	this->height = height;
	this->width = width;
}

int Cell::getColor() {
	return color;
}

void Cell::printCell() {
	int x = pos.getX();
	int y = pos.getY();
	Controller::gotoXY(pos.getX(), pos.getY());
	Controller::SetColor(color, WHITE);
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			Controller::gotoXY(x, y);
			cout << ' ';
			x = x + 1;
		}
		x = pos.getX();
		y = y + 1;
	}
}