#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {

  cout << "Enter a bunch of words, dude: ";
  string longest = "";
  string shortest = "";
  string word;

  while (cin >> word) {
    if (shortest.length() == 0)
      shortest = word;
    if (word.length() > longest.length())
      longest = word;
    if (word.length() < shortest.length())
      shortest = word;
  }

  cout << "longest word: " << longest << endl;
  cout << "shortest word: " << shortest << endl;

  return 0;
}
