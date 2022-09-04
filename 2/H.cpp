// Отчет: https://contest.yandex.ru/contest/22450/run-report/69973721/

#include <cassert>
#include <string>
#include <stack>
#include <iostream>

int main() {
    std::stack<int> s; 
    int c;

    do {
        c = getchar();
        
        if (c == '(' || c == '{' || c == '[')
        {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (!s.empty() && (
                (s.top() == '(' && c == ')') ||
                (s.top() == '{' && c == '}') ||
                (s.top() == '[' && c == ']'))
            )
            {
                s.pop();
            }
            else {               
                std::cout << "False\n";
                return 0;
            }
        }
    } while (c != '\n' && c != EOF);

    if (s.empty()) {
        std::cout << "True\n";
    }
    else {
        std::cout << "False\n";
    }

    return 0;
}
