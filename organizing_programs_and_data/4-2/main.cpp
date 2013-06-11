#include <iomanip>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::setw;

int main()
{
	for(int i = 1; i < 101; ++i)
	{
		cout << setw(3) << i << setw(8) << i*i << endl;
	}
	return 0;
}
