#pragma once
#include "Library.h"
#include "Tower.h"
#include "Map.h"


void colour_block(int x, int y, int h, int w, int color);
void colour_block2(int x, int y, int w, int h, int bcolor);
void print_rectangle(int x, int y, int w, int h, int bcolor, int color);

void print_box_continue(int x, int y, int bcolor, int color);
void print_box_yes(int x, int y,int bcolor,int color);
void print_box_no(int x, int y, int bcolor, int color);
void print_continue(int x, int y, int bcolor, int color);
void print_yes(int x, int y, int bcolor, int color);
void print_no(int x, int y, int bcolor, int color);
void print_no_money(int x, int y, int bcolor, int color);
void print_lose(int x, int y, int bcolor, int color);
void print_win(int x, int y, int bcolor, int color);
void print_tower_Level1(int x, int y,int bcolor,int color);
void print_tower_Level2(int x, int y, int bcolor, int color);
void print_tower_Level3(int x, int y, int bcolor, int color);
void print_x(int x, int y, int bcolor, int color);
void print_x_block(int x, int y, int bcolor, int color);

void print_menu_continue(int x, int y);

int print_continue_board(int x, int y,Map m);
void print_menu_Tower(int x,int y);
int get_lever_Tower(int x, int y,Map m);

void play_map1();
