#include "Cell.h"

void Cell::setColor(int color) {
	this->color = color;
}

int Cell::getColor() {
	return color;
}

void Cell::printCell() {
	Controller::gotoXY(pos.getX(), pos.getY());
	Controller::SetColor(color, color);
	cout << "  ";
}