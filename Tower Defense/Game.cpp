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

	buildTower();
}

void Game::buildTower() {
	Cell* pointer = &_map[0][0];
	pointer->hoverCell();

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
					pointer = &_map[pointer->getRow() - 1][pointer->getCol()];
					pointer->hoverCell();
				}
				break;
			case 3: // left
				if (pointer->getCol() > 0) {
					pointer->printCell();
					pointer = &_map[pointer->getRow()][pointer->getCol() - 1];
					pointer->hoverCell();
				}
				break;
			case 4: // right
				if (pointer->getCol() < _map.getWidth() - 1) {
					pointer->printCell();
					pointer = &_map[pointer->getRow()][pointer->getCol() + 1];
					pointer->hoverCell();
				}
				break;
			case 5:  // down
				if (pointer->getRow() < _map.getHeight() - 1) {
					pointer->printCell();
					pointer = &_map[pointer->getRow() + 1][pointer->getCol()];
					pointer->hoverCell();
				}
				break;
			case 6:
				
				break;
			case 15:
				
				break;
			default:
				break;
			}
		}
	}
}