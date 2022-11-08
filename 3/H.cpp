#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <array>

const int MAX_ARRAY_SIZE = 1000;

int cmp(int n1, int n2) {
  if (n1 == n2) {
    return 0;
  }

  std::string s1 = std::to_string(n1); 
  std::string s2 = std::to_string(n2); 

  if (std::stoi(s1 + s2) > std::stoi(s2 + s1)) {
    return 1;
  }
  else {
    return -1;
  }
}

void bubble_sort(std::array<int, MAX_ARRAY_SIZE> &array, unsigned int n) {
  for (int i = n - 1; i >= 0; i--)
  {
    bool altered_flag = false;
    for (int j = 1; j <= i; j++)
    {
      // array[j - 1] > array[j]
      if (cmp(array[j - 1], array[j]) == -1) {
        std::swap(array[j - 1], array[j]);
        altered_flag = true;
      }
    }
  }
}

void print_array(const std::array<int, MAX_ARRAY_SIZE> &array,
    size_t n, char separator = ' ') {
  for (size_t i = 0; i < n; i++)
  {
    std::cout << array[i];
    if (separator != '\0' && i < n - 1) {
      std::cout << separator;
    }
  }
  std::cout << '\n';
}

int main(int argc, char const *argv[])
{
  unsigned int n;
  std::cin >> n;

  std::array<int, MAX_ARRAY_SIZE> numbers;

  for (size_t i = 0; i < n; i++)
  {
    std::cin >> numbers[i];
  }
  bubble_sort(numbers, n);
  print_array(numbers, n, '\0');
  return 0;
}
