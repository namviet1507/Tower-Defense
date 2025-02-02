﻿#include "Library.h"
#include "Controller.h"
#include <SFML/Audio.hpp>

using namespace sf;

HWND Controller::consoleWindow = GetConsoleWindow();
HANDLE Controller::consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

void Controller::setUpConsole()
{
	setAndCenterWindow();
	setConsoleTitle();
	hideScrollBars();
	disableMouseInput();
	showCursor(false);
}

void Controller::SetColor(int background_color, int text_color) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int color_code = background_color * 16 + text_color;
	SetConsoleTextAttribute(h, color_code);
}

void Controller::setColorRGB(int red, int green, int blue, int bgRed, int bgGreen, int bgBlue) {
	if ((red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) ||
		(bgRed < 0 || bgRed > 255 || bgGreen < 0 || bgGreen > 255 || bgBlue < 0 || bgBlue > 255)) {
		return;
	}

	cout << "\033[38;2;" << red << ";" << green << ";" << blue << "m"  // Màu văn bản
		<< "\033[48;2;" << bgRed << ";" << bgGreen << ";" << bgBlue << "m";  // Màu nền
}

void Controller::gotoXY(int x, int y) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = x;
	Position.Y = y;
	SetConsoleCursorPosition(h, Position);
}

void Controller::hideScrollBars()
{
	ShowScrollBar(consoleWindow, SB_BOTH, 0);
}

void Controller::showCursor(bool show)
{
	CONSOLE_CURSOR_INFO info = { 1, show };
	SetConsoleCursorInfo(consoleOutput, &info);
}

void Controller::setConsoleTitle()
{
	SetConsoleTitleA("TOWER DEFENSE");
}

void Controller::setAndCenterWindow()
{
	RECT rectClient, rectWindow;
	GetClientRect(consoleWindow, &rectClient), GetWindowRect(consoleWindow, &rectWindow);
	int width = 1100;
	int height = 768;
	int posX = (GetSystemMetrics(SM_CXSCREEN) - width) / 2,
		posY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
	MoveWindow(consoleWindow, posX, posY, width, height, TRUE);
}

void Controller::disableMouseInput()
{
	DWORD prev_mode;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}

int Controller::getConsoleInput() {
	int c = _getch();
	if (c == 0 || c == 224)
	{
		switch (_getch())
		{
		case KEY_UP:				//lên
			return 2;
		case KEY_LEFT:				//trái
			return 3;
		case KEY_RIGHT:				//phải
			return 4;
		case KEY_DOWN:				//xuống
			return 5;
		default:					//nút khác
			return 0;
		}
	}
	else
	{
		if (c == KEY_ESC)                  //esc
			return 1;
		else if (c == 87 || c == 119) //W, w
			return 2;
		else if (c == 65 || c == 97)  //A, a
			return 3;
		else if (c == 68 || c == 100) //D, d
			return 4;
		else if (c == 83 || c == 115) //S, s
			return 5;
		else if (c == 13)             //Enter
			return 6;
		else if (c == 72 || c == 104) //H, h
			return 7;
		else if (c == 81 || c == 113) // Q, q
			return 8;
		else if (c == 76 || c == 108) // L, l
			return 9;
		else if (c == 89 || c == 121) // Y, y
			return 10;
		else if (c == 77 || c == 109) // M, m
			return 11;
		else if (c == 78 || c == 110) // N, n
			return 12;
		else if (c == 85 || c == 117) // U, u
			return 14;
		else if (c == 32)
			return 15;
		else
			return 0;                 //nút khác
	}
}

void Controller::playSound(int i)
{
	static map<int, SoundBuffer> soundBuffers;
	static map<int, Sound> sounds;

	static vector<string> soundFile{
		"Sound/MOVE.wav", "Sound/enterbutton.wav", "Sound/error.wav",
		"Sound/enter.wav", "Sound/win.wav", "Sound/SoundGame.wav",
		"Sound/lose.wav", "Sound/nhacnen.wav"
	};

	if (soundBuffers.find(i) == soundBuffers.end()) {
		SoundBuffer buffer;
		if (!buffer.loadFromFile(soundFile[i])) {
			cerr << "Failed to load sound: " << soundFile[i] << std::endl;
			return;
		}
		soundBuffers[i] = buffer;
	}

	// Phát âm thanh
	sounds[i].setBuffer(soundBuffers[i]);
	sounds[i].play();
}