#pragma once
#include "Library.h"
#include "Menu.h"
#include "Player.h"

class Game : public Player {
	public:
		static int mode;				// Chế độ Game
		static bool isPlaying;			// check còn đang chơi không
		static bool isPause;
		static bool Flag_Pause;
		static int num_enemy;

		static void setupGame();		// Cài đặt game

		static void printBoard();
		static void printNumEnemy();
};