#pragma once
#include "Library.h"
#include "Tower.h"
#include "Map.h"
#include "Menu.h"


void colour_block(int x, int y, int h, int w, int color);
void colour_block2(int x, int y, int w, int h, int bcolor);
void print_rectangle(int x, int y, int w, int h, int bcolor, int color);
void print_tower_Level1(int x, int y,int bcolor,int color);
void print_tower_Level2(int x, int y, int bcolor, int color);
void print_tower_Level3(int x, int y, int bcolor, int color);
void print_x(int x, int y, int bcolor, int color);
void print_x_block(int x, int y, int bcolor, int color);
void print_menu_Tower(int x,int y);
int get_lever_Tower(int x, int y,Map m);
void check_continue_play();

void play_map1();
