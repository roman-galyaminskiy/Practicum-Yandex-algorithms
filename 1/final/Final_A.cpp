// Отчет: https://contest.yandex.ru/contest/22450/run-report/69973721/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

// В первой строке дана длина улицы —– n (1 ≤ n ≤ 10^6).
// Номера домов (положительные числа) уникальны и не превосходят 10^9. 

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> lots;

  int buf;
  for (int i = 0; i < n; i++)
  {
    std::cin >> buf;
    lots.push_back(buf);
  }

  std::vector<int> results(n, INT_MAX);

  int zero_index = -1;

  for (int i = 0; i < n; i++)
  {
    if (lots[i] == 0)
    {
      results[i] = 0;
      zero_index = i;
    }
    else
    {
      if (zero_index > -1)
      {
        results[i] = i - zero_index;
      }
    }
  }

  zero_index = -1;
  for (int i = n - 1; i >= 0; i--)
  {    
    if (lots[i] == 0)
    {
      zero_index = i;
    }
    if (zero_index > -1) {
      results[i] = std::min(results[i], zero_index - i);
    }
  }
  
  for (int i = 0; i < n; i++) {
    std::cout << results[i];
    if (i < lots.size() - 1)
    {
      std::cout << ' ';
    }
  }
  std::cout << '\n';

  return 0;
}