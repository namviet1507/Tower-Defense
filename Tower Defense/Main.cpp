#include "Game.h"
#include "Controller.h"
#include "Map.h"
#include "Enemy.h"
#include "Tower.h"
#include "Play.h"

//vector<vector<Cell>> findPath(Map _map) {
//	for (int i = 0; i < _map.getHeight(); i++) {
//		if (_map[i][0].getFlagRoad() || _map[i][_map.getWidth() - 1].getFlagBuild()) {
//
//		}
//	}
//	for (int j = 0; j < _map.getWidth(); j++) {
//		if (_map[0][j].getFlagRoad() || _map[_map.getHeight() - 1][j].getFlagBuild()) {
//
//		}
//	}
//}

int main() {
	Controller::setUpConsole();
	Menu::music_is_open = true;
	Menu::sound_is_open = true;
	Screen::printMainScreen();

	Map map;

	map.setMap("./Map/Easy/level1.bin");

	

	return 0;
}