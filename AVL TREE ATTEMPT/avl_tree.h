#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <map>

struct Node {
    int key;
    std::string value;
    Node* left;
    Node* right;
    int height;
};

class AVLTree {
public:
    AVLTree();

    void insert(int key, const std::string& value);
    std::string search(int key);
    void display();
    void deleteNode(int key);
    std::string index(int index);
    int min();
    int max();
    std::string prev(int key);
    std::string next(int key);

private:
    Node* root;

    int height(Node* node);
    int balanceFactor(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* balance(Node* node);
    Node* insert(Node* node, int key, const std::string& value);
    std::string search(Node* node, int key);
    void display(Node* node, int indent);
    Node* findMinNode(Node* node);
    Node* deleteNode(Node* node, int key);
    int countNodes(Node* node);
    Node* findNodeByIndex(Node* node, int& index);
    Node* findMinNodeWithKey(Node* node);
    Node* findMaxNodeWithKey(Node* node);
    Node* findPrevNode(Node* node, int key);
    Node* findNextNode(Node* node, int key);
};

#endif // AVL_TREE_H
