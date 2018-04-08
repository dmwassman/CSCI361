#include <iostream>
#include <string>

using namespace std;

class Vehicle {
	public:
		Vehicle();
		Vehicle(string m, string o);
		string getManufacturer() const;
		string getOwner() const;
		void setManufacture(string m);
		void setOwner(string o);
	private:
		string manufacture;
		string owner;
};

Vehicle::Vehicle() : manufacture(""), owner("") {}

Vehicle::Vehicle(string m, string o) : manufacture(m), owner(o) {}

string Vehicle::getManufacturer() const {
	return manufacture;
}

string Vehicle::getOwner() const {
	return owner;
}

void Vehicle::setManufacture(string m) {
	manufacture = m;
}

void Vehicle::setOwner(string o) {
	owner = o;
}

class Car : public Vehicle {
	public:
		Car();
		Car(string m, string o, double t, int d, string ty, int y);
		double getTons() const;
		int getDoors() const;
		string getType() const;
		int getYear() const;
		void setTons(double t);
		void setDoors(int d);
		void setType(string ty);
		void setYear(int y);
	private:
		double tons;
		int doors;
		string type;
		int year;
};

Car::Car() : Vehicle(), tons(0.0), doors(0), type(""), year(0) {}

Car::Car(string m, string o, double t, int d, string ty, int y) : Vehicle(m, o), tons(t), doors(d), type(ty), year(y) {}

double Car::getTons() const {
	return tons;
}

int Car::getDoors() const {
	return doors;
}

string Car::getType() const {
	return type;
}

int Car::getYear() const {
	return year;
}

void Car::setTons(double t) {
	tons = t;
}

void Car::setDoors(int d) {
	doors = d;
}

void Car::setType(string ty) {
	type = ty;
}

void Car::setYear(int y) {
	year = y;
}

class SportsCar : public Car {
	public:
		SportsCar();
		SportsCar(string m, string o, double t, int d, string ty, int y, double s);
		double getSpeed();
		void setSpeed(double s);
	private:
		double speed;
};

SportsCar::SportsCar() : Car(), speed(0) {}

SportsCar::SportsCar(string m, string o, double t, int d, string ty, int y, double s) : Car(m, o, t, d, ty, y), speed(s) {}

double SportsCar::getSpeed() {
	return speed;
}

void SportsCar::setSpeed(double s) {
	speed = s;
}

int main()
{
	double t,s;
	int players,d,y;
	string m,o,ty;
	
	cout << "Enter the number of contestants:";
	cin >> players;

	SportsCar* cars;
	cars = new SportsCar[players];
	
	for (int i = 1; i <= players; i++) {
		cout << "Enter contestant " << i << " name:";
		cin >> o;
		cout << "Enter contestant " << i << " vehicle manufacturer:";
		cin >> m;
		cout << "Enter contestant " << i << " car weight in tons:";
		cin >> t;
		cout << "Enter contestant " << i << " number of doors:";
		cin >> d;
		cout << "Enter contestant " << i << " drive type:";
		cin >> ty;
		cout << "Enter contestant " << i << " year:";
		cin >> y;
		cout << "Enter contestant " << i << " max speed in mph:";
		cin >> s;
		cars[i - 1] = SportsCar(m,o,t,d,ty,y,s);
	}
	
	SportsCar winner;
	for (int i = 0; i < players; i++) {
		if(cars[i].getSpeed() > winner.getSpeed()) {
			winner = cars[i];
		}
	}
	
	cout << "The winner is: " << winner.getOwner() << endl;
	return 0;
}	