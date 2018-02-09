/* Do Programming Project 2 on page 611. You may watch the video note for 
 * Programming Project 1 on page 611 to get some idea. Then try to finish
 * independently by complete this sample file.
 * 
 * Author: David Wassman
 * Version: 2/8/2018
 */

#include <iostream>
using namespace std;

class CDAccount
{
public:
    CDAccount();
    CDAccount(double new_balance, double new_interest_rate, int new_term);
    double get_initial_balance() const;
    double get_balance_at_maturity() const;
    double get_interest_rate() const;
    int get_term() const;
    void input(istream& in);
    void output(ostream& out);
    
private:
    int dollar;
    int cent;
    double interest_rate;
    int term; // months until maturity
};

int main()
{
    // You implement the test code here
    // You may watch the video note to get the idea
    // notice that user will only enter balance as a double value
    // You may implement it as a menu oriented testing program
    // which be able to test constructors, methods of CDAccount class
	int i = 0;
	double balance;
	double interest;
	int term;
	CDAccount a;
			
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	while(i != 7){
		cout << "**** CD Account Test *****\n"
			<< "1. Create a new CD account\n"
			<< "2. Create new CD account from constructor\n"
			<< "3. Get initial balance\n"
			<< "4. Get maturity balance\n"
			<< "5. Get interest rate\n"
			<< "6. Get term\n"
			<< "7. Exit\n"
			<< "Choice: ";
			
		cin >> i;
	
		switch(i){
			case 1: 
				cout << "\tEnter space-seperated values for initial balace, interest rate and term: ";
				a.input(cin);
				break;
			case 2:
				cout << "\tEnter space-seperated values for initial balace, interest rate and term: ";
				cin >> balance >> interest >> term;
				
				a = CDAccount(balance, interest, term);
				
				break;
			case 3:
				cout << a.get_initial_balance() << endl;
				break;
			case 4:
				a.output(cout);
				break;
			case 5:
				cout << a.get_interest_rate() << endl;
				break;
			case 6:
				cout << a.get_term() << endl;
				break;
			default:
				break;

		}
	}	
				
	
		
}

// Implement the class definition here. Notice that the interfaces are the
// same as in Programming Project 1. However, the implementation will be
// different since the private information balance is stored differently
// for example, the input function will only read the balance, itnerest rate
// and term from the user. So it should be modified as following
CDAccount::CDAccount() : dollar(0), cent(0), interest_rate(0), term(0)
{}

CDAccount::CDAccount(double new_balance, double new_interest_rate, int new_term) 
{
	dollar = int(new_balance);
	cent = int((new_balance - dollar)*100);
	
	interest_rate = new_interest_rate/100.00;
	
	term = new_term;
	
}

double CDAccount::get_initial_balance() const
{
	return dollar + cent/100.00;
}

double CDAccount::get_balance_at_maturity() const
{
	double balance = dollar + cent/100.00;
	
	return balance + balance*interest_rate*(term/12.0);
}

double CDAccount::get_interest_rate() const
{
	return interest_rate*100.00;
}

int CDAccount::get_term() const
{
	return term;
}

void CDAccount::input(istream& in)
{
    double balance;
    in >> balance; // get initial balance from user
    
    // convert balance to dollars and cents since this is how balance stored
    dollar = (int) balance; // dollar is the interger part of balace
    cent = (int) ((balance - dollar)*100); // cent is the fraction part * 100
    
    in >> interest_rate; // get interest rate from user
		interest_rate /= 100.00;
    in >> term; // get term from user
}

void CDAccount::output(ostream& out)
{
	
	out.setf(ios::fixed);
	out.setf(ios::showpoint);
	out.precision(2);
	cout << "When your CD matures in " 
		<< term << " months, \n"
		<< "it will have a balance of $"
		<< get_balance_at_maturity() << endl;
}