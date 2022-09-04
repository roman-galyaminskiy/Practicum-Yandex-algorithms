#include <iostream>
// #include <stdint.h>

int main()
{
  uint32_t n, result;
  std::cin >> n;
  result = 0;

  if (n < 2) {
    std::cout << 1 << std::endl;
    return 0;
  }

  
  int16_t prev_prev, prev, curr;

  std::cin >> prev;
  std::cin >> curr;

  // std::cout << prev << ' ' << curr << std::endl;
  if (curr < prev) {
    result++;
  }

  for (size_t i = 2; i < n; i++)
  {
    prev_prev = prev;
    prev = curr;
    std::cin >> curr;

    if (prev > prev_prev && prev > curr) {
      result++;
    }
  }
  // std::cout << prev << ' ' << curr << std::endl;
  if (curr > prev) {
    result++;
  }

  std::cout << result << std::endl;

  return 0;
}