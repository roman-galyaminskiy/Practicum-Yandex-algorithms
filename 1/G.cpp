#include <iostream>

int main()
{
  uint16_t n;
  std::cin >> n;  
  char bites[16];
  
  if (n == 0) {
    printf("0");
  }
  else {
    size_t bites_size = 0;
    while (n > 0)
    {
      bites[bites_size] = n % 2;
      bites_size++;
      n = n / 2;
    }

    for (int64_t i = bites_size - 1; i >= 0; i--)
    {
      printf("%c", '0' + bites[i]);
    }
  }
  
  printf("\n");

  return 0;
}