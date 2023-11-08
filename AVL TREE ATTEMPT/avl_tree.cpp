#include "avl_tree.h"
#include <iomanip>
#include <algorithm>

AVLTree::AVLTree() {
    root = nullptr;
}

int AVLTree::height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int AVLTree::balanceFactor(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* AVLTree::balance(Node* node) {
    int bf = balanceFactor(node);

    if (bf > 1) {
        if (balanceFactor(node->left) < 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (bf < -1) {
        if (balanceFactor(node->right) > 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

Node* AVLTree::insert(Node* node, int key, const std::string& value) {
    if (node == nullptr) {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->left = newNode->right = nullptr;
        newNode->height = 1;
        return newNode;
    }

    if (key < node->key)
        node->left = insert(node->left, key, value);
    else if (key > node->key)
        node->right = insert(node->right, key, value);
    else
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));
    return balance(node);
}

void AVLTree::insert(int key, const std::string& value) {
    root = insert(root, key, value);
}

std::string AVLTree::search(Node* node, int key) {
    if (node == nullptr)
        return "Key not found";
    if (key < node->key)
        return search(node->left, key);
    else if (key > node->key)
        return search(node->right, key);
    else
        return node->value;
}

std::string AVLTree::search(int key) {
    return search(root, key);
}

void AVLTree::display(Node* node, int indent) {
    if (node != nullptr) {
        if (node->right)
            display(node->right, indent + 4);
        if (indent > 0)
            std::cout << std::setw(indent) << " ";
        std::cout << node->key << " (" << node->value << ")" << std::endl;
        if (node->left)
            display(node->left, indent + 4);
    }
}

void AVLTree::display() {
    display(root, 0);
}

Node* AVLTree::findMinNode(Node* node) {
    if (node->left)
        return findMinNode(node->left);
    return node;
}

Node* AVLTree::deleteNode(Node* node, int key) {
    if (node == nullptr)
        return node;

    if (key < node->key)
        node->left = deleteNode(node->left, key);
    else if (key > node->key)
        node->right = deleteNode(node->right, key);
    else {
        if (node->left == nullptr || node->right == nullptr) {
            Node* temp = node->left ? node->left : node->right;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }

            delete temp;
        } else {
            Node* temp = findMinNode(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->key);
        }

        if (node == nullptr)
            return node;

        node->height = 1 + std::max(height(node->left), height(node->right));
        return balance(node);
    }
}

void AVLTree::deleteNode(int key) {
    root = deleteNode(root, key);
}

int AVLTree::countNodes(Node* node) {
    if (node == nullptr)
        return 0;
    return countNodes(node->left) + countNodes(node->right) + 1;
}

Node* AVLTree::findNodeByIndex(Node* node, int& index) {
    if (node == nullptr)
        return nullptr;

    int leftCount = countNodes(node->left);

    if (index < leftCount)
        return findNodeByIndex(node->left, index);
    else if (index == leftCount)
        return node;
    else {
        index -= (leftCount + 1);
        return findNodeByIndex(node->right, index);
    }
}

std::string AVLTree::index(int index) {
    if (index < 0 || index >= countNodes(root))
        return "Index out of bounds";
    
    Node* node = findNodeByIndex(root, index);
    return node->value;
}

Node* AVLTree::findMinNodeWithKey(Node* node) {
    if (node->left)
        return findMinNodeWithKey(node->left);
    return node;
}

Node* AVLTree::findMaxNodeWithKey(Node* node) {
    if (node->right)
        return findMaxNodeWithKey(node->right);
    return node;
}

int AVLTree::min() {
    Node* node = findMinNodeWithKey(root);
    return node->key;
}

int AVLTree::max() {
    Node* node = findMaxNodeWithKey(root);
    return node->key;
}

Node* AVLTree::findPrevNode(Node* node, int key) {
    if (node == nullptr)
        return nullptr;

    if (key <= node->key)
        return findPrevNode(node->left, key);

    Node* rightPrev = findPrevNode(node->right, key);
    return rightPrev ? rightPrev : node;
}

std::string AVLTree::prev(int key) {
    Node* node = findPrevNode(root, key);
    return (node == nullptr) ? "No predecessor" : node->value;
}

Node* AVLTree::findNextNode(Node* node, int key) {
    if (node == nullptr)
        return nullptr;

    if (key >= node->key) {
        // If the key is greater or equal, the successor might be in the right subtree
        Node* rightNext = findNextNode(node->right, key);
        return rightNext ? rightNext : nullptr;
    } else {
        // If the key is smaller, the successor might be in the left subtree or this node
        Node* leftNext = findNextNode(node->left, key);
        return leftNext ? leftNext : node;
    }
}

std::string AVLTree::next(int key) {
    Node* node = findNextNode(root, key);
    return (node == nullptr) ? "No successor" : node->value;
}
