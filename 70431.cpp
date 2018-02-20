#include <iostream>

using namespace std;

class Rational {
	public:
		Rational(int n, int d);
		Rational();
		void operator =(const Rational& r2);
		void operator +=(const Rational& r2);
		void operator -=(const Rational& r2);
		void operator *=(const Rational& r2);
		void operator /=(const Rational& r2);
		friend Rational operator +(const Rational& r1, const Rational& r2);
		friend Rational operator -(const Rational& r1, const Rational& r2);
		friend Rational operator *(const Rational& r1, const Rational& r2);
		friend Rational operator /(const Rational& r1, const Rational& r2);
		friend bool operator <(const Rational& r1, const Rational& r2);
		friend bool operator >(const Rational& r1, const Rational& r2);
		friend bool operator ==(const Rational& r1, const Rational& r2);
		friend bool operator !=(const Rational& r1, const Rational& r2);
		friend bool operator <=(const Rational& r1, const Rational& r2);
		friend bool operator >=(const Rational& r1, const Rational& r2);
		friend istream& operator >>(istream& ins, Rational& r1);
		friend ostream& operator <<(ostream& outs, const Rational& r1);
	private:
		int numerator;
		int denominator;
};

int main()
{
	Rational a, b, c;
	
	cout << "Enter:";
	cin >> a >> b;
	cout << "two rational numbers:";
	c = a + b;
	cout << a << " + " << b << " = " << c << endl;
	c = a - b;
	cout << a << " - " << b << " = " << c << endl;
	c = a * b;
	cout << a << " * " << b << " = " << c << endl;
	c = a / b;
	cout << a << " / " << b << " = " << c << endl;
	cout << a << " < " << b << " = ";
	if(a < b){
		cout << "true";
	}else{
		cout << "false";
	}
	cout << endl << a << " > " << b << " = ";
	if(a > b){
		cout << "true";
	}else{
		cout << "false";
	}	
	
	cout << endl << a << " == " << b << " = ";
	if(a == b){
		cout << "true";
	}else{
		cout << "false";
	}
	
	cout << endl << a << " != " << b << " = ";
	if(a != b){
		cout << "true";
	}else{
		cout << "false";
	}
	
	cout << endl << a << " <= " << b << " = ";
	if(a <= b){
		cout << "true";
	}else{
		cout << "false";
	}
	
	cout << endl << a << " >= " << b << " = ";
	if( a >= b){
		cout << "true";
	}else{
		cout << "false";
	}
	
	cout << endl;
	
	
	return 0;
}


Rational::Rational() : numerator(0), denominator(1)
{}

Rational::Rational(int n, int d) : numerator(n), denominator(d)
{
	int m;
	
	if(numerator > denominator){
		m = numerator;
	}else{
		m = denominator;
	}
	
	if(numerator > 0){
		for(m = m; m > 0; m--){
			if(numerator % m == 0 && denominator % m == 0){
				numerator /= m;
				denominator /= m;
				m = 0;
			}
		}
	}
}

istream& operator >>(istream& ins, Rational& r1)
{
	char c;
	ins >> r1.numerator >> c >> r1.denominator;
	return ins;
}

ostream& operator <<(ostream& outs, const Rational& r1)
{
	outs << r1.numerator << "/" << r1.denominator;
	return outs;
}

void Rational::operator =(const Rational& r2)
{
	numerator = r2.numerator;
	denominator = r2.denominator;
}

void Rational::operator +=(const Rational& r2)
{
	int n1, n2, d1, d2;
	int m = 1;
	
	n1 = numerator;
	n2 = r2.numerator;
	d1 = denominator;
	d2 = r2.denominator;
	
	if(d1 == d2){
		numerator = n1 + n2;
	}else if(d1 % d2 == 0){
		m = d1 / d2;
		n2 *= m;
		numerator = n1 + n2;
	}else if(d2 % d1 == 0){
		m = d2 / d1;
		n1 *= m;
		
		numerator = n1 + n2;
		denominator = d2;
	}else{
		m = d1;
	
		while(true){
			if(m % d1 == 0 && m % d2 == 0){
				break;
			}else{
				m++;
			}
		}
		
		n1 *= m/d1;
		n2 *= m/d2;
		
		numerator = n1 + n2;
		denominator = m;
	}
}

void Rational::operator -=(const Rational& r2)
{
	int n1, n2, d1, d2;
	int m = 1;
	
	n1 = numerator;
	n2 = r2.numerator;
	d1 = denominator;
	d2 = r2.denominator;
	
	if(d1 == d2){
		numerator = n1 - n2;
	}else if(d1 % d2 == 0){
		m = d1 / d2;
		n2 *= m;
		
		numerator = n1 - n2;
	}else if(d2 % d1 == 0){
		m = d2 / d1;
		n1 *= m;
		
		numerator = n1 - n2;
		denominator = d2;
	}else{
		m = d1;
	
		while(true){
			if(m % d1 == 0 && m % d2 == 0){
				break;
			}else{
				m++;
			}
		}
		
		n1 *= m/d1;
		n2 *= m/d2;
		
		numerator = n1 - n2;
		denominator = m;
	}
}

void Rational::operator *=(const Rational& r2)
{
	numerator *= r2.numerator;
	denominator *= r2.denominator;
}

void Rational::operator /=(const Rational& r2)
{
	int m = 1;
	if(numerator < 0 || r2.numerator < 0){
		m = -1;
	}
	
	numerator *= r2.denominator * m;
	denominator *= r2.numerator * m;
}

Rational operator +(const Rational& r1, const Rational& r2)
{
	Rational r(r1.numerator,r1.denominator);
	r += r2;
	
	return r;
}

Rational operator -(const Rational& r1, const Rational& r2)
{
	Rational r(r1.numerator,r1.denominator);
	r -= r2;
	
	return r;
}

Rational operator *(const Rational& r1, const Rational& r2)
{
	Rational r(r1.numerator,r1.denominator);
	r *= r2;
	
	return r;
}

Rational operator /(const Rational& r1, const Rational& r2)
{
	Rational r(r1.numerator, r1.denominator);
	r /= r2;
	
	return r;
}

bool operator <(const Rational& r1, const Rational& r2)
{
	double n1, n2;
	
	n1 = r1.numerator/double(r1.denominator);
	n2 = r2.numerator/double(r2.denominator);
	
	if(n1 < n2){
		return true; 
	}else{
		return false;
	}
}

bool operator >(const Rational& r1, const Rational& r2)
{
	double n1, n2;
	
	n1 = r1.numerator/double(r1.denominator);
	n2 = r2.numerator/double(r2.denominator);
	if(n1 > n2){
		return true;
	}else{
		return false;
	}
}

bool operator ==(const Rational& r1, const Rational& r2)
{
	double n1, n2;
	
	n1 = r1.numerator/double(r1.denominator);
	n2 = r2.numerator/double(r2.denominator);
	if(n1 == n2){
		return true;
	}else{
		return false;
	}
}

bool operator !=(const Rational& r1, const Rational& r2)
{
	return !(r1 == r2);
}

bool operator <=(const Rational& r1, const Rational& r2)
{
	double n1, n2;
	
	n1 = r1.numerator/double(r1.denominator);
	n2 = r2.numerator/double(r2.denominator);
	
	if(n1 <= n2){
		return true;
	}else{
		return false;
	}
}

bool operator >=(const Rational& r1, const Rational& r2)
{
	double n1, n2;
	
	n1 = r1.numerator/double(r1.denominator);
	n2 = r2.numerator/double(r2.denominator);
	
	if(n1 >= n2){
		return true;
	}else{
		return false;
	}
}
