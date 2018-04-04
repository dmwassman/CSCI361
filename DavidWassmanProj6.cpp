#include <iostream>
#include "DavidWassmanProj6Circle.h"

using namespace std;

int main() {
	Circle c(2);
	cout << c.getName() << " has radius " << c.getRadius() << " and area " << c.getArea() << endl;
	
	return 0;
}