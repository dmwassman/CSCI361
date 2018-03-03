#include <iostream>
#include "DavidWassmanMoney.h"

using namespace std;


int main()
{
	char repeat = 'y';
	int p;
	Money x,y;
	
	do
	{
		cout << "**Enter a money value in the format (-)$0.00: ";
		cin >> x;

		cout << "**Enter another money value in the format (-)$0.00: ";
		cin >> y;

		cout << "The total cents of the first value is " << x.getValue() << endl;
		cout << "The total cents of the second value is " << y.getValue() << endl;

		cout << "The negative of the first value is " << (-x) << endl;
		cout << "The negative of the second value is " << (-y) << endl;

		cout << "**Enter a whole percentage: ";
		cin >> p;

		cout << p << "% of " << x << " is " << x.percent(p) << endl;
		cout << p << "% of " << y << " is " << y.percent(p) << endl;

		cout << x << " + " << y << " = " << (x + y) << endl;
		cout << x << " - " << y << " = " << (x - y) << endl;

		cout << x << " is ";
		if(!(x == y))
			cout << "NOT ";
		cout << "equal to " << y << endl;

		cout << x << " is ";
		if(!(x < y))
			cout << "NOT ";
		cout << "less than " << y << endl;

		cout << x << " is ";
		if(!(x <= y))
			cout << "NOT ";
		cout << "less than or equal to " << y << endl;

		cout << x << " is ";
		if(!(x > y))
			cout << "NOT ";
		cout << "greater than " << y << endl;

		cout << x << " is ";
		if(!(x >= y))
			cout << "NOT ";
		cout << "greater than or equal to " << y << endl;
		
		do
		{
			cout << "\n**Do you want to test again? (Y/N):";
			cin >> repeat;
			if(repeat == 'y' || repeat == 'Y' || repeat == 'n' || repeat == 'N')
				break;
		}while(true);
		
	}while(repeat != 'n' && repeat != 'N');
	
}