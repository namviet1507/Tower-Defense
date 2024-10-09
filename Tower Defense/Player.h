#pragma once
#include "Library.h"

class Player {
	private:
		wstring playerName;
		int score;
	public:
		Player();
		void setPlayerName(wstring);
		void setScore(int);
		wstring getPlayerName();
		int getScore();
};