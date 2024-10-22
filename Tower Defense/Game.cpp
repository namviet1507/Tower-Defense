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

	_map.setMap(file_map);
	_map.printMap();
	printControlPanel();

	buildTower();
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

Tower Game::selectTower(int x, int y) {
	Tower temp;
	for (int i = 0; i < list_tower.size(); i++) {
		Screen::printRectangle(x + (i * 7), y, 7, 9);
	}
	return temp;
}

void Game::buildTower() {
	vector<Cell*> place_build;
	for (int i = 0; i < _map.getHeight(); i++) {
		for (int j = 0; j < _map.getWidth(); j++) {
			if (_map[i][j].getFlagBuild()) {
				place_build.push_back(&_map[i][j]);
			}
		}
	}

	vector<thread> fires;
	vector<Tower> towers;

	Cell* pointer = place_build[0];
	pointer->hoverCell();

	while (true) {
		int i_min = -1;
		int min_dis = 100;
		switch (Controller::getConsoleInput()) {
		case 2: // up
			i_min = -1;
			min_dis = 100;
			for (int i = pointer->getRow() - 1; i >= 0; i--) {
				for (int j = 0; j < place_build.size(); j++) {
					if (place_build[j]->getRow() == i &&
						min_dis * min_dis > pow(abs(place_build[j]->getRow() - pointer->getRow()), 2) + pow(abs(place_build[j]->getCol() - pointer->getCol()), 2)) {
						min_dis = abs(place_build[j]->getRow() - pointer->getRow());
						i_min = j;
					}
				}
			}
			if (i_min == -1 && Menu::sound_is_open) {
				Controller::playSound(ERROR_SOUND);
			}
			else {
				if(Menu::sound_is_open) Controller::playSound(MOVE_SOUND);
				pointer->printCell();
				pointer = place_build[i_min];
				pointer->hoverCell();
			}

			break;
		case 3: // left
			i_min = -1;
			min_dis = 100;
			for (int i = pointer->getCol() - 1; i >= 0; i--) {
				for (int j = 0; j < place_build.size(); j++) {
					if (place_build[j]->getCol() == i &&
						min_dis * min_dis > pow(abs(place_build[j]->getRow() - pointer->getRow()), 2) + pow(abs(place_build[j]->getCol() - pointer->getCol()), 2)) {
						min_dis = abs(place_build[j]->getRow() - pointer->getRow());
						i_min = j;
					}
				}
			}
			if (i_min == -1 && Menu::sound_is_open) {
				Controller::playSound(ERROR_SOUND);
			}
			else {
				if (Menu::sound_is_open) Controller::playSound(MOVE_SOUND);
				pointer->printCell();
				pointer = place_build[i_min];
				pointer->hoverCell();
			}
			break;
		case 4: // right
			i_min = -1;
			min_dis = 100;
			for (int i = pointer->getCol() + 1; i < _map.getWidth(); i++) {
				for (int j = 0; j < place_build.size(); j++) {
					if (place_build[j]->getCol() == i &&
					min_dis * min_dis > pow(abs(place_build[j]->getRow() - pointer->getRow()), 2) + pow(abs(place_build[j]->getCol() - pointer->getCol()), 2)) {
						min_dis = abs(place_build[j]->getRow() - pointer->getRow());
						i_min = j;
					}
				}
			}
			if (i_min == -1 && Menu::sound_is_open) {
				Controller::playSound(ERROR_SOUND);
			}
			else {
				if (Menu::sound_is_open) Controller::playSound(MOVE_SOUND);
				pointer->printCell();
				pointer = place_build[i_min];
				pointer->hoverCell();
			}
			
			break;
		case 5:  // down
			i_min = -1;
			min_dis = 100;
			for (int i = pointer->getRow() + 1; i < _map.getHeight(); i++) {
				for (int j = 0; j < place_build.size(); j++) {
					if (place_build[j]->getRow() == i &&
						min_dis * min_dis > pow(abs(place_build[j]->getRow() - pointer->getRow()), 2) + pow(abs(place_build[j]->getCol() - pointer->getCol()), 2)) {
						min_dis = abs(place_build[j]->getRow() - pointer->getRow());
						i_min = j;
					}
				}
			}
			if (i_min == -1 && Menu::sound_is_open) {
				Controller::playSound(ERROR_SOUND);
			}
			else {
				if (Menu::sound_is_open) Controller::playSound(MOVE_SOUND);
				pointer->printCell();
				pointer = place_build[i_min];
				pointer->hoverCell();
			}
			break;
		case 6: {
			Tower tower;
			int level = 0;
			if(pointer->getPosY() == 0) 
				level = get_lever_Tower(pointer->getPosX(), pointer->getPosY() - 4, _map);
			else 
				level = get_lever_Tower(pointer->getPosX(), pointer->getPosY(), _map);
			tower.setLevel(level);


			
			break;
		}
		default:
			break;
		}
	}
}