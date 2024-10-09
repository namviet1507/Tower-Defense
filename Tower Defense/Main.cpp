#include "Game.h"
#include "Controller.h"
#include "Map.h"

int main() {
	Controller::setUpConsole();
	Menu::music_is_open = true;
	Menu::sound_is_open = true;
	Screen::printMainScreen();
<<<<<<< HEAD

=======
>>>>>>> 46e839356593e403559f5a7077ec1c58ab720f70
	system("PAUSE");
	return 0;
}