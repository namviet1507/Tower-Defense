#include "Cell.h"

void Cell::setRowCol(int row, int col) {
	this->row = row;
	this->col = col;
}

void Cell::setColor(int color) {
	this->color = color;
}

void Cell::setColorHover() {
	if (is_destination) color_hover = LIGHT_GREEN;
	else if (is_tower || is_road) color_hover = LIGHT_RED;
	else color_hover = LIGHT_YELLOW;
}

void Cell::setPos(int x, int y) {
	pos.setX(x);
	pos.setY(y);
}

void Cell::setArea(int height, int width) {
	this->height = height;
	this->width = width;
}

int Cell::getRow() {
	return row;
}

int Cell::getCol() {
	return col;
}

int Cell::getPosX() {
	return pos.getX();
}

int Cell::getPosY() {
	return pos.getY();
}

int Cell::getHeight() {
	return height;
}

int Cell::getWidth() {
	return width;
}

int Cell::getColor() {
	return color;
}

void Cell::printCell() {
	int x = pos.getX();
	int y = pos.getY();

	if (type[0]) {
		Screen::printGrass(x, y);
	}
	else if (type[1]) {
		Screen::printBush(x, y);
	}
	else if (type[2]) {
		Screen::printLand(x, y);
	}
	else {
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
}

void Cell::hoverCell() {
	int x = pos.getX();
	int y = pos.getY();

	Controller::gotoXY(pos.getX(), pos.getY());
	Controller::SetColor(color_hover, WHITE);
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

void Cell::setFlagDes(bool flag) {
	is_destination = flag;
}
void Cell::setFlagTower(bool flag) {
	is_tower = flag;
}
void Cell::setFlagRoad(bool flag) {
	is_road = flag;
}

void Cell::setFlagGrass(bool grass) {
	this->type[0] = grass;
}

void Cell::setFlagBush(bool bush) {
	this->type[1] = bush;
}

void Cell::setFlagLand(bool land) {
	this->type[2] = land;
}

bool Cell::getFlagGrass() {
	return this->type[0];
}

bool Cell::getFlagBush() {
	return this->type[1];
}

bool Cell::getFlagLand() {
	return this->type[2];
}

bool Cell::getFlagDes() {
	return is_destination;
}
bool Cell::getFlagTower() {
	return is_tower;
}
bool Cell::getFlagRoad() {
	return is_road;
}

vector<bool> Cell::getType() {
	return type;
}