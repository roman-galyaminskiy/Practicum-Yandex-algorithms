#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  uint32_t n;
  std::cin >> n;
  std::vector<uint32_t> lots;

  uint32_t buf;
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> buf;
    lots.push_back(buf);
  }

  std::vector<uint32_t> results;

  int64_t zero_index = -1;

  for (size_t i = 0; i < n; i++)
  {
    if (zero_index > -1)
    {
      if (lots[i] == 0)
      {
        results[i] = 0;
        zero_index = i;
      }
      else
      {
        results[i] = i - zero_index;
      }
    }
  }

  zero_index = -1;
  for (int i = n - 1; i >= 0; i--)
  {
    if (zero_index > -1) {
      if (lots[i] == 0)
      {
        zero_index = i;
      }
      results[i] = std::min(results[i], zero_index - i);
    }
  }
  
  for (size_t i = 0; i < n; i++) {
    std::cout << results[i];
    if (i < lots.size() - 1)
    {
      std::cout << ' ';
    }
}