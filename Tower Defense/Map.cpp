#include "Map.h"

int Map::getHeight() {
	return height;
}

int Map::getWidth() {
	return width;
}

void Map::setSize(int height, int width) {
	this->width = width;
	this->height = height;
	map.resize(height);
	for (int i = 0; i < height; i++) map[i].resize(width);
}

void Map::setMap(string fileMap) {
	fstream fin;
	fin.open(fileMap.c_str(), ios::in);

	if (fin.is_open() == false) {
		Controller::SetColor(BLACK, BLACK);
		system("cls");
		exit(0);
		return;
	}

	int cell_width;
	int cell_height;

	fin >> cell_height >> cell_width >> height >> width;
	setSize(height, width);

	int x = left;
	int y = top;

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int color;
			bool flag_build, flag_tower, flag_road;
			fin >> color >> flag_build >> flag_tower >> flag_road;
			// color 
			map[i][j].setColor(color);
			map[i][j].setFlagBuild(flag_build);
			map[i][j].setFlagTower(flag_tower);
			map[i][j].setFlagRoad(flag_road);
			map[i][j].setColorHover();
			map[i][j].setArea(cell_height, cell_width);
			map[i][j].setRowCol(i, j);
			map[i][j].setPos(x, y);
			x = x + cell_width;
		}
		x = left;
		y = y + cell_height;
	}

	fin.close();
}

void Map::printMap() {
	Controller::SetColor(BRIGHT_WHITE, BLACK);
	system("cls");
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			map[i][j].printCell();
		}
	}
}

vector<Cell>& Map::operator [] (int index) {
	return map[index];
}

void Map::createMap() {
	cout << "Input size map: ";
	int h, w;
	cin >> height >> width;
	setSize(height, width);

	cout << "Input (h, w): ";
	cin >> h >> w;

	cout << "Input name file: ";
	string filename;
	cin >> filename;

	int x = left, y = top;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j].setArea(h, w);
			map[i][j].setColor(AQUA);
			map[i][j].setPos(x, y);
			map[i][j].setRowCol(i, j);
			map[i][j].setColorHover();
			x += w;
		}
		x = left;
		y += h;
	}

	system("cls");
	printMap();

	Cell* pointer = &map[0][0];
	pointer->hoverCell();

	int color;
	bool flag_build, flag_tower, flag_road;

	Controller::gotoXY(132, 2);
	Controller::SetColor(BLACK, WHITE);
	cout << "input color: ";
	cin >> color;
	Controller::gotoXY(132, 3);
	cout << "can build: ";
	cin >> flag_build;
	Controller::gotoXY(132, 4);
	cout << "is tower: ";
	cin >> flag_tower;
	Controller::gotoXY(132, 5);
	cout << "is road: ";
	cin >> flag_road;


	for (int i = 0; i < 4; i++) {
		Controller::gotoXY(132, 2 + i);
		Controller::SetColor(BLACK, BLACK);
		cout << "                         ";
	}

	int num = 0;
	bool stop = false;

	while (stop == false) {
		if (_kbhit()) {
			switch (Controller::getConsoleInput()) {
			case 1:
				stop = true;
				break;
			case 2: // up
				if (pointer->getRow() > 0) {
					pointer->printCell();
					pointer = &map[pointer->getRow() - 1][pointer->getCol()];
					pointer->hoverCell();
				}
				break;
			case 3: // left
				if (pointer->getCol() > 0) {
					pointer->printCell();
					pointer = &map[pointer->getRow()][pointer->getCol() - 1];
					pointer->hoverCell();
				}
				break;
			case 4: // right
				if (pointer->getCol() < width - 1) {
					pointer->printCell();
					pointer = &map[pointer->getRow()][pointer->getCol() + 1];
					pointer->hoverCell();
				}
				break;
			case 5:  // down
				if (pointer->getRow() < height - 1) {
					pointer->printCell();
					pointer = &map[pointer->getRow() + 1][pointer->getCol()];
					pointer->hoverCell();
				}
				break;
			case 6:
				pointer->setColor(color);
				pointer->setFlagBuild(flag_build);
				pointer->setFlagTower(flag_tower);
				pointer->setFlagRoad(flag_road);
				pointer->setMark(num);
				num++;
				pointer->setColorHover();
				break;
			case 15:
				Controller::gotoXY(132, 2);
				Controller::SetColor(BLACK, WHITE);
				cout << "input color: ";
				cin >> color;
				Controller::gotoXY(132, 3);
				cout << "can build: ";
				cin >> flag_build;
				Controller::gotoXY(132, 4);
				cout << "is tower: ";
				cin >> flag_tower;
				Controller::gotoXY(132, 5);
				cout << "is road: ";
				cin >> flag_road;

				for (int i = 0; i < 4; i++) {
					Controller::gotoXY(132, 2 + i);
					Controller::SetColor(BLACK, BLACK);
					cout << "                         ";
				}
				break;
			default:
				break;
			}
		}
	}

	fstream fout;
	filename = "./Map/" + filename;
	fout.open(filename.c_str(), ios::out);

	fout << h << ' ' << w << ' ' << height << ' ' << width << '\n';
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			fout << map[i][j].getColor() << ' ' << map[i][j].getFlagBuild() << ' ' << map[i][j].getFlagTower() << ' ' << map[i][j].getFlagRoad() << map[i][j].getMark() << '\n';
		}
		cout << '\n';
	}

	fout.close();
}