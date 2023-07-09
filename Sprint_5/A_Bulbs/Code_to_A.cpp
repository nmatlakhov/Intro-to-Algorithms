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


int Solution(const Node* root) {
    int cur_value = root->value;
    int cur_max = cur_value;
    if (root->left != nullptr) {
        int left_max = Solution(root->left);
        if (left_max > cur_max) { cur_max = left_max; }
    }
    
    if (root->right != nullptr) {
        int right_max = Solution(root->right);
        if (right_max > cur_max) { cur_max = right_max; }
    }
    return cur_max;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({ 1, nullptr, nullptr });
    Node node2({ -5, nullptr, nullptr });
    Node node3({ 3, &node1, &node2 });
    Node node4({ 2, &node3, nullptr });
    assert(Solution(&node4) == 3);
}

void test2() {
    Node node1({ 14, nullptr, nullptr });
    Node node2({ 15, nullptr, nullptr });
    Node node3({ 3, nullptr, nullptr });
    Node node4({ 0, nullptr, nullptr });
    Node node5({ 1, nullptr, nullptr });

    Node node6({ 8, &node1, &node2 });
    Node node7({ 10, nullptr, &node3 });

    Node node8({ 3, &node6, &node7 });
    Node node9({ 6, &node4, &node5 });

    Node node10({ 2, nullptr, nullptr });
    Node node11({ 5, &node10, &node9 });

    Node node12({ 1, &node8, &node11 });

    assert(Solution(&node12) == 15);
}

int main() {
    test();
    test2();
}
#endif