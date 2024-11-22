#pragma once
#include "Point.h"
#include "Menu.h"

// Forward declaration
class Enemy;

class Bullet {
protected:
	int dame;
	int speed;
	Point position;
	int range_x;
	int range_y;
	Point src;
public:
	void setSrc(const Point&);
	void setPosition(const Point&);
	Bullet();
	virtual void printBullet() = 0;
	void wayBullet(Enemy*);
};

class ArcheryBullet : public Bullet {
public:
	ArcheryBullet();
	void printBullet();
};

class MagicBullet : public Bullet {
public:
	MagicBullet();
	void printBullet();
};