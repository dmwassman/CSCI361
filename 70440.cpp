#include <iostream>
#include <string>

using namespace std;

class Person {
	public:
		Person(string n);
		string name;
};

Person::Person(string n) : name(n) {}

class Vehicle {
	public:
		Vehicle();
		Vehicle(string m, int c, string o);
		string getManufacturer() const;
		int getCylinder() const;
		string getOwner() const;
		void setManufacturer(string m);
		void setCylinder(int c);
		void setOwner(string o);
	private:
		string manufacturer;
		int cylinders;
		Person owner;
};

Vehicle::Vehicle() : manufacturer(""), cylinders(0), owner("") {}

Vehicle::Vehicle(string m, int c, string o) : manufacturer(m), cylinders(c), owner(o) {}

string Vehicle::getManufacturer() const {
	return manufacturer;
}

int Vehicle::getCylinder() const {
	return cylinders;
}

string Vehicle::getOwner() const {
	return owner.name;
}

void Vehicle::setManufacturer(string m) {
	manufacturer = m;
}

void Vehicle::setCylinder(int c) {
	cylinders = c;
}

void Vehicle::setOwner(string o) {
	owner.name = o;
}

class Truck : public Vehicle {
	public:
		Truck();
		Truck(string m, int c, string o, double load, int tow);
		double getLoad() const;
		int getTow() const;
		void setLoad(double l);
		void setTow(int t);
		friend ostream& operator << (ostream& outs, const Truck& t); 
	private:
		double tonLoad;
		int poundTow;
};

Truck::Truck() : Vehicle(), tonLoad(0), poundTow(0) {}

Truck::Truck(string m, int c, string o, double load, int tow) : Vehicle(m, c, o), tonLoad(load), poundTow(tow) {}

double Truck::getLoad() const {
	return tonLoad;
}

int Truck::getTow() const {
	return poundTow;
}

void Truck::setLoad(double l) {
	tonLoad = l;
}

void Truck::setTow(int t) {
	poundTow = t;
}
ostream& operator << (ostream& outs, const Truck& t) {
	outs << t.getManufacturer() << "(" << t.getCylinder() << " cylinders, " << t.tonLoad << " tons maximum load, " << t.poundTow << " lbs towing capacity), owned by " << t.getOwner() << endl;
	return outs;
}


int main()
{
	double load;
	int players,c,tow;
	string m,o;
	
	cout << "Enter the number of contestants:";
	cin >> players;
	
	Truck* trucks;
	trucks = new Truck[players];
	
	for (int i = 0; i < players; i++) {
		cout << "Enter contestant " << i + 1 << " info\n";
		cout << "Enter truck's manufacturer:";
		cin >> m;
		cout << "Enter truck's number of cylinders:";
		cin >> c;
		cout << "Enter truck's owner:";
		cin >> o;
		cout << "Enter truck's maximum load (in tons):";
		cin >> load;
		cout << "Enter truck's maximum towing capacity (in pounds):";
		cin >> tow;
		
		trucks[i].setManufacturer(m);
		trucks[i].setCylinder(c);
		trucks[i].setOwner(o);
		trucks[i].setLoad(load);
		trucks[i].setTow(tow);
	}
	
	Truck winner;
	for (int i = 0; i < players; i++) {
		if(trucks[i].getLoad() + trucks[i].getTow() > winner.getLoad() + winner.getTow()) {
			winner = trucks[i];
		}
	}
	
	cout << winner;
	return 0;

}