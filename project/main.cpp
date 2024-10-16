#include <stdio.h>
#include <Windows.h>
#include <random>
#include <functional>

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

	int answer;
	int isPlay;

	//奇数か偶数か選択をさせる関数
	std::function<void(FuncPtr p)> funcAnswerSelect = [&](FuncPtr p) {
		p(&answer);
		if (answer == 2) {
			printf("偶数を選択したね。\n");
		} else if (answer == 1) {
			printf("奇数を選択したね。\n");
		} else {
			printf("入力が間違っているよ。もう一度入力して。\n");
			funcAnswerSelect(p);
		}
	};

	//もう一度プレイするかどうかの選択をさせる関数
	std::function<void(FuncPtr p)> funcPlaySelect = [&](FuncPtr p) {
		p(&isPlay);
		if (isPlay == 1) {
			printf("1を選択したね。\n");
		} else if (isPlay == 2) {
			printf("2を選択したね。\n");
		} else {
			printf("入力が間違っているよ。もう一度入力して。\n");
			funcPlaySelect(p);
		}
	};

	//ゲームの説明
	printf("サイコロを振るから出た目が奇数か偶数か当ててね\n");
	Sleep(1500);

	//ゲームループ
	while (true) {

		//サイコロを振る
		printf("サイコロを振ります");
		SetTimeOut(3);
		int dice = Random(1, 6);

		//回答の入力
		printf("\n奇数は1,偶数は2で答えてね。さあ、サイコロの出目はどっち!?\n");
		
		funcAnswerSelect(Answer);

		//奇数偶数判定
		printf("サイコロの出目は");
		SetTimeOut(3);
		if (dice % 2 == 0) {
			printf("偶数です！\n");
		} else {
			printf("奇数です！\n");
		}

		//正解判定
		Sleep(1000);
		printf("\n");
		if (answer == dice % 2) {
			printf("正解です！おめでとうございます！\n");
		} else {
			printf("不正解です！残念でした！\n");
		}

		//サイコロの結果
		Sleep(1000);
		printf("\nサイコロの出目は%dでした。\n", dice);

		//もう一度プレイするかどうか
		printf("もう一度プレイしますか？\n");
		printf("はい : 1, いいえ : 2\n");
		
		funcPlaySelect(Answer);
		if (isPlay == 1) {
			printf("OK!もう一度始めるよ！\n\n");
			Sleep(1000);
			continue;
		} else {
			printf("ゲーム終了!またね。\n");
			Sleep(1000);
			break;
		}
	}
	return 0;
}