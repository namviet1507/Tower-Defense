#pragma once
#include "Library.h"
#include "Menu.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"
#include "Tower.h"
#include "Play.h"
#include "Enemy.h"

class Game : public Player {
	int mode;
	bool is_playing;
	string file_map;
	Map _map;
	vector<int> list_tower;
	vector<Tower> towers;
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

	int selectTower(int x, int y);
	void printBlockSelectTower(int x, int y, int bcolor, int color, int index);

	void getPlace(vector<vector<bool>>&, vector<Cell*>& , Cell*);

	void setupGame();
	void buildTower();

	void runGame();
};

extern Game _game;