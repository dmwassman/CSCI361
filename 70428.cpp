#include <iostream>
#include <string>

using namespace std;

class Rational{
	public:
		Rational(int numerator, int denominator);
		Rational();
		Rational add(Rational n);
		Rational sub(Rational n);
		Rational mul(Rational n);
		Rational div(Rational n);
		string equal(Rational n);
		void input();
		void output();
		int num;
		int dem;
};

int main()
{
	Rational a,b;
	
	cout << "Enter:";
	a.input();
	b.input();
	cout << "two rational numbers:";
	a.add(b);
	
	
}

Rational::Rational(int numerator, int denominator) : num(numerator), dem(denominator)
{}

Rational::Rational() : num(0), dem(1)
{}

Rational Rational::add(Rational n)
{
	Rational sum;
	int n1,n2,d1,d2;
	int m = 1;
	
	n1 = num;
	n2 = n.num;
	d1 = dem;
	d2 = n.dem;
	
	if(d1 == d2)
	{
		sum.num = n1 + n2;
		sum.dem = d1;
	}else if(d1%d2 == 0)
	{
		m = d1/d2;
		n2 *= m;
	
		sum.num = n1 + n2;
		sum.dem = d1;
	}else if(d2%d1 == 0)
	{
		m = d2/d1;
		n1 *= m;
		
		sum.num = n1 + n2;
		sum.dem = d2;
	}else {
		m = d1;
		while(true){
			if(m%d1 == 0 && m%d2 == 0)
			{
				break;
			}else{
				m++;
			}
		}
		
		cout << m << endl;
	}
	
	return sum;
}
void Rational::input()
{
	char c;
	cin >> num >> c >> dem;
}

void Rational::output()
{
	cout << num << '/' << dem << endl;
}