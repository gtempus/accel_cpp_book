#include <iostream>
#include <string>

/*
 * This code will not compile because
 * line 15 references 'x' but it is already out of scope.
 * This code will compile if we move the curly brace on line 14
 * down to the end of line 15.
 */
int main() 
{
  { std::string s = "a string";
    { std::string x = s + ", really";
      std::cout << s << std::endl; }
    std::cout << x << std::endl;
  }
  return 0;
}
