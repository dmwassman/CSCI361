#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void reverse(char* front, char* rear);
// Precondition: The front and rear are pointing to the front
//               and rear of a C-string, respectively
// Postcondition: The C-string is reversed

string* addEntry(string* dynamiccArray, int& size, string newEntry);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: A new dynamic array is created, which is one larger than
//                dynamicArray All elements from dynamicArray are copied to
//                new array, the new entry is added to new array, the size
//                is increased, the dynamicArray is deleted, new dynamic
//                array is returned.

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: The function should search dynamicArray for entryToDelete.
//                If not found, the request should be ignored and the
//                unmodified dynamicArray returned. If found, create a new
//                dynamic array one element smaller than dynamicArray. Copy
//                all element except entryToDelete into the new array, delete
//                dynamicArray, decrement size, and return the new dynamic
//                array

void print(const string* dynamicArray, int size);
// Precondition: dynamicArray point to a array of strings with give size,
// Postcondition: The elements in dynamic array will be print out. One
//                element per line forllowed by its index

int main()
{
    // write code to test reverse function.
    // make sure that you test it on at least two strings
    // one string has even length, another string has odd length
  	
		// Even string (odd size for '\0')
		char strEven[7] = "ABCDEF";
		// Odd string
		char strOdd[6] = "abcde";
		char *front, *rear;
		int size;
	
		//Even first
		//Null for loop to find string size
		for(size = 0; strEven[size] != '\0'; size++){}
		front = strEven;
		// pointer math to point to the last element in string
		rear = front + --size;

		reverse(front,rear);
		
		// Odd
		for(size = 0; strOdd[size] != '\0'; size++){}
		front = strOdd;
		rear = front + --size;
	
		reverse(front,rear);
	
		// Loop thr
		for(int i = 0; strEven[i] != '\0'; i++)
		{
			cout << strEven[i];
		}
	
		cout << endl;
		for(int i = 0; strOdd[i] != '\0'; i++)
		{
			cout << strOdd[i];
		}
		cout << endl;
	
		// write code to test add entry and delete entry function
    // you may watch video notes to get idea for this part
  	string *dynamicArray = new string("ABCDEF");
		string sEven = *dynamicArray;
	
		print(dynamicArray,sEven.length());
	
	
		
	
		
	
	return 0;
		
		
}

void reverse(char* front, char* rear)
{
	char tmp;
	while(front < rear)
	{
		tmp = *front;
		*(front++) = *rear;
		*(rear--) = tmp;
	}
}
	

/*string* addEntry(string* dynamicArray, int& size, string newEntry)
{
	// you implement this. Please read Programming Project 6 on page 536
    // you may watch video notes to get the idea
	char *newArray;
	
	newArray = new char[size + 1];
	
	for(int i = 0; i < size; i++)
	{
		newArray[i] = dynamicArray[i];
	}
	
	size++;
	
	return newArray;
}

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete)
{
	// you implement this. Please read Programming Project 6 on page 536
    // you may watch video notes to get the idea
}
//*/
void print(const string* dynamicArray, int size)
{
    // you implement this.
    // you may watch video notes to get the idea
		string strTmp = *dynamicArray;
	
		for(int i = 0; i < size; i++)
		{
			cout << strTmp[i] << ' ' << i << endl;
		}
}
