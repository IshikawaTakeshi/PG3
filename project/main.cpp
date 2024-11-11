#include <stdio.h>
#include <random>
#include <functional>

class IShape {
public:
	virtual void Size() = 0;

	virtual void Draw() = 0;
protected:

	float size_;
};


class Rectangle : public IShape {

public:
	Rectangle(int w, int h) {
		width_ = w;
		height_ = h;
	}

	void Size() override {
		size_ =  width_ * height_;
	}

	void Draw() override {
		printf("Rectangle Size : %.2f\n",size_);
	}

private:

	int width_;
	int height_;

};

class Circle : public IShape {

public:
	Circle(float r) {
		radius_ = r;
	}

	void Size() override {
		size_ = static_cast<float>(3.14 * radius_ * radius_);
	}

	void Draw() override {
		printf("Circle Size : %.2f\n", size_);
	}

private:

	float radius_;
};


int main(void) {

	IShape* shape = new Rectangle(10, 20);
	IShape* shape2 = new Circle(10);

	shape->Size();
	shape2->Size();

	shape->Draw();
	shape2->Draw();

	return 0;
}