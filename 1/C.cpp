#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

using matrix_data = std::vector<std::vector<int16_t>>;

class Matrix {
public:
  Matrix(size_t r, size_t c, matrix_data d): rows(r), columns(c), data(d) {} 
  void print_sorted_neightbours(size_t r, size_t c);
private:
  size_t rows;
  size_t columns;
  matrix_data data;
};

void Matrix::print_sorted_neightbours(size_t r, size_t c) {
  // std::cout << r << ' ' << c << std::endl;

  std::vector<int16_t> neightbours;
  if (c + 1 < columns) {
    neightbours.push_back(data[r][c + 1]);
  }
  if ((signed long long)c - 1 >= 0) {
    neightbours.push_back(data[r][c - 1]);
  }
  if (r + 1 < rows) {
    neightbours.push_back(data[r + 1][c]);
  }
  if ((signed long long)r - 1 >= 0) {
    neightbours.push_back(data[r - 1][c]);
  }
  std::sort(neightbours.begin(), neightbours.end());

  for (auto it = begin(neightbours); it != end(neightbours); ++it) {
    if (it == begin(neightbours)) 
    {
      std::cout << *it;
    }
    else
    {
      std::cout << ' ' << *it;
    }
  }
  std::cout << std::endl;
}

Matrix fill_matrix()
{
  size_t n, m;
  int16_t buf;
  std::cin >> n >> m;
  matrix_data data;
  
  for (size_t i = 0; i < n; i++)
  {
    std::vector<std::int16_t> row;
    for (size_t j = 0; j < m; j++)
    {
      std::cin >> buf;
      row.push_back(buf);
    }
    data.push_back(row);
  }

  return Matrix(n, m, data);
}

int main() {  
  Matrix matrix = fill_matrix();
  uint16_t rows, columns;
  std::cin >> rows >> columns;
  matrix.print_sorted_neightbours(rows, columns);
  return 0;
}