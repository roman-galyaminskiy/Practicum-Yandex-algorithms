#include <iostream>
#include <vector>

int64_t find_next_zero(const std::vector<uint32_t> &lots, int64_t from, int64_t to)
{
  for (int64_t i = from; i < to; i++)
  {
    if (lots[i] == 0)
      return i;
  }
  return -1;
}

int64_t choose_nearest(uint32_t left, uint32_t right, uint32_t i)
{
  if (i < left) {
    return left - i;
  }
  else if ((i - left) < (right - i)) {
    return (i - left);
  }
  else {
    return (right - i);
  }
}

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

  int64_t prev_zero_index, zero_index;

  // Находим первые 2 пустых участка. Если найден только один пустой участок - выводим ответ.
  prev_zero_index = find_next_zero(lots, 0, lots.size());
  zero_index = find_next_zero(lots, prev_zero_index + 1, lots.size());

  if (zero_index == -1)
  {
    for (uint32_t i = 0; i < n - 1; i++)
    {
      std::cout << (i < prev_zero_index ? prev_zero_index - i : i - prev_zero_index) << ' ';
    }
    std::cout << ((n - 1) - prev_zero_index) << '\n';
    return 0;
  }

  std::vector<uint32_t> results;
  for (uint32_t i = 0; i < lots.size(); i++) 
  {
    if (i > zero_index) {
      prev_zero_index = zero_index;
       
      zero_index = find_next_zero(lots, zero_index + 1, lots.size());

      if (zero_index == -1) 
      {
        for (uint32_t j = i; j < lots.size(); j++) 
        {
          std::cout << (j - prev_zero_index);
          
          if (j < lots.size() - 1)
          {
            std::cout << ' ';
          }
        }
        return 0;
      }
    }
    std::cout << choose_nearest(prev_zero_index, zero_index, i);
    if (i < lots.size() - 1)
    {
      std::cout << ' ';
    }
  }
}