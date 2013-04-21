#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{

  for (int i = 0; i < 5; ++i)
    cout << string(10,'*') << endl;

  cout << endl;

  for (int i = 0; i < 10; ++i)
    cout << string(30,'*') << endl;

  cout << endl;

  for (int i = 0; i < 10; ++i)
    cout << string(i,'*') << endl;

  return 0;
}
