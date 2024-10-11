#include "Monster.h"

Monster::~Monster() {

};

void Monster::ApplyDamage(int dmgAmount) {

	this->hitPoints -= dmgAmount;
	if (this->hitPoints <= 0) {
		this->state = MonsterState::Dead;
	}
}

MonsterState Monster::GetState() const {
	return state;
}

void Monster::SetState(MonsterState state) {
	this->state = state;
}

void Monster::SetEffectType(EffectType et) {
	this->currentEffectType = et;
}

void Monster::SetSpeed(int sp) {
	this->speed = sp;
}