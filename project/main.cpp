#include <stdio.h>
#include <Windows.h>
#include <random>
#include <functional>


class ISoda {
public:
	virtual void PrintName() = 0;

};

class CocaCola : public ISoda {
public:
	void PrintName() override {
		printf("CocaCola is Soda.\n");
	}
};

class Pepsi : public ISoda {

public:
	void PrintName() override {
		printf("PepsiCola is Soda.\n");
	}
};

class Fanta : public ISoda {
public:
	void PrintName() override {
		printf("Fanta is Soda.\n");
	}
};

int main(void) {

	ISoda* pSoda = new CocaCola();
	ISoda* pSoda2 = new Pepsi();
	ISoda* pSoda3 = new Fanta();

	pSoda->PrintName();
	pSoda2->PrintName();
	pSoda3->PrintName();

	return 0;
}