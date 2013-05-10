#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;

int main()
{
  cout << "Please enter a whole bunch of integers, "
    "followed by end-of-file: ";

  vector<int> numbers;
  int x;

  while (cin >> x) {
    numbers.push_back(x);
  }

  typedef vector<int>::size_type vec_sz;
  vec_sz size = numbers.size();

  if (size < 4) {
    cout << endl << "You need to enter at least four integers "
      "for this to work, Bub. "
      "Please try again." << endl;
    return 1;
  }

  sort(numbers.begin(), numbers.end());

  int quads = size / 4;
  int extras = size % 4;
  int quartBoundary = size - 1 - quads;
  bool extraPrinted = false;

  cout << "=== Top Quartile ===" << endl;

  for (int element = size - 1; element >= 0; --element) {
    if (quartBoundary == element) {
      if (extras > 0 && !extraPrinted) {
	extraPrinted = true;
	quartBoundary--; 
      }else {
	cout << "=== Next Quartile ===" << endl;
	extras--;
	extraPrinted = false;
	quartBoundary -= quads;
      }
    }
    cout << numbers[element] << endl;
  }

  cout << "=== Finished ===" << endl;

  return 0;
}
