#include "Game.h"
#include "Controller.h"
#include "Map.h"
#include "Enemy.h"
#include "Tower.h"
#include "Play.h"

int main() {
	// remember below.

	Controller::setUpConsole();
	Menu::music_is_open = true;
	Menu::sound_is_open = true;
	while (true)
	{
		int mode = Screen::printMainScreen();
		if (mode == 0)
		{
			isbreakmap1 = false;
			while (!isbreakmap1)
			{
				Play::play_map(".\\Map\\level1_enemy.txt", ".\\Map\\level1_map.txt");
			}
		}
		else if (mode == 1)
		{
			isbreakmap1 = false;
			while (!isbreakmap1)
			{
				Play::play_map(".\\Map\\level2_enemy.txt", ".\\Map\\level2_map.txt");
			}
		}
		else if (mode == 2)
		{
			isbreakmap1 = false;
			while (!isbreakmap1)
			{
				Play::play_map(".\\Map\\level3_enemy.txt", ".\\Map\\level3_map.txt");
			}
		}
		else
		{
			system("cls");
			cout << "shitttttttttttttttttttttttttttttttttt";
		}
	}



	/*Map t;
	t.createMap();*/
	//t.setMap(".\\Map\\level1_map.txt");
	////t.printMap();
	//vector< vector<int> > temp;
	//t.findPositionOfTower(temp);
	//cout << temp.size() << "\n\n\n";
	//for (int i = 0; i < temp.size(); i++)
	//{
	//	for (int j = 0; j < temp[i].size(); j++)
	//	{
	//		cout << temp[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	//t.printMap();
	//Enemy my;
	//MOVE(".\\Map\\tet.txt", my);
	//enemy_move1(20, ".\\Map\\tet.txt");
//	for (int i = 0; i < t.getHeight(); i++)
//{
//	for (int j = 0; j < t.getWidth(); j++)
//	{
//		cout << t.getMap()[i][j].getMark() << ' ';
//	}
//	cout << '\n';
//}

	/*vector< vector<int> > ans;
	t.browerMap(ans);
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}*/

	return 0;
}