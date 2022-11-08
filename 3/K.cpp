#include <vector>
#include <cassert>
#include <iterator>

using Iterator = std::vector<int>::iterator;
using CIterator = std::vector<int>::const_iterator;

std::vector<int> merge(
	CIterator left_begin, CIterator left_end, 
	CIterator right_begin, CIterator right_end) {
	
  std::vector<int> result;

  while (std::distance(left_begin, left_end) > 0 && 
      std::distance(right_begin, right_end) > 0)
  {
    if (*left_begin <= *right_begin) {
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
    std::vector<int> merged = merge(left, mid, mid, right);
    
    for (Iterator ptr = begin; ptr < end; ptr++)
    {
      int i = std::distance(begin, ptr);
      *ptr = merged[i];
    }
    
  }
}

void test_merge_sort() {
	std::vector<int> a = {1, 4, 9};
	std::vector<int> b = {2, 10, 11};
	std::vector<int> c = merge(a.cbegin(), a.cend(), b.cbegin(), b.cend());
	std::vector<int> expected = {1, 2, 4, 9, 10, 11};
	assert(c == expected);

  std::vector<int> d = {1, 4, 2, 10, 1, 2};
	std::vector<int> sorted = {1, 1, 2, 2, 4, 10};
	merge_sort(d.begin(), d.end());
	assert(d == sorted);
}

// int main(int argc, char const *argv[])
// {
//   test_merge_sort();
//   return 0;
// }
