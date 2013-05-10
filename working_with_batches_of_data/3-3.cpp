#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {

  cout << "Enter a bunch of words, dude: ";
  vector<string> words;
  vector<int> occurrences;
  string word;

  while (cin >> word) {
    bool foundWord = false;
    for (vector<int>::size_type index = 0; index < words.size(); index++) {
      if (word == words[index]) {
	occurrences[index]++;
	foundWord = true;
	break;
      }
    }

    if (!foundWord) {
      words.push_back(word);
      occurrences.push_back(1);
    }
  }

  cout << "Here are the occurrences in your input: " << endl;
  for (vector<int>::size_type index = 0; index < words.size(); index++)
    cout << words[index] << ": " << occurrences[index] << " times" << endl;

  return 0;
}
