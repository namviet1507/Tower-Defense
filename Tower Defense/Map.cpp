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
	fin.open(fileMap.c_str(), ios::in | ios::binary);

	if (fin.is_open() == false) {
		Controller::SetColor(BLACK, BLACK);
		system("cls");
		exit(0);
		return;
	}

	if (fin.is_open() == false) {
		Controller::SetColor(BLACK, BLACK);
		system("cls");
		exit(0);
		return;
	}

	int cell_width;
	int cell_height;

	fin.read((char*)&cell_height, sizeof(int));
	fin.read((char*)&cell_width, sizeof(int));
	fin.read((char*)&height, sizeof(int));
	fin.read((char*)&width, sizeof(int));

	setSize(height, width);

	int x = left;
	int y = top;

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int color;
			bool flag_build, flag_tower, flag_road;

			fin.read((char*)&color, sizeof(int));
			fin.read((char*)&flag_build, sizeof(bool));
			fin.read((char*)&flag_tower, sizeof(bool));
			fin.read((char*)&flag_road, sizeof(bool));

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
	cin >> height >> width;
	setSize(height, width);

	cout << "Input (h, w): ";
	int h, w;
	cin >> h >> w;

	cout << "Input name file: ";
	string filename;
	cin >> filename;

	cout << "Input mode: ";
	string mode;
	cin >> mode;

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

	fstream fout, file_list_map;

	string path;
	if (mode == "Easy") path = FileListMapEasy;
	else if (mode == "Dificult") path = FileListMapDificult;
	else path = FileListMapNormal;

	file_list_map.open(path, ios::app | ios::binary);
	if (file_list_map.is_open() == false) return;
	char c_filename[100];
	strcpy_s(c_filename, filename.c_str());
	file_list_map.write((char*)&c_filename, 100);
	file_list_map.close();

	filename = "./Map/" + mode + '/' + filename;
	fout.open(filename.c_str(), ios::out | ios::binary);

	if (fout.is_open() == false) {
		return;
	}

	fout.write((char*)&h, sizeof(int));
	fout.write((char*)&w, sizeof(int));
	fout.write((char*)&height, sizeof(int));
	fout.write((char*)&width, sizeof(int));

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			color = map[i][j].getColor();
			flag_build = map[i][j].getFlagBuild();
			flag_tower = map[i][j].getFlagTower();
			flag_road = map[i][j].getFlagRoad();

			fout.write((char*)&color, sizeof(int));
			fout.write((char*)&flag_build, sizeof(bool));
			fout.write((char*)&flag_tower, sizeof(bool));
			fout.write((char*)&flag_road, sizeof(bool));

		}
	}

	fout.close();
}