/*https://contest.yandex.ru/contest/24810/run-report/81539258/*/
/*
ПРИНЦИП РАБОТЫ:
Описан по ходу функции.

ВРЕМЕННАЯ СЛОЖНОСТЬ
Поиску нужной вершины в BST займет в худшем случае O(h), где h - высота дерева. Худший случай - когда узел будет находится в листе дерева.

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ
Чтобы хранить локальные переменные и адрес возврата на каждом уровне рекурсии требуется O(h) памяти на стэке, где h - высота дерева => высота рекурсии.

*/


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
#include <cassert>


Node* remove(Node* root, int key) {
    //Если узел пустой, то вернем нулевой указатель
    if (root == nullptr) { return nullptr;}

    //Если значение узла больше, чем искомый ключ, то будем рекурсивно искать значение в левом потомке
    if (key < root->value) { root->left = remove(root->left, key);}

    //Если значение узла меньше, чем искомый ключ, то будем рекурсивно искать значение в правом потомке
    if (root->value < key) { root->right = remove(root->right, key); }
    
    //Если значение узла совпадает с искомым ключом, то мы удалим этот узел
    if(root->value == key) {

        //Если у узла нет потомков, то возвращаем ссылку на нулевой указатель => указатель на этот узел исчезнет и он будет удален из памяти (считаем, что удален)
        if ((root->left == nullptr) & (root->right == nullptr)) { return nullptr; }

        //Если у узла есть правый потомок, но нет левого => возвращаем указатель на правого потомка, элемент справа по свойству BST был больше (или равен), чем его прародитель
        if ((root->left == nullptr) & (root->right != nullptr)) { return root->right; }

        //Если у узла есть левый потомок, но нет правого => возвращаем указатель на левого потомка, элемент слева по свойству BST был меньше, чем его прародитель
        if (root->right == nullptr) { return root->left; }

        //Если у узла были оба потомка, то мы будем искать самую правую вершину в левом потомке

        //Выберем дерево левого потомка
        Node* curNode = root->left;

        //Ищем самую правую вершину (у неё правый потомок будет нулевым указателем)
        while (curNode->right != nullptr) {
            curNode = curNode->right;
        }

        //Заменяем значение в узле на значение в самом правой вершине левого потомка. Её значение будет больше всех значений в левом поддереве удаляемой вершины и
        //меньше, либо равно всем значениям в правом поддереве удаляемой вершины
        root->value = curNode->value;

        //После чего мы удаляем самую правую вершину рекурсивно
        root->left = remove(root->left, curNode->value);
    }
  
    //Возвращаем ссылку на корень измененного дерева
    return root;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({ nullptr, nullptr, 2 });
    Node node2({ &node1, nullptr, 3 });
    Node node3({ nullptr, &node2, 1 });
    Node node4({ nullptr, nullptr, 6 });
    Node node5({ &node4, nullptr, 8 });
    Node node6({ &node5, nullptr, 10 });
    Node node7({ &node3, &node6, 5 });
    Node* newHead = remove(&node7, 10);
    assert(newHead->value == 5);
    assert(newHead->right == &node5);
    assert(newHead->right->value == 8);
}

int main() {
    test();
}
#endif