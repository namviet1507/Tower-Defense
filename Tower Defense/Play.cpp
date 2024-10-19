#include "Play.h"

void colour_block(int x, int y, int h, int w, int color)
{
	Cell t;
	t.setArea(h, w);
	t.setColor(color);
	t.setPos(x, y);
	t.printCell();
}

void colour_block2(int x, int y, int w, int h, int bcolor)
{
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, bcolor);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << " ";
		}
		Controller::gotoXY(x, y+i+1);
	}
}

void print_rectangle(int x, int y, int w, int h, int bcolor, int color)
{
	Controller::gotoXY(x, y);
	Controller::SetColor(bcolor, color);
	putchar(201);
	for (int i = 1; i < w -1; i++) {
		putchar(205);
	}
	putchar(187);
	Controller::gotoXY(x, y + 1);

	for (int i = 1; i < h - 1; i++)
	{
		cout << char(186);
		for (int j = 1; j < w -1; j++)
		{
			cout << " ";
		}
		cout << char(186);
		Controller::gotoXY(x, y + i + 1);
	}

	Controller::gotoXY(x, y + h-1);
	putchar(200);
	for (int i = 1; i < w-1; i++)
		putchar(205);
	putchar(188);
}


void print_tower_Level1(int x, int y,int bcolor,int color)
{
	Tower t;
	print_rectangle(x, y, 7, 7, bcolor, color);
	t.drawTowerLevel1_Up(x + 1, y +2, bcolor, color);
}
void print_tower_Level2(int x, int y, int bcolor, int color)
{
	Tower t;
	print_rectangle(x, y, 9, 7, bcolor, color);
	t.drawTowerLevel2_Up(x + 1, y + 1, bcolor, color);
}
void print_tower_Level3(int x, int y, int bcolor, int color)
{
	Tower t;
	print_rectangle(x, y, 11, 7, bcolor, color);
	t.drawTowerLevel3_Up(x + 1, y + 1, bcolor, color);
}

void print_x(int x, int y, int bcolor, int color)
{

	Controller::SetColor(bcolor, color);
	Controller::gotoXY(x, y);
	Screen::printVietnamese(L"█");
	Controller::gotoXY(x+4, y);
	Screen::printVietnamese(L"█");
	Controller::gotoXY(x+1, y+1);
	Screen::printVietnamese(L"█");
	Controller::gotoXY(x+2, y+2);
	Screen::printVietnamese(L"█");
	Controller::gotoXY(x+1, y+3);
	Screen::printVietnamese(L"█");
	Controller::gotoXY(x+3, y+3);
	Screen::printVietnamese(L"█");
	Controller::gotoXY(x+3, y+1);
	Screen::printVietnamese(L"█");
	Controller::gotoXY(x, y+4);
	Screen::printVietnamese(L"█");
	Controller::gotoXY(x+4, y+4);
	Screen::printVietnamese(L"█");


}
void print_x_block(int x, int y, int bcolor, int color)
{
	print_rectangle(x, y, 7, 7, bcolor, color);
	print_x(x + 1, y + 1, bcolor, color);
}

void print_menu_Tower(int x,int y)
{
	print_tower_Level1(x, y, 5, 6);
	print_tower_Level2(x + 7, y, 5, 6);
	print_tower_Level3(x + 7 + 9, y, 5, 6);
	print_x_block(x + 7 + 9 + 11, y, 5, 6);
}

int get_lever_Tower(int x, int y,Map m)
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
				return pos;
			}
		}
	}
}
















void play_map1()
{
	//Controller::showCursor(false);

	Controller::setUpConsole();
	Map test;
	test.setMap("./Map/level1.txt");
	test.printMap();
	int pos_x[4] = { 10,34,42,114 };
	int pos_y[4] = {36,11,1,31};
	int w[4] = {5,5,5,5};
	int h[4] = {16,8,16,8};
	bool choose[4] = { false,false,false,false };
	int res[4] = { -1,-1,-1,-1 };
	vector<thread> draws;
	vector<thread> bullets;
	vector<Tower> towers(4);

	ingame = true;

	int old_pos;
	int position = 0;

	colour_block(pos_x[position], pos_y[position], w[position], h[position], 4);

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

				colour_block(pos_x[old_pos], pos_y[old_pos], w[old_pos], h[old_pos], 6);
				colour_block(pos_x[position], pos_y[position], w[position], h[position], 4);
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
				colour_block(pos_x[old_pos], pos_y[old_pos], w[old_pos], h[old_pos], 6);
				colour_block(pos_x[position], pos_y[position], w[position], h[position], 4);
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
				colour_block(pos_x[old_pos], pos_y[old_pos], w[old_pos], h[old_pos], 6);
				colour_block(pos_x[position], pos_y[position], w[position], h[position], 4);
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

				colour_block(pos_x[old_pos], pos_y[old_pos], w[old_pos], h[old_pos], 6);
				colour_block(pos_x[position], pos_y[position], w[position], h[position], 4);
			}

			else if (temp == 6)
			{
				int i = get_lever_Tower(pos_x[position], pos_y[position], test);
				choose[position] = true;
				cnt++;
				res[position] = i;

				// push tower
				if (choose[0] == true)
				{
					if (res[0] == 1)
					{
						towers[0].drawTowerLevel1_Up(14, 36, 6, 4);
					}
					else if (res[0] == 2)
					{
						towers[0].drawTowerLevel2_Up(14, 36, 6, 4);
					}
					else if (res[0] == 3)
					{
						towers[0].drawTowerLevel3_Up(14, 36, 6, 4);
					}
				}
				if (choose[1] == true)
				{
					if (res[1] == 1)
					{
						towers[1].drawTowerLevel2_Right(34, 11, 6, 4);
					}
					else if (res[1] == 2)
					{
						towers[1].drawTowerLevel2_Right(34, 11, 6, 4);
					}
					else if (res[1] == 3)
					{
						towers[1].drawTowerLevel2_Right(34, 11, 6, 4);
					}
				}
				if (choose[2] == true)
				{
					if (res[2] == 1)
					{
						towers[2].drawTowerLevel2_Down(46, 0, 6, 4);
					}
					else if (res[2] == 2)
					{
						towers[2].drawTowerLevel2_Down(46, 0, 6, 4);
					}
					else if (res[2] == 3)
					{
						towers[2].drawTowerLevel2_Down(46, 0, 6, 4);
					}
				}

				if (choose[3] == true)
				{
					if (res[3] == 1)
					{
						towers[3].drawTowerLevel2_Left(117, 31, 6, 4);
					}
					else if (res[3] == 2)
					{
						towers[3].drawTowerLevel2_Left(117, 31, 6, 4);
					}
					else if (res[3] == 3)
					{
						towers[3].drawTowerLevel2_Left(117, 31, 6, 4);
					}
				}


				//
				for (int j = 0; j < 4; j++)
				{
					if (choose[j] == false)
					{
						position = j;
						break;
					}
				}
				colour_block(pos_x[position], pos_y[position], w[position], h[position], 4);
			}
			
		}
	}
	colour_block(pos_x[position], pos_y[position], w[position], h[position], 6);
	///
	if (res[0] == 1)
	{
		towers[0].drawTowerLevel1_Up(14, 36, 6, 4);
	}
	else if (res[0] == 2)
	{
		towers[0].drawTowerLevel2_Up(14, 36, 6, 4);
	}
	else if (res[0] == 3)
	{
		towers[0].drawTowerLevel3_Up(14, 36, 6, 4);
	}


	if (res[1] == 1)
	{
		towers[1].drawTowerLevel2_Right(34, 11, 6, 4);
	}
	else if (res[1] == 2)
	{
		towers[1].drawTowerLevel2_Right(34, 11, 6, 4);
	}
	else if (res[1] == 3)
	{
		towers[1].drawTowerLevel2_Right(34, 11, 6, 4);
	}

	if (res[2] == 1)
	{
		towers[2].drawTowerLevel2_Down(46, 0, 6, 4);
	}
	else if (res[2] == 2)
	{
		towers[2].drawTowerLevel2_Down(46, 0, 6, 4);
	}
	else if (res[2] == 3)
	{
		towers[2].drawTowerLevel2_Down(46, 0, 6, 4);
	}

	if (res[3] == 1)
	{
		towers[3].drawTowerLevel2_Left(117, 31, 6, 4);
	}
	else if (res[3] == 2)
	{
		towers[3].drawTowerLevel2_Left(117, 31, 6, 4);
	}
	else if (res[3] == 3)
	{
		towers[3].drawTowerLevel2_Left(117, 31, 6, 4);
	}
	////////
	if (res[0] == 1)
	{
		bullets.push_back(thread(&Tower::tower_bullet_level1_Up, &towers[0], 14, 36));
	}
	else if (res[0] == 2)
	{
		bullets.push_back(thread(&Tower::tower_bullet_level2_Up, &towers[0], 14, 36));
	}
	else if (res[0] == 3)
	{
		bullets.push_back(thread(&Tower::tower_bullet_level3_Up, &towers[0], 14, 36));
	}

	//
	if (res[1] == 1)
	{

		bullets.push_back(thread(&Tower::tower_bullet_level2_Right, &towers[1], 34, 11, 114, 11));
	}
	else if (res[1] == 2)
	{

		bullets.push_back(thread(&Tower::tower_bullet_level2_Right, &towers[1], 34, 11, 114, 11));
	}
	else if (res[1] == 3)
	{
		bullets.push_back(thread(&Tower::tower_bullet_level2_Right, &towers[1], 34, 11, 114, 11));
	}
	////
	//colour_block(125, 18, 5, 5, 2);
	if (res[2] == 1)
	{
		bullets.push_back(thread(&Tower::tower_bullet_level2_Down, &towers[2], 46, 0, 46, 35));
	}
	else if (res[2] == 2)
	{
		bullets.push_back(thread(&Tower::tower_bullet_level2_Down, &towers[2], 46, 0, 46, 35));
	}
	else if (res[2] == 3)
	{
		bullets.push_back(thread(&Tower::tower_bullet_level2_Down, &towers[2], 46, 0, 46, 35));
	}
	////
	if (res[3] == 1)
	{
		bullets.push_back(thread(&Tower::tower_bullet_level2_Left, &towers[3], 117, 31, 73, 31));
	}
	else if (res[3] == 2)
	{
		bullets.push_back(thread(&Tower::tower_bullet_level2_Left, &towers[3], 117, 31, 73, 31));
	}
	else if (res[3] == 3)
	{
		bullets.push_back(thread(&Tower::tower_bullet_level2_Right, &towers[3], 117, 31, 73, 31));
	}


	bullets.push_back(thread(print_hp_player, 125, 18, 0, 4));
	bullets.push_back(thread(enemy_map1, 20));
	bullets.push_back(thread(check_win, 20));

	for (auto& bu : bullets)
	{
		bu.join();
	}
	if (losegame)
	{
		Controller::gotoXY(125, 0);
		cout << "you lose!";
	}
	if (wingame)
	{
		Controller::gotoXY(125, 10);
		cout << "you win!";
	}
	//colour_block(125, 18, 5, 5, 2);
	//colour_block(125, 8, 3, 2, 3);
	//Tower t1,t2,t3,t4;
	//t1.drawTowerLevel2_Up(14, 36, 6, 4);
	//t2.drawTowerLevel2_Down(46, 0, 6, 4);
	//t3.drawTowerLevel2_Right(34, 11, 6, 4);
	//t4.drawTowerLevel2_Left(117, 31, 6, 4);

	//thread tow(&Tower::tower_bullet_level2_Up, &t1, 14, 36);
	//thread tow1(&Tower::tower_bullet_level2_Down, &t2, 46, 0, 46, 35);
	//thread tow2(&Tower::tower_bullet_level2_Right, &t2, 34, 11, 114, 11);
	//thread tow3(&Tower::tower_bullet_level2_Left, &t2, 117, 31, 73, 31);

	//thread te(enemy_map1, 30);

	//tow.join();
	//tow1.join();
	//tow2.join();
	//tow3.join();
	//te.join();


	cin.get();
}