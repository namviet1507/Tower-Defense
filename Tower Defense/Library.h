#pragma once
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <windows.h>
#include <random>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <cmath>

#include <io.h>
#include <fcntl.h>
#include <codecvt>
#include <locale>
#include <conio.h>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

// COLOR CODE
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15

// Color RGB
#define RGB_GRAY 128, 128, 128
#define RGB_BLACK 0, 0, 0
#define RGB_WHITE 220,220,220
#define RGB_RED 255, 0, 0
#define RGB_BLUE 0,0,255
#define RGB_AQUA 0,255,255
#define RGB_TUR 64,224,208

#define RGB_Y_GREEN 181, 220, 91
#define RGB_Y_GREEN 181, 220, 91
#define RGB_L_GREEN 113, 170, 53 
#define RGB_D_GREEN 59, 122, 67
#define RGB_GREEN 62, 151, 88
#define RGB_A_GREEN 65, 121, 100

#define RGB_YELLOW 214, 206, 114
#define RGB_L_YELLOW 249, 241, 165

#define RGB_PINK 255, 192, 203 
#define RGB_D_PINK 255,20,147
#define RGB_PURPLE 238,130,238

#define RGB_BROWN 109, 77, 71
#define RGB_L_BROWN 136, 122, 87
#define RGB_D_BROWN 32, 28, 9


// MOVEMENT
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_ENTER 13

// SOUNDTRACK
#define MOVE_SOUND 0
#define ENTER_SOUND 1
#define ERROR_SOUND 2
#define DIE_SOUND 3
#define WIN_SOUND 4
#define BACKGROUND_SOUND 5
#define LOSE_SOUND 6
#define GAME_SOUND 7