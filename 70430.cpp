#include <iostream>
#include <string>

using namespace std;

class Movie{
	public:
		Movie(string t, string r);
		void setMovie(string t, string r);
		void setScore(int s);
		double average();
		string title;
		string rating;
		int score[6];
};

int main()
{
	string t,r;
	int s = 0;
	
	cout << "Enter:";
	getline(cin,t);
		
	cout << "the title of the movie:Enter:";
	getline(cin,r);
	
	
	Movie m(t,r);
	
	cout << "the MPAA rating:Enter:";
	while(s != -1){
		cin >> s;
		if(s != -1){
			m.setScore(s);
		}
	}
	cout << "space separated list of people ratings of the movie:";
	cout << "MPAA rating for " << m.title << " is " << m.rating << ", and the average people rating is " << m.average() << ".\n"; 
}

Movie::Movie(string t,string r) : title(t), rating(r)
{
	for(int i = 0; i < 6; i++)
	{
		score[i] = 0;
	}
}

void Movie::setScore(int s)
{
	if(s > -1 && s < 6){
		score[s]++;
	}else{
		cout << "Score must be between 1 and 5.\n";
	}
}


void Movie::setMovie(string t, string r)
{
	title = t;
	rating = r;
}

double Movie::average()
{
	int sum = 0;
	int count = 0;
	for(int i = 1; i < 6; i++){
		count += score[i];
		sum += score[i] * i;
	}
	
	return sum/double(count);
}