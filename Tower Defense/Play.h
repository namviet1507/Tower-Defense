#pragma once
#include "Library.h"
#include "Tower.h"
#include "Map.h"
#include "Game.h"

struct Play
{
	static Cell c;
	static void colour_block(int x, int y, int h, int w, int color);
	static void colour_block2(int x, int y, int w, int h, int bcolor);
	static void print_rectangle(int x, int y, int w, int h, int bcolor, int color);

	static void printBoxContinue(int x, int y, int bcolor, int color);
	static void printBoxSave(int x, int y, int bcolor, int color);
	static void printBoxExit(int x, int y, int bcolor, int color);

	static int printMenuPause(int x, int y, int bcolor, int color);

	static void print_box_continue(int x, int y, int bcolor, int color);
	static void print_box_yes(int x, int y, int bcolor, int color);
	static void print_box_no(int x, int y, int bcolor, int color);
	static void print_continue(int x, int y, int bcolor, int color);
	static void print_yes(int x, int y, int bcolor, int color);
	static void print_no(int x, int y, int bcolor, int color);
	static void print_no_money(int x, int y, int bcolor, int color);
	static void print_lose(int x, int y, int bcolor, int color);
	static void print_win(int x, int y, int bcolor, int color);
	static void print_tower_Level1(int x, int y, int bcolor, int color);
	static void print_tower_Level2(int x, int y, int bcolor, int color);
	static void print_tower_Level3(int x, int y, int bcolor, int color);
	static void print_x(int x, int y, int bcolor, int color);
	static void print_x_block(int x, int y, int bcolor, int color);

	static string getFileSave();

	static void print_menu_continue(int x, int y);

	static int print_continue_board(int x, int y, Map m);
	static void print_menu_Tower(int x, int y);
	static int get_lever_Tower(int x, int y, Map m);

	static void play_map(string, string);

	static void print_quit_game(int x, int y, int bcolor, int color);

	static void MOVE(string, Enemy&);
	static void enemy_move1(int, string);

	static void effect_tower_main(Cell&);

	static void process_endgame();

	static void playContinue(vector<vector<int>> posTower, int res[], bool choice[], string file_map, string file_enemy);
};

