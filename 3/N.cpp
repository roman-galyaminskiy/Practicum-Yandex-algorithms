#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <array>
#include <vector>
#include <utility>
	
using Iterator = std::vector<std::pair<int, int>>::iterator;
using CIterator = std::vector<std::pair<int, int>>::const_iterator;

void print(std::vector<std::pair<int, int>> a) {
  for (auto &&i : a)
  {
    // std::cout << '[' << i.first << ' ' << i.second << "]\n"; 
    std::cout << i.first << ' ' << i.second << '\n'; 
  }
}


int cmp(std::pair<int, int> left, std::pair<int, int> right) {
  if (left.first > right.first) {
    return 1;
  } else if (left.first == right.first) {
     if (left.second > right.second) {
      return 1;
    } else if (left.first == right.first) {
      return 0;
    } else {
      return -1;
    }
  } else {
    return -1;
  }
}

std::vector<std::pair<int, int>> merge(
	CIterator left_begin, CIterator left_end, 
	CIterator right_begin, CIterator right_end) {
	
  std::vector<std::pair<int, int>> result;

  while (std::distance(left_begin, left_end) > 0 && 
      std::distance(right_begin, right_end) > 0)
  {
    if (cmp(*left_begin, *right_begin) < 1) {
      result.push_back(*left_begin);
      left_begin++;
    } 
    else {
      result.push_back(*right_begin);
      right_begin++;
    }
  }

  for (auto ptr = left_begin; ptr < left_end; ptr++) {
    result.push_back(*ptr);
  }

  for (auto ptr = right_begin; ptr < right_end; ptr++) {
    result.push_back(*ptr);
  }  

  return result;
}

void merge_sort(Iterator begin, Iterator end) {
  int test = std::distance(begin, end);
  if (test > 1) {
    int diff = std::distance(begin, end);
    Iterator left = begin;
    Iterator mid = begin;
    std::advance(mid, diff/2);
    Iterator right = end;

    merge_sort(left, mid);
    merge_sort(mid, right);
    std::vector<std::pair<int, int>> merged = merge(left, mid, mid, right);
    
    for (Iterator ptr = begin; ptr < end; ptr++)
    {
      int i = std::distance(begin, ptr);
      *ptr = merged[i];
    }
    
  }
}

int main(int argc, char const *argv[])
{
  unsigned int n;
  std::cin >> n;

  std::vector<std::pair<int, int>> pairs;

  int left, right;
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> left >> right;
    pairs.push_back(std::make_pair(left, right));
  }
  merge_sort(pairs.begin(), pairs.end());
  // print(pairs);

  std::vector<std::pair<int, int>> result;

  // std::cout << "######\n";
  left = -1;
  right = -1;
  for (auto &&pair : pairs)
  {
    if (pair.first <= right) {
      if (pair.second > right) {
        right = pair.second;
      }
    }
    else {
      if (left > -1 && right > -1) {
        result.push_back(std::make_pair(left, right));
      }
      left = pair.first;
      right = pair.second;
    }
  }
  result.push_back(std::make_pair(left, right));
  
  print(result);
  return 0;
}
