/*
Name: DavidWassmanProj1.cpp
Purpose: Complete Programming Project 4 & 6
*/

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
  	
		// setup test data
		size = 5;
		string *dynamicArray = new string[size];
	
		dynamicArray[0] = "Test1";
		dynamicArray[1] = "Test2";
		dynamicArray[2] = "Test3";
		dynamicArray[3] = "Test4";
		dynamicArray[4] = "Test5";

		// Add entry to a dynamic array
		dynamicArray = addEntry(dynamicArray, size, "Test6");	
		print(dynamicArray, size);		
	
		// Remove entry from a dynamic array
		dynamicArray = deleteEntry(dynamicArray, size, "Test3");
		print(dynamicArray, size);		
	
		
	
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
	

string* addEntry(string* dynamicArray, int& size, string newEntry)
{
	// you implement this. Please read Programming Project 6 on page 536
    // you may watch video notes to get the idea
	
	// Create new array for adding the entry
	string *newArray = new string[++size];
	
	// Loop through the current dynamic array and add elements to new
	for(int i = 0; i < size - 1; i++)
	{
		newArray[i] = dynamicArray[i];
	}
	
	// add new elemnt to last index of new array
	newArray[size - 1] = newEntry;
	return newArray;
}

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete)
{
	// you implement this. Please read Programming Project 6 on page 536
    // you may watch video notes to get the idea
	
	// New interger for new size
	int newSize = 0;
	
	// Use for loop to iterate through the current dynamic array and add 
		//to new size all elements not equal to entryToDelete
	for(int i = 0; i < size; i++)
	{
		if(dynamicArray[i] != entryToDelete)
		{
			newSize++;
		}
	}
	
	// Create new dynamic array to the new size
	string *newArray = new string[newSize];
	
	newSize = 0;
	for(int i = 0; i < size; i++)
	{
		// Add elements from old dynamic array to new array if not equal
			// to entryToDelete
		if(dynamicArray[i] != entryToDelete)
		{
			newArray[newSize++] = dynamicArray[i];
		}
	}
	
	// Set size to new size
	size = newSize;
	return newArray;
}

void print(const string* dynamicArray, int size)
{
    // you implement this.
    // you may watch video notes to get the idea
	// Simple loop to print out the elements of the array
	for(int i = 0; i < size; i++)
	{
		cout << dynamicArray[i] << " " << i << endl;
	}
}
