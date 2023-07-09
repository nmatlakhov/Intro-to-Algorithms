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

int calcNodeSum(const Node* root, int initial_sum) {
    if ((root->left == nullptr) & (root->right == nullptr)) { return root->value + 10* initial_sum; }

    int result = 0;
    if (root->left != nullptr) { result += calcNodeSum(root->left, initial_sum * 10 + root->value ); }
    if (root->right != nullptr) { result += calcNodeSum(root->right, initial_sum * 10 + root->value ); }

    return result;
}

int Solution(const Node* root) {
    return calcNodeSum(root, 0);
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({ 2, nullptr, nullptr });
    Node node2({ 1, nullptr, nullptr });
    Node node3({ 3, &node1, &node2 });
    Node node4({ 2, nullptr, nullptr });
    Node node5({ 1, &node4, &node3 });
    assert(Solution(&node5) == 275);
}

int main() {
    test();
}
#endif