//Implementation file Money.cpp: This is the IMPLEMENTATION file for the class Money
//Interface file Money.h

#include <iostream>
#include <cstdlib>
#include "DavidWassmanMoney.h"

using namespace std;

namespace {
	int digitToInt(char c);
	//Converts char variables for numerical values to corresponding integer values
	int isDigit(char c);
	//Check to see if char variable corresponds to a numerical value
	
	int digitToInt(char c)
	{
		return (int(c) - int('0'));
	}
	
	int isDigit(char c)
	{
		if(int(c) > 47 && int(c) < 58)
			return true;
		else
			return false;
	}
}

namespace std
{
	//Constructors
	Money::Money() : allCents(0)
	{}

	Money::Money(long dollars) : allCents(dollars * 100)
	{}

	Money::Money(long dollars, int cents) : allCents(dollars * 100 + long(cents))
	{}

	//Member functions
	Money Money::operator -()
	{
		return Money(0,allCents * -1);
	}

	double Money::getValue() const
	{
		return (allCents * 0.01);
	}

	Money Money::percent(int percentFigure) const
	{
		Money temp;

		temp.allCents = allCents * (percentFigure / 100);

		return temp;
	}

	//Friend functions
	Money operator +(const Money& amount1, const Money& amount2)
	{
		return amount1.allCents + amount2.allCents;
	}

	Money operator -(const Money& amount1, const Money& amount2)
	{
		return amount1.allCents - amount2.allCents;
	}

	bool operator ==(const Money& amount1, const Money& amount2)
	{
		if(amount1.allCents == amount2.allCents)
			return true;
		else
			return false;
	}

	bool operator <(const Money& amount1, const Money& amount2)
	{
		if(amount1.allCents < amount2.allCents)
			return true;
		else
			return false;
	}

	bool operator <=(const Money& amount1, const Money& amount2)
	{
		if(amount1.allCents <= amount2.allCents)
			return true;
		else
			return false;
	}

	bool operator >(const Money& amount1, const Money& amount2)
	{
		if(amount1.allCents > amount2.allCents)
			return true;
		else	
			return false;
	}

	bool operator >=(const Money& amount1, const Money& amount2)
	{
		if(amount1.allCents >= amount2.allCents)
			return true;
		else
			return false;
	}

	istream& operator >>(istream& ins, Money& amount)
	{
		bool neg = false;
		char ds,dp, d1, d2;
		long dollars;
		int cents;

		ins >> ds;
		if(ds == '-')
		{
			neg = true;
			ins >> ds;
		}
		
		

		ins >> dollars >> dp >> d1 >> d2;

		if(ds != '$' || dp != '.' || !(isDigit(d1)) || !(isDigit(d2)))
		{
			cout << "error illegal form for money input\n";
			exit(1);
		}
		
		cents = digitToInt(d1) * 10 + digitToInt(d2);
		amount.allCents = dollars * 100 + cents;
		if(neg)
			amount.allCents *= -1;

		return ins;
	}

	ostream& operator <<(ostream& outs, const Money& amount)
	{
		bool neg;
		long cents;
		
		
		cents = amount.allCents;
		
		if(cents < 0)
		{
			outs << '-';
			cents *= -1;
		}

		outs << '$' << cents / 100 << '.';

		cents = cents % 100;
		if(cents < 10)
			outs << '0';

		outs << cents;

		return outs;
	}
}

