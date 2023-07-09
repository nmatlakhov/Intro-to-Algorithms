#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#ifndef REMOTE_JUDGE
#include <cassert>
#include <string>
#include<iostream>

struct Node {
    std::string value;
    Node* next;
    Node(const std::string& value, Node* next) : value(value), next(next) {

    }
};
#endif


Node* solution(Node* head, int idx) {
    Node* new_node = head;
    Node* current_node = new_node;
    if (idx == 0) {
        new_node = head->next;
        return new_node;
    }

    while (idx > 1) {
        current_node = current_node->next;
        idx--;
    }
    Node* next_node = current_node->next;
    current_node->next = next_node->next;

    return new_node;
}

#ifndef REMOTE_JUDGE
void test() {
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
}

int main() {
    test();
}
#endif