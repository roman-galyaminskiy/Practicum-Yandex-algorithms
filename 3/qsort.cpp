#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

std::vector<int> partition(std::vector<int> array, int pivot_index) {
  if (array.size() > 1) {
    int j = -1;
    int pivot_value = array[pivot_index];
    std::swap(array[pivot_index], array[array.size() - 1]);

    for (size_t i = 0; i < array.size() - 1; i++)
    {
      if (array[i] < pivot_value) {
        j++;
        std::swap(array[i], array[j]);
      }
    }

    for (size_t i = j; i < array.size() - 1; i++)
    {
      array[i + 1] = array[i];
    }
    array[j + 1] = pivot_value;    
  }
  return array;
}

std::vector<int> qsort(std::vector<int> input) {
  if (input.size() > 1) {
    std::srand(time(NULL));
    int random = std::rand() % input.size();

    return combine(less(input, input[random]), greater(input, input[random]));
  }
  return input;
}


int main(int argc, char const *argv[])
{
  std::vector<int> v = {4, 1, 3, 2, 6, 8};
  std::vector<int> result = qsort(v);

  for (auto &&i : result)
  {
    std::cout << i;
  }
  std::cout << '\n';

  return 0;
}
