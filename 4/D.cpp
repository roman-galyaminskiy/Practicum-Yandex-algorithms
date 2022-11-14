#include <iostream>
#include <string>
#include <limits>
#include <array>
#include <vector>
#include <cmath>
#include <tuple>

// В первой строке дано число a - основание, по которому считается хеш.
// Во второй строке дано число m < 10^9 - модуль.
// В третьей строке дана строка s, состоящая из больших и маленьких латинских букв.
long long polynomial_hash(std::string s, long long a, long long m) {
  long long result = 0;

  if (s.size() > 0) {
    for (size_t i = 0; i < s.size() - 1; i++)
    {
      result = ((result + s[i]) * a) & (m - 1);
    }
    result = (result + s[s.size() - 1]) & (m - 1);
  }
  return result;
}

size_t basket(long long hash, size_t size) {
  return hash % size;
}
 
int main(int argc, char const *argv[])
{
  int n; 
  const long long a = 1000000007;
  const long long m = pow(2, 32);
  const int size = 100007;
  std::cin >> n;
  std::array<std::pair<size_t, std::string>, size> hashes;

  for (auto &&i : hashes)
  {
    i.first = 0;
    i.second = "";
  }
  
  std::vector<std::string> strings;
  std::string s;
  std::getline(std::cin, s);
  size_t index;
  for (size_t i = 0; i < n; i++)
  {
    std::getline(std::cin, s);
    index = basket(polynomial_hash(s, a, m), size);
    
    if (hashes[index].second != "" && hashes[index].second != s) {
      std::cout << index << ' ' << s << ' ' << polynomial_hash(s, a, m) << ' ' << hashes[index].second << ' ' << polynomial_hash(hashes[index].second, a, m) << std::endl;
      return 1;
    }

    if (hashes[index].first == 0) {
      strings.push_back(s);
      hashes[index].second = s;
    }
    hashes[index].first++;
  }

  for (auto &&i : strings)
  {
    std::cout << i << '\n';
  }
  std::cout << std::flush;
  
  return 0;
}

// 123
// 100003
// hash