#include <iostream>
#include <array>
#include <bits/stdc++.h>

void print_array(int *array, size_t n) {
  for (size_t i = 0; i < n; i++)
  {
    std::cout << array[i];
    if (i < n - 1) {
      std::cout << ' ';
    }
  }
  std::cout << '\n';
}

void bubble_sort(int *array, unsigned int n) {
  for (int i = n - 1; i >= 0; i--)
  {
    bool altered_flag = false;
    for (int j = 1; j <= i; j++)
    {
      if (array[j - 1] > array[j]) {
        std::swap(array[j - 1], array[j]);
        altered_flag = true;
      }
    }
    if (altered_flag || (i == n - 1 && !altered_flag)) {
      print_array(array, n);
    }
  }
  
}

int main(int argc, char const *argv[])
{
  unsigned int n;
  std::cin >> n;

  int array[1000];

  for (size_t i = 0; i < n; i++)
  {
    std::cin >> array[i];
  }
  bubble_sort(array, n);
  
  return 0;
}
