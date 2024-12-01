#pragma once
#include "Library.h"
#include "Player.h"

#define LIST_FILE "./ListSaveFile/listFile.txt"
class Menu
{
private:

public:
	static bool music_is_open;
	static bool sound_is_open;
	static void Setting();
	static void goBack();									//Trở về menu
	static void readLoadGame();								//Đọc bảng xếp hạng

		static void helpScreen();								//Màn hình hướng dẫn
		static void signup();									// Đăng ký

};

struct Screen {

	static bool isVie;
	static void printMainScreen();							//In ra màn hình chính
	static void printLogo();
	static void printLogoEffect();
	static void printLogoStandard();
	static int printLevel();								//In ra mức độ chơi
	static void printRectangle(int left, int top, int width, int height);			//Vẽ hình chữ nhật
	static void printVietnamese(wstring);


	static void printTower(int x, int y);
	static void printAnt(int x, int y);
	static void printBall(int x, int y);

	static void printGrass(int x, int y);
	static void printBush(int x, int y);
	static void printLand(int x, int y);
};

struct ListFile {
	// load game
	static void printListFile(int start, int end, vector<string> arrFilename);
	static string getFile();
	static void processSaveFile(string, vector<vector<int>> posTower, int res[4], bool choice[], string file_map, string file_enemy);		// Lưu file
	static void processLoadFile(string filename, vector<vector<int>>& posTower, int res[4], bool choice[], string& file_map, string& file_enemy);	// Tải file
};