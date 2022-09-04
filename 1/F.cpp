// extract to string
#include <iostream>
#include <string>

int fun(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
  {
    return c;
  }
  else if (c >= 'A' && c <= 'Z')
  {
    return c - 'A' + 'a';
  }
  else
  {
    return -1;
  }
}

int main()
{
  std::string str;
  std::getline(std::cin, str);

  if (str.length() == 0)
  {
    std::cout << "False" << std::endl;
    return 0;
  }

  int head = -1, tail = -1;
  int head_buff, tail_buff;
  size_t i = 0;
  size_t j = 0;

  while (i < str.length() && j < str.length())
  {
    head_buff = fun(str[i]);
    tail_buff = fun(str[str.length() - 1 - j]);
    // printf("head_buff=%c tail_buff=%c\n", head_buff, tail_buff);

    if (head_buff != -1)
    {
      head = head_buff;
    }
    else
    {
      i++;
    }

    if (tail_buff != -1)
    {
      tail = tail_buff;
    }
    else
    {
      j++;
    }

    if (head != -1 && tail != -1)
    {
      // printf("head=%c tail=%c\n", head, tail);
      if (head != tail)
      {
        std::cout << "False" << std::endl;
        return 0;
      }
      head = -1;
      tail = -1;
      i++;
      j++;
    }
  }

  std::cout << "True" << std::endl;
  return 0;
}