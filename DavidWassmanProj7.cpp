/*
Name: DavidWassmanProj7.cpp
Purpose: Complete Programming Project 16.1
*/

#include <iostream>
#include <string>

using namespace std;

class TimeFormatMistake {
	public:
		TimeFormatMistake(int h, int m);
	private:
		int hour;
		int min;
};

int main()
{
	char repeat;
	string time,hour,min, part;
	
	
	do{
		cout << "Enter time in 24-hour notation:\n";
		cin >> time;
		
		hour = time.substr(0, time.find(":"));
		
		stoi(hour);
		
		
		
		
		cout << "Again?(y/n)\n";
		cin >> repeat;
	} while(repeat == 'y' || repeat == 'Y');
	
	return 0;
}