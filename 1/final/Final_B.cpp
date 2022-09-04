#include <iostream>
#include <map>

int main()
{
  int k;
  std::cin >> k;
  int field_size = 16;
  char field[field_size];

  int buf;
  int i = 0;
  while (i < field_size) {
    buf = getchar();

    if (buf != '\n') {
      field[i] = buf;
      i++;
    }
  }

  std::map<char, int> freqs;
  std::map<char,int>::iterator it;

  for (int i = 0; i < field_size; i++)
  {
    if (field[i] != '.') {
      it = freqs.find(field[i]);

      if (it != freqs.end())
      {
        (it->second)++;
      }
      else 
      {
        freqs[field[i]] = 1;
      }
    }
  }

  int result = 0;
  for (auto i : freqs) 
  {
    if (i.second <= k * 2)
      result++;
  }
  std::cout << result << '\n';

  return 0;
}