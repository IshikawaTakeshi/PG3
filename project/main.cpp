#include <stdio.h>
#include <Windows.h>
#include <random>
#include <functional>

#include "Enemy.h"

int main(void) {
	Enemy* enemy = new Enemy();
	enemy->Update();

	return 0;
}