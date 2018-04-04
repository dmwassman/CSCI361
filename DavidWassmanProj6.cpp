#include <iostream>
#include "DavidWassmanProj6Circle.h"
#include "DavidWassmanProj6Rectangle.h"

using namespace std;

int main() {
	Circle c(2);
	cout << c.getName() << " has radius " << c.getRadius() << " and area " << c.getArea() << endl;
	
	
	Rectangle r(3,4);
	cout << r.getName() << " has width " << r.getWidth() << " has height " << r.getHeight() << " and area " << r.getArea() << endl;
	return 0;
}