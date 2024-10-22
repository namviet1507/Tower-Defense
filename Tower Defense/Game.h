#pragma once
#include "Library.h"
#include "Menu.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"
#include "Tower.h"

class Game : public Player {
	int mode;
	bool is_playing;
	string file_map;
	Map _map;

	vector<Cell*> places;

public:
	int getMode();
	bool getFlagPlaying();
	string getFileMap();

	void setMode(int);
	void setFlagPlaying(bool);
	void setFileMap(string);

	void printControlPanel();
	void selectTower();

	void setPlaceBuild();

	void setupGame();
	void buildTower();
};

extern Game _game;