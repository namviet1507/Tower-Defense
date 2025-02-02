#pragma once
#include "Library.h"
#include "Point.h"

enum class EffectType {
	None, Slow,
};

enum class MonsterType {
	None, Type1, Type2, Type3
};

enum class MonsterState {
	Alive, Dead
};

class Monster : public Point {
private:
	int id;
	int hitPoints;
	int speed;
	int level;
	int reward;
	int xPosition;
	int yPosition;
	MonsterState state;
	EffectType currentEffectType;

public:
	Monster() : id(0), hitPoints(10), speed(1), level(1), reward(1), xPosition(0), yPosition(0) { };

	Monster(int newId, int newHitPoints, int newSpeed, int lvl, int reward, int xSpawn, int ySpawn) :
		id(newId), hitPoints(newHitPoints), speed(newSpeed), level(lvl), reward(reward), xPosition(xSpawn), yPosition(ySpawn) { };

	virtual ~Monster();

	void ApplyDamage(int);
	MonsterState GetState() const;
	void SetState(MonsterState state);

	// Various accessors and mutators
	inline int getID() const { return id; }
	inline int getLevel() const { return level; }
	inline int getHitPoints() const { return hitPoints; }
	inline int getSpeed() const { return speed; }
	inline int getReward()const { return reward; }
	inline int getX() const { return xPosition; }
	inline int getY() const { return yPosition; }
	inline void setX(int x) { xPosition = x; }
	inline void setY(int y) { yPosition = y; }
	inline void setLevel(int num) { level = num; }
	inline void setReward(int num) { reward = num; }
	inline void setHitPoints(int num) { hitPoints = num; }

	void displayStats();

	void SetEffectType(EffectType);
	EffectType GetEffectType() const { return this->currentEffectType; }
	int GetSpeed() const { return this->speed; }
	void SetSpeed(int);
};

