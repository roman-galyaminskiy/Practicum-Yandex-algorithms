#include <iostream>
#include <string>
#include <limits>



// В первой строке дано число a - основание, по которому считается хеш.
// Во второй строке дано число m < 10^9 - модуль.
// В третьей строке дана строка s, состоящая из больших и маленьких латинских букв.
unsigned long polynomial_hash(std::string s, int a, int m) {
  unsigned long result = 0;

  if (s.size() > 0) {
    for (size_t i = 0; i < s.size() - 1; i++)
    {
      result = ((result + s[i]) * a) % m;
    }
    result += s[s.size() - 1];
  }
  return result;
}
 
int main(int argc, char const *argv[])
{
  int a;
  unsigned int m;
  std::string s;
  std::cin >> a >> m >> s; 
  std::cout << polynomial_hash(s, a, m) << std::endl;
  return 0;
}

// 123
// 100003
// hash