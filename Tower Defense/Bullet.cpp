#include "Bullet.h"
#include "Tower.h"
#include "Enemy.h"

Bullet::Bullet() {
	dame = 0;
	speed = 0;
	position = { 0, 0 };
	range_x = 0;
	range_y = 0;
}

ArcheryBullet::ArcheryBullet() {
	dame = 1;
	speed = 10;
	range_x = 30;
	range_y = 15;
}

MagicBullet::MagicBullet() {
	dame = 2;
	speed = 20;
	range_x = 40;
	range_y = 20;
}

void Bullet::setSrc(const Point& p) {
	src = p;
}

void Bullet::setPosition(const Point& p) {
	position = p;
}

void Bullet::wayBullet(Enemy* target) {
	bool out_of_range = false;
	while (position.getDistance(target->getPosition()) > 2) {

		if (abs(position.getX() - src.getX()) > range_x || abs(position.getY() - src.getY()) > range_y) {
			out_of_range = true;
			break;
		}
		Point next = position.getNextPoint(target->getPosition());
		if (position.getX() != next.getX() && position.getY() != next.getY()) Sleep(speed);
		_mutex.lock();
		Controller::SetColor(BLACK, BLACK);
		if (position.getDistance(src) > 3)
			printBullet();
		_mutex.unlock();
		position = next;
		_mutex.lock();
		Controller::SetColor(BLACK, RED);
		if (position.getDistance(src) > 3)
			printBullet();
		_mutex.unlock();
		Sleep(speed);
	}

	if (out_of_range == false) {
		// sub hp enemy
	}
	delete this;
}

// █ ▀ ▄ ▐▌ ■ │ ─ 

void ArcheryBullet::printBullet() {
	//if (position.getX() == src.getX() && position.getY() > src.getY()) {
	//	// ▄
	//	// │
	//	Controller::gotoXY(position.getX(), position.getY());
	//	Screen::printVietnamese(L"▄");
	//	Controller::gotoXY(position.getX(), position.getY() + 1);
	//	Screen::printVietnamese(L"│");
	//}
	//else if (position.getX() == src.getX() && position.getY() < src.getY()) {
	//	// │
	//	// ▀
	//	Controller::gotoXY(position.getX(), position.getY() - 1);
	//	Screen::printVietnamese(L"│");
	//	Controller::gotoXY(position.getX(), position.getY());
	//	Screen::printVietnamese(L"▀");
	//}
	//else if (position.getX() > src.getX() && position.getY() == src.getY()) {
	//	// ─■
	//	// 
	//	Controller::gotoXY(position.getX() - 1, position.getY());
	//	Screen::printVietnamese(L"─");
	//	Controller::gotoXY(position.getX(), position.getY());
	//	Screen::printVietnamese(L"■");
	//}
	//else if (position.getX() < src.getX() && position.getY() == src.getY()) {
	//	// ■─
	//	// 
	//	Controller::gotoXY(position.getX(), position.getY());
	//	Screen::printVietnamese(L"■");
	//	Controller::gotoXY(position.getX() + 1, position.getY());
	//	Screen::printVietnamese(L"─");
	//}
	//else if (position.getX() < src.getX() && position.getY() < src.getY()) {
	//	//  /
	//	// ▀
	//	Controller::gotoXY(position.getX() + 1, position.getY() - 1);
	//	Screen::printVietnamese(L"/");
	//	Controller::gotoXY(position.getX(), position.getY());
	//	Screen::printVietnamese(L"▀");
	//}
	//else if (position.getX() > src.getX() && position.getY() > src.getY()) {
	//	//  ▄
	//	// /
	//	Controller::gotoXY(position.getX(), position.getY());
	//	Screen::printVietnamese(L"▄");
	//	Controller::gotoXY(position.getX() - 1, position.getY() + 1);
	//	Screen::printVietnamese(L"/");
	//}
	//else if (position.getX() < src.getX() && position.getY() > src.getY()) {
	//	// ▄
	//	//  \/
	//	Controller::gotoXY(position.getX(), position.getY());
	//	Screen::printVietnamese(L"▄");
	//	Controller::gotoXY(position.getX() + 1, position.getY() + 1);
	//	Screen::printVietnamese(L"\\");
	//}
	//else if (position.getX() == src.getX() && position.getY() > src.getY()) {
	//	// \
	//	//  ▀
	//	Controller::gotoXY(position.getX() - 1, position.getY() - 1);
	//	Screen::printVietnamese(L"\\");
	//	Controller::gotoXY(position.getX(), position.getY());
	//	Screen::printVietnamese(L"▄");
	//}
	Controller::gotoXY(position.getX() - 1, position.getY());
	Screen::printVietnamese(L"─");
	Controller::gotoXY(position.getX(), position.getY());
	Screen::printVietnamese(L"■");
}

void MagicBullet::printBullet() {
	Controller::gotoXY(position.getX(), position.getY());
	Screen::printVietnamese(L"▄");
	Controller::gotoXY(position.getX() + 1, position.getY() + 1);
	Screen::printVietnamese(L"▀");
}