#pragma once
#include "Library.h"
#include"Controller.h"
#include "Menu.h"
#include "Enemy.h"
using namespace std;
class Player {
	private:
		int score;
		int hp;
	public:
		Player() { hp = 10; score = 10; }
		int get_hp() { return hp; }
		void de_hp(int a) { hp -= a; }
		void print_hp(int x, int y, int bcolor, int color);
};
extern Player player;

void print_hp_player(int x,int y,int bcolor,int color);