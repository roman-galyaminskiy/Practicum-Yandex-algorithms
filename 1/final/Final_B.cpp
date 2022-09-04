#include <iostream>

int main()
{
  int k;
  std::cin >> k;
  const int field_size = 16;
  char field[16] = {'.'};

  int buf;
  int i = 0;
  while (i < field_size) {
    buf = getchar();

    if (buf != '\n') {
      field[i] = buf;
      i++;
    }
  }

  const int freq_size = 9;
  int freqs[freq_size] = {0};

  for (int i = 0; i < field_size; i++)
  {
    if (field[i] != '.' && field[i] >= '1' && field[i] <= '9')
    {
      freqs[field[i] - '1']++;
    }
  }

  int result = 0;
  for (int i = 0; i < field_size; i++)
  {
    if (freqs[i] > 0 && freqs[i] <= k * 2 )
      result++;
  }
  std::cout << result << '\n';

  return 0;
}