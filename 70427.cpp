#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int i;
	vector<int> grades;
	
	cout << "Enter:";
	do
	{
		cin >> i;
		if(i != -1)
		{
			grades.push_back(i);
		}
	}while(i != -1);
	
	for(int j = 0; j < grades.size(); j++)
	{
		if(grades[j] > i)
		{
			i = grades[j];
		}
	}
	
	
	int *d = new int[i+1];
	d[0] = 0;
	
	for(int j = 0; j < grades.size(); j++)
	{
		d[grades[j]] += 1;
	}
	
	for(int j = 0; j <= i; j++)
	{
		if(d[j] > 0)
		{
			cout << "Number of " << j << "'s: " << d[j] << endl;
		}
	}
	
	return 0;
}