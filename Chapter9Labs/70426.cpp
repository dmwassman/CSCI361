#include <iostream>

using namespace std;

void reverse(char c[], int i)
{
  char *a, *z;
  char tmp;
  
  
  a = c;
  z = a + --i;
  
 for(int j = 0; j < i/2; j++)
  {
    tmp = *a;
    *(a++) = *z;
    *(z--) = tmp;  
 }
  
  
}

int main()
{
  char x[100];
  char c;
  int i = 0;
  
  cout << "Enter: ";
  do
  {
    cin.get(c);
    if (c != '\n' )
    {
      x[i++] = c;
    }
  }while (c != '\n');
    
  reverse(x,i);
    
  cout << "a string: " << x << endl;
    
    
  
  return 0;
}