#include <string>
#include <stack>
#include <iostream>

int main()
{
    std::string line;
    std::getline(std::cin, line);

    std::stack<int> operands;
    int operand = 0;
    int token;
    char minus_operator_flag = 0;

    size_t i = 0;
    while (i < line.size())
    {
        token = line[i];
        if (token >= '0' && token <= '9')
        {
            size_t j = i;
            while (line[j] != ' ' && j < line.size()) {
                j++;
            }
            operand = std::stoi(line.substr(i, j));            
        }
    }


    std::cout << operands.top() << '\n';
    return 0;
}
