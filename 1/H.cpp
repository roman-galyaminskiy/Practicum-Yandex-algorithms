#include <algorithm>
#include <iostream>
#include <string>

std::string binary_sum(std::string term1, std::string term2)
{
  std::string greater;
  std::string less;

  if (term1.size() > term2.size()) {
    greater = term1;
    less = term2;
  }
  else 
  {
    greater = term2;
    less = term1;
  }
  // std::cout << "binary_sum: greater=" << greater << " less=" << less << '\n';

  std::string result;
  char buf = 0;
  for (int32_t i = 0; i < greater.size(); i++)
  {
    char sum;
    // std::cout << (int32_t)greater.size() - i - 1 << ' ' << (int32_t)less.size() - i - 1 << '\n';
    if ((int32_t)less.size() - i - 1 >= 0) {
      // printf(
      //   "greater=%c less=%c\n",
      //   greater[(int32_t)greater.size() - i - 1],
      //   less[(int32_t)less.size() - i - 1]
      // );
      sum = greater[(int32_t)greater.size() - i - 1] - '0' + less[(int32_t)less.size() - i - 1] - '0' + buf;      
    }
    else {
      sum = greater[(int32_t)greater.size() - i - 1] - '0' + buf;
    }
    // printf("sum=%c\n", '0' + sum);

    switch (sum)
    {
    case 0:
      result.push_back('0');
      buf = 0;
      break;
    case 1:
      result.push_back('1');
      buf = 0;
      break;
    case 2:
      result.push_back('0');
      buf = 1;
      break;
    case 3:
      result.push_back('1');
      buf = 1;
      break;
    default:
      break;
    }
  }  
  // printf("buf=%c\n", '0' + buf);
  if (buf == 1) {
    result.push_back('0' + buf);
  }
  
  // std::cout << result << '\n';
  std::reverse(result.begin(), result.end());
  return result;
}

int main()
{
  std::string bin1, bin2;
  std::getline(std::cin, bin1);
  std::getline(std::cin, bin2);

  std::cout << binary_sum(bin1, bin2) << '\n';
  return 0;
}