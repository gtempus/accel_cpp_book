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
  cout << "Please enter the row padding: ";
  string rowPadInput;
  cin >> rowPadInput;
  int rowPad = std::stoi(rowPadInput);

  cout << "Please enter the column padding: ";
  string colPadInput;
  cin >> colPadInput;
  int colPad = std::stoi(colPadInput);

  //create the greeting padding
  string greetingPad(colPad, ' ');
  string rowPadLine(greeting.size() + colPad * 2, ' ');

  //total number of rows to write
  const int rows = rowPad * 2 + 3;
  const string::size_type cols = greeting.size() + colPad * 2 + 2;

  // separate the output from the input
  cout << endl;

  // invariant: we have written r rows so far
  for(int r = 0; r != rows; ++r) {
    // write a row of output (as we will decribe in 2.4/22)

    string::size_type c = 0;
    
    // invariant: we have written c characters so far in the current row
    while (c != cols) {
      if (r == rowPad + 1 && c == 1) {
	cout << greetingPad << greeting << greetingPad;
	c += (greeting.size() + greetingPad.size() * 2);
      } else {
	if (r == 0 || r == rows - 1 || c == 0 || c == cols -1) {
	  cout << "*";
	  ++c;
	}
	else {
	  cout << rowPadLine;
	  c = cols - 1;
	}
      }
      
    }
    cout << endl;
  }

  return 0;
}
