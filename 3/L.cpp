#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <array>
#include <vector>
#include <utility>
#include <iterator>

using Iterator = std::vector<int>::iterator;
using CIterator = std::vector<int>::const_iterator;

CIterator binary_search1(CIterator begin, CIterator end, int value,  int flag) {
  int dist = std::distance(begin, end);
  CIterator mid = begin;
  std::advance(mid, dist/2);

  if (*mid == value) {
    return mid;
  }
  if (dist < 1) {
    return mid;
  } else if (*mid > value) {
    // влево
    return binary_search1(begin, mid - 1, value, -1);
  } else {
    // вправо
    return binary_search1(mid + 1, end, value, 1);
  }
}

int main(int argc, char const *argv[])
{
  unsigned int n;
  // unsigned int n = 6;
  std::cin >> n;


  std::vector<int> bank;
  // std::vector<int> bank = {1, 2, 4, 4, 6, 8};

  int buf = -1;
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> buf;
    // if (bank.empty() || buf > bank.back()) {
      bank.push_back(buf);
    // }
  }
  
  int price;
  std::cin >> price;
  // price = 3;

  std::pair<int, int> results = std::make_pair(-1, -1);

  if (price <= bank.back()) {
    CIterator result = binary_search1(bank.begin(), bank.end(), price, 0);

    if (result == bank.end()) {
      results.first = -1;
    }
    else {
      if (*result >= price) {
        results.first = std::distance<std::vector<int>::const_iterator>(bank.begin(), result) + 1;
        for (auto ptr = result; ptr >= bank.begin(); ptr--)
        {
          int test = std::distance<std::vector<int>::const_iterator>(bank.begin(), ptr);
          if (*ptr >= price) {
            results.first = std::distance<std::vector<int>::const_iterator>(bank.begin(), ptr) + 1;
          } else {
            break;
          }
        }  
      }
      else {
        results.first = std::distance<std::vector<int>::const_iterator>(bank.begin(), result) + 1;
        for (auto ptr = result; ptr < bank.end(); ptr++)
        {
          int test = std::distance<std::vector<int>::const_iterator>(bank.begin(), ptr);
          if (*ptr >= price) {
            results.first = std::distance<std::vector<int>::const_iterator>(bank.begin(), ptr) + 1;
            break;
          }
        }  
      }
    }
  }  

  price *= 2;
  if (price <= bank.back()) {
    CIterator result = binary_search1(bank.begin(), bank.end(), price, 0);
    
    if (result == bank.end()) {
      results.second = -1;
    }
    else {
      if (*result >= price) {
        results.second = std::distance<std::vector<int>::const_iterator>(bank.begin(), result) + 1;
        for (auto ptr = result; ptr >= bank.begin(); ptr--)
        {
          int test = std::distance<std::vector<int>::const_iterator>(bank.begin(), ptr);
          if (*ptr >= price) {
            results.second = std::distance<std::vector<int>::const_iterator>(bank.begin(), ptr) + 1;
          } else {
            break;
          }
        }  
      }
      else {
        results.second = std::distance<std::vector<int>::const_iterator>(bank.begin(), result) + 1;
        for (auto ptr = result; ptr < bank.end(); ptr++)
        {
          int test = std::distance<std::vector<int>::const_iterator>(bank.begin(), ptr);
          if (*ptr >= price) {
            results.second = std::distance<std::vector<int>::const_iterator>(bank.begin(), ptr) + 1;
            break;
          }
        }  
      }
    }
  }

  std::cout << results.first << ' ' << results.second << '\n';
  // std::cout << results.first << '\n';

  return 0;
}
