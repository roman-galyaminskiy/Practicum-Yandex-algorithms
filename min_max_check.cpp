#include <limits.h>
#include <iostream>
using namespace std;
int main()
{
  printf("%d <= char is %d bits <= %d\n", CHAR_MIN, CHAR_BIT, CHAR_MAX);
  printf("%d <= int <= %d\n", INT_MIN, INT_MAX);
  printf("%d <= unsigned int <= %ld\n", 0, UINT_MAX);
  printf("%d <= short <= %d\n", SHRT_MIN, SHRT_MAX);
  printf("%d <= unsigned short <= %d\n", 0, USHRT_MAX);
  printf("%ld <= long int <= %ld\n", LONG_MIN, LONG_MAX);
  printf("%ld <= unsinged long int <= %lu\n", 0, ULONG_MAX);
  return 0;
}