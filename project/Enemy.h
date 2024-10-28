#pragma once
class Enemy {
public:

	enum class Behavior {
		APPROACH,
		SHOOT,
		RETREAT
	};

	Enemy() = default;
	~Enemy() = default;

	void Update();

private:

	static void (Enemy::* spFuncTable[])();

	Behavior mBehavior = Behavior::APPROACH;

	void Approach();

	void Shoot();

	void Retreat();
};

