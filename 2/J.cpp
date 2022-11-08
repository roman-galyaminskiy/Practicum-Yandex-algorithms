#include <cassert>
#include <string>
#include <stack>
#include <iostream>

// В первой строке записано количество команд n — целое число, не превосходящее 1000. В каждой из следующих n строк записаны команды по одной строке. 

struct Node {
    int value_ = 0;
    Node *next_ = nullptr;
    Node *prev_ = nullptr;

    Node(int value) : value_{value} {}
    // Node(Node* prev, int value) : prev_{prev}, value_{value}  {}

    void set_next(Node* next) {
        next_ = next;
    }

    void set_prev(Node* prev) {
        prev_ = prev;
    }

    void set_data(int value) {
        value_ = value;
    }

    
};

class QueueUsingDoublyLinkedList {
public:
    void put(int value) {
        if (size_ == 0) {
            Node* node = new Node(value);
            head_ = node;
            tail_ = node;
        }
        else 
        {
            Node* node = new Node(value);
            tail_->next_ = node;
            node->prev_ = tail_;
            tail_ = node;
        }
        size_++;
        return;
    }

    void get() {
        if (size_ == 0) {
            std::cout << "error\n";
        }
        else {
            int value = head_->value_;
            Node* old_head = head_;
            head_ = old_head->next_; 

            if (head_) {
                head_->prev_ = nullptr;
            }
            delete(old_head);
            size_--;
            std::cout << value << '\n';
        }
    }

    void size() {
        std::cout << size_ << '\n';
    }
private:
    int size_ = 0;
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
};

int main() {
    int n;
    std::cin >> n;


    std::string cmd;
    std::string arg;
    int val;

    QueueUsingDoublyLinkedList* queue = new QueueUsingDoublyLinkedList;

    for (int i = 0; i < n; i++)
    {
        std::cin >> cmd;
        if (cmd == "put") {
            std::cin >> arg;
            val = std::stoi(arg);
            queue->put(val);
        }
        else if (cmd == "get")
        {
            queue->get();
        }
        else if (cmd == "size") 
        {
            queue->size();
        }

    }
    
    return 0;
}
