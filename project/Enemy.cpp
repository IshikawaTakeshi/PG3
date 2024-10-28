#include "Enemy.h"
#include <stdio.h>

void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::Approach, //接近
	&Enemy::Shoot,    //射撃
	&Enemy::Retreat  //離脱
};

void Enemy::Update() {
	(this->*spFuncTable[static_cast<size_t>(mBehavior)])();
	mBehavior = Behavior::SHOOT;
	(this->*spFuncTable[static_cast<size_t>(mBehavior)])();
	mBehavior = Behavior::RETREAT;
	(this->*spFuncTable[static_cast<size_t>(mBehavior)])();
}

void Enemy::Approach() {
	printf("接近\n");
	printf("↓\n");
}

void Enemy::Shoot() {
	printf("射撃\n");
	printf("↓\n");
}

void Enemy::Retreat() {
	printf("離脱\n");
}