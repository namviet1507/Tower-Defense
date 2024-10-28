#pragma once
#include "Library.h"
#include "Menu.h"
#include "Player.h"

class Game : public Player {
public:
	static int mode;				// Chế độ Game
	static bool isPlaying;			// check còn đang chơi không

	static void setupGame();		// Cài đặt game
};