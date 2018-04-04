//Implementation file Circle.cpp: This is the IMPLEMENTATION file for the class Circle
//Interface file Circle.h

#include "DavidWassmanProj6Circle.h"

using namespace std;

namespace std {
	Circle::Circle() : Shape("Circle"), radius(0) 
	{}
	
	Circle::Circle(int theRadius) : Shape("Circle"), radius(theRadius) 
	{}
	
	void Circle::setRadius(int newRadius) {
		this->radius = newRadius;
	}
	
	double Circle::getRadius() {
		return radius;
	}
	
	double Circle::getArea() {
		return 3.14159 * radius * radius;
	}
}
