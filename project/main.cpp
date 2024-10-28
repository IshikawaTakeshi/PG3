#include <stdio.h>
#include <Windows.h>
#include <random>
#include <functional>

#include "Enemy.h"

typedef void (*FuncPtr)(int*);

//乱数の生成
int Random(int min, int max) {
	std::random_device rd;
	std::mt19937 mt(rd());
	return std::uniform_int_distribution<int>(min, max)(mt);
}

//待ち時間の設定
void SetTimeOut(int count) {
	for (int i = 0; i < count; i++) {
		putchar('.');
		Sleep(1000); //ミリ秒単位
	}
}

void Answer(int* answer) {
	printf("回答 : ");
	scanf_s(" %d", answer);
}


int main(void) {
	Enemy* enemy = new Enemy();
	enemy->Update();

	return 0;
}