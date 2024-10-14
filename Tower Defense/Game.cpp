#include "Game.h"

void Game::setMode(int mode) {
	this->mode = mode;
}

void Game::setFlagPlaying(bool isPlaying) {
	this->isPlaying = isPlaying;
}

void Game::setFileMap(string file_map) {
	this->file_map = file_map;
}

int Game::getMode() {
	return mode;
}

bool Game::getFlagPlaying() {
	return isPlaying;
}

string Game::getFileMap() {
	return file_map;
}

void Game::setupGame() {
	Controller::SetColor(BRIGHT_WHITE, BLACK);
	system("cls");

	mode = Screen::printLevel();
	string filemap = "./Map/level" + to_string(mode + 1) + ".txt";
	
	m.setMap(filemap);
	m.printMap();
	buildTower();
}

void Game::buildTower() {
	Cell* pointer = &m.map[0][0];
	
	system("cls");
	m.printMap();
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
					pointer = &m.map[pointer->getRow() - 1][pointer->getCol()];
					pointer->hoverCell();
				}
				break;
			case 3: // left
				if (pointer->getCol() > 0) {
					pointer->printCell();
					pointer = &m.map[pointer->getRow()][pointer->getCol() - 1];
					pointer->hoverCell();
				}
				break;
			case 4: // right
				if (pointer->getCol() < m.getWidth() - 1) {
					pointer->printCell();
					pointer = &m.map[pointer->getRow()][pointer->getCol() + 1];
					pointer->hoverCell();
				}
				break;
			case 5:  // down
				if (pointer->getRow() < m.getHeight() - 1) {
					pointer->printCell();
					pointer = &m.map[pointer->getRow() + 1][pointer->getCol()];
					pointer->hoverCell();
				}
				break;
			default:
				break;
			}
		}
	}
}