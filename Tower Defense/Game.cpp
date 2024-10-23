#include "Game.h"

Game _game;

int Game::getMode() {
	return mode;
}
bool Game::getFlagPlaying() {
	return is_playing;
}
string Game::getFileMap() {
	return file_map;
}

void Game::setMode(int mode) {
	this->mode = mode;
}

void Game::setFlagPlaying(bool is_playing) {
	this->is_playing = is_playing;
}

void Game::setFileMap(string file_map) {
	this->file_map = file_map;
}

void Game::setupGame() {
	Controller::SetColor(BRIGHT_WHITE, BLACK);
	system("cls");

	player = { 10, 10, 40 };

	_map.setMap(file_map);
	_map.printMap();
	printControlPanel();

	buildTower();
	runGame();
	cin.get();
}

void Game::printControlPanel() {
	
	Controller::SetColor(BRIGHT_WHITE, BLACK);
	Screen::printRectangle(124, 1, 28, 38);

	Controller::gotoXY(126, 3);
	Screen::printVietnamese(L"  _ | ~_  ");
	Controller::gotoXY(126, 4);
	Screen::printVietnamese(L"[_]--'--[_]");
	Controller::gotoXY(126, 5);
	Screen::printVietnamese(L"|'|\"\"`\"\"|'|");
	Controller::gotoXY(126, 6);
	Screen::printVietnamese(L"| | /^\\ | |");
	Controller::gotoXY(126, 7);
	Screen::printVietnamese(L"|_|_|I|_|_|");

	player.print_hp(138, 4, BRIGHT_WHITE, RED);
	print_cost_first(138, 5, BRIGHT_WHITE, YELLOW);


	Screen::printRectangle(131, 36, 14, 2);
	Controller::gotoXY(134, 37);
	cout << "ESC: PAUSE";
}

void Game::printBlockSelectTower(int x, int y, int bcolor, int color,  int index) {
	Controller::SetColor(bcolor, color);
	Screen::printRectangle(x + (index * 10), y, 9, 9);
	if (index != 0) {
		Controller::gotoXY(x + (index * 10), y);
		putchar(194);
		Controller::gotoXY(x + (index * 10), y + 9);
		putchar(193);
	}
	if (index < list_tower.size()) {
		int denta_x, denta_y;
		if (list_tower[index] == 1) {
			denta_x = index * 10 + 3;
			denta_y = 2;
		}
		else if (list_tower[index] == 2) {
			denta_x = index * 10 + 2;
			denta_y = 2;
		}
		else if (list_tower[index] == 3) {
			denta_x = index * 10 + 1;
			denta_y = 2;
		}
		Tower temp;
		temp.setPos(x + denta_x, y + denta_y);
		temp.setLevel(list_tower[index]);
		temp.setDir(1);
		temp.draw_tower(bcolor, color);

		Controller::gotoXY(x + index * 10 + 4, y + 8);
		cout << temp.getPrice() << " $";
		
		Controller::gotoXY(x + (index * 10) + 10, y);
		putchar(194);
		Controller::gotoXY(x + (index * 10) + 10, y + 9);
		putchar(193);
	}
	else {
		Controller::SetColor(GRAY, YELLOW);
		Controller::gotoXY(x + (index * 10) + 3, y + 2);
		Screen::printVietnamese(L"█");
		Controller::gotoXY(x + (index * 10) + 7, y + 2);
		Screen::printVietnamese(L"█");
		Controller::gotoXY(x + (index * 10) + 4, y + 3);
		Screen::printVietnamese(L"█");
		Controller::gotoXY(x + (index * 10) + 5, y + 4);
		Screen::printVietnamese(L"█");
		Controller::gotoXY(x + (index * 10) + 4, y + 5);
		Screen::printVietnamese(L"█");
		Controller::gotoXY(x + (index * 10) + 6, y + 5);
		Screen::printVietnamese(L"█");
		Controller::gotoXY(x + (index * 10) + 6, y + 3);
		Screen::printVietnamese(L"█");
		Controller::gotoXY(x + (index * 10) + 3, y + 6);
		Screen::printVietnamese(L"█");
		Controller::gotoXY(x + (index * 10) + 7, y + 6);
		Screen::printVietnamese(L"█");
	}
}

int Game::selectTower(int x, int y) {
	Tower temp;
	Controller::SetColor(GRAY, LIGHT_YELLOW);
	for (int i = 0; i <= list_tower.size(); i++) {
		printBlockSelectTower(x, y, GRAY, YELLOW, i);
	}

	int index = 0;
	printBlockSelectTower(x, y, RED, YELLOW, index);
	while (true) {
		switch (Controller::getConsoleInput())
		{
		case 3: //left
			if (index == 0) {
				if(Menu::sound_is_open)
					Controller::playSound(ERROR_SOUND);
			}
			else {
				if (Menu::sound_is_open) Controller::playSound(MOVE_SOUND);
				printBlockSelectTower(x, y, GRAY, YELLOW, index);
				index--;
				printBlockSelectTower(x, y, RED, YELLOW, index);
			} 
			break;
		case 4: // right
			if (index == list_tower.size()) {
				if(Menu::sound_is_open)
					Controller::playSound(ERROR_SOUND);
			}
			else {
				if(Menu::sound_is_open) Controller::playSound(MOVE_SOUND);
				printBlockSelectTower(x, y, GRAY, YELLOW, index);
				index++;
				printBlockSelectTower(x, y, RED, YELLOW, index);
			}
			break;
		case 6: // enter
			if(Menu::sound_is_open) Controller::playSound(ENTER_SOUND);
			if (index == list_tower.size()) return -1;
			return list_tower[index];
			break;
		default:
			if (Menu::sound_is_open) Controller::playSound(ERROR_SOUND);
			break;
		}
	}

	return 0;
}

void Game::getPlace(vector<vector<bool>>& geted, vector<Cell*> &res, Cell* pointer) {
	if (pointer->getFlagBuild() && geted[pointer->getRow()][pointer->getCol()] == false) {
		res.push_back(pointer);
		geted[pointer->getRow()][pointer->getCol()] = true;

		if (pointer->getRow() + 1 < _map.getHeight()) {
			getPlace(geted, res, &_map[pointer->getRow() + 1][pointer->getCol()]);
		}
		if (pointer->getCol() + 1 < _map.getWidth()) {	
			getPlace(geted, res, &_map[pointer->getRow()][pointer->getCol() + 1]);
		}
	}
}

void Game::buildTower() {
	vector<vector<bool>> geted(_map.getHeight(), vector<bool>(_map.getWidth(), false));
	vector<vector<Cell*>> place_build;

	for (int i = 0; i < _map.getHeight(); i++) {
		for (int j = 0; j < _map.getWidth(); j++) {
			if (_map[i][j].getFlagBuild()) {
				vector<Cell*> temp;
				getPlace(geted, temp, &_map[i][j]);
				place_build.push_back(temp);
			}
		}
	}

	Cell* pointer = place_build[0][0];
	int index = 0;
	for (int i = 0; i < place_build[index].size(); i++) {
		place_build[index][i]->hoverCell();
	}


	while (place_build.size() > 0) {
		int i_min = -1;
		int min_dis = 100;
		pointer = place_build[index][0];
		switch (Controller::getConsoleInput()) {
		case 2: // up
			i_min = -1;
			min_dis = 100;
			for (int i = pointer->getRow() - 1; i >= 0; i--) {
				for (int j = 0; j < place_build.size(); j++) {
					if (place_build[j][0]->getRow() == i &&
						min_dis * min_dis > pow(abs(place_build[j][0]->getRow() - pointer->getRow()), 2) + pow(abs(place_build[j][0]->getCol() - pointer->getCol()), 2)) {
						min_dis = abs(place_build[j][0]->getRow() - pointer->getRow());
						i_min = j;
					}
				}
			}
			if (i_min == -1 && Menu::sound_is_open) {
				Controller::playSound(ERROR_SOUND);
			}
			else {
				if(Menu::sound_is_open) Controller::playSound(MOVE_SOUND);
				for (int i = 0; i < place_build[index].size(); i++) {
					place_build[index][i]->printCell();
				}
				pointer = place_build[i_min][0];
				index = i_min;
				for (int i = 0; i < place_build[index].size(); i++) {
					place_build[index][i]->hoverCell();
				}
			}

			break;
		case 3: // left
			i_min = -1;
			min_dis = 100;
			for (int i = pointer->getCol() - 1; i >= 0; i--) {
				for (int j = 0; j < place_build.size(); j++) {
					if (place_build[j][0]->getCol() == i &&
						min_dis * min_dis > pow(abs(place_build[j][0]->getRow() - pointer->getRow()), 2) + pow(abs(place_build[j][0]->getCol() - pointer->getCol()), 2)) {
						min_dis = abs(place_build[j][0]->getRow() - pointer->getRow());
						i_min = j;
					}
				}
			}
			if (i_min == -1 && Menu::sound_is_open) {
				Controller::playSound(ERROR_SOUND);
			}
			else {
				if (Menu::sound_is_open) Controller::playSound(MOVE_SOUND);
				for (int i = 0; i < place_build[index].size(); i++) {
					place_build[index][i]->printCell();
				}
				pointer = place_build[i_min][0];
				index = i_min;
				for (int i = 0; i < place_build[index].size(); i++) {
					place_build[index][i]->hoverCell();
				}
			}
			break;
		case 4: // right
			i_min = -1;
			min_dis = 100;
			for (int i = pointer->getCol() + 1; i < _map.getWidth(); i++) {
				for (int j = 0; j < place_build.size(); j++) {
					if (place_build[j][0]->getCol() == i &&
					min_dis * min_dis > pow(abs(place_build[j][0]->getRow() - pointer->getRow()), 2) + pow(abs(place_build[j][0]->getCol() - pointer->getCol()), 2)) {
						min_dis = abs(place_build[j][0]->getRow() - pointer->getRow());
						i_min = j;
					}
				}
			}
			if (i_min == -1 && Menu::sound_is_open) {
				Controller::playSound(ERROR_SOUND);
			}
			else {
				if (Menu::sound_is_open) Controller::playSound(MOVE_SOUND);
				for (int i = 0; i < place_build[index].size(); i++) {
					place_build[index][i]->printCell();
				}
				pointer = place_build[i_min][0];
				index = i_min;
				for (int i = 0; i < place_build[index].size(); i++) {
					place_build[index][i]->hoverCell();
				}
			}
			
			break;
		case 5:  // down
			i_min = -1;
			min_dis = 100;
			for (int i = pointer->getRow() + 1; i < _map.getHeight(); i++) {
				for (int j = 0; j < place_build.size(); j++) {
					if (place_build[j][0]->getRow() == i &&
						min_dis * min_dis > pow(abs(place_build[j][0]->getRow() - pointer->getRow()), 2) + pow(abs(place_build[j][0]->getCol() - pointer->getCol()), 2)) {
						min_dis = abs(place_build[j][0]->getRow() - pointer->getRow());
						i_min = j;
					}
				}
			}
			if (i_min == -1 && Menu::sound_is_open) {
				Controller::playSound(ERROR_SOUND);
			}
			else {
				if (Menu::sound_is_open) Controller::playSound(MOVE_SOUND);
				for (int i = 0; i < place_build[index].size(); i++) {
					place_build[index][i]->printCell();
				}
				pointer = place_build[i_min][0];
				index = i_min;
				for (int i = 0; i < place_build[index].size(); i++) {
					place_build[index][i]->hoverCell();
				}
			}
			break;
		case 6: {
			if (pointer->getFlagBuild() == false) {
				if (Menu::sound_is_open) Controller::playSound(ERROR_SOUND);
				break;
			}
			Tower tower;
			int level = 0;
			int x = pointer->getPosX();
			int y = pointer->getPosY();

			if (x >= 60) x = x + 7 - (list_tower.size() + 1) * 10;
			if (y >= 14) y = y - 5;

			level = selectTower(x, y);
			tower.setLevel(level);
			if (player.get_cost() < tower.getPrice()) {
				print_no_money(30, 18, 8, 13);
				Sleep(400);
				_map.printMap();
				break;
			}
			else {
				mu.lock();
				player.de_cost(20);
				mu.unlock();
			}

			print_cost_first(138, 5, BRIGHT_WHITE, YELLOW);

			if (level == -1) {
				for (int i = 0; i < place_build[index].size(); i++) {
					place_build[index][i]->setFlagBuild(false);
					place_build[index][i]->setColorHover();
				}
				place_build.erase(place_build.begin() + index);
				index = 0;
				if (place_build.size() > 0) {
					for (int i = 0; i < place_build[index].size(); i++) {
						place_build[index][i]->hoverCell();
					}
				}
				_map.printMap();
				break;
			}
			
			int dir = 1;
			if (_map[pointer->getRow() - 1][pointer->getCol()].getFlagRoad()) dir = 1;
			else if (_map[pointer->getRow()][pointer->getCol() - 1].getFlagRoad()) dir = 2;
			else if (_map[pointer->getRow() + 1][pointer->getCol()].getFlagRoad()) dir = 3;
			else if (_map[pointer->getRow()][pointer->getCol() + 1].getFlagRoad()) dir = 4;

			tower.setDir(dir);
			if (dir == 2)
				x = pointer->getPosX() + 3;
			else x = pointer->getPosX();
			y = pointer->getPosY();
			tower.setPos(x, y);
			towers.push_back(tower);

			for (int i = 0; i < place_build[index].size(); i++) {
				place_build[index][i]->setFlagBuild(false);
				pointer->setFlagTower(true);
				place_build[index][i]->setColorHover();
			}
			place_build.erase(place_build.begin() + index);
			index = 0;
			_map.printMap();
			for (int i = 0; i < towers.size(); i++) { 
				towers[i].draw_tower(YELLOW, BLACK);
			}

			if (place_build.size() > 0) {
				for (int i = 0; i < place_build[index].size(); i++) {
					place_build[index][i]->hoverCell();
				}
			}
			break;
		}
		default:
			break;
		}
	}
}

void Game::runGame() {
	vector<thread> threads;

	for (int i = 0; i < towers.size(); i++) {
		threads.push_back(thread(&Tower::tower_bullet, &towers[i]));
	}

	threads.push_back(thread(print_cost_player, 138, 5, BRIGHT_WHITE, YELLOW));
	threads.push_back(thread(print_hp_player, 138, 4, BRIGHT_WHITE, RED));
	threads.push_back(thread(enemy_map1, 20));
	threads.push_back(thread(check_win, 20));

	ingame = true;

	for (auto& t : threads)
	{
		t.join();
	}
}