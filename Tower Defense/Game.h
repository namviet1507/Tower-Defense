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
public:
	static int mode;
	static bool isPlaying;
	static string file_map;
	static string file_enemy;
	static void setupGame();


};