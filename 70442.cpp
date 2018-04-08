#include <iostream>
#include <string>

using namespace std;

class Person {
	public:
		Person();
		Person(string f, string l);
		Person(const Person& p);
		string getFirst() const;
		string getLast() const;
		void setFirst(string f);
		void setLast(string l);
		bool operator ==(Person& p) const;
		bool operator !=(Person& p) const;
	private:
		string first;
		string last;
};

Person::Person() : first(""), last("") {}

Person::Person(string f, string l) : first(f), last(l) {}

Person::Person(const Person& p) {
	first = p.first;
	last = p.last;
}

string Person::getFirst() const {
	return first;
}

string Person::getLast() const {
	return last;
}

void Person::setFirst(string f) {
	first = f;
}

void Person::setLast(string l) {
	last = l;
}

bool Person::operator ==(Person& p) const {
	return this->getFirst() == p.getFirst() && this->getLast() == p.getLast();
}

bool Person::operator != (Person& p) const {
	return this->getFirst() != p.getFirst() || this->getLast() != p.getLast();
}

class Doctor : public Person {
	public:
		Doctor();
		Doctor(string f, string l,double r);
		double getRate() const;
		void setRate(double r);
		void operator = (const Doctor& d);
	private:
		double rate;
};

Doctor::Doctor() : Person(), rate(0) {}

Doctor::Doctor(string f, string l,double r) : Person(f,l), rate(r) {}

double Doctor::getRate() const {
	return rate;
}

void Doctor::setRate(double r) {
	rate = r;
}

void Doctor::operator = (const Doctor& d) {
		setFirst(d.getFirst());
		setLast(d.getLast());
		rate = d.rate;
}

class Patient : public Person {
	public:
		Patient();
		Patient(string f, string l, Doctor* d);
		Doctor* getDoctor() const;
		void setDoctor(Doctor* d);
	private:
		Doctor* doctor;
};

Patient::Patient() : Person(), doctor(new Doctor) {}

Patient::Patient(string f, string l, Doctor* d) : Person(f, l), doctor(d) {}

Doctor* Patient::getDoctor() const {
	return doctor;
}

void Patient::setDoctor(Doctor* d) {
	doctor = d;
}

class Billing {
	public:
		Billing();
		Billing(Doctor* d, Patient* p, int h);
		double getBill() const;
	private:
		Doctor* doctor;
		Patient* patient;
		double amount;
};

Billing::Billing() : doctor(new Doctor), patient(new Patient), amount(0) {}

Billing::Billing(Doctor* d, Patient* p, int h) : doctor(d), patient(p) {
	if(doctor == p->getDoctor()) {
		amount = h * double(doctor->getRate());
	} else {
		amount = h * double(doctor->getRate()) * 1.25;
	}
}

double Billing::getBill() const {
	return amount;
}

int main()
{
	double r, total;
	int h;
	string pf,pl,df,dl;
	
	cout << "Enter:";
	cin >> pf >> pl;
	
	cout << " the patient's name: Enter:";
	cin >> df >> dl >> r;
	Doctor primary(df,dl,r);
	Patient patient(pf,pl,&primary);
	cout << " primary physician's name and their rate: Enter:";	
	cin >> df >> dl >> r;
	Doctor doctor(df,dl,r);
	cout << " a doctor's name and their hourly rate: Enter:";
	cin >> h;
	
	Billing billPrimary(&primary, &patient, h);
	if(doctor == primary){
		cout << billPrimary.getBill() << endl;
		
		total = billPrimary.getBill() * 2;		
		cout << total << endl;
	} else {
		Billing billDoctor(&doctor, &patient, h);
		total = billPrimary.getBill() + billDoctor.getBill();
	}
	
	cout << " amount of hours: You owe: " << total << " dollars.\n";
	return 0;
}