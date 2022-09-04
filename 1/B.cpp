#include <iostream>

bool even(uint32_t n) {
  return ((n & 1) == 0);
}

int main()
{
  uint32_t a, b, c;
  std::cin >> a >> b >> c;

  if (even(a) == even(b) && even(a) == even(c)) {
    std::cout << "WIN" << std::endl;
  } 
  else {
    std::cout << "FAIL" << std::endl;
  }
  return 0;
}