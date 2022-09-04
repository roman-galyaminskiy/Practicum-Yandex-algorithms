#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>

#ifndef REMOTE_JUDGE

#include <string>

struct Node {  
    std::string value;  
    Node* next;  
    Node(const std::string &value, Node* next) : value(value), next(next) {}
};

#endif


void solution(Node* head) {
    // Your code
    Node* node = head;
    while (node) 
    {
        std::cout << node->value << '\n';
        node = node->next;
    }
}

#ifndef REMOTE_JUDGE
void test() {
    Node node3("node3", nullptr);
    Node node2("node2", &node3);
    Node node1("node1", &node2);
    Node node0("node0", &node1);
    solution(&node0);
    
    // Node node5("node5", nullptr);
    // solution(&node5);
    
    /*
    Output is:
    node0
    node1
    node2
    node3
    */
}

int main() {
    test();
}
#endif