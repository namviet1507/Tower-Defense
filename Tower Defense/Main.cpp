#include "Game.h"
#include "Controller.h"
#include "Map.h"

int main() {
	Controller::setUpConsole();
	//Menu::music_is_open = true;
	//Menu::sound_is_open = true;
	//Screen::printMainScreen();
	
	Sleep(1000);
	Map m;
	m.setMap("./Map/medium.txt");
	m.printMap();

	//for (int i = 0; i < 36; i++) {
	//	for (int j = 0; j < 56; j++) {
	//		cout << "01 ";
	//	}
	//	cout << '\n';
	//}


	system("PAUSE");
	return 0;
}