
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#ifndef REMOTE_JUDGE
#include <cassert>
#include <string>

struct Node {  
    std::string value;  
    Node* next;  
    Node(const std::string &value, Node* next) : value(value), next(next) {
        
    }
};
#endif


Node* solution(Node* head, int idx) {
    // Your code
    int i = 0;
    Node* prev = nullptr;
    Node* node = head;
    while (node) {
        if (i == idx) {
            // removing head
            if (prev == nullptr) {
                return node->next;
            }
            else {
                prev->next = node->next;
            }
        }
        prev = node;
        node = node->next;
        i++;
    }
    return head;
}

#ifndef REMOTE_JUDGE
void test() {
    // {
        Node node3("node3", nullptr);
        Node node2("node2", &node3);
        Node node1("node1", &node2);
        Node node0("node0", &node1);
        Node* new_head = solution(&node0, 1);
        assert(new_head == &node0);
        assert(new_head->next == &node2);
        assert(new_head->next->next == &node3);
        assert(new_head->next->next->next == nullptr);
        // result is : node0 -> node2 -> node3
    // }
    // {
    //     Node node3("node3", nullptr);
    //     Node node2("node2", &node3);
    //     Node node1("node1", &node2);
    //     Node node0("node0", &node1);
    //     Node* new_head = solution(&node0, 0);
    //     assert(new_head == &node1);
    //     assert(new_head->next == &node2);
    //     assert(new_head->next->next == &node3);
    //     assert(new_head->next->next->next == nullptr);
    // }
    // {
    //     Node node3("node3", nullptr);
    //     Node node2("node2", &node3);
    //     Node node1("node1", &node2);
    //     Node node0("node0", &node1);
    //     Node* new_head = solution(&node0, 3);
    //     assert(new_head == &node0);
    //     assert(new_head->next == &node1);
    //     assert(new_head->next->next == &node2);
    //     assert(new_head->next->next->next == nullptr);
    // }
}

int main() {
    test();
}
#endif