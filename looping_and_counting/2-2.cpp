#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
  // ask for the person's name
  cout << "Please enter your first name: ";

  // read the name
  string name;
  cin >> name;

  //build the message that we intend to write
  const string greeting = "Hello, " + name + "!";

  // the number of blanks surrounding the greeting
  const int rowPad = 2;
  const int colPad = 5;

  //total number of rows to write
  const int rows = rowPad * 2 + 3;
  const string::size_type cols = greeting.size() + colPad * 2 + 2;

  // separate the output from the input
  cout << endl;

  //write rows rows of output
  int r = 0;

  // invariant: we have written r rows so far
  for(int r = 0; r != rows; ++r) {
    // write a row of output (as we will decribe in 2.4/22)

    string::size_type c = 0;
    
    // invariant: we have written c characters so far in the current row
    while (c != cols) {
      if (r == rowPad + 1 && c == colPad + 1) {
	cout << greeting;
	c += greeting.size();
      } else {
	if (r == 0 || r == rows - 1 || c == 0 || c == cols -1)
	  cout << "*";
	else
	  cout << " ";
	++c;
      }
      
    }
    cout << endl;
  }

  return 0;
}
