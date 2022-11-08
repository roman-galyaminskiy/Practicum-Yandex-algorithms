#include <map>
#include <vector>
#include <string>
#include <iostream>

std::map<int, std::vector<char>> keys;

void func1(std::string s, std::string result) {
  if (s.size() == 0) {
    std::cout << result << ' ';
    return;
  }
  int n = s.front() - '0';
  s.erase(0, 1);
  std::vector<char> n_keys = keys[n];

  for (size_t i = 0; i < n_keys.size(); i++)
  {
    func1(s, result + n_keys[i]);
  }
}

void func(std::string s) {
  int n = s.front() - '0';
  s.erase(0, 1);
  std::vector<char> n_keys = keys[n];

  for (size_t i = 0; i < n_keys.size(); i++)
  {
    func1(s, std::string(1, n_keys[i]));
  }  
}


 
int main(int argc, char const *argv[])
{
  keys[2] = {'a', 'b', 'c'};
  keys[3] = {'d', 'e', 'f'};
  keys[4]= {'g', 'h', 'i'};
  keys[5] = {'j', 'k', 'l'};
  keys[6] = {'m', 'n', 'o'};
  keys[7] = {'p', 'q', 'r', 's'};
  keys[8] = {'t', 'u', 'v'};
  keys[9] = {'w', 'x', 'y' , 'z'};

  std::string s;
  std::vector<std::string> results;
  std::getline(std::cin, s);
  func(s);
  std::cout << '\n';
  return 0;
}
