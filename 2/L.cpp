#include <string>
#include <iostream>

long int powi (int base, unsigned int exp)
{
    int res = 1;
    while (exp) {
        if (exp & 1)
            res *= base;
        exp >>= 1;
        base *= base;
    }
    return res;
}

int fib(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int i, n, k;
    i = 2;
    std::cin >> n;
    std::cin >> k;

    long int prev_prev = 1; 
    long int prev = 1;

    while (i <= n)
    {
        long int cur = (prev_prev + prev) % (powi(10, k));
        prev_prev = prev;
        prev = cur;
        i++;
    }

    std::cout << prev << '\n';
    return 0;
}
