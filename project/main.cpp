#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <thread>

void print(int num) {
	std::cout << "thread " << num << "\n" << std::endl;
}

int main(void) {

	std::thread t1(print, 1);
	t1.join();
	std::thread t2(print, 2);
	t2.join();
	std::thread t3(print, 3);
	t3.join();

	return 0;
}