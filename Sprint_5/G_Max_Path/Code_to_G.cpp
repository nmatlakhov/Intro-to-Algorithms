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
int result = INT8_MIN;

int findMax(const Node* root) {
    if (root == nullptr) { return 0; }


    int leftMax = max(findMax(root->left), 0);
    int rightMax = max(findMax(root->right), 0);

    result = max(result, leftMax + rightMax + root->value);

    return max(leftMax + root->value, rightMax + root->value);
}

int Solution(const Node* root) {
    int max = findMax(root);
    return result;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({ 5, nullptr, nullptr });
    Node node2({ 1, nullptr, nullptr });
    Node node3({ -3, &node2, &node1 });
    Node node4({ 2, nullptr, nullptr });
    Node node5({ 2, &node4, &node3 });
    assert(Solution(&node5) == 6);
}

int main() {
    test();
}
#endif