#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Complex {
	public:
		Complex(int x, int y);
		Complex(int x);
		Complex();
		friend bool operator ==(const Complex& c1, const Complex& c2);
		friend Complex operator +(const Complex& c1, const Complex& c2);
		friend Complex operator -(const Complex& c1, const Complex& c2);
		friend Complex operator *(const Complex& c1, const Complex& c2);
		friend istream& operator >>(istream& ins, Complex& c);
		friend ostream& operator <<(ostream& outs, const Complex& c);
	private:
		int a;
		int b;
};

int main(){
	Complex a, b, c;
	
	cout << "Enter:";
	cin >> a >> b;
	cout << "two complex numbers:";
	cout << a;
	if(a == b){
		cout << " is equal to ";
	}else{
		cout << " is not equal to ";
	}
	cout << b << endl;
	
	c = a + b;
	cout << a << " + " << b << " = " << c << endl;
	c = a - b;
	cout << a << " - " << b << " = " << c << endl;
	c = a * b;
	cout << a << " * " << b << " = " << c << endl;
	
}

Complex::Complex(int x, int y) : a(x), b(y)
{}

Complex::Complex(int x) : a(x), b(0)
{}

Complex::Complex() : a(0), b(0)
{}


bool operator ==(const Complex& c1, const Complex& c2)
{
	if(c1.a == c2.a && c1.b == c1.b){
		return true;
	}else{
		return false;
	}
}

Complex operator +(const Complex& c1, const Complex& c2)
{
	Complex c;
	
	c.a = c1.a + c2.a;
	c.b = c1.b + c2.b;
	
	return c;
}

Complex operator -(const Complex& c1, const Complex& c2)
{
	Complex c;
	
	c.a = c1.a - c2.a;
	c.b = c1.b - c2.b;
	
	return c;
}

Complex operator *(const Complex& c1, const Complex& c2)
{
	Complex c;
	
	c.a = c1.a*c2.a - c1.b*c2.b;
	c.b = c1.a*c2.b + c1.b*c2.a;

	
	return c;
}
istream& operator >>(istream& ins, Complex& c)
{
	string z="";
	char t;
	int m = 1;
	while(cin.get(t)){
		
		if(t == '+'){
			c.a = atoi(z.c_str());
			z = "";
		}else if(t == '-'){
			m = -1;
			c.a = atoi(z.c_str());
			z = "";
		}else if(t == '*'){
			c.b = atoi(z.c_str()) * m;
			break;
		}else if(t == 'i'){
		}else if(t == ' '){
		}else{
			z += t;
		}
		
		
	}
	
	return ins;
}

ostream& operator <<(ostream& outs, const Complex& c)
{
	if(c.b >= 0){
		outs << c.a << "+" << c.b << "*i";
	}else{
		outs << c.a << c.b << "*i";
	}
	return outs;
}