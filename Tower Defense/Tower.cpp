#include "Tower.h"
#include "Controller.h"
#include "Library.h"

void Tower::drawTowerLevel1(int x, int y, int colorFirst, int colorSecond)
{
    Controller::gotoXY(x + 2, y);
    Controller::SetColor(colorFirst, colorSecond);
    Screen::printVietnamese(L"▓"); 
    Controller::gotoXY(x + 2, y + 1);
    Screen::printVietnamese(L"▓"); 
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"▓▓▓▓▓");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"▓▓▓▓▓");


    /*int i = 0;
    Controller::showCursor(false);
    while (y - 1 - i > 0)
    {
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L"^");
        Sleep(1000);
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L"    ");
        i += 1;
        Controller::gotoXY(x + 2, y - 1 - i);
        Screen::printVietnamese(L"*");
    }*/
}


void Tower::drawTowerLevel2(int x, int y, int colorFirst, int colorSecond)
{
    Controller::gotoXY(x + 2, y);
    Controller::SetColor(colorFirst, colorSecond);
    Screen::printVietnamese(L"▓ ▓");
    Controller::gotoXY(x + 2, y + 1);
    Screen::printVietnamese(L"▓ ▓");
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"░░░░░░░");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"░░░░░░░");
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"░░░░░░░");
}

void Tower::drawTowerLevel3(int x, int y, int colorFirst, int colorSecond)
{
    Controller::gotoXY(x + 2, y);
    Controller::SetColor(colorFirst, colorSecond);
    Screen::printVietnamese(L"▓ ▓ ▓");
    Controller::gotoXY(x + 2, y + 1);
    Screen::printVietnamese(L"▓ ▓ ▓");
    Controller::gotoXY(x, y + 2);
    Screen::printVietnamese(L"█████████");
    Controller::gotoXY(x, y + 3);
    Screen::printVietnamese(L"█████████");
    Controller::gotoXY(x, y + 4);
    Screen::printVietnamese(L"█████████");
}


/*
                           ▓
                           ▓
                         ▓▓▓▓▓
                         ▓▓▓▓▓  */
                          


                        //  ▓ ▓
                        //  ▓ ▓
                        //░░░░░░░
                        //░░░░░░░
                        //░░░░░░░



                        //  ▓ ▓ ▓
                        //  ▓ ▓ ▓
                        //█████████
                        //█████████
                        //█████████