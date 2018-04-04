//Header file Circle.h: This is the INTERFACE for the class Circle
#include <string>

using namespace std;

#ifndef CIRCLE_H
#define CIRCLE_H
#include "DavidWassmanProj6Shape.h"

namespace std {
	class Circle : public Shape {
		public:
			Circle();
			Circle(int theRadius);
			void setRadius(int newRadius);
			double getRadius();
			virtual double getArea();
		private:
			int radius;
	};
}
#endif