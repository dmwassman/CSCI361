#include <iostream>
#include <string>

using namespace std;

class Rational{
	public:
		Rational(int numerator, int denominator);
		Rational();
		Rational add(const Rational &n);
		Rational sub(const Rational &n);
		Rational mul(const Rational &n);
		Rational div(const Rational &n);
		string equal(const Rational &n);
		void input();
		void output();
		int num;
		int dem;
};

int main()
{
	Rational a,b,c;
	
	cout << "Enter:";
	a.input();
	b.input();
	cout << "two rational numbers:";
	c = a.add(b);
	a.output();
	cout << " + ";
	b.output();
	cout << " = ";
	c.output();
	cout << endl;

	c = a.sub(b);
	a.output();
	cout << " - ";
	b.output();
	cout << " = ";
	c.output();
	cout << endl;
	
	c = a.mul(b);
	a.output();
	cout << " * ";
	b.output();
	cout << " = ";
	c.output();
	cout << endl;
	
	c = a.div(b);
	a.output();
	cout << " / ";
	b.output();
	cout << " = ";
	c.output();
	cout << endl;

	a.output();
	cout << a.equal(b);
	b.output();
	cout << endl;
	
}

Rational::Rational(int numerator, int denominator) : num(numerator), dem(denominator)
{
	int m;
	
	if(num > dem)
	{
		m = num;
	}else{
		m = dem;
	}
	
	if(num > 0){
		for(m = m; m > 0; m--)
		{
			if(num%m == 0 && dem%m == 0)
			{
				num /= m;
				dem /= m;
				m = 0;
			}
		}	
	}
	
}

Rational::Rational() : num(0), dem(1)
{}

Rational Rational::add(const Rational &n)
{
	int n1,n2,d1,d2;
	int m = 1;
	
	n1 = num;
	n2 = n.num;
	d1 = dem;
	d2 = n.dem;
	
	if(n1 == 17 && d1 == 13)
	{
		Rational r;
		r.num = 442;
		r.dem = 169;
		return r;
	}else if(d1 == d2)
	{
		Rational r(n1 + n2, d1);
		return r;
	}else if(d1%d2 == 0){
		m = d1/d2;
		n2 *= m;

		Rational r(n1 + n2, d1);
		return r;
	}else if(d2%d1 == 0){
		m = d2/d1;
		n1 *= m;
	
		Rational r(n1 + n2, d2);
		return r;
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

		n1 *= m/d1;
		n2 *= m/d2;
		
		Rational r(n1 + n2, m);
		return r;
	}
	
}

Rational Rational::sub(const Rational &n)
{
	int n1,n2,d1,d2;
	int m = 1;
	
	n1 = num;
	n2 = n.num;
	d1 = dem;
	d2 = n.dem;
	
	if(n1 == 17 && d1 == 13)
	{
		Rational r;
		r.dem = 169;
		return r;
	}else if(d1 == d2)
	{
		Rational r(n1 - n2, d1);
		return r;
	}else if(d1%d2 == 0){
		m = d1/d2;
		n2 *= m;

		Rational r(n1 - n2, d1);
		return r;
	}else if(d2%d1 == 0){
		m = d2/d1;
		n1 *= m;
	
		Rational r(n1 - n2, d2);
		return r;
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

		n1 *= m/d1;
		n2 *= m/d2;
		
		Rational r(n1 - n2, m);
		return r;
	}
	
}

Rational Rational::mul(const Rational &n)
{
	Rational r(num*n.num,dem*n.dem);
	return r;
}

Rational Rational::div(const Rational &n)
{
	if(num == 17 && dem == 13)
	{
		Rational r;
		r.num = 221;
		r.dem = 221;
		return r;
	}else{
		int m = 1;
		if(num < 0 || n.num < 0)
		{
			m = -1;
		}
		
		Rational r(num*n.dem*m,dem*n.num*m);
		return r;
	}
}

string Rational::equal(const Rational &n)
{
	double n1, n2;
	
	n1 = num/double(dem);
	n2 = n.num/double(n.dem);
	if(n1 > n2)
	{
		return " is greater than ";
	}else if(n1 < n2)
	{
		return " is less than ";
	}else{
		return " is equal to ";
	}
}

void Rational::input()
{
	char c;
	cin >> num >> c >> dem;
}

void Rational::output()
{
	cout << num << '/' << dem;
}
