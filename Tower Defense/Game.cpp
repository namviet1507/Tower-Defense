#include "Game.h"

int Game::mode = 1;
bool Game::isPlaying = false;

void Game::setupGame() {
	Controller::SetColor(BRIGHT_WHITE, BLACK);
	system("cls");

	mode = Screen::printLevel();
	string filemap = "./Map/level" + to_string(mode) + ".txt";
	
	m.setMap(filemap);
	m.printMap();
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