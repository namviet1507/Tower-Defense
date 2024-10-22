#pragma once
#include "Library.h"
#include "Menu.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"
#include "Tower.h"
#include "Play.h"

class Game : public Player {
	int mode;
	bool is_playing;
	string file_map;
	Map _map;
	vector<int> list_tower;
public:
	Game() {
		mode = 0;
		is_playing = false;
		file_map = "";
		list_tower = { 1, 2, 3 };
	}

	int getMode();
	bool getFlagPlaying();
	string getFileMap();

	void setMode(int);
	void setFlagPlaying(bool);
	void setFileMap(string);

	void printControlPanel();
	Tower selectTower(int x, int y);

	void setupGame();
	void buildTower();
};

extern Game _game;