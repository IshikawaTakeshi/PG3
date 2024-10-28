#include <stdio.h>
#include <Windows.h>
#include <random>
#include <functional>

template <typename T>
class MathUtil {
public:

	T a;
	T b;

	MathUtil(T a, T b) : a(a), b(b) {}
	
	T Min() {
		return static_cast<T>(a < b ? a : b);
	}
};

int main(void) {

	MathUtil<int> mathUtil(1, 2);
	MathUtil<float> mathUtil2(1.0f, 2.0f);
	MathUtil<double> mathUtil3(1.0, 2.0);

	printf("int min: %d\n", mathUtil.Min());
	printf("float min: %f\n", mathUtil2.Min());
	printf("double min: %f\n", mathUtil3.Min());

	return 0;
}