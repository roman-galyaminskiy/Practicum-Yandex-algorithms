#include <iostream>

int main()
{
  // std::cout << UINT32_MAX << std::endl;
  uint32_t n;
  std::cin >> n;
  char word[UINT16_MAX];
  char longest_word[UINT16_MAX];
  uint16_t cur_len = 0;
  uint16_t max_len = 0;

  int c;
  c = getchar(); // LF

  for (size_t i = 0; i <= n; i++)
  {
    c = (char)getchar();
    // std::cout << c << std::endl;
    // printf("%c\n", c);

    if (c == ' ' || i == n)
    {
      if (cur_len > max_len)
      {
        max_len = cur_len;

        for (size_t j = 0; j < max_len; j++)
        {
          longest_word[j] = word[j];
        }
      }
      cur_len = 0;
    }
    else
    {
      // std::cout << cur_len << std::endl;
      word[cur_len] = c;
      cur_len++;
    }
  } 


  // std::cout << max_len << std::endl;
  for (size_t i = 0; i < max_len; i++)
  {
    std::cout << longest_word[i];
  }
  std::cout << '\n' << max_len << std::endl;

  return 0;
}