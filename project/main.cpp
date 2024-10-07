#include <stdio.h>

template <typename T>
T Min(T a, T b) {
	return static_cast<T>(a < b ? a : b);
}

char Min(char a, char b) {
	return printf("数字以外は代入できません\n");
}



int main() {

	printf("int    : %d\n",Min<int>(114,514));
	printf("float  : %f\n",Min<float>(11.4f,51.4f));
	printf("double : %lf\n", Min<double>(1.14, 5.14));
	printf("%c", Min('a', 'b'));

	return 0;
}