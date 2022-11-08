#include <iostream>
#include <string>

void func(int n, std::string s, int c) {
  if (c < 0) {
    return;
  }
  if (n == 0) {
    for (size_t i = 0; i < c; i++)
    {
      s = s + ')';
    }
    
    std::cout << s << '\n';
  }
  else {
    func(n - 1, s + '(', c + 1);
    func(n, s + ')', c - 1);
  }
} 

int main(int argc, char const *argv[])
{
  int n;
  std::cin >> n;
  func(n - 1, "(", 1);


  return 0;
}
