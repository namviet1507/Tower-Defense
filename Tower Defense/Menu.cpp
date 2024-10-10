#include "Game.h"
#include "Controller.h"
#pragma comment(lib, "winmm.lib")

bool Menu::music_is_open;
bool Menu::sound_is_open;

bool Screen::isVie;
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
	//system("cls");
	Screen::printLogo();
	int choice[4] = { 0,0,0,0 }, curChoice = 0;
	while (true) {
		choice[curChoice] = 1;
		if (choice[0]) {
			Controller::SetColor(GREEN, BRIGHT_WHITE);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(50, 14 + i);
				cout << "              ";
			}
			
			if (Screen::isVie) {
				Controller::gotoXY(56, 15);
				Screen::printVietnamese(L"DỄ");
			}
			else {
				Controller::gotoXY(55, 15);
				cout << "EASY";
			}
		}
		else {
			Controller::gotoXY(50, 15);
			Controller::SetColor(BRIGHT_WHITE, BRIGHT_WHITE);
			cout << "              ";
			Controller::SetColor(BRIGHT_WHITE, LIGHT_GREEN);
			Screen::printRectangle(50, 14, 12, 2);
			Controller::SetColor(BRIGHT_WHITE, GREEN);
			if (Screen::isVie) {
				Controller::gotoXY(56, 15);
				Screen::printVietnamese(L"DỄ");
			}
			else {
				Controller::gotoXY(55, 15);
				cout << "EASY";
			}
		}
		if (choice[1]) {
			Controller::SetColor(GREEN, LIGHT_YELLOW);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(50, 18 + i);
				cout << "              ";
			}
			if (Screen::isVie) {
				Controller::gotoXY(52, 19);
				Screen::printVietnamese(L"BÌNH THƯỜNG");
			}
			else {
				Controller::gotoXY(54, 19);
				cout << "NORMAL";
			}
		}
		else {
			Controller::gotoXY(50, 19);
			Controller::SetColor(BRIGHT_WHITE, BRIGHT_WHITE);
			cout << "              ";
			Controller::SetColor(BRIGHT_WHITE, LIGHT_GREEN);
			Screen::printRectangle(50, 18, 12, 2);
			Controller::SetColor(BRIGHT_WHITE, GREEN);
			if (Screen::isVie) {
				Controller::gotoXY(52, 19);
				Screen::printVietnamese(L"BÌNH THƯỜNG");
			}
			else {
				Controller::gotoXY(54, 19);
				cout << "NORMAL";
			}
		}
		if (choice[2]) {
			Controller::SetColor(GREEN, LIGHT_RED);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(50, 22 + i);
				cout << "              ";
			}
			if (Screen::isVie) {
				Controller::gotoXY(55, 23);
				Screen::printVietnamese(L"KHÓ");
			}
			else {
				Controller::gotoXY(52, 23);
				cout << "DIFFICULT";
			}
		}
		else {
			Controller::gotoXY(50, 23);
			Controller::SetColor(BRIGHT_WHITE, BRIGHT_WHITE);
			cout << "              ";
			Controller::SetColor(BRIGHT_WHITE, LIGHT_GREEN);
			Screen::printRectangle(50, 22, 12, 2);
			Controller::SetColor(BRIGHT_WHITE, GREEN);

			if (Screen::isVie) {
				Controller::gotoXY(55, 23);
				Screen::printVietnamese(L"KHÓ");
			}
			else {
				Controller::gotoXY(52, 23);
				cout << "DIFFICULT";
			}
		}

		if (choice[3]) {
			Controller::SetColor(GREEN, LIGHT_RED);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(50, 26 + i);
				cout << "              ";
			}
			if (Screen::isVie) {
				Controller::gotoXY(53, 27);
				Screen::printVietnamese(L"QUAY LẠI");
			}
			else {
				Controller::gotoXY(55, 27);
				cout << "BACK";
			}
		}
		else {
			Controller::gotoXY(50, 27);
			Controller::SetColor(BRIGHT_WHITE, BRIGHT_WHITE);
			cout << "              ";
			Controller::SetColor(BRIGHT_WHITE, LIGHT_GREEN);
			Screen::printRectangle(50, 26, 12, 2);
			Controller::SetColor(BRIGHT_WHITE, GREEN);

			if (Screen::isVie) {
				Controller::gotoXY(53, 27);
				Screen::printVietnamese(L"QUAY LẠI");
			}
			else {
				Controller::gotoXY(55, 27);
				cout << "BACK";
			}
		}

		int temp, key;
		if (temp = _getch()) {
			if (temp != 224 && temp)
			{
				if (temp == KEY_ENTER) {
					if (Menu::sound_is_open)
						Controller::playSound(ENTER_SOUND);
					return curChoice;
				}
			}
			else {
				key = _getch();
				if (Menu::sound_is_open)
					Controller::playSound(MOVE_SOUND);
				switch (key)
				{
				case KEY_UP:
					if (Menu::sound_is_open)
						Controller::playSound(MOVE_SOUND);
					choice[curChoice] = 0;
					if (curChoice > 0) curChoice--;
					else curChoice = 3;
					break;
				case KEY_DOWN:
					if (Menu::sound_is_open)
						Controller::playSound(MOVE_SOUND);
					choice[curChoice] = 0;
					if (curChoice < 3) curChoice++;
					else curChoice = 0;
				default:
					break;
				}
			}
		}
	}
}

void Menu::readLoadGame() {}

void Menu::Setting() {
	system("cls");
	system("color F0");
	int choice[4] = { 0,0,0,0 }, temp, key, curChoice = 0;
	Controller::SetColor(BRIGHT_WHITE, LIGHT_AQUA);
	Controller::gotoXY(30, 2);
	Screen::printVietnamese(L"███████╗███████╗████████╗████████╗██╗███╗   ██╗ ██████╗ \n");
	Controller::SetColor(BRIGHT_WHITE, AQUA);
	Controller::gotoXY(30, 3);
	Screen::printVietnamese(L"██╔════╝██╔════╝╚══██╔══╝╚══██╔══╝██║████╗  ██║██╔════╝ \n");
	Controller::SetColor(BRIGHT_WHITE, LIGHT_BLUE);
	Controller::gotoXY(30, 4);
	Screen::printVietnamese(L"███████╗█████╗     ██║      ██║   ██║██╔██╗ ██║██║  ███╗\n");
	Controller::SetColor(BRIGHT_WHITE, BLUE);
	Controller::gotoXY(30, 5);
	Screen::printVietnamese(L"╚════██║██╔══╝     ██║      ██║   ██║██║╚██╗██║██║   ██║\n");
	Controller::SetColor(BRIGHT_WHITE, LIGHT_PURPLE);
	Controller::gotoXY(30, 6);
	Screen::printVietnamese(L"███████║███████╗   ██║      ██║   ██║██║ ╚████║╚██████╔╝\n");
	Controller::SetColor(BRIGHT_WHITE, PURPLE);
	Controller::gotoXY(30, 7);
	Screen::printVietnamese(L"╚══════╝╚══════╝   ╚═╝      ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═════╝ \n");
	
	Controller::SetColor(BRIGHT_WHITE, YELLOW);
	Controller::gotoXY(2, 8);
	Screen::printVietnamese(L"                  ██████\n");
	Controller::SetColor(BRIGHT_WHITE, YELLOW);
	Controller::gotoXY(2, 9);
	Screen::printVietnamese(L"                ██      ██\n");
	Controller::SetColor(BRIGHT_WHITE, YELLOW);
	Controller::gotoXY(2, 10);
	Screen::printVietnamese(L"      ██████    ██      ██    ██████\n");
	Controller::SetColor(BRIGHT_WHITE, YELLOW);
	Controller::gotoXY(2, 11);
	Screen::printVietnamese(L"    ██      ████          ████      ██\n");
	Controller::SetColor(BRIGHT_WHITE, LIGHT_RED);
	Controller::gotoXY(2, 12);
	Screen::printVietnamese(L"    ██                              ██\n");
	Controller::SetColor(BRIGHT_WHITE, LIGHT_RED);
	Controller::gotoXY(2, 13);
	Screen::printVietnamese(L"    ██                              ██ \n");
	Controller::SetColor(BRIGHT_WHITE, LIGHT_RED);
	Controller::gotoXY(2, 14);
	Screen::printVietnamese(L"      ██                          ██\n");
	Controller::SetColor(BRIGHT_WHITE, LIGHT_RED);
	Controller::gotoXY(2, 15);
	Screen::printVietnamese(L"      ██                          ██\n");
	Controller::SetColor(BRIGHT_WHITE, RED);
	Controller::gotoXY(2, 16);
	Screen::printVietnamese(L"  ████            ██████            ████\n");
	Controller::SetColor(BRIGHT_WHITE, RED);
	Controller::gotoXY(2, 17);
	Screen::printVietnamese(L"██              ██      ██              ██\n");
	Controller::SetColor(BRIGHT_WHITE, RED);
	Controller::gotoXY(2, 18);
	Screen::printVietnamese(L"██              ██      ██              ██\n");
	Controller::SetColor(BRIGHT_WHITE, RED);
	Controller::gotoXY(2, 19);
	Screen::printVietnamese(L"██              ██      ██              ██\n");
	Controller::SetColor(BRIGHT_WHITE, LIGHT_PURPLE);
	Controller::gotoXY(2, 20);
	Screen::printVietnamese(L"  ████            ██████            ████\n");
	Controller::SetColor(BRIGHT_WHITE, LIGHT_PURPLE);
	Controller::gotoXY(2, 21);
	Screen::printVietnamese(L"      ██                          ██\n");
	Controller::SetColor(BRIGHT_WHITE, LIGHT_PURPLE);
	Controller::gotoXY(2, 22);
	Screen::printVietnamese(L"      ██                          ██\n");
	Controller::SetColor(BRIGHT_WHITE, LIGHT_PURPLE);
	Controller::gotoXY(2, 23);
	Screen::printVietnamese(L"    ██                              ██\n");
	Controller::SetColor(BRIGHT_WHITE, PURPLE);
	Controller::gotoXY(2, 24);
	Screen::printVietnamese(L"    ██                              ██\n");
	Controller::SetColor(BRIGHT_WHITE, PURPLE);
	Controller::gotoXY(2, 25);
	Screen::printVietnamese(L"    ██      ████          ████      ██ \n");
	Controller::SetColor(BRIGHT_WHITE, PURPLE);
	Controller::gotoXY(2, 26);
	Screen::printVietnamese(L"      ██████    ██      ██    ██████\n");
	Controller::SetColor(BRIGHT_WHITE, GRAY);
	Controller::gotoXY(2, 27);
	Screen::printVietnamese(L"                ██      ██\n");
	Controller::SetColor(BRIGHT_WHITE, GRAY);
	Controller::gotoXY(2, 28);
	Screen::printVietnamese(L"                  ██████\n");


	while (true) {
		choice[curChoice] = 1;
		if (Menu::music_is_open) {
			Controller::SetColor(GREEN, BRIGHT_WHITE);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(70, 12 + i);
				cout << "           ";
			}
			Controller::gotoXY(74, 13);
			if (Screen::isVie)
				Screen::printVietnamese(L"BẬT");
			else cout << "ON";
		}
		else {
			Controller::SetColor(RED, BRIGHT_WHITE);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(70, 12 + i);
				cout << "           ";
			}
			Controller::gotoXY(74, 13);
			if (Screen::isVie)
				Screen::printVietnamese(L"TẮT");
			else cout << "OFF";
		}
		if (Menu::sound_is_open) {
			Controller::SetColor(GREEN, BRIGHT_WHITE);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(70, 15 + i);
				cout << "           ";
			}
			Controller::gotoXY(74, 16);
			if (Screen::isVie)
				Screen::printVietnamese(L"BẬT");
			else cout << "ON";
		}
		else {
			Controller::SetColor(RED, BRIGHT_WHITE);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(70, 15 + i);
				cout << "           ";
			}
			Controller::gotoXY(74, 16);
			if (Screen::isVie)
				Screen::printVietnamese(L"TẮT");
			else cout << "OFF";
		}
		if (Screen::isVie) {
			Controller::SetColor(AQUA, BRIGHT_WHITE);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(70, 18 + i);
				cout << "           ";
			}
			Controller::gotoXY(71, 19);
			Screen::printVietnamese(L"TIẾNG VIỆT");
		}
		else {
			Controller::SetColor(PURPLE, BRIGHT_WHITE);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(70, 18 + i);
				cout << "           ";
			}
			Controller::gotoXY(72, 19);
			cout << "ENGLISH";
		}
		if (choice[0]) {
			Controller::SetColor(GREEN, BRIGHT_WHITE);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(50, 12 + i);
				cout << "              ";
			}
			if (Screen::isVie) {
				Controller::gotoXY(53, 13);
				Screen::printVietnamese(L"ÂM NHẠC");
			}
			else {
				Controller::gotoXY(54, 13);
				cout << "MUSIC";
			}
		}
		else {
			Controller::gotoXY(50, 13);
			Controller::SetColor(BRIGHT_WHITE, WHITE);
			cout << "              ";
			Controller::SetColor(BRIGHT_WHITE, LIGHT_GREEN);
			Screen::printRectangle(50, 12, 12, 2);
			Controller::SetColor(BRIGHT_WHITE, GREEN);

			if (Screen::isVie) {
				Controller::gotoXY(53, 13);
				Screen::printVietnamese(L"ÂM NHẠC");
			}
			else {
				Controller::gotoXY(54, 13);
				cout << "MUSIC";
			}
		}
		if (choice[1]) {
			Controller::SetColor(GREEN, LIGHT_YELLOW);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(50, 15 + i);
				cout << "              ";
			}
			if (Screen::isVie) {
				Controller::gotoXY(53, 16);
				Screen::printVietnamese(L"ÂM THANH");
			}
			else {
				Controller::gotoXY(55, 16);
				cout << "SFX";
			}
		}
		else {
			Controller::gotoXY(50, 16);
			Controller::SetColor(BRIGHT_WHITE, WHITE);
			cout << "              ";
			Controller::SetColor(BRIGHT_WHITE, LIGHT_GREEN);
			Screen::printRectangle(50, 15, 12, 2);
			Controller::SetColor(BRIGHT_WHITE, GREEN);
			if (Screen::isVie) {
				Controller::gotoXY(53, 16);
				Screen::printVietnamese(L"ÂM THANH");
			}
			else {
				Controller::gotoXY(55, 16);
				cout << "SFX";
			}
		}

		if (choice[2]) {
			Controller::SetColor(GREEN, LIGHT_PURPLE);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(50, 18 + i);
				cout << "              ";
			}
			if (Screen::isVie) {
				Controller::gotoXY(53, 19);
				Screen::printVietnamese(L"NGÔN NGỮ");
			}
			else {
				Controller::gotoXY(53, 19);
				cout << "LANGUAGE";
			}
		}
		else {
			Controller::gotoXY(50, 19);
			Controller::SetColor(BRIGHT_WHITE, WHITE);
			cout << "              ";
			Controller::SetColor(BRIGHT_WHITE, LIGHT_GREEN);
			Screen::printRectangle(50, 18, 12, 2);
			Controller::SetColor(BRIGHT_WHITE, GREEN);
			if (Screen::isVie) {
				Controller::gotoXY(53, 19);
				Screen::printVietnamese(L"NGÔN NGỮ");
			}
			else {
				Controller::gotoXY(53, 19);
				cout << "LANGUAGE";
			}
		}

		if (choice[3]) {
			Controller::SetColor(GREEN, LIGHT_PURPLE);
			for (int i = 0; i < 3; i++) {
				Controller::gotoXY(50, 21 + i);
				cout << "              ";
			}
			if (Screen::isVie) {
				Controller::gotoXY(53, 22);
				Screen::printVietnamese(L"QUAY LẠI");
			}
			else {
				Controller::gotoXY(55, 22);
				cout << "BACK";
			}
		}
		else {
			Controller::gotoXY(50, 22);
			Controller::SetColor(BRIGHT_WHITE, WHITE);
			cout << "              ";
			Controller::SetColor(BRIGHT_WHITE, LIGHT_GREEN);
			Screen::printRectangle(50, 21, 12, 2);
			Controller::SetColor(BRIGHT_WHITE, GREEN);
			if (Screen::isVie) {
				Controller::gotoXY(53, 22);
				Screen::printVietnamese(L"QUAY LẠI");
			}
			else {
				Controller::gotoXY(55, 22);
				cout << "BACK";
			}
		}
		if (temp = _getch()) {
			if (temp != 224 && temp)
			{
				if (temp == KEY_ENTER) {
					if (Menu::sound_is_open)
						Controller::playSound(ENTER_SOUND);
					if (curChoice == 0)
						Menu::music_is_open = !Menu::music_is_open;
					else if (curChoice == 1)
						Menu::sound_is_open = !Menu::sound_is_open;
					else if (curChoice == 2)
						Screen::isVie = !Screen::isVie;
					else
						if (Game::isPlaying) {
							
						}
						else Menu::goBack();
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
					else curChoice = 3;
					break;
				case KEY_DOWN:
					if (Menu::sound_is_open)
						Controller::playSound(MOVE_SOUND);
					choice[curChoice] = 0;
					if (curChoice < 3) curChoice++;
					else curChoice = 0;
				default:
					break;
				}
			}
		}
	}
}

void Menu::signup() {}

void Screen::printVietnamese(wstring text) {
	int mode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << text;
	mode = _setmode(_fileno(stdout), _O_TEXT);
}

void Screen::printLogoStandard() {

	Controller::SetColor(BRIGHT_WHITE, LIGHT_AQUA);
	Controller::gotoXY(6, 5);
	Screen::printVietnamese(L"████████╗ ██████╗ ██╗    ██╗███████╗██████╗ \n");
	Controller::SetColor(BRIGHT_WHITE, AQUA);
	Controller::gotoXY(6, 6);
	Screen::printVietnamese(L"╚══██╔══╝██╔═══██╗██║    ██║██╔════╝██╔══██╗\n");
	Controller::SetColor(BRIGHT_WHITE, LIGHT_BLUE);
	Controller::gotoXY(6, 7);
	Screen::printVietnamese(L"   ██║   ██║   ██║██║ █╗ ██║█████╗  ██████╔╝\n");
	Controller::SetColor(BRIGHT_WHITE, BLUE);
	Controller::gotoXY(6, 8);
	Screen::printVietnamese(L"   ██║   ██║   ██║██║███╗██║██╔══╝  ██╔══██╗\n");
	Controller::SetColor(BRIGHT_WHITE, LIGHT_PURPLE);
	Controller::gotoXY(6, 9);
	Screen::printVietnamese(L"   ██║   ╚██████╔╝╚███╔███╔╝███████╗██║  ██║\n");
	Controller::SetColor(BRIGHT_WHITE, PURPLE);
	Controller::gotoXY(6, 10);
	Screen::printVietnamese(L"   ╚═╝    ╚═════╝  ╚══╝╚══╝ ╚══════╝╚═╝  ╚═╝\n");

	Controller::SetColor(BRIGHT_WHITE, YELLOW);
	Controller::gotoXY(56, 5);
	Screen::printVietnamese(L"██████╗ ███████╗███████╗███████╗███╗   ██╗███████╗███████╗\n");
	Controller::SetColor(BRIGHT_WHITE, LIGHT_RED);
	Controller::gotoXY(56, 6);
	Screen::printVietnamese(L"██╔══██╗██╔════╝██╔════╝██╔════╝████╗  ██║██╔════╝██╔════╝\n");
	Controller::SetColor(BRIGHT_WHITE, RED);
	Controller::gotoXY(56, 7);
	Screen::printVietnamese(L"██║  ██║█████╗  █████╗  █████╗  ██╔██╗ ██║███████╗█████╗  \n");
	Controller::SetColor(BRIGHT_WHITE, LIGHT_PURPLE);
	Controller::gotoXY(56, 8);
	Screen::printVietnamese(L"██║  ██║██╔══╝  ██╔══╝  ██╔══╝  ██║╚██╗██║╚════██║██╔══╝  \n");
	Controller::SetColor(BRIGHT_WHITE, PURPLE);
	Controller::gotoXY(56, 9);
	Screen::printVietnamese(L"██████╔╝███████╗██║     ███████╗██║ ╚████║███████║███████╗\n");
	Controller::SetColor(BRIGHT_WHITE, GRAY);
	Controller::gotoXY(56, 10);
	Screen::printVietnamese(L"╚═════╝ ╚══════╝╚═╝     ╚══════╝╚═╝  ╚═══╝╚══════╝╚══════╝\n");

}

void Screen::printLogoEffect() {
	int cnt = 15;
	while (cnt--) {
		Controller::SetColor(BRIGHT_WHITE, rand() % 6 + 1);
		Controller::gotoXY(6, 5);
		Screen::printVietnamese(L"████████╗ ██████╗ ██╗    ██╗███████╗██████╗ \n");
		Controller::SetColor(BRIGHT_WHITE, rand() % 6 + 1);
		Controller::gotoXY(6, 6);
		Screen::printVietnamese(L"╚══██╔══╝██╔═══██╗██║    ██║██╔════╝██╔══██╗\n");
		Controller::SetColor(BRIGHT_WHITE, rand() % 6 + 1);
		Controller::gotoXY(6, 7);
		Screen::printVietnamese(L"   ██║   ██║   ██║██║ █╗ ██║█████╗  ██████╔╝\n");
		Controller::SetColor(BRIGHT_WHITE, rand() % 6 + 1);
		Controller::gotoXY(6, 8);
		Screen::printVietnamese(L"   ██║   ██║   ██║██║███╗██║██╔══╝  ██╔══██╗\n");
		Controller::SetColor(BRIGHT_WHITE, rand() % 6 + 1);
		Controller::gotoXY(6, 9);
		Screen::printVietnamese(L"   ██║   ╚██████╔╝╚███╔███╔╝███████╗██║  ██║\n");
		Controller::SetColor(BRIGHT_WHITE, rand() % 6 + 1);
		Controller::gotoXY(6, 10);
		Screen::printVietnamese(L"   ╚═╝    ╚═════╝  ╚══╝╚══╝ ╚══════╝╚═╝  ╚═╝\n");

		Controller::SetColor(BRIGHT_WHITE, rand() % 6 + 1);
		Controller::gotoXY(56, 5);
		Screen::printVietnamese(L"██████╗ ███████╗███████╗███████╗███╗   ██╗███████╗███████╗\n");
		Controller::SetColor(BRIGHT_WHITE, rand() % 6 + 1);
		Controller::gotoXY(56, 6);
		Screen::printVietnamese(L"██╔══██╗██╔════╝██╔════╝██╔════╝████╗  ██║██╔════╝██╔════╝\n");
		Controller::SetColor(BRIGHT_WHITE, rand() % 6 + 1);
		Controller::gotoXY(56, 7);
		Screen::printVietnamese(L"██║  ██║█████╗  █████╗  █████╗  ██╔██╗ ██║███████╗█████╗  \n");
		Controller::SetColor(BRIGHT_WHITE, rand() % 6 + 1);
		Controller::gotoXY(56, 8);
		Screen::printVietnamese(L"██║  ██║██╔══╝  ██╔══╝  ██╔══╝  ██║╚██╗██║╚════██║██╔══╝  \n");
		Controller::SetColor(BRIGHT_WHITE, rand() % 6 + 1);
		Controller::gotoXY(56, 9);
		Screen::printVietnamese(L"██████╔╝███████╗██║     ███████╗██║ ╚████║███████║███████╗\n");
		Controller::SetColor(BRIGHT_WHITE, rand() % 6 + 1);
		Controller::gotoXY(56, 10);
		Screen::printVietnamese(L"╚═════╝ ╚══════╝╚═╝     ╚══════╝╚═╝  ╚═══╝╚══════╝╚══════╝\n");
		Sleep(125);
	}
}

int check = 1;
void Screen::printLogo() {
	if (check) {
		check = 0;
		Screen::printLogoEffect();
	}
	Screen::printLogoStandard();

	Controller::gotoXY(10, 15);
	Controller::SetColor(BRIGHT_WHITE, PURPLE);
	cout << R"(

	       [ O ]
		 \ \      p
		  \ \  \o/
		   \ \--'---_
		   /\ \   / ~~\_
	 ./---/__|=/_/------//~~~\
	/___________________/O   O \
	(===(\_________(===(Oo o o O)
	 \~~~\____/     \---\Oo__o--
	   ~~~~~~~       ~~~~~~~~~~
	)";

}

void Menu::helpScreen() {
	Controller::showCursor(false);
	Controller::SetColor(BRIGHT_WHITE, BLACK);
	system("cls");
	int left = 5, top = 2, width = 100, height = 23;
	int line1 = 8, line2 = 17, line3 = 23;
	Screen::printRectangle(left, top, width, height);
	Controller::gotoXY(left + 1, line1);
	for (int i = 0; i < width; i++)
	{
		putchar(196);
	}
	Controller::gotoXY(left + 1, line2);
	for (int i = 0; i < width; i++)
	{
		putchar(196);
	}
	Controller::gotoXY(left + 1, line3);
	for (int i = 0; i < width; i++)
	{
		putchar(196);
	}
	for (int i = 1; i < height; i++)
	{
		Controller::gotoXY(line2 + 3, top + i);
		putchar(179);
	}
	Controller::gotoXY(line2 + 3, line1);
	putchar(197);
	Controller::gotoXY(line2 + 3, line2);
	putchar(197);

	Controller::SetColor(BRIGHT_WHITE, BLUE);
	Controller::gotoXY(left + 3, top + 2);
	Screen::printVietnamese(L"Giới thiệu:");

	Controller::gotoXY(left + 17, top + 1);
	putchar(249);
	Screen::printVietnamese(L"  Tower Defense là một thể loại game chiến thuật rất phổ biến, trong đó người chơi");
	Controller::gotoXY(left + 17, top + 2);
	Screen::printVietnamese(L" phải xây dựng các tháp (towers) để bảo vệ căn cứ khỏi các đợt tấn công của kẻ thù.");
	
	Controller::gotoXY(left + 17, top + 3);
	putchar(249);
	Screen::printVietnamese(L"  Trong game, người chơi sẽ đối mặt với các 'đợt sóng' kẻ địch, và nhiệm vụ của họ");
	Controller::gotoXY(left + 17, top + 4);
	Screen::printVietnamese(L" là ngăn chặn kẻ địch tiến vào căn cứ của mình. Nếu kẻ địch đến được căn cứ của bạn,");
	Controller::gotoXY(left + 17, top + 5);
	Screen::printVietnamese(L" bạn sẽ mất máu hoặc điểm. Khi hết máu, game kết thúc.");

	Controller::SetColor(BRIGHT_WHITE, LIGHT_RED);
	Controller::gotoXY(left + 3, top + 11);
	Screen::printVietnamese(L"Luật chơi:");

	Controller::gotoXY(left + 17, top + 7);
	int left1 = left + 17;
	putchar(249);
	Screen::printVietnamese(L"  Người chơi bắt đầu game với một số lượng tiền nhất định và một số tháp cơ bản.");
	Controller::gotoXY(left1, top + 8);
	Screen::printVietnamese(L" Kẻ địch bắt đầu xuất hiện từ các điểm spawn.");

	Controller::gotoXY(left1, top + 9);
	putchar(249);
	Screen::printVietnamese(L"  Một số kẻ địch có tốc độ di chuyển nhanh, trong khi một số khác có nhiều máu hơn,");
	Controller::gotoXY(left1, top + 10);
	Screen::printVietnamese(L" hoặc có khả năng phòng thủ cao. Bạn cần xây dựng tháp sao cho phù hợp với");
	Controller::gotoXY(left1, top + 11);
	Screen::printVietnamese(L" từng loại kẻ địch.");

	Controller::gotoXY(left1, top + 12);
	putchar(249);
	Screen::printVietnamese(L"  Khi một kẻ địch vượt qua hệ thống phòng thủ của bạn và vào căn cứ,");
	Controller::gotoXY(left1, top + 13);
	Screen::printVietnamese(L" bạn sẽ mất một lượng máu nhất định. Khi hết máu, bạn sẽ thua cuộc.");
	
	Controller::SetColor(BRIGHT_WHITE, PURPLE);
	Controller::gotoXY(left1 + 30, top + 14);
	Screen::printVietnamese(L"Chúc bạn nhiều may mắn !");

	Controller::SetColor(BRIGHT_WHITE, AQUA);
	Controller::gotoXY(left + 3, top + 18);
	cout << "Developers:";
	Controller::gotoXY(left + 31, top + 16);
	Screen::printVietnamese(L"Dev 1: Nguyễn Bách Khoa (23127066)");
	Controller::gotoXY(left + 31, top + 17);
	Screen::printVietnamese(L"Dev 2: Trương Hoàng Lâm (23127402)");
	Controller::gotoXY(left + 31, top + 18);
	Screen::printVietnamese(L"Dev 3: Bùi Quang Sơn (23127468)");
	Controller::gotoXY(left + 31, top + 19);
	Screen::printVietnamese(L"Dev 4: Bùi Nam Việt (23127516)");
	Controller::gotoXY(left + 31, top + 20);
	Screen::printVietnamese(L"Dev 5: Trương Quang Huy (23127530)");

	Controller::SetColor(BRIGHT_WHITE, BLUE);
	Controller::gotoXY(left + 3, top + 22);
	Screen::printVietnamese(L"Giảng viên: ");
	Controller::gotoXY(left + 40, top + 22);
	Screen::printVietnamese(L"Trương Toàn Thịnh");

	Controller::SetColor(BRIGHT_WHITE, BLACK);
	Screen::printRectangle(45, 27, 8, 2);
	Controller::SetColor(BRIGHT_WHITE, RED);
	Controller::gotoXY(43, 28);
	putchar(175);
	Controller::gotoXY(47, 28);
	Screen::printVietnamese(L"Trở về");
	Controller::gotoXY(56, 28);
	putchar(174);
	while (Controller::getConsoleInput() != 6)
	{
		if (Menu::sound_is_open)
			Controller::playSound(ERROR_SOUND);
	}
	if (Menu::sound_is_open)
		Controller::playSound(ENTER_SOUND);
	if (Game::isPlaying) {
		
	}
	else Menu::goBack();
}

void Menu::goBack() {
	Screen::printMainScreen();
}