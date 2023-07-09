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


void print_range(Node* root, int l, int r) {
    if (root == nullptr) {
        return;
    }
    
    if (root->value < l) { 
        print_range(root->right, l, r); 
    }
    else if (root->value >= l) { 
        print_range(root->left, l, r); 
        
        if (root->value <= r) { 
            cout << root->value << " ";
            print_range(root->right, l, r); 
        }

    }

}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({ nullptr, nullptr, 2 });
    Node node2({ nullptr, &node1, 1 });
    Node node3({ nullptr, nullptr, 8 });
    Node node4({ nullptr, &node3, 8 });
    Node node5({ &node4, nullptr, 9 });
    Node node6({ &node5, nullptr, 10 });
    Node node7({ &node2, &node6, 5 });
    print_range(&node7, 2, 8);
    // expected output: 2 5 8 8
}

//void test2() {
//    Node node1({ nullptr, nullptr, 900 });
//    Node node2({ nullptr, nullptr, 1550});
//    Node node3({ nullptr, nullptr, 1800 });
//    Node node4({ nullptr, nullptr, 2200 });
//    Node node5({ &node2, nullptr, 1600 });
//    Node node6({ &node1, &node5, 1400 });
//    Node node7({ &node3, &node4, 2000 });
//    Node node8({ &node6, &node7, 1600 });
//    print_range(&node8, 1500, 1900);
//    // expected output: 2 5 8 8
//}

int main() {
    test();
}
#endif