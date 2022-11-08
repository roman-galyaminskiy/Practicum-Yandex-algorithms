// Отчет https://contest.yandex.ru/contest/22781/run-report/70271952/

#include <string>
#include <stack>
#include <iostream>
#include <cmath>

// Взято отсюда: ttps://hg.openjdk.java.net/jdk8/jdk8/jdk/file/687fd7c7986d/src/share/classes/java/lang/Math.java
int floorDiv(int x, int y) {
    int r = x / y;
    if ((x ^ y) < 0 && (r * y != x)) {
        r--;
    }

    return r;
}

int main()
{
    std::string line;
    std::getline(std::cin, line);

    std::stack<int> operands;
    int operand = 0;
    int token;

    size_t i = 0;
    while (i < line.size())
    {
        token = line[i];
        if (token >= '0' && token <= '9')
        {
            int start = i;
            i++;
            while (line[i] != ' ' && i < line.size()) {
                i++;
            }
            operand = std::stoi(line.substr(start, i));  
            operands.push(operand);          
        }
        else if (token == '-') 
        {
            i++;
            token = line[i];

            if (i < line.size() && token >= '0' && token <= '9')
            {
                int start = i - 1;
                i++;
                while (line[i] != ' ' && i < line.size()) {
                    i++;
                }
                operand = std::stoi(line.substr(start, i));  
                operands.push(operand);          
            }
            else {
                int right = operands.top();
                operands.pop();
                int left = operands.top();
                operands.pop();

                operands.push(left - right);
            }
                
        }
        else if (token == '+') {
            int right = operands.top();
            operands.pop();
            int left = operands.top();
            operands.pop();

            operands.push(left + right);
            i++;
        }
        else if (token == '*') {
            int right = operands.top();
            operands.pop();
            int left = operands.top();
            operands.pop();

            operands.push(left * right);
            i++;
        }
        else if (token == '/') {
            int right = operands.top();
            operands.pop();
            int left = operands.top();
            operands.pop();
            operands.push(floorDiv(left, right));
            i++;
        }
        else {
            i++;
        }
    }

    std::cout << operands.top() << '\n';
    return 0;
}
