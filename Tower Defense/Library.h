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
#include <filesystem>

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
#define MATCH_SOUND 3
#define WIN_SOUND 4
#define BACKGROUND_SOUND 5
#define LOSE_SOUND 6

// Color RGB
#define RGB_GRAY 128, 128, 128
#define RGB_BLACK 0, 0, 0
#define RGB_WHITE 245,245,245
#define RGB_RED 255, 0, 0
#define RGB_BROWN 126, 81, 9
#define RGB_BLUE 0,0,255
#define RGB_AQUA 0,255,255
#define RGB_TUR 64,224,208
#define RGB_DARK_GREEN 0, 100, 0
#define RGB_GREEN 0,128,0
#define RGB_FOREST_GREEN 34, 139, 34


#define FileListMapEasy "./Map/Easy/ListFileMap.bin"
#define FileListMapNormal "./Map/Normal/ListFileMap.bin"
#define FileListMapDificult "./Map/Difficult/ListFileMap.bin"