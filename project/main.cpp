#include <stdio.h>
#include <Windows.h>
#include <random>
#include <functional>

template <typename T1,typename T2>
class MathUtil {
public:

	T1 a;
	T2 b;

	MathUtil(T1 a, T2 b) : a(a), b(b) {}
	
	T1 Min() {
		return static_cast<T1>(a < b ? a : b);
	}
};

int main(void) {

	MathUtil<int,int> mathUtil(1, 2);
	MathUtil<float,float> mathUtil2(1.0f, 2.0f);
	MathUtil<double,double> mathUtil3(1.0, 2.0);
	MathUtil<int, float> mathUtil4(1, 2.0f);
	MathUtil<float, double> mathUtil5(1.0f, 2.0);
	MathUtil<double, int> mathUtil6(1.0, 2);

	printf("int min: %d\n", mathUtil.Min());
	printf("float min: %f\n", mathUtil2.Min());
	printf("double min: %f\n", mathUtil3.Min());
	printf("int, float min: %d\n", mathUtil4.Min());
	printf("float, double min: %f\n", mathUtil5.Min());
	printf("double, int min: %f\n", mathUtil6.Min());

	return 0;
}