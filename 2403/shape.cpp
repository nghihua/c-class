#include <iostream>
#include <string>
#include <typeinfo>
#include <cmath>
#include <vector>

using namespace std;

const float pi = 3.14;

class Point {
private:
	int x;
	int y;
public:
	void update(int x, int y){
		this->x = x;
		this->y = y;
	}
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
	float computeDistance(Point p) {
		return sqrt(pow(x - p.getx(),2)+pow(y - p.gety(),2));
	}
};

class Shape {
protected:
	Point center;
public:
	virtual float computeArea() = 0;
	virtual float computeCircum() = 0;
	float computeDistance(Point p) {
		return center.computeDistance(p);
	};
	Point getCenter() {
		return center;
	};
};

class Circle : public Shape{
private:
	int r;
public:
	Circle(int x, int y, int r) {
		center.update(x, y);
		this->r = r;
	}
	float computeArea() {
		return pi*r*r;
	}
	float computeCircum() {
		return pi*2*r;
	}
};

class Rectangle : public Shape{
private:
	int a;
	int b;
public:
	Rectangle(int x, int y, int a, int b) {
		center.update(x, y);
		this->a = a;
		this->b = b;
	}
	float computeArea() {
		return a*b;
	}
	float computeCircum() {
		return 2*(a+b);
	}
};

class Square : public Shape{
private:
	int a;
public:
	Square(int x, int y, int a) {
		center.update(x, y);
		this->a = a;
	}
	float computeArea() {
		return a*a;
	}
	float computeCircum() {
		return 4*a;
	}
};

int main() {
	Shape* circle = new Circle(1,1,2);
	cout<<"Area of circle is "<<circle->computeArea()<<endl;
	cout<<"Circumference of circle is "<<circle->computeCircum()<<endl;
	Shape* square = new Square(2,1,2);
	cout<<"Area of square is "<<square->computeArea()<<endl;
	cout<<"Circumference of square is "<<square->computeCircum()<<endl;
	cout<<"The distance of square to circle is "<<square->computeDistance(circle->getCenter())<<endl;
	Shape* rectangle = new Rectangle(3,1,2,3);
	cout<<"Area of rectangle is "<<rectangle->computeArea()<<endl;
	cout<<"Circumference of rectangle is "<<rectangle->computeCircum()<<endl;
	cout<<"The distance of rectangle to circle is "<<rectangle->computeDistance(circle->getCenter())<<endl;
	return 0;
}