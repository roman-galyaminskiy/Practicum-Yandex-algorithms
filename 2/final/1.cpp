// Отчет: https://contest.yandex.ru/contest/22781/run-report/70832502/

#include <cassert>
#include <string>
#include <stack>
#include <iostream>
#include <optional>

class MyCircularDequeue
{

public:
    MyCircularDequeue(int max_size) : max_size_(max_size) {}

    bool push_front(int x)
    {
        if (size_ == max_size_)
        {
            return false;
        }
        head = (head == 0 ? max_size_ : head) - 1;
        buf[head] = x;
        size_++;
        return true;
    }
    
    std::optional<int> pop_front()
    {
        if (size_ == 0)
        {
            return {};
        }
        int result = buf[head];
        head = (head + 1) % max_size_;
        size_--;
        return result;
    }

    bool push_back(int x)
    {
        if (size_ == max_size_)
        {
            return false;
        }
        buf[tail] = x;
        tail = (tail + 1) % max_size_;
        size_++;
        return true;
    }
        
    std::optional<int> pop_back()
    {
        if (size_ == 0)
        {
            return {};
        }
        tail = (tail == 0 ? max_size_ : tail) - 1;
        size_--;
        return buf[tail];
    }

private:
    static const int max_buf_size = 50000;
    int buf[max_buf_size];
    int size_ = 0;
    int max_size_;
    int head = 0;
    int tail = 0;
};

int main()
{
    int n;
    std::cin >> n;
    int max_size;
    std::cin >> max_size;
    MyCircularDequeue *myqueue = new MyCircularDequeue(max_size);

    std::string cmd;
    std::string arg;
    int val;
    for (int i = 0; i < n; i++)
    {
        std::cin >> cmd;
        if (cmd == "push_back")
        {
            std::cin >> arg;
            val = std::stoi(arg);
            if(!myqueue->push_back(val)) {
                std::cout << "error\n";
            }
        }
        else if (cmd == "push_front")
        {
            std::cin >> arg;
            val = std::stoi(arg);
            if(!myqueue->push_front(val)) {
                std::cout << "error\n";
            };
        }
        else if (cmd == "pop_front")
        {
            std::optional<int> val = myqueue->pop_front();
            if (val.has_value()) {
                std::cout << val.value() << '\n';
            } else {
                std::cout << "error\n";
            }
        }
        else if (cmd == "pop_back")
        {
            std::optional<int> val = myqueue->pop_back();
            if (val.has_value()) {
                std::cout << val.value() << '\n';
            } else {
                std::cout << "error\n";
            }
        }        
    }

    return 0;
}
