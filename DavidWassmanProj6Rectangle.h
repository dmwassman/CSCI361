//Header file Rectangle.h: This is the INTERFACE for the class Rectangle

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "DavidWassmanProj6Shape.h"

namespace std {
	class Rectangle {
		public:
			Rectangle();
			Rectangle(int x, int y);
			void setParameter(int x, int y);
			int getWidth();
			int getHeight();
			virtual double getArea();
		private:
			int width;
			int height;
	};
	
}
#endif