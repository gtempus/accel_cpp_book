#include <string>

int main()
{
  const std::string exclam = "!";
  /*
   * The following line doesn't work since the '+' operator
   * does not work for two string literals ("hello" + ",world").
   * The '+' operator does work when concatenating a std::string with a 
   * string literal however (ex. 1-1.cpp)
   */
  const std::string message = "Hello" + ", world" + exclam;
  return 0;
}
