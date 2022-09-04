#include <iostream>

int main() {
  int rows, cols;
  std::cin >> rows >> cols;

  short int matrix[1000][1000];

  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      std::cin >> matrix[j][i];
    }    
  }

  for (size_t i = 0; i < cols; i++)
  {
    for (size_t j = 0; j < rows; j++)
    {
      std::cout << matrix[i][j];

      if (j < rows - 1)
      {
        std::cout << ' ';
      }
    }    
    std::cout << '\n';
  }
  std::cout << '\n';

  return 0; 
}