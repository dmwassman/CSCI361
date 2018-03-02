#include <iostream>
#include "DavidWassmanMoney.h"

using namespace std;


int main()
{
	Money x,y;
	
	cout << "Enter a money value in the format (-)$0.00: ";
	cin >> x;
	
	cout << "Enter another money value in the format (-)$0.00: ";
	cin >> y;

	cout << (-x) << endl;
	
	
}