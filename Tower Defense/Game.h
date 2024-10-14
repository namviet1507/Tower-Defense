#pragma once
#include "Library.h"
#include "Menu.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"

class Game : public Player {
	Map m;
	int mode;				// Chế độ Game
	string file_map;		// file để lấy data map
	bool isPlaying;			// check còn đang chơi không

	public:
		void setMode(int);
		void setFlagPlaying(bool);
		void setFileMap(string);

		int getMode();
		bool getFlagPlaying();
		string getFileMap();

		void setupGame();		// Cài đặt game
		void buildTower();
};