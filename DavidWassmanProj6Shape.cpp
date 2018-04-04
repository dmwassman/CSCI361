//Implementation file Shaoe.cpp: This is the IMPLEMENTATION file for the class Shape
//Interface file Shape.h

#include "DavidWassmanProj6Shape.h"
#include <string>

using namespace std;

namespace std {
	Shape::Shape() {
		name = "";
	}
	
	Shape::Shape(string name) {
		this->name = name;
	}
	
	string Shape::getName() {
		return this->name;
	}
	
	void Shape::setName(string newName) {
		this->name = newName;
	}
	
}