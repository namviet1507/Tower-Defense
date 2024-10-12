#pragma once
#include "Library.h"
#include "Menu.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"

class Game : public Player {
	Map m;
	public:
		static int mode;				// Chế độ Game
		static bool isPlaying;			// check còn đang chơi không

		void setupGame();		// Cài đặt game
		void buildTower();
};