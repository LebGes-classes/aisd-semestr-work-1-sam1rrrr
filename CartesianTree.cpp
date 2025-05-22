#include <iostream>
#include <cstdlib>
#include "CartesianTree.h"

using namespace std;

CartesianTree::Node::Node(int k) : key(k), priority(rand()), left(NULL), right(NULL) {}

CartesianTree::CartesianTree() : root(NULL) { srand(time(0)); }

CartesianTree::~CartesianTree() { clear(root); }

void CartesianTree::merge(Node* left, Node* right, Node*& result) {
    if (!left)
    {
        result = right;
        return;
    }
    if (!right)
    {
        result = left;
        return;
    }

    if (left->priority > right->priority)
    {
        merge(left->right, right, left->right);
        result = left;
    }
    else
    {
        merge(left, right->left, right->left);
        result = right;
    }
}

void CartesianTree::split(Node* node, int key, Node*& left, Node*& right) {
    if (!node)
    {
        left = right = NULL;
        return;
    }

    if (node->key <= key)
    {
        split(node->right, key, node->right, right);
        left = node;
    }
    else
    {
        split(node->left, key, left, node->left);
        right = node;
    }
}

void CartesianTree::clear(Node* node) {
    if (!node)
    {
        return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
}

void CartesianTree::printInOrder(Node* node) {
    if (!node)
    {
        return;
    }
    printInOrder(node->left);
    cout << node->key << " ";
    printInOrder(node->right);
}

void CartesianTree::insert(int key) {
    Node* left = NULL;
    Node* right = NULL;
    split(root, key, left, right);

    Node* newNode = new Node(key);
    merge(left, newNode, left);
    merge(left, right, root);
}

void CartesianTree::remove(int key) {
    Node* left = NULL;
    Node* middle = NULL;
    Node* right = NULL;

    split(root, key - 1, left, middle);
    split(middle, key, middle, right);

    merge(left, right, root);
}

bool CartesianTree::find(int key) {
    Node* left = NULL;
    Node* middle = NULL;
    Node* right = NULL;

    split(root, key - 1, left, middle);
    split(middle, key, middle, right);

    bool found = (middle != NULL);

    merge(left, middle, left);
    merge(left, right, root);

    return found;
}

void CartesianTree::printInOrder() {
    printInOrder(root);
    cout << endl;
}