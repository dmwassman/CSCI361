//Header file Money.h: This is the INTERFACE for the class Money
//Values of this type are dollars and cents which are converted to total cents.
//Input and output are in (-)$0.00 format

#ifndef MONEY_H
#define MONEY_H

namespace std
{
	class Money{
		public:
			//Constructors
			Money();
			Money(long dollars);
			Money(long dollars, int cents);
		
			//member functions
			void operator -();
			//Precondition: class object declared and given value
			//Postcondition: Returns negative of the value in class object
			double getValue() const;
			//Precondition: class object initialized
			//Postcondition: return value of allCents
			Money percent(int percentFigure) const;
			//Precondition: class object declared and initialized
			//Postcondition: returns 10% of the amount in class object
	
			//friend functions
			friend Money operator +(const Money& amount1, const Money& amount2);
			//Precondition: amount1 and amount2 have been given values.
			//Postcondition: returns amount1 + amount 2
			friend Money operator -(const Money& amount1, const Money& amount2);
			//Precondition: amount1 and amount2 have been given values.
			//Postcondition: returns amount1 - amount2
			friend bool operator ==(const Money& amount1, const Money& amount2);
			//Precondition: amount1 and amount2 have been given values
			//Postcondition: Returns true if amount1 = amount2, false otherwise
			friend bool operator <(const Money& amount1, const Money& amount2);
			//Precondition: amount1 and amount2 have been given values
			//Postcondition: Returns true if amount1 < amount2, false otherwise
			friend bool operator <=(const Money& amount1, const Money& amount2);
			//Precondition: amount1 and amount2 have been given values
			//Postcondition: Returns true if amount <= amount2, false otherwise
			friend bool operator >(const Money& amount1, const Money& amount2);
			//Precondition: amount1 and amount2 have been given values
			//Postcondition: Returns true if amount1 > amount2, false otherwise
			friend bool operator >=(const Money& amount1, const Money& amount2);
			//Precondition: amount1 and amount2 have been given values
			//Postcondition: Returns true if amount >= amount2, false otherwise
			friend istream& operator >>(istream& ins, Money& amount);
			//Precondition: amount declared
			//Postcondition: Add value to amount in proper format
			friend ostream& operator <<(ostream& outs, const Money& amount);
			//Precondition: amount has been given a value
			//Postcondition: display amount in proper format

		private:
			long allCents;
	};
}
#endif
