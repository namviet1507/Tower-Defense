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
		Controller::SetColor(BLACK, 4);
		system("cls");
		exit(0);
		return;
	}

	int cell_width;
	int cell_height;

	fin >> numRow >> cell_height >> cell_width >> height >> width;
	setSize(height, width);

	int x = left;
	int y = top;

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int color;
			bool flag_build, flag_tower, flag_road;
			int mark;
			fin >> color >> flag_build >> flag_tower >> flag_road >> mark;
			// color 
			map[i][j].setColor(color);
			map[i][j].setFlagBuild(flag_build);
			map[i][j].setFlagTower(flag_tower);
			map[i][j].setFlagRoad(flag_road);
			map[i][j].setColorHover();
			map[i][j].setArea(cell_height, cell_width);
			map[i][j].setRowCol(i, j);
			map[i][j].setPos(x, y);
			map[i][j].setMark(mark);
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
			map[i][j].setMark(-1);
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
	int num(0);
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
	fout << num << ' ';
	fout << h << ' ' << w << ' ' << height << ' ' << width << '\n';
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			fout << map[i][j].getColor() << ' ' << map[i][j].getFlagBuild() << ' ' << map[i][j].getFlagTower() << ' ' << map[i][j].getFlagRoad() << " " << map[i][j].getMark() << '\n';
		}
		cout << '\n';
	}

	fout.close();
}

void Map::browseMap(vector< vector< int > >& result)
{
	Cell start;
	int posx, posy;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j].getMark() == 0)
			{
				start = map[i][j];
				posx = i;
				posy = j;
			}
		}
	}
	int currentPos_I, currentPos_J;
	Cell cur;
	vector<bool> checkWay(4, false);
	// checkWay[0]:up
	// checkWay[1]:down
	// checkWay[2]:left
	// checkWay[3]:right
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j].getMark() == 1)
			{
				cur = map[i][j];
				currentPos_I = i;
				currentPos_J = j;
				if (i - posx == 1 && j == posy)
				{
					checkWay[1] = true;
				}
				if (posx - i == 1 && j == posy)
				{
					checkWay[0] = true;
				}
				if (i == posx && posy - j == 1)
				{
					checkWay[2] = true;
				}
				if (i == posx && j - posy == 1)
				{
					checkWay[3] = true;
				}
			}
		}
	}

	int indexX[4] = { -1, 1,  0, 0 };
	int indexY[4] = { 0,  0, -1, 1 };
	// k = 0 : up
	// k = 1 : down
	// k = 2 : left
	// k = 3 : right.

	Cell end;
	while (numRow)
	{
		// is going up
		if (checkWay[0])
		{
			bool satifiedWay0 = false;
			end = cur;
			for (int i = 0; i < 4; i++)
			{
				if (i == 0 || i == 1) continue;
				// i == 2 || i == 3: left || right

				int newIndexX = currentPos_I + indexX[i];
				int newIndexY = currentPos_J + indexY[i];
				if (newIndexX < 0 || newIndexX >= height) continue;
				if (newIndexY < 0 || newIndexY >= width) continue;
				cur = map[newIndexX][newIndexY];

				if (map[newIndexX][newIndexY].getMark() != -1)
				{
					// change way.
					vector<int> temp;
					temp.push_back(0);
					temp.push_back(start.getPosX());
					temp.push_back(start.getPosY());
					temp.push_back(end.getPosX());
					temp.push_back(end.getPosY());
					result.push_back(temp);

					if (i == 2)
					{
						checkWay[2] = true;
						checkWay[0] = false;
						start = end;
						currentPos_I = newIndexX;
						currentPos_J = newIndexY;
						satifiedWay0 = true;
						break;
					}
					if (i == 3)
					{
						checkWay[3] = true;
						checkWay[0] = false;
						start = end;
						currentPos_I = newIndexX;
						currentPos_J = newIndexY;
						satifiedWay0 = true;
						break;
					}
				}
			}

			//no change way
			if (!satifiedWay0)
			{
				currentPos_I += indexX[0];
				currentPos_J += indexY[0];
				cur = map[currentPos_I][currentPos_J];

				if (cur.getMark() == -1)
				{
					vector<int> newTemp;
					newTemp.push_back(0);
					newTemp.push_back(start.getPosX());
					newTemp.push_back(start.getPosY());
					newTemp.push_back(end.getPosX());
					newTemp.push_back(end.getPosY());
					result.push_back(newTemp);
					return;
				}
			}


		}

		// is going down
		if (checkWay[1])
		{
			bool satifiedWay1 = false;
			end = cur;
			for (int i = 0; i < 4; i++)
			{
				if (i == 0 || i == 1) continue;
				// i == 2 || i == 3: left || right
				int newIndexX = currentPos_I + indexX[i];
				int newIndexY = currentPos_J + indexY[i];
				if (newIndexX < 0 || newIndexX >= height) continue;
				if (newIndexY < 0 || newIndexY >= width) continue;
				cur = map[newIndexX][newIndexY];

				if (map[newIndexX][newIndexY].getMark() != -1)
				{
					// change way.
					vector<int> temp;
					temp.push_back(1);
					temp.push_back(start.getPosX());
					temp.push_back(start.getPosY());
					temp.push_back(end.getPosX());
					temp.push_back(end.getPosY());
					result.push_back(temp);

					if (i == 2)
					{
						checkWay[2] = true;
						checkWay[1] = false;
						start = end;
						currentPos_I = newIndexX;
						currentPos_J = newIndexY;
						satifiedWay1 = true;

						break;
					}
					if (i == 3)
					{
						checkWay[3] = true;
						checkWay[1] = false;
						start = end;
						currentPos_I = newIndexX;
						currentPos_J = newIndexY;
						satifiedWay1 = true;

						break;
					}
				}
			}

			//no change way
			if (!satifiedWay1)
			{
				currentPos_I += indexX[1];
				currentPos_J += indexY[1];
				cur = map[currentPos_I][currentPos_J];
				if (cur.getMark() == -1)
				{
					vector<int> newTemp;
					newTemp.push_back(1);
					newTemp.push_back(start.getPosX());
					newTemp.push_back(start.getPosY());
					newTemp.push_back(end.getPosX());
					newTemp.push_back(end.getPosY());
					result.push_back(newTemp);
					return;
				}
			}
		}

		// is going left
		if (checkWay[2])
		{
			bool satifiedWay2 = false;
			end = cur;
			for (int i = 0; i < 4; i++)
			{
				if (i == 2 || i == 3) continue;
				// i == 0 || i == 1 : up || down
				int newIndexX = currentPos_I + indexX[i];
				int newIndexY = currentPos_J + indexY[i];

				if (newIndexX < 0 || newIndexX >= height) continue;
				if (newIndexY < 0 || newIndexY >= width) continue;
				cur = map[newIndexX][newIndexY];
				if (map[newIndexX][newIndexY].getMark() != -1)
				{
					// change way.
					vector<int> temp;
					temp.push_back(2);
					temp.push_back(start.getPosX());
					temp.push_back(start.getPosY());
					temp.push_back(end.getPosX());
					temp.push_back(end.getPosY());
					result.push_back(temp);

					if (i == 0)
					{
						checkWay[0] = true;
						checkWay[2] = false;
						start = end;
						currentPos_I = newIndexX;
						currentPos_J = newIndexY;
						satifiedWay2 = true;

						break;
					}
					if (i == 1)
					{
						checkWay[1] = true;
						checkWay[2] = false;
						start = end;
						currentPos_I = newIndexX;
						currentPos_J = newIndexY;
						satifiedWay2 = true;
						break;
					}
				}
			}

			//no change way
			if (!satifiedWay2) {
				currentPos_I += indexX[2];
				currentPos_J += indexY[2];
				cur = map[currentPos_I][currentPos_J];
				if (cur.getMark() == -1)
				{
					vector<int> newTemp;
					newTemp.push_back(2);
					newTemp.push_back(start.getPosX());
					newTemp.push_back(start.getPosY());
					newTemp.push_back(end.getPosX());
					newTemp.push_back(end.getPosY());
					result.push_back(newTemp);
					return;
				}
			}
		}

		// is going right
		if (checkWay[3])
		{
			bool satifiedWay3 = false;
			end = cur;
			for (int i = 0; i < 4; i++)
			{
				if (i == 2 || i == 3) continue;
				// i == 0 || i == 1: up || down
				int newIndexX = currentPos_I + indexX[i];
				int newIndexY = currentPos_J + indexY[i];
				if (newIndexX < 0 || newIndexX >= height) continue;
				if (newIndexY < 0 || newIndexY >= width) continue;
				cur = map[newIndexX][newIndexY];

				if (map[newIndexX][newIndexY].getMark() != -1)
				{
					// change way.
					vector<int> temp;
					temp.push_back(3);
					temp.push_back(start.getPosX());
					temp.push_back(start.getPosY());
					temp.push_back(end.getPosX());
					temp.push_back(end.getPosY());
					result.push_back(temp);

					if (i == 0)
					{
						checkWay[0] = true;
						checkWay[3] = false;
						start = end;
						currentPos_I = newIndexX;
						currentPos_J = newIndexY;
						satifiedWay3 = true;
						break;
					}
					if (i == 1)
					{
						checkWay[1] = true;
						checkWay[3] = false;
						start = end;
						currentPos_I = newIndexX;
						currentPos_J = newIndexY;
						satifiedWay3 = true;
						break;
					}
				}
			}

			//no change way
			if (!satifiedWay3)
			{
				currentPos_I += indexX[3];
				currentPos_J += indexY[3];
				cur = map[currentPos_I][currentPos_J];
				if (cur.getMark() == -1)
				{
					vector<int> newTemp;
					newTemp.push_back(3);
					newTemp.push_back(start.getPosX());
					newTemp.push_back(start.getPosY());
					newTemp.push_back(end.getPosX());
					newTemp.push_back(end.getPosY());
					result.push_back(newTemp);
					return;
				}
			}
		}
		--numRow;
	}
}

void Map::findPositionOfTower(vector< vector<int> >& result)
{
	int indexX[4] = { -1, 1, 0, 0 };
	int indexY[4] = { 0, 0, -1, 1 };

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			vector<int>temp;

			if (map[i][j].getFlagTower())
			{
				for (int k = 0; k < 4; k++)
				{
					int newIndexX = indexX[k] + i;
					int newIndexY = indexY[k] + j;

					if (newIndexX < 0 || newIndexX >= height) continue;
					if (newIndexY < 0 || newIndexY >= width) continue;

					if (map[newIndexX][newIndexY].getFlagRoad())
					{
						temp.push_back(k);
						while (newIndexX + indexX[k] >= 0 && newIndexX + indexX[k] < height && newIndexY + indexY[k] >= 0 && newIndexY + indexY[k] < width && map[newIndexX + indexX[k]][newIndexY + indexY[k]].getFlagRoad())
						{
							newIndexX += indexX[k];
							newIndexY += indexY[k];
						}
						temp.push_back(map[i][j].getPosX());
						temp.push_back(map[i][j].getPosY());
						temp.push_back(map[newIndexX][newIndexY].getPosX());
						temp.push_back(map[newIndexX][newIndexY].getPosY());
						break;
					}
				}
				result.push_back(temp);
			}
		}
	}

}