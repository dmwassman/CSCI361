//Implementation file Rectangle.cpp: This is the IMPLEMENTATION file for the class Rectangle
//Interface file Rectangle.h

#include "DavidWassmanProj6Rectangle.h"

using namespace std;

namespace std {
	Rectangle::Rectangle() : Shape("Rectangle"), width(0), height(0) {}
	Rectangle::Rectangle(int x, int y) : Shape("Rectangle"), width(x), height(y) {}
	
	void Rectangle::setParameter(int x, int y) {
		width = x;
		height = y;
	}
	
	int Rectangle::getWidth() {
		return width;
	}
	
	int Rectangle::getHeight() {
		return height;
	}
	
	double Rectangle::getArea() {
		return width * height;
	}
}
