#include <iostream>
#include <string>
#include <vector>

using namespace std;


class StringSet {
	public:
		StringSet(string a[],int size);
		StringSet();
		friend StringSet operator +(const StringSet& set1, const StringSet& set2);
		friend StringSet operator *(const StringSet& set1, const StringSet& set2);
		friend istream& operator >>(istream& ins, StringSet& s);
		friend ostream& operator <<(ostream& outs, const StringSet& s);
	private:
		vector<string> set;
	
};

int main()
{
	StringSet a, b, c;
	
	cout << "Enter:";
	cin >> a;
	cout << "the first set of strings terminated by the word END:Enter:";
	cin >> b;
	cout << "the second set of strings terminated by the word END:\n";
	cout << a << endl;
	cout << b << endl;
	c = a + b;
	cout << " + : " << c << endl;
	c = a * b;
	cout << " * : " << c << endl;
	return 0;
}

StringSet::StringSet(string a[], int size)
{
	for(int i = 0; i < size; i++){
		set.push_back(a[i]);
	}
}

StringSet::StringSet()
{}

StringSet operator +(const StringSet& set1, const StringSet& set2)
{
	bool add;
	StringSet s;
	string stemp;
	
	s.set = set1.set;
	for(int i = 0; i < set2.set.size();i++){
		add = true;
		for(int j = 0; j < set1.set.size();j++){
			if(set2.set[i] == set1.set[j]){
				add = false;
			}
		}
		
		if(add){
			s.set.push_back(set2.set[i]);
		}
	}
	
	for(int i = 0; i < s.set.size(); i++){
		for(int j = i; j < s.set.size(); j++){
			if(s.set[j] < s.set[i]){
				stemp = s.set[i];
				s.set[i] = s.set[j];
				s.set[j] = stemp;
			}
		}
	}

	return s;
}

StringSet operator *(const StringSet & set1, const StringSet& set2)
{
	bool add;
	StringSet s;
	
	
	for(int i = 0; i < set1.set.size(); i++){
		add = false;
		for(int j = 0; j < set2.set.size(); j++){
			if(set2.set[j] == set1.set[i]){
				add = true;
			}
		}
		
		if(add){
			s.set.push_back(set1.set[i]);
		}
	}
	
	return s;
}

istream& operator >>(istream& ins, StringSet& s)
{
	string stemp;
	
	while(stemp != "END"){
		ins >> stemp;
		if(stemp != "END"){
			s.set.push_back(stemp);
		}
	}
	
	for(int i = 0; i < s.set.size(); i++){
		for(int j = i; j < s.set.size(); j++){
			if(s.set[j] < s.set[i]){
				stemp = s.set[i];
				s.set[i] = s.set[j];
				s.set[j] = stemp;
			}
		}
	}
	
	
	
	return ins;
}

ostream& operator <<(ostream& outs, const StringSet& s)
{
	outs << "{ ";
	for(int i = 0; i < s.set.size(); i++)
	{
		if(i > 0){
			outs << ", ";
		}
		outs << s.set[i];
	}
	outs << " }";
	
	return outs;
	
}
	