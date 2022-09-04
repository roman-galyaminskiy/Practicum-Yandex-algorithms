#include <cassert>
#include <string>
#include <stack>
#include <iostream>

int main() {
    std::stack<int> s; 
    std::stack<int> max;   
    int n;
    std::cin >> n;

    std::string cmd;
    std::string arg;
    int val;
    for (int i = 0; i < n; i++)
    {
        std::cin >> cmd;
        if (cmd == "push") {
            std::cin >> arg;
            val = std::stoi(arg);
            s.push(val);

            if (max.empty() || val > max.top()) {
                max.push(val);
            }
            else {
                max.push(max.top());
            }
        }
        else if (cmd == "pop")
        {
            if (!s.empty())
            {
                s.pop();
                max.pop();
            }
            else 
            {
                std::cout << "error\n";
            }
        }
        else if (cmd == "get_max") 
        {
            if (!max.empty()) {
                std::cout << max.top() << '\n';
            }
            else {
                std::cout << "None\n";
            }
        }

    }
    
    return 0;
}
