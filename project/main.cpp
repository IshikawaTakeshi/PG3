#include <stdio.h>


int RecursiveWage(int time,int wage) {
	if (time <= 1) return wage;
	int newWage = wage;
	newWage = (newWage * 2 - 50);
	return RecursiveWage(time - 1, newWage);
}

template <typename T>
T Max(T a, T b) {
	return a > b ? a : b;
}


int main() {
	//一般的な賃金体系
	int hourlyWage = 1072;
	//再帰的な賃金体系
	int recursiveWage = 100;
	//労働時間
	int workingHours = 0;

	//労働時間を入力
	printf("労働時間を入力してください: ");
	scanf_s("%d", &workingHours);
	printf("労働時間 : %d時間\n", workingHours);

	//一般的な賃金体系の計算
	int generalWage = hourlyWage * workingHours;
	//再帰的な賃金体系の計算
	int result = 0;
	for (int i = 1; i <= workingHours; i++) {
		int newWage = RecursiveWage(i, recursiveWage);
		result += newWage;
	}
	

	//結果の出力
	printf("一般的な賃金体系で%d時間働いた: %d\n",workingHours, generalWage);
	printf("再帰的な賃金体系で%d時間働いた: %d\n",workingHours, result);
	printf("収入が高い方: %d\n", Max(generalWage, result));
	
	return 0;
}