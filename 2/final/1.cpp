#include <cassert>
#include <string>
#include <stack>
#include <iostream>

class MyQueueSized
{

public:
    MyQueueSized(int max_size) : max_size_(max_size) {}

    void push_back(int x)
    {
        if (size_ == max_size_)
        {
            std::cout << "error\n";
        }
        else
        {
            buf[tail] = x;
            tail = (tail + 1) % max_size_;
            size_++;
        }
        return;
    }
    
    void push_front(int x)
    {
        if (size_ == max_size_)
        {
            std::cout << "error\n";
        }
        else
        {
            if (head == 0)
            {
                head = max_size_ - 1;
            }
            else
            {
                head--;
            }
            buf[head] = x;
            size_++;
        }
        return;
    }
    
    int *pop_front()
    {
        if (size_ == 0)
        {
            return nullptr;
        }

        int *ptr = &(buf[head]);
        head = (head + 1) % max_size_;
        size_--;
        return ptr;
    }
    
    int *pop_back()
    {
        if (size_ == 0)
        {
            return nullptr;
        }

        if (tail == 0)
        {
            tail = max_size_ - 1;
        }
        else
        {
            tail--;
        }
        size_--;

        return &(buf[tail]);
    }
    
    int *peek()
    {
        if (size_ == 0)
        {
            return nullptr;
        }
        return &(buf[head]);
    }
    
    int size()
    {
        return size_;
    }

private:
    int size_ = 0;
    int max_size_;
    int buf[50000];
    int head = 0;
    int tail = 0;
};

int main()
{
    int n;
    std::cin >> n;
    int max_size;
    std::cin >> max_size;
    MyQueueSized *myqueue = new MyQueueSized(max_size);

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
            myqueue->push_back(val);
        }
        else if (cmd == "push_front")
        {
            std::cin >> arg;
            val = std::stoi(arg);
            myqueue->push_front(val);
        }
        else if (cmd == "pop_front")
        {
            int *ptr = myqueue->pop_front();

            if (ptr != nullptr)
            {
                std::cout << *ptr << '\n';
            }
            else
            {
                std::cout << "error\n";
            }
        }
        else if (cmd == "pop_back")
        {
            int *ptr = myqueue->pop_back();

            if (ptr != nullptr)
            {
                std::cout << *ptr << '\n';
            }
            else
            {
                std::cout << "error\n";
            }
        }        
    }

    return 0;
}
