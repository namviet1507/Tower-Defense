#pragma once
#include "Library.h"
#include "Player.h"

#define LIST_FILE "listFile.bin"

class Menu : public Player {
	private:
		
	public:
		static char NAMEFILE[100];
		static char FILENAME[100];
		static bool music_is_open;
		static bool sound_is_open;
		static void Setting();
		static void goBack();									//Trở về menu
		
		static void processLoadFile(string);
		static void readLoadGame();								//Đọc bảng xếp hạng
		static string getFile();

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
	static void printRectangle(int, int, int, int);			//Vẽ hình chữ nhật
	static void printVietnamese(wstring);
	static void printListFile(int, int, vector<string>);
	
};

struct ListFile {

	static void printListFile(int start, int end, vector<string> arrFilename);
	static string getFile();
	static void processSaveFile(char);		// Lưu file
	static void processLoadFile(string filename);	// Tải file
};