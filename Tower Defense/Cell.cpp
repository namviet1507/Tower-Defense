#include "Cell.h"

void Cell::setRowCol(int row, int col) {
	this->row = row;
	this->col = col;
}

void Cell::setColor(int color) {
	this->color = color;
}

void Cell::setColorHover() {
	if (can_build) color_hover = LIGHT_GREEN;
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
	Controller::gotoXY(pos.getX(), pos.getY());
	Controller::SetColor(color, WHITE);
	if (can_build) {
		printDes(LIGHT_YELLOW, BLACK);
	}
	else if (isGrass) {
		printGrass();
	}
	else if(isBush) {
		printBush();
	}
	else {
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

void Cell::printDes(int bcolor, int color) {
	int x = pos.getX();
	int y = pos.getY();
	if (c.size() >= 2 && c[1]) {
		Controller::SetColor(bcolor, color);
		Controller::gotoXY(x, y);
		Screen::printVietnamese(L" ╔╦╦╦╗    ╔╦╦╦╗ ");
		Controller::gotoXY(x, y + 1);
		Screen::printVietnamese(L" █████╩╩╩╩█████ ");
		Controller::gotoXY(x, y + 2);
		Screen::printVietnamese(L"  █■█      █■█  ");
		Controller::gotoXY(x, y + 3);
		Screen::printVietnamese(L" █▓█▓█    █▓█▓█ ");
		Controller::gotoXY(x, y + 4);
		Screen::printVietnamese(L"███████  ███████");

	}
	else if (c.size() >= 2 && c[0]) {
		Controller::SetColor(bcolor, color);
		Controller::gotoXY(x, y);
		Screen::printVietnamese(L" ╔╦╦╦╗  ");
		Controller::gotoXY(x, y + 1);
		Screen::printVietnamese(L" █████  ");
		Controller::gotoXY(x, y + 2);
		Screen::printVietnamese(L"  █■█   ");
		Controller::gotoXY(x, y + 3);
		Screen::printVietnamese(L" █▓█▓█  ");
		Controller::gotoXY(x, y + 4);
		Screen::printVietnamese(L"███████ ");

		Controller::SetColor(bcolor, color);
		Controller::gotoXY(x, y + 5);
		Screen::printVietnamese(L" ╔╦╦╦╗  ");
		Controller::gotoXY(x, y + 1 + 5);
		Screen::printVietnamese(L" █████  ");
		Controller::gotoXY(x, y + 2 + 5);
		Screen::printVietnamese(L"  █■█   ");
		Controller::gotoXY(x, y + 3 + 5);
		Screen::printVietnamese(L" █▓█▓█  ");
		Controller::gotoXY(x, y + 4 + 5);
		Screen::printVietnamese(L"███████ ");
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

void Cell::printGrass() {
	int x = pos.getX();
	int y = pos.getY();
	for (int i = 0; i < 5; i++) {
		Controller::gotoXY(x, y + i);
		Controller::setColorRGB(RGB_L_GREEN, RGB_L_GREEN);
		Screen::printVietnamese(L"        ");
	}

	int ran = 3127 * (row + 16) * (col * 17);
	int n = ran % 4;
	for (int i = 0; i < n; i++) {
		int denta_x = (ran * (row * i + 10 - col * i)) % 8;
		int denta_y = (ran * (row * i + 10 - col * i)) % 5;
		int t = (ran * (row * i + 10 - col * i)) % 3;
		Controller::gotoXY(x + denta_x, y + denta_y);
		if (t == 0) {
			Controller::setColorRGB(RGB_YELLOW, RGB_L_GREEN);
		}
		else if (t == 1) {
			Controller::setColorRGB(RGB_PINK, RGB_L_GREEN);
		}
		else {
			Controller::setColorRGB(RGB_PURPLE, RGB_L_GREEN);
		}
		Screen::printVietnamese(L"*");
	}
}

void Cell::printBush() {
	int x = pos.getX();
	int y = pos.getY();
	for (int i = 0; i < 5; i++) {
		Controller::gotoXY(x, y + i);
		Controller::setColorRGB(RGB_GREEN, RGB_GREEN);
		Screen::printVietnamese(L"        ");
	}

	int ran = 3127 * (row + 16) * (col * 17);

	//c[0] top, c[1] bot, c[2] left, c[3] right
	//ngang
	for (int i = 0; i < 8; i++) {
		if (c[0] == false) {
			Controller::gotoXY(x + i, y);
			int t = ran % 2;
			if (t == 0)
				Controller::setColorRGB(RGB_D_GREEN, RGB_GREEN);
			else
				Controller::setColorRGB(RGB_A_GREEN, RGB_GREEN);
			Screen::printVietnamese(L"▀");
		}

		if (c[1] == false) {
			Controller::gotoXY(x + i, y + 4);
			int t = ran % 2;
			if (t == 0)
				Controller::setColorRGB(RGB_D_GREEN, RGB_GREEN);
			else
				Controller::setColorRGB(RGB_A_GREEN, RGB_GREEN);
			Screen::printVietnamese(L"▄");
		}
	}

	//doc
	for (int i = 0; i < 5; i++) {
		if (c[2] == false) {
			Controller::gotoXY(x, y + i);
			Controller::setColorRGB(RGB_D_GREEN, RGB_A_GREEN);
			int t = ran % 2;
			if (t == 1) {
				Screen::printVietnamese(L"▀");
			}
			else {
				Screen::printVietnamese(L"▄");
			}
		}

		if (c[3] == false) {
			Controller::gotoXY(x + 7, y + i);
			Controller::setColorRGB(RGB_D_GREEN, RGB_A_GREEN);
			int t = ran % 2;
			if (t == 1) {
				Screen::printVietnamese(L"▀");
			}
			else {
				Screen::printVietnamese(L"▄");
			}
		}
	}

	int n = rand() % 4;
	for (int i = 0; i < n; i++) {
		int denta_x = n % 6 + 1;
		int denta_y = n % 3 + 1;
		Controller::gotoXY(x + denta_x, y + denta_y);
		Controller::setColorRGB(RGB_L_GREEN, RGB_GREEN);
		Screen::printVietnamese(L"▀");
	}
}

void  Cell::setC(vector<bool> _C) {
	c = _C;
}

void Cell::setFlagGrass(bool flag) {
	isGrass = flag;
}

void Cell::setFlagBush(bool flag) {
	isBush = flag;
}

bool Cell::getFlagGrass() {
	return isGrass;
}

bool Cell::getFlagBush() {
	return isBush;
}

void Cell::setFlagBuild(bool flag) {
	can_build = flag;
}
void Cell::setFlagTower(bool flag) {
	is_tower = flag;
}
void Cell::setFlagRoad(bool flag) {
	is_road = flag;
}

bool Cell::getFlagBuild() {
	return can_build;
}
bool Cell::getFlagTower() {
	return is_tower;
}
bool Cell::getFlagRoad() {
	return is_road;
}