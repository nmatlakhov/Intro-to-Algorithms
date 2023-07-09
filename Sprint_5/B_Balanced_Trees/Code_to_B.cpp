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

int TreeHeight(const Node* root) {
    if (root == nullptr) { return 0; }
    int leftHeight = TreeHeight(root->left);
    if (leftHeight == -1) { return -1; }

    int reightHeight = TreeHeight(root->right);
    if (reightHeight == -1) { return -1; }

    if (abs(leftHeight - reightHeight) > 1) { return -1; }
    else { return max(leftHeight, reightHeight) + 1; }
}

bool Solution(const Node* root) {
    int check = TreeHeight(root);

    if (check > 0) { return true; }
    else { return false; }
}


#ifndef REMOTE_JUDGE
void test() {
    Node node1({ 1, nullptr, nullptr });
    Node node2({ -5, nullptr, nullptr });
    Node node3({ 3, &node1, &node2 });
    Node node4({ 10, nullptr, nullptr });
    Node node5({ 2, &node3, &node4 });
    assert(Solution(&node5));
}

int main() {
    test();
}
#endif