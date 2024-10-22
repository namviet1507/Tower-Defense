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

	//Screen::printRectangle(136, 29, 3, 2);
	//Controller::gotoXY(138, 30);
	//Screen::printVietnamese(L"^");
	//Screen::printRectangle(131, 32, 3, 2);
	//Controller::gotoXY(133, 33);
	//Screen::printVietnamese(L"<");
	//Screen::printRectangle(136, 32, 3, 2);
	//Controller::gotoXY(138, 33);
	//Screen::printVietnamese(L"v");
	//Screen::printRectangle(141, 32, 3, 2);
	//Controller::gotoXY(143, 33);
	//Screen::printVietnamese(L">");

	Screen::printRectangle(131, 36, 14, 2);
	Controller::gotoXY(134, 37);
	cout << "ESC: PAUSE";

	/*Tower tower;
	tower.drawTowerLevel1_Up(126, 3, BRIGHT_WHITE, GRAY);
	Controller::SetColor(BRIGHT_WHITE, BLACK);
	Controller::gotoXY(136, 3);
	cout << "Tower level 1";
	Controller::gotoXY(136, 4);
	cout << "Dame: 1";
	Controller::gotoXY(136, 5);
	cout << "speed: x";

	tower.drawTowerLevel2_Up(126, 10, BRIGHT_WHITE, GRAY);
	Controller::SetColor(BRIGHT_WHITE, BLACK);
	Controller::gotoXY(136, 10);
	cout << "Tower level 2";
	Controller::gotoXY(136, 11);
	cout << "Dame: 2";
	Controller::gotoXY(136, 12);
	cout << "speed: x";*/
}

void Game::selectTower() {
	Tower tower;
	tower.drawTowerLevel1_Up(126, 3, BRIGHT_WHITE, GRAY);
	Controller::SetColor(BRIGHT_WHITE, BLACK);
	Controller::gotoXY(136, 3);
	cout << "Tower level 1";
	Controller::gotoXY(136, 4);
	cout << "Dame: 1";
	Controller::gotoXY(136, 5);
	cout << "speed: x";

	tower.drawTowerLevel2_Up(126, 10, BRIGHT_WHITE, GRAY);
	Controller::SetColor(BRIGHT_WHITE, BLACK);
	Controller::gotoXY(136, 10);
	cout << "Tower level 2";
	Controller::gotoXY(136, 11);
	cout << "Dame: 2";
	Controller::gotoXY(136, 12);
	cout << "speed: x";
}

void Game::buildTower() {




	//Cell* pointer = &_map[0][0];
	//pointer->hoverCell();

	//bool stop = false;
	//while (stop == false) {
	//	if (_kbhit()) {
	//		switch (Controller::getConsoleInput()) {
	//		case 1:
	//			stop = true;
	//			break;
	//		case 2: // up
	//			if (pointer->getRow() > 0) {
	//				if (Menu::sound_is_open) {
	//					Controller::playSound(MOVE_SOUND);
	//				}
	//				pointer->printCell();
	//				pointer = &_map[pointer->getRow() - 1][pointer->getCol()];
	//				pointer->hoverCell();
	//			}
	//			else {
	//				if (Menu::sound_is_open) {
	//					Controller::playSound(ERROR_SOUND);
	//				}
	//			}
	//			break;
	//		case 3: // left
	//			if (pointer->getCol() > 0) {
	//				if (Menu::sound_is_open) {
	//					Controller::playSound(MOVE_SOUND);
	//				}
	//				pointer->printCell();
	//				pointer = &_map[pointer->getRow()][pointer->getCol() - 1];
	//				pointer->hoverCell();
	//			}
	//			else {
	//				if (Menu::sound_is_open) {
	//					Controller::playSound(ERROR_SOUND);
	//				}
	//			}
	//			break;
	//		case 4: // right
	//			if (pointer->getCol() < _map.getWidth() - 1) {
	//				if (Menu::sound_is_open) {
	//					Controller::playSound(MOVE_SOUND);
	//				}
	//				pointer->printCell();
	//				pointer = &_map[pointer->getRow()][pointer->getCol() + 1];
	//				pointer->hoverCell();
	//			}
	//			else {
	//				if (Menu::sound_is_open) {
	//					Controller::playSound(ERROR_SOUND);
	//				}
	//			}
	//			break;
	//		case 5:  // down
	//			if (pointer->getRow() < _map.getHeight() - 1) {
	//				if (Menu::sound_is_open) {
	//					Controller::playSound(MOVE_SOUND);
	//				}
	//				pointer->printCell();
	//				pointer = &_map[pointer->getRow() + 1][pointer->getCol()];
	//				pointer->hoverCell();
	//			}
	//			else {
	//				if (Menu::sound_is_open) {
	//					Controller::playSound(ERROR_SOUND);
	//				}
	//			}
	//			break;
	//		case 6:
	//			if (pointer->getFlagBuild()) {
	//				if (Menu::sound_is_open) {
	//					Controller::playSound(ENTER_SOUND);
	//				}
	//				
	//			}
	//			else {
	//				if (Menu::sound_is_open) {
	//					Controller::playSound(ERROR_SOUND);
	//				}
	//			}
	//			break;
	//		case 15:
	//			
	//			break;
	//		default:
	//			if (Menu::sound_is_open) {
	//				Controller::playSound(ERROR_SOUND);
	//			}
	//			break;
	//		}
	//	}
	//}
}