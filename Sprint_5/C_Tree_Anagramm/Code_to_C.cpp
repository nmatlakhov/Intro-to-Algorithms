﻿#ifndef REMOTE_JUDGE
struct Node {
    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
    Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};
#endif

#ifdef REMOTE_JUDGE
#include "solution_tree.h"
#endif
#include <cmath>
#include <iostream>
#include <cassert>


using namespace std;

bool isMirror(const Node* left, const Node* right) {
    if ((left == nullptr) & (right == nullptr)) {return true;}

    if ((left == nullptr) | (right == nullptr)) { return false; }
    
    return (left->value == right->value) & isMirror(left->left, right->right) & isMirror(left->right, right->left);
}

bool Solution(const Node* root) {
    if (root == nullptr) { return true; }
    else {
        return isMirror(root->left, root->right);
    }
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({ 3, nullptr, nullptr });
    Node node2({ 4, nullptr, nullptr });
    Node node3({ 4, nullptr, nullptr });
    Node node4({ 3, nullptr, nullptr });
    Node node5({ 2, &node1, &node2 });
    Node node6({ 2, &node3, &node4 });
    Node node7({ 1, &node5, &node6 });
    assert(Solution(&node7));
}


int main() {
    test();
}
#endif