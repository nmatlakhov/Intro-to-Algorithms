#ifndef REMOTE_JUDGE
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

bool checkTree(const Node* root, const Node* left, const Node* right) {
    if (root == nullptr) {
        return true;
    }

    if ((left != nullptr) && (root->value <= left->value)) { return false; }
    if ((right != nullptr) && (root->value >= right->value)) { return false; }

    bool checkRight = checkTree(root->right, root, right);
    bool checkLeft = checkTree(root->left, left, root);

    return checkRight && checkLeft;
}


bool Solution(const Node* root) {
    return checkTree(root, nullptr, nullptr);
}



#ifndef REMOTE_JUDGE
void test() {
    {
        Node node1({ 1, nullptr, nullptr });
        Node node2({ 4, nullptr, nullptr });
        Node node3({ 3, &node1, &node2 });
        Node node4({ 8, nullptr, nullptr });
        Node node5({ 5, &node3, &node4 });
        assert(Solution(&node5));
    }
    {
        Node node1({ 1, nullptr, nullptr });
        Node node2({ 5, nullptr, nullptr });
        Node node3({ 3, &node1, &node2 });
        Node node4({ 8, nullptr, nullptr });
        Node node5({ 5, &node3, &node4 });
        assert(!Solution(&node5));
    }
}


int main() {
    test();
}
#endif