#include "Game.h"
#include "Controller.h"
#pragma comment(lib, "winmm.lib")

bool Menu::music_is_open = false;
bool Menu::sound_is_open = false;


bool Screen::isVie;
Menu a;
void Screen::printRectangle(int left, int top, int width, int height)
{
	Controller::gotoXY(left, top);
	putchar(218);
	for (int i = 0; i < width; i++) {
		putchar(196);
	}
	putchar(191);
	int i = 0;
	for (; i < height; i++)
	{
		Controller::gotoXY(left, top + i + 1);
		putchar(179);
		Controller::gotoXY(left + width + 1, top + i + 1);
		putchar(179);
	}

	Controller::gotoXY(left, top + i);
	putchar(192);
	for (i = 0; i < width; i++)
		putchar(196);
	putchar(217);
}

void Screen::printMainScreen() {
	Controller::SetColor(BRIGHT_WHITE, BLACK);
	system("cls");
	Game::isPlaying = false;
	if (Menu::sound_is_open)
		Controller::playSound(BACKGROUND_SOUND);
	Screen::printLogo();
	int choice[5] = { 0,0,0,0,0 }, temp, key, curChoice = 0;
	while (true) {
		choice[curChoice] = 1;
		if (choice[0]) {
			Controller::SetColor(GREEN, BRIGHT_WHITE);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(50, 14 + i);
				cout << "              ";
			}
			if (Screen::isVie) {
				Controller::gotoXY(52, 15);
				Screen::printVietnamese(L"CHƠI NGAY");
			}
			else {
				Controller::gotoXY(55, 15);
				cout << "PLAY";
			}
		}
		else {
			Controller::gotoXY(50, 15);
			Controller::SetColor(BRIGHT_WHITE, WHITE);
			cout << "              ";
			Controller::SetColor(BRIGHT_WHITE, LIGHT_GREEN);
			Screen::printRectangle(50, 14, 12, 2);
			Controller::SetColor(BRIGHT_WHITE, GREEN);
			Controller::gotoXY(52, 15);
			if (Screen::isVie) {
				Controller::gotoXY(52, 15);
				Screen::printVietnamese(L"CHƠI NGAY");
			}
			else {
				Controller::gotoXY(55, 15);
				cout << "PLAY";
			}
		}
		if (choice[1]) {
			Controller::SetColor(GREEN, LIGHT_YELLOW);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(50, 17 + i);
				cout << "              ";
			}
			if (Screen::isVie) {
				Controller::gotoXY(53, 18);
				Screen::printVietnamese(L"CHƠI LẠI");
			}
			else {
				Controller::gotoXY(52, 18);
				cout << "LOAD GAME";
			}
		}
		else {
			Controller::gotoXY(50, 18);
			Controller::SetColor(BRIGHT_WHITE, WHITE);
			cout << "              ";
			Controller::SetColor(BRIGHT_WHITE, LIGHT_GREEN);
			Screen::printRectangle(50, 17, 12, 2);
			Controller::SetColor(BRIGHT_WHITE, GREEN);
			Controller::gotoXY(53, 18);
			if (Screen::isVie) {
				Controller::gotoXY(53, 18);
				Screen::printVietnamese(L"CHƠI LẠI");
			}
			else {
				Controller::gotoXY(52, 18);
				cout << "LOAD GAME";
			}
		}

		if (choice[2]) {
			Controller::SetColor(GREEN, LIGHT_PURPLE);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(50, 20 + i);
				cout << "              ";
			}
			if (Screen::isVie) {
				Controller::gotoXY(53, 21);
				Screen::printVietnamese(L"TRỢ GIÚP");
			}
			else {
				Controller::gotoXY(55, 21);
				cout << "HELP";
			}
		}
		else {
			Controller::gotoXY(50, 21);
			Controller::SetColor(BRIGHT_WHITE, WHITE);
			cout << "              ";
			Controller::SetColor(BRIGHT_WHITE, LIGHT_GREEN);
			Screen::printRectangle(50, 20, 12, 2);
			Controller::SetColor(BRIGHT_WHITE, GREEN);
			Controller::gotoXY(53, 21);
			if (Screen::isVie) {
				Controller::gotoXY(53, 21);
				Screen::printVietnamese(L"TRỢ GIÚP");
			}
			else {
				Controller::gotoXY(55, 21);
				cout << "HELP";
			}
		}

		if (choice[3]) {
			Controller::SetColor(GREEN, BLUE);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(50, 23 + i);
				cout << "              ";
			}
			Controller::gotoXY(53, 24);
			if (Screen::isVie)
				Screen::printVietnamese(L"CÀI ĐẶT");
			else cout << "SETTING";
		}
		else {
			Controller::gotoXY(50, 24);
			Controller::SetColor(BRIGHT_WHITE, WHITE);
			cout << "              ";
			Controller::SetColor(BRIGHT_WHITE, LIGHT_GREEN);
			Screen::printRectangle(50, 23, 12, 2);
			Controller::SetColor(BRIGHT_WHITE, GREEN);
			Controller::gotoXY(53, 24);
			if (Screen::isVie)
				Screen::printVietnamese(L"CÀI ĐẶT");
			else cout << "SETTING";
		}

		if (choice[4]) {
			Controller::SetColor(GREEN, LIGHT_RED);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(50, 26 + i);
				cout << "              ";
			}
			if (Screen::isVie) {
				Controller::gotoXY(54, 27);
				Screen::printVietnamese(L"THOÁT");
			}
			else {
				Controller::gotoXY(55, 27);
				cout << "EXIT";
			}
		}
		else {
			Controller::gotoXY(50, 27);
			Controller::SetColor(BRIGHT_WHITE, WHITE);
			cout << "              ";
			Controller::SetColor(BRIGHT_WHITE, LIGHT_GREEN);
			Screen::printRectangle(50, 26, 12, 2);
			Controller::SetColor(BRIGHT_WHITE, GREEN);
			Controller::gotoXY(54, 27);
			if (Screen::isVie) {
				Controller::gotoXY(54, 27);
				Screen::printVietnamese(L"THOÁT");
			}
			else {
				Controller::gotoXY(55, 27);
				cout << "EXIT";
			}
		}

		if (temp = _getch()) {
			if (temp != 224 && temp)
			{
				if (temp == KEY_ENTER) {
					if (Menu::sound_is_open)
						Controller::playSound(ENTER_SOUND);
					system("cls");
					if (curChoice == 0) {
						Game::mode = Screen::printLevel();
						Menu::signup();
						Game::setupGame();
					}
					else if (curChoice == 1) {
						Menu::readLoadGame();
					}
					else if (curChoice == 2) {
						Menu::helpScreen();
					}
					else if (curChoice == 3) {
						Menu::Setting();
					}
					else {
						Controller::SetColor(BLACK, BRIGHT_WHITE);
						system("cls");
						exit(0);
					}
				}
			}
			else {
				key = _getch();
				switch (key)
				{
				case KEY_UP:
					if (Menu::sound_is_open)
						Controller::playSound(MOVE_SOUND);
					choice[curChoice] = 0;
					if (curChoice > 0) curChoice--;
					else curChoice = 4;
					break;
				case KEY_DOWN:
					if (Menu::sound_is_open)
						Controller::playSound(MOVE_SOUND);
					choice[curChoice] = 0;
					if (curChoice < 4) curChoice++;
					else curChoice = 0;
				default:
					break;
				}
			}
		}
	}
}

int Screen::printLevel() {
	return 0;
}

void Menu::helpScreen() {}

void Menu::readLoadGame() {}

void Menu::Setting() {}

void Menu::signup() {}

void Screen::printLogo() {}

void Screen::printVietnamese(wstring str) {}