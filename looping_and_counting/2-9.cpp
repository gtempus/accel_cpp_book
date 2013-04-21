#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

int main()
{
  int first = 0;
  int second = 0;

  cout << "Please enter a number: ";
  cin >> first;
  
  cout << endl;

  cout << "Please enter a different number: ";
  cin >> second;

  cout << endl;

  cout << (first > second ? first : second) 
       << " is greater than " 
       << (first > second ? second : first) << endl;
  return 0;
}
