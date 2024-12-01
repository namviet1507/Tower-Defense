#include "Play.h"



void Play::colour_block(int x, int y, int h, int w, int color)
{
	Cell t;
	t.setArea(h, w);
	t.setColor(color);
	t.setFlagGrass(false);
	t.setPos(x, y);
	t.printCell();
}

void Play::colour_block2(int x, int y, int w, int h, int bcolor)
{
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, bcolor);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << " ";
		}
		Controller::gotoXY(x, y + i + 1);
	}
}

void Play::print_rectangle(int x, int y, int w, int h, int bcolor, int color)
{
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	putchar(201);
	for (int i = 1; i < w - 1; i++) {
		putchar(205);
	}
	putchar(187);
	Controller::gotoXY(x, y + 1);

	for (int i = 1; i < h - 1; i++)
	{
		cout << char(186);
		for (int j = 1; j < w - 1; j++)
		{
			cout << " ";
		}
		cout << char(186);
		Controller::gotoXY(x, y + i + 1);
	}

	Controller::gotoXY(x, y + h - 1);
	putchar(200);
	for (int i = 1; i < w - 1; i++)
		putchar(205);
	putchar(188);
}

void Play::print_box_continue(int x, int y, int bcolor, int color)
{
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	putchar(201);
	for (int i = 1; i < 84 - 1; i++) {
		putchar(205);
	}
	putchar(187);
	Controller::gotoXY(x, y + 1);

	for (int i = 1; i < 7; i++)
	{
		cout << char(186);
		for (int j = 1; j < 84 - 1; j++)
		{
			cout << " ";
		}
		cout << char(186);
		Controller::gotoXY(x, y + i + 1);
	}

}

void Play::print_box_yes(int x, int y, int bcolor, int color)
{
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	putchar(204);
	for (int i = 1; i < 42 - 1; i++) {
		putchar(205);
	}
	putchar(203);
	Controller::gotoXY(x, y + 1);

	for (int i = 1; i < 7 - 1; i++)
	{
		cout << char(186);
		for (int j = 1; j < 42 - 1; j++)
		{
			cout << " ";
		}
		cout << char(186);
		Controller::gotoXY(x, y + i + 1);
	}

	Controller::gotoXY(x, y + 7 - 1);
	putchar(200);
	for (int i = 1; i < 42 - 1; i++)
		putchar(205);
	putchar(202);
}
void Play::print_box_no(int x, int y, int bcolor, int color)
{
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	putchar(203);
	for (int i = 1; i < 42; i++) {
		putchar(205);
	}
	putchar(185);
	Controller::gotoXY(x, y + 1);

	for (int i = 1; i < 7 - 1; i++)
	{
		cout << char(186);
		for (int j = 1; j < 42; j++)
		{
			cout << " ";
		}
		cout << char(186);
		Controller::gotoXY(x, y + i + 1);
	}

	Controller::gotoXY(x, y + 7 - 1);
	putchar(202);
	for (int i = 1; i < 42; i++)
		putchar(205);
	putchar(188);
}

void Play::print_continue(int x, int y, int bcolor, int color)
{
	//print_rectangle(x - 1, y - 1, 84, 8, bcolor, color);
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L" ██████  ██████  ███    ██ ████████ ██ ███    ██ ██    ██ ███████         ██████  ");
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"██      ██    ██ ████   ██    ██    ██ ████   ██ ██    ██ ██                   ██ ");
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"██      ██    ██ ██ ██  ██    ██    ██ ██ ██  ██ ██    ██ █████             ▄███  ");
	Controller::gotoXY(x, y + 3);
	Screen::printVietnamese(L"██      ██    ██ ██  ██ ██    ██    ██ ██  ██ ██ ██    ██ ██                ▀▀    ");
	Controller::gotoXY(x, y + 4);
	Screen::printVietnamese(L" ██████  ██████  ██   ████    ██    ██ ██   ████  ██████  ███████           ██    ");
}
void Play::print_yes(int x, int y, int bcolor, int color)
{
	//print_rectangle(x - 1, y - 1, 42, 7, bcolor, color);
	print_box_yes(x - 1, y - 1, bcolor, color);
	Controller::gotoXY(x + 8, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"██    ██ ███████ ███████ ");
	Controller::gotoXY(x + 8, y + 1);
	Screen::printVietnamese(L" ██  ██  ██      ██      ");
	Controller::gotoXY(x + 8, y + 2);
	Screen::printVietnamese(L"  ████   █████   ███████ ");
	Controller::gotoXY(x + 8, y + 3);
	Screen::printVietnamese(L"   ██    ██           ██ ");
	Controller::gotoXY(x + 8, y + 4);
	Screen::printVietnamese(L"   ██    ███████ ███████ ");
}
void Play::print_no(int x, int y, int bcolor, int color)
{
	//print_rectangle(x - 1, y - 1, 42, 7, bcolor, color);
	print_box_no(x - 2, y - 1, bcolor, color);
	Controller::gotoXY(x + 12, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"███    ██  ██████  ");
	Controller::gotoXY(x + 12, y + 1);
	Screen::printVietnamese(L"████   ██ ██    ██ ");
	Controller::gotoXY(x + 12, y + 2);
	Screen::printVietnamese(L"██ ██  ██ ██    ██ ");
	Controller::gotoXY(x + 12, y + 3);
	Screen::printVietnamese(L"██  ██ ██ ██    ██ ");
	Controller::gotoXY(x + 12, y + 4);
	Screen::printVietnamese(L"██   ████  ██████  ");
}

void Play::print_no_money(int x, int y, int bcolor, int color)
{
	print_rectangle(x - 1, y - 1, 73, 8, bcolor, color);
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"██████╗ ███████╗███╗   ██╗███╗   ██╗██╗██╗     ███████╗███████╗███████╗");
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"██╔══██╗██╔════╝████╗  ██║████╗  ██║██║██║     ██╔════╝██╔════╝██╔════╝");
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"██████╔╝█████╗  ██╔██╗ ██║██╔██╗ ██║██║██║     █████╗  ███████╗███████╗");
	Controller::gotoXY(x, y + 3);
	Screen::printVietnamese(L"██╔═══╝ ██╔══╝  ██║╚██╗██║██║╚██╗██║██║██║     ██╔══╝  ╚════██║╚════██║");
	Controller::gotoXY(x, y + 4);
	Screen::printVietnamese(L"██║     ███████╗██║ ╚████║██║ ╚████║██║███████╗███████╗███████║███████║");
	Controller::gotoXY(x, y + 5);
	Screen::printVietnamese(L"╚═╝     ╚══════╝╚═╝  ╚═══╝╚═╝  ╚═══╝╚═╝╚══════╝╚══════╝╚══════╝╚══════╝");
}
void Play::print_lose(int x, int y, int bcolor, int color)
{


	print_rectangle(x - 1, y - 1, 76, 8, bcolor, color);
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"██╗      ██████╗ ███████╗███████╗     ██████╗  █████╗ ███╗   ███╗███████╗");
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"██║     ██╔═══██╗██╔════╝██╔════╝    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝");
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"██║     ██║   ██║███████╗█████╗      ██║  ███╗███████║██╔████╔██║█████╗  ");
	Controller::gotoXY(x, y + 3);
	Screen::printVietnamese(L"██║     ██║   ██║╚════██║██╔══╝      ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ");
	Controller::gotoXY(x, y + 4);
	Screen::printVietnamese(L"███████╗╚██████╔╝███████║███████╗    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗");
	Controller::gotoXY(x, y + 5);
	Screen::printVietnamese(L"╚══════╝ ╚═════╝ ╚══════╝╚══════╝     ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝");
}
void Play::print_win(int x, int y, int bcolor, int color)
{
	print_rectangle(x - 1, y - 1, 66, 8, bcolor, color);
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	Screen::printVietnamese(L"██╗    ██╗██╗███╗   ██╗     ██████╗  █████╗ ███╗   ███╗███████╗");
	Controller::gotoXY(x, y + 1);
	Screen::printVietnamese(L"██║    ██║██║████╗  ██║    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝");
	Controller::gotoXY(x, y + 2);
	Screen::printVietnamese(L"██║ █╗ ██║██║██╔██╗ ██║    ██║  ███╗███████║██╔████╔██║█████╗  ");
	Controller::gotoXY(x, y + 3);
	Screen::printVietnamese(L"██║███╗██║██║██║╚██╗██║    ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ");
	Controller::gotoXY(x, y + 4);
	Screen::printVietnamese(L"╚███╔███╔╝██║██║ ╚████║    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗");
	Controller::gotoXY(x, y + 5);
	Screen::printVietnamese(L" ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝     ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝");
}

void Play::print_tower_Level1(int x, int y, int bcolor, int color)
{
	Tower t;
	print_rectangle(x, y, 7, 9, bcolor, color);
	t.drawTowerLevel1_Up(x + 1, y + 2, bcolor, color);
	Controller::gotoXY(x + 2, y + 7);
	Controller::SetColor(bcolor, color);
	cout << "10 $";
}
void Play::print_tower_Level2(int x, int y, int bcolor, int color)
{
	Tower t;
	print_rectangle(x, y, 9, 9, bcolor, color);
	t.drawTowerLevel2_Up(x + 1, y + 1, bcolor, color);
	Controller::gotoXY(x + 2, y + 7);
	Controller::SetColor(bcolor, color);
	cout << "20 $";
}
void Play::print_tower_Level3(int x, int y, int bcolor, int color)
{
	Tower t;
	print_rectangle(x, y, 11, 9, bcolor, color);
	t.drawTowerLevel3_Up(x + 1, y + 1, bcolor, color);
	Controller::gotoXY(x + 2, y + 7);
	Controller::SetColor(bcolor, color);
	cout << "40 $";
}

void Play::print_x(int x, int y, int bcolor, int color)
{

	Controller::SetColor(bcolor, color);
	Controller::gotoXY(x, y);
	Screen::printVietnamese(L"█");
	Controller::gotoXY(x + 4, y);
	Screen::printVietnamese(L"█");
	Controller::gotoXY(x + 1, y + 1);
	Screen::printVietnamese(L"█");
	Controller::gotoXY(x + 2, y + 2);
	Screen::printVietnamese(L"█");
	Controller::gotoXY(x + 1, y + 3);
	Screen::printVietnamese(L"█");
	Controller::gotoXY(x + 3, y + 3);
	Screen::printVietnamese(L"█");
	Controller::gotoXY(x + 3, y + 1);
	Screen::printVietnamese(L"█");
	Controller::gotoXY(x, y + 4);
	Screen::printVietnamese(L"█");
	Controller::gotoXY(x + 4, y + 4);
	Screen::printVietnamese(L"█");


}
void Play::print_x_block(int x, int y, int bcolor, int color)
{
	print_rectangle(x, y, 7, 9, bcolor, color);
	print_x(x + 1, y + 1, bcolor, color);
}

void Play::print_menu_continue(int x, int y)
{
	print_box_continue(x - 1, y - 1, LIGHT_GREEN, LIGHT_PURPLE);
	print_continue(x, y, LIGHT_GREEN, LIGHT_PURPLE);
	print_yes(x, y + 7, AQUA, LIGHT_PURPLE);
	print_no(x + 42, y + 7, AQUA, LIGHT_PURPLE);
}
int Play::print_continue_board(int x, int y, Map m)
{
	print_menu_continue(30, 18);
	int old_pos;
	int pos = 0;
	print_yes(x, y + 7, YELLOW, LIGHT_PURPLE);

	while (true)
	{
		if (_kbhit())
		{
			int tmp = Controller::getConsoleInput();
			if (tmp == 3) // left
			{
				old_pos = pos;
				pos--;
				if (pos == -1)
					pos = 1;

				if (old_pos == 0)
				{
					print_yes(x, y + 7, AQUA, LIGHT_PURPLE);
				}
				else if (old_pos == 1)
				{
					print_no(x + 42, y + 7, AQUA, LIGHT_PURPLE);
				}

				if (pos == 0)
				{
					print_yes(x, y + 7, YELLOW, LIGHT_PURPLE);
				}
				else if (pos == 1)
				{
					print_no(x + 42, y + 7, YELLOW, LIGHT_PURPLE);
				}

			}
			else if (tmp == 4) // right
			{
				old_pos = pos;
				pos++;
				if (pos == 2)
					pos = 0;

				if (old_pos == 0)
				{
					print_yes(x, y + 7, AQUA, LIGHT_PURPLE);
				}
				else if (old_pos == 1)
				{
					print_no(x + 42, y + 7, AQUA, LIGHT_PURPLE);
				}

				if (pos == 0)
				{
					print_yes(x, y + 7, YELLOW, LIGHT_PURPLE);
				}
				else if (pos == 1)
				{
					print_no(x + 42, y + 7, YELLOW, LIGHT_PURPLE);
				}
			}
			else if (tmp == 6) // enter
			{
				if(pos == 0)
					m.printMap();
				return pos;
			}
		}
	}

	return 0;
}

void Play::print_menu_Tower(int x, int y)
{
	print_tower_Level1(x, y, 5, 6);
	print_tower_Level2(x + 7, y, 5, 6);
	print_tower_Level3(x + 7 + 9, y, 5, 6);
	print_x_block(x + 7 + 9 + 11, y, 5, 6);
}

void Play::printBoxContinue(int x, int y, int bcolor, int color) {
	print_rectangle(x, y, 15, 3, bcolor, color);
	
	Controller::gotoXY(x + 3, y + 1);
	Controller::SetColor(bcolor, color);
	if (Screen::isVie) {
		Screen::printVietnamese(L"Tiếp tục");
	}
	else {
		cout << "Continue";
	}
}

void Play::printBoxSave(int x, int y, int bcolor, int color) {
	print_rectangle(x, y, 15, 3, bcolor, color);

	Controller::gotoXY(x + 3, y + 1);
	Controller::SetColor(bcolor, color);
	if (Screen::isVie) {
		Screen::printVietnamese(L"Lưu Game");
	}
	else {
		cout << "Save Game";
	}
}

void Play::printBoxExit(int x, int y, int bcolor, int color) {
	print_rectangle(x, y, 15, 3, bcolor, color);

	Controller::gotoXY(x + 3, y + 1);
	Controller::SetColor(bcolor, color);
	if (Screen::isVie) {
		Screen::printVietnamese(L"Thoát Game");
	}
	else {
		cout << "Exit Game";
	}
}

int Play::printMenuPause(int x, int y, int bcolor, int color) {
	Play::printBoxContinue(x, y, LIGHT_PURPLE, BRIGHT_WHITE);
	Play::printBoxSave(x, y + 4, BRIGHT_WHITE, LIGHT_PURPLE);
	Play::printBoxExit(x, y + 8, BRIGHT_WHITE, LIGHT_PURPLE);

	int choice = 0;

	while (true) {
		if (_kbhit()) {
			switch (Controller::getConsoleInput())
			{
			case 2:
				if (choice > 0) {
					choice--;
					if (choice == 0) {
						Play::printBoxContinue(x, y, LIGHT_PURPLE, BRIGHT_WHITE);
						Play::printBoxSave(x, y + 4, BRIGHT_WHITE, LIGHT_PURPLE);
						Play::printBoxExit(x, y + 8, BRIGHT_WHITE, LIGHT_PURPLE);
					}
					else if (choice == 1) {
						Play::printBoxContinue(x, y, BRIGHT_WHITE, LIGHT_PURPLE);
						Play::printBoxSave(x, y + 4, LIGHT_PURPLE, BRIGHT_WHITE);
						Play::printBoxExit(x, y + 8, BRIGHT_WHITE, LIGHT_PURPLE);
					}
					else {
						Play::printBoxContinue(x, y, BRIGHT_WHITE, LIGHT_PURPLE);
						Play::printBoxSave(x, y + 4, BRIGHT_WHITE, LIGHT_PURPLE);
						Play::printBoxExit(x, y + 8, LIGHT_PURPLE, BRIGHT_WHITE);
					}
				}
				break;
			case 5:
				if (choice < 2) {
					choice++;
					if (choice == 0) {
						Play::printBoxContinue(x, y, LIGHT_PURPLE, BRIGHT_WHITE);
						Play::printBoxSave(x, y + 4, BRIGHT_WHITE, LIGHT_PURPLE);
						Play::printBoxExit(x, y + 8, BRIGHT_WHITE, LIGHT_PURPLE);
					}
					else if (choice == 1) {
						Play::printBoxContinue(x, y, BRIGHT_WHITE, LIGHT_PURPLE);
						Play::printBoxSave(x, y + 4, LIGHT_PURPLE, BRIGHT_WHITE);
						Play::printBoxExit(x, y + 8, BRIGHT_WHITE, LIGHT_PURPLE);
					}
					else {
						Play::printBoxContinue(x, y, BRIGHT_WHITE, LIGHT_PURPLE);
						Play::printBoxSave(x, y + 4, BRIGHT_WHITE, LIGHT_PURPLE);
						Play::printBoxExit(x, y + 8, LIGHT_PURPLE, BRIGHT_WHITE);
					}
				}
				break;
			case 6:
				Play::printBoxContinue(x, y, BRIGHT_WHITE, BRIGHT_WHITE);
				Play::printBoxSave(x, y + 4, BRIGHT_WHITE, BRIGHT_WHITE);
				Play::printBoxExit(x, y + 8, BRIGHT_WHITE, BRIGHT_WHITE);
				return choice;

				break;
			default:
				break;
			}
		}
	}
}

int Play::get_lever_Tower(int x, int y, Map m)
{
	print_menu_Tower(x, y);
	int old_pos;
	int pos = 1;
	print_tower_Level1(x, y, 4, 6);
	while (true)
	{
		if (_kbhit())
		{
			int tmp = Controller::getConsoleInput();
			if (tmp == 3)
			{
				old_pos = pos;
				pos--;
				if (pos == 0)
					pos = 4;

				if (old_pos == 1)
				{
					print_tower_Level1(x, y, 5, 6);
				}
				else if (old_pos == 2)
				{
					print_tower_Level2(x + 7, y, 5, 6);
				}
				else if (old_pos == 3)
				{
					print_tower_Level3(x + 7 + 9, y, 5, 6);
				}
				else if (old_pos == 4)
				{
					print_x_block(x + 7 + 9 + 11, y, 5, 6);
				}

				if (pos == 1)
				{
					print_tower_Level1(x, y, 4, 6);
				}
				else if (pos == 2)
				{
					print_tower_Level2(x + 7, y, 4, 6);
				}
				else if (pos == 3)
				{
					print_tower_Level3(x + 7 + 9, y, 4, 6);
				}
				else if (pos == 4)
				{
					print_x_block(x + 7 + 9 + 11, y, 4, 6);
				}

			}
			else if (tmp == 4)
			{
				old_pos = pos;
				pos++;
				if (pos == 5)
					pos = 1;

				if (old_pos == 1)
				{
					print_tower_Level1(x, y, 5, 6);
				}
				else if (old_pos == 2)
				{
					print_tower_Level2(x + 7, y, 5, 6);
				}
				else if (old_pos == 3)
				{
					print_tower_Level3(x + 7 + 9, y, 5, 6);
				}
				else if (old_pos == 4)
				{
					print_x_block(x + 7 + 9 + 11, y, 5, 6);
				}

				if (pos == 1)
				{
					print_tower_Level1(x, y, 4, 6);
				}
				else if (pos == 2)
				{
					print_tower_Level2(x + 7, y, 4, 6);
				}
				else if (pos == 3)
				{
					print_tower_Level3(x + 7 + 9, y, 4, 6);
				}
				else if (pos == 4)
				{
					print_x_block(x + 7 + 9 + 11, y, 4, 6);
				}
			}
			else if (tmp == 6)
			{
				m.printMap();
				int c;
				mu.lock();
				c = player.get_cost();
				mu.unlock();
				if (pos == 1)
				{
					if (c < 10)
					{
						print_no_money(30, 18, 8, 13);
						Sleep(400);
						m.printMap();
						return 4;
					}
					else
					{
						mu.lock();
						player.de_cost(10);
						mu.unlock();
					}
				}
				if (pos == 2)
				{
					if (c < 20)
					{
						print_no_money(30, 18, 8, 13);
						Sleep(400);
						m.printMap();
						return 4;
					}
					else
					{
						mu.lock();
						player.de_cost(20);
						mu.unlock();
					}
				}
				if (pos == 3)
				{
					if (c < 40)
					{
						print_no_money(30, 18, 8, 13);
						Sleep(400);
						m.printMap();
						return 4;
					}
					else
					{
						mu.lock();
						player.de_cost(40);
						mu.unlock();
					}
				}

				return pos;
			}
		}
	}
}

void Play::play_map(string filename_enemy, string filename_map)
{
	Map newMap;
	newMap.setMap(filename_enemy);
	vector< vector<int> > pickWay;
	newMap.browseMap(pickWay);

	player.new_hp(10);
	Map test;
	test.setMap(filename_map);
	test.printMap();

	vector< vector<int> > posTower; 
	test.findPositionOfTower(posTower);

	bool choose[4] = { false,false,false,false };
	int res[4] = { -1,-1,-1,-1 };
	vector<thread> draws;
	vector<thread> bullets;
	vector<Tower> towers(4);
	showcost = true;
	Player::print_cost_first(142, 2, BRIGHT_WHITE, GREEN);
	ingame = true;
	losegame = false;
	wingame = false;

	int old_pos;
	int position = 0;
	colour_block(posTower[position][1], posTower[position][2], 5, 8, 4);

	int cnt = 0;
	bool stop = false;
	while (cnt < 4)
	{
		if (_kbhit())
		{
			int temp = Controller::getConsoleInput();
			if (temp == 2) // up
			{
				old_pos = position;
				int i = 0;
				do
				{
					position++;
					if (position == 4)
						position = 2;

				} while (choose[position] && i < cnt);

				colour_block(posTower[old_pos][1], posTower[old_pos][2], 5, 8, 6);
				colour_block(posTower[position][1], posTower[position][2], 5, 8, 4);
			}
			else if (temp == 3) // left
			{
				old_pos = position;
				int i = 0;
				do
				{
					position--;
					if (position == -1)
						position = 3;
				} while (choose[position] && i < cnt);
				colour_block(posTower[old_pos][1], posTower[old_pos][2], 5, 8, 6);
				colour_block(posTower[position][1], posTower[position][2], 5, 8, 4);
			}
			else if (temp == 4)
			{
				old_pos = position;

				int i = 0;
				do
				{
					position++;
					if (position == 4)
						position = 0;
				} while (choose[position] && i < cnt);
				colour_block(posTower[old_pos][1], posTower[old_pos][2], 5, 8, 6);
				colour_block(posTower[position][1], posTower[position][2], 5, 8, 4);
			}

			else if (temp == 5)
			{
				old_pos = position;

				int i = 0;
				do
				{
					position--;
					if (position == -1)
						position = 3;
					else if (position == 2)
						position = 0;
				} while (choose[position] && i < cnt);

				colour_block(posTower[old_pos][1], posTower[old_pos][2], 5, 8, 6);
				colour_block(posTower[position][1], posTower[position][2], 5, 8, 4);
			}
			else if (temp == 6)
			{
				int i;
				if (position == 0)
					i = get_lever_Tower(posTower[position][1], posTower[position][2], test);
				else
					i = get_lever_Tower(posTower[position][1], posTower[position][2], test);

				//test.printMap();
				Player::print_cost_first(142, 2, BRIGHT_WHITE, GREEN);
				choose[position] = true;
				cnt++;
				res[position] = i;
				// push tower
				for (int i = 0; i < 4; i++)
				{
					if (choose[i])
					{
						if (posTower[i][0] == 0) // up
						{
							if (res[i] == 1)
							{
								towers[i].drawTowerLevel1_Up(posTower[i][1], posTower[i][2], 6, 4);
							}
							else if (res[i] == 2)
							{
								towers[i].drawTowerLevel2_Up(posTower[i][1], posTower[i][2], 6, 4);
							}
							else if (res[i] == 3)
							{
								towers[i].drawTowerLevel3_Up(posTower[i][1], posTower[i][2], 6, 4);
							}
						}


						if (posTower[i][0] == 1) // down
						{
							if (res[i] == 1)
							{
								towers[i].drawTowerLevel1_Down(posTower[i][1], posTower[i][2], 6, 4);
							}
							else if (res[i] == 2)
							{
								towers[i].drawTowerLevel2_Down(posTower[i][1], posTower[i][2], 6, 4);
							}
							else if (res[i] == 3)
							{
								towers[i].drawTowerLevel3_Down(posTower[i][1], posTower[i][2], 6, 4);
							}
						}


						if (posTower[i][0] == 2) // left
						{
							if (res[i] == 1)
							{
								towers[i].drawTowerLevel1_Left(posTower[i][1], posTower[i][2], 6, 4);
							}
							else if (res[i] == 2)
							{
								towers[i].drawTowerLevel2_Left(posTower[i][1], posTower[i][2], 6, 4);
							}
							else if (res[i] == 3)
							{
								towers[i].drawTowerLevel3_Left(posTower[i][1], posTower[i][2], 6, 4);
							}
						}


						if (posTower[i][0] == 3) // right
						{
							if (res[i] == 1)
							{
								towers[i].drawTowerLevel1_Right(posTower[i][1], posTower[i][2], 6, 4);
							}
							else if (res[i] == 2)
							{
								towers[i].drawTowerLevel2_Right(posTower[i][1], posTower[i][2], 6, 4);
							}
							else if (res[i] == 3)
							{
								towers[i].drawTowerLevel3_Right(posTower[i][1], posTower[i][2], 6, 4);
							}
						}
					}
				}

				for (int j = 0; j < 4; j++)
				{
					if (choose[j] == false)
					{
						position = j;
						break;
					}
				}
				colour_block(posTower[position][1], posTower[position][2], 5, 8, 4);
			}

		}
	}
	colour_block(posTower[position][1], posTower[position][2], 5, 8, 6);
	///
	for (int i = 0; i < 4; i++)
	{
		if (choose[i])
		{
			if (posTower[i][0] == 0) // up
			{
				if (res[i] == 1)
				{
					towers[i].drawTowerLevel1_Up(posTower[i][1], posTower[i][2], 6, 4);
				}
				else if (res[i] == 2)
				{
					towers[i].drawTowerLevel2_Up(posTower[i][1], posTower[i][2], 6, 4);
				}
				else if (res[i] == 3)
				{
					towers[i].drawTowerLevel3_Up(posTower[i][1], posTower[i][2], 6, 4);
				}
			}


			if (posTower[i][0] == 1) // down
			{
				if (res[i] == 1)
				{
					towers[i].drawTowerLevel1_Down(posTower[i][1], posTower[i][2], 6, 4);
				}
				else if (res[i] == 2)
				{
					towers[i].drawTowerLevel2_Down(posTower[i][1], posTower[i][2], 6, 4);
				}
				else if (res[i] == 3)
				{
					towers[i].drawTowerLevel3_Down(posTower[i][1], posTower[i][2], 6, 4);
				}
			}


			if (posTower[i][0] == 2) // left
			{
				if (res[i] == 1)
				{
					towers[i].drawTowerLevel1_Left(posTower[i][1], posTower[i][2], 6, 4);
				}
				else if (res[i] == 2)
				{
					towers[i].drawTowerLevel2_Left(posTower[i][1], posTower[i][2], 6, 4);
				}
				else if (res[i] == 3)
				{
					towers[i].drawTowerLevel3_Left(posTower[i][1], posTower[i][2], 6, 4);
				}
			}


			if (posTower[i][0] == 3) // right
			{
				if (res[i] == 1)
				{
					towers[i].drawTowerLevel1_Right(posTower[i][1], posTower[i][2], 6, 4);
				}
				else if (res[i] == 2)
				{
					towers[i].drawTowerLevel2_Right(posTower[i][1], posTower[i][2], 6, 4);
				}
				else if (res[i] == 3)
				{
					towers[i].drawTowerLevel3_Right(posTower[i][1], posTower[i][2], 6, 4);
				}
			}
		}
	}
	////////
	for (int i = 0; i < 4; i++)
	{
		if (choose[i])
		{
			if (posTower[i][0] == 0) // up
			{
				if (res[i] == 1)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level1_Up, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
				else if (res[i] == 2)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level2_Up, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
				else if (res[i] == 3)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level3_Up, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
			}


			if (posTower[i][0] == 1) // down
			{
				if (res[i] == 1)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level1_Down, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
				else if (res[i] == 2)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level2_Down, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
				else if (res[i] == 3)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level3_Down, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
			}


			if (posTower[i][0] == 2) // left
			{
				if (res[i] == 1)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level1_Left, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
				else if (res[i] == 2)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level2_Left, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
				else if (res[i] == 3)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level3_Left, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
			}


			if (posTower[i][0] == 3) // right
			{
				if (res[i] == 1)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level1_Right, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
				else if (res[i] == 2)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level2_Right, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
				else if (res[i] == 3)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level3_Right, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
			}
		}
	}


	bullets.push_back(thread(Player::print_cost_player, 142, 2, BRIGHT_WHITE, GREEN));
	bullets.push_back(thread(Player::print_hp_player, 138, 3, BRIGHT_WHITE, RED));
	bullets.push_back(thread(enemy_move1, Game::num_enemy, filename_enemy));
	bullets.push_back(thread(Player::check_win, Game::num_enemy, posTower, res, choose, filename_map, filename_enemy));
	bullets.push_back(thread(Game::printNumEnemy));

	for (auto& bu : bullets)
	{
		bu.join();
	}

	if (losegame)
	{
		print_lose(30, 18, YELLOW, LIGHT_PURPLE);
		Sleep(3000);
	}
	else if (wingame)
	{
		print_win(30, 18, YELLOW, LIGHT_PURPLE);
		Sleep(3000);
	}

	int value = print_continue_board(30, 18, test);

	if (value == 1)
	{
		Game::isPlaying = false;
		Menu::goBack();
		//isbreakmap1 = true;
	}
}

string Play::getFileSave() {
	mu.lock();
	print_rectangle(132, 32, 22, 7, BRIGHT_WHITE, BLACK);
	Controller::gotoXY(132, 35);
	putchar(204);
	for (int i = 1; i < 21; i++) {
		Controller::gotoXY(132 + i, 35);
		putchar(205);
	}
	Controller::gotoXY(132 + 21, 35);
	putchar(185);

	Controller::SetColor(BRIGHT_WHITE, BLACK);
	if (Screen::isVie) {
		Controller::gotoXY(136, 33);
		Screen::printVietnamese(L"Nhập tên file");
		Controller::gotoXY(134, 34);
		Screen::printVietnamese(L"(Độ dài 6 đến 12)");
	}
	else {
		Controller::gotoXY(136, 33);
		cout << "Enter file name";
		Controller::gotoXY(136, 34);
		cout << "(Length 6 - 12)";
	}
	mu.unlock();
	string filename;
	do {
		mu.lock();
		Controller::gotoXY(134, 36);
		getline(cin, filename);
		mu.unlock();
	} while (filename.size() > 12 || filename.size() < 6);

	mu.lock();
	print_rectangle(132, 32, 22, 7, BRIGHT_WHITE, BRIGHT_WHITE);
	mu.unlock();

	return filename;
}

void Play::MOVE(string filename, Enemy& e)
{

	Map other;
	other.setMap(filename);
	vector< vector<int> > toMove;
	other.browseMap(toMove);

	for (int i = 0; i < toMove.size(); i++)
	{
		int WAY, start_X, start_Y, end_X, end_Y;
		WAY = toMove[i][0];
		start_X = toMove[i][1];
		start_Y = toMove[i][2];
		end_X = toMove[i][3];
		end_Y = toMove[i][4];
		if (WAY == 0)
		{
			e.move_l(start_X + 2, start_Y + 2, end_X + 2, end_Y + 2);
		}
		if (WAY == 1)
		{
			e.move_x(start_X + 2, start_Y + 2, end_X + 2, end_Y + 2);
		}
		if (WAY == 2)
		{
			e.move_t(start_X + 2, start_Y + 2, end_X + 2, end_Y + 2);
		}
		if (WAY == 3)
		{
			e.move_p(start_X + 2, start_Y + 2, end_X + 12, end_Y + 2);
		}
	}
	if (e.get_hp() <= 0)
	{
		mu.lock();
		player.in_cost(1);
		mu.unlock();
	}
	if (e.get_hp() > 0)
	{
		mu.lock();
		player.de_hp(1);
		mu.unlock();
	}
	e.set_hp(0);
}
void Play::enemy_move1(int num, string fileName)
{
	e_global.clear();
	e_global.resize(num);
	vector<thread> threads;

	for (int i = 0; i < num; i++)
	{
		bool check;
		mu.lock();
		check = ingame;
		mu.unlock();
		if (check == false)
		{
			break;
		}
		mu.lock();

		bool isPause = Game::isPause;
		
		mu.unlock();

		if (isPause) {
			--i;
			continue;
		}

		mu.lock();
		bool Flag_Pause = Game::Flag_Pause;
		mu.unlock();


		if (Flag_Pause)
		{
			Sleep(5000);
			mu.lock();
			Game::Flag_Pause = false;
			mu.unlock();
		}


		mu.lock();
		Enemy& e = e_global[i];
		Enemy::count++;
		mu.unlock();

		//Sleep(5000);
		threads.push_back(thread(MOVE, fileName, ref(e)));
		Sleep(5000);
	}

	for (auto& th : threads)
	{
		if (th.joinable()) th.join();
	}
}

void Play::playContinue(vector<vector<int>> posTower, int res[], bool choice[], string file_map, string file_enemy) {
	Map newMap;
	newMap.setMap(file_enemy);
	vector< vector<int> > pickWay;
	newMap.browseMap(pickWay);

	player.new_hp(10);
	Controller::setUpConsole();
	Map test;
	test.setMap(file_map);
	test.printMap();

	vector<thread> bullets;
	vector<Tower> towers(4);
	showcost = true;
	Player::print_cost_first(142, 2, BRIGHT_WHITE, GREEN);
	ingame = true;
	losegame = false;
	wingame = false;

	///
	for (int i = 0; i < 4; i++)
	{
		if (choice[i])
		{
			if (posTower[i][0] == 0) // up
			{
				if (res[i] == 1)
				{
					towers[i].drawTowerLevel1_Up(posTower[i][1], posTower[i][2], 6, 4);
				}
				else if (res[i] == 2)
				{
					towers[i].drawTowerLevel2_Up(posTower[i][1], posTower[i][2], 6, 4);
				}
				else if (res[i] == 3)
				{
					towers[i].drawTowerLevel3_Up(posTower[i][1], posTower[i][2], 6, 4);
				}
			}


			if (posTower[i][0] == 1) // down
			{
				if (res[i] == 1)
				{
					towers[i].drawTowerLevel1_Down(posTower[i][1], posTower[i][2], 6, 4);
				}
				else if (res[i] == 2)
				{
					towers[i].drawTowerLevel2_Down(posTower[i][1], posTower[i][2], 6, 4);
				}
				else if (res[i] == 3)
				{
					towers[i].drawTowerLevel3_Down(posTower[i][1], posTower[i][2], 6, 4);
				}
			}


			if (posTower[i][0] == 2) // left
			{
				if (res[i] == 1)
				{
					towers[i].drawTowerLevel1_Left(posTower[i][1], posTower[i][2], 6, 4);
				}
				else if (res[i] == 2)
				{
					towers[i].drawTowerLevel2_Left(posTower[i][1], posTower[i][2], 6, 4);
				}
				else if (res[i] == 3)
				{
					towers[i].drawTowerLevel3_Left(posTower[i][1], posTower[i][2], 6, 4);
				}
			}


			if (posTower[i][0] == 3) // right
			{
				if (res[i] == 1)
				{
					towers[i].drawTowerLevel1_Right(posTower[i][1], posTower[i][2], 6, 4);
				}
				else if (res[i] == 2)
				{
					towers[i].drawTowerLevel2_Right(posTower[i][1], posTower[i][2], 6, 4);
				}
				else if (res[i] == 3)
				{
					towers[i].drawTowerLevel3_Right(posTower[i][1], posTower[i][2], 6, 4);
				}
			}
		}
	}

	////////
	for (int i = 0; i < 4; i++)
	{
		if (choice[i])
		{
			if (posTower[i][0] == 0) // up
			{
				if (res[i] == 1)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level1_Up, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
				else if (res[i] == 2)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level2_Up, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
				else if (res[i] == 3)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level3_Up, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
			}


			if (posTower[i][0] == 1) // down
			{
				if (res[i] == 1)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level1_Down, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
				else if (res[i] == 2)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level2_Down, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
				else if (res[i] == 3)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level3_Down, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
			}


			if (posTower[i][0] == 2) // left
			{
				if (res[i] == 1)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level1_Left, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
				else if (res[i] == 2)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level2_Left, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
				else if (res[i] == 3)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level3_Left, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
			}


			if (posTower[i][0] == 3) // right
			{
				if (res[i] == 1)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level1_Right, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
				else if (res[i] == 2)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level2_Right, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
				else if (res[i] == 3)
				{
					bullets.push_back(thread(&Tower::tower_bullet_level3_Right, &towers[i], posTower[i][1], posTower[i][2], posTower[i][3], posTower[i][4]));
				}
			}
		}
	}



	bullets.push_back(thread(Player::print_cost_player, 142, 2, BRIGHT_WHITE, GREEN));
	bullets.push_back(thread(Player::print_hp_player, 138, 3, BRIGHT_WHITE, RED));
	bullets.push_back(thread(enemy_move1, Game::num_enemy, file_enemy));
	bullets.push_back(thread(Player::check_win, Game::num_enemy, posTower, res, choice, file_map, file_enemy));
	bullets.push_back(thread(Game::printNumEnemy));

	for (auto& bu : bullets)
	{
		bu.join();
	}

	if (losegame)
	{
		print_lose(30, 18, 8, 13);
		Sleep(3000);
	}
	else if (wingame)
	{
		print_win(30, 18, 8, 13);
		Sleep(3000);
	}

	int value = print_continue_board(30, 18, test);

	if (value == 1)
	{
		Game::isPlaying = false;
		Menu::goBack();
		//isbreakmap1 = true;
	}
}