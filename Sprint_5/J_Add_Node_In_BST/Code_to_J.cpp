#ifndef REMOTE_JUDGE
struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(Node* left, Node* right, int value) : value(value), left(left), right(right) {}
};
#endif

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif
#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;


Node* insert(Node* root, int key) {
    Node* addNode = new Node(nullptr, nullptr, key);
    if (root == nullptr) { return addNode; }

    Node* next_node = root;
    Node* cur_node = nullptr;

    while (next_node != nullptr) {
        cur_node = next_node;
        if (key < next_node->value) {
            next_node = next_node->left;
        }
        else {
            next_node = next_node->right;
        }
    }
    
    if (key < cur_node->value) {
        cur_node->left = addNode;
    }
    else {
        cur_node->right = addNode;
    }
    

    return root;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({ nullptr, nullptr, 7 });
    Node node2({ &node1, nullptr, 8 });
    Node node3({ nullptr, &node2, 7 });
    Node* newHead = insert(&node3, 6);
    assert(newHead->left->value == 6);
    assert(newHead == &node3);
}

int main() {
    test();
}
#endif