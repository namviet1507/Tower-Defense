#pragma once
#include "Library.h"
#include"Controller.h"
#include "Menu.h"
#include "Enemy.h"
using namespace std;

extern bool ingame;
extern bool wingame;
extern bool losegame;
extern bool showcost;
extern bool isbreakmap1;

class Player {
	private:
		int score;
		int hp;
		int cost;
	public:
		Player() { hp = 10; score = 10; cost = 40; }
		Player(int h,int s,int c) { hp = h; score = s; cost = c; }
		Player(const Player& other) { hp = other.hp; score = other.score; cost = other.cost; }
		void new_hp(int h) { hp = h; }
		int get_hp() { return hp; }
		void de_hp(int a) { hp -= a; }
		int get_cost() { return cost; }
		void in_cost(int a) { cost += a; }
		void de_cost(int a) { cost -= a; }
		void print_hp(int x, int y, int bcolor, int color);
		void print_cost(int x, int y, int bcolor, int color);
};
extern Player player;

void print_cost_first(int x, int y, int bcolor, int color);

void print_hp_player(int x,int y,int bcolor,int color);
void print_cost_player(int x, int y, int bcolor, int color);
void check_win(int num_enemy);