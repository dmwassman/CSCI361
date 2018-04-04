//Header file Shape.h: This is the INTERFACE for the class Shape
#include <string>

using namespace std;

#ifndef SHAPE_H
#define SHAPE_H

namespace std {
	class Shape {
		public:
			Shape();
			Shape(string name);
			string getName();
			void setName(string newName);
			virtual double getArea() = 0;
		private:
			string name;
	};
	
}
#endif