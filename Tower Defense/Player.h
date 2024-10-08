#pragma once
#include "Library.h"

class Player {
	private:
		wstring playerName;
		int score;
	public:
		Player();
		wstring getPlayerName();
		void setPlayerName(wstring);
		int getScore();
		void setScore(int);

};