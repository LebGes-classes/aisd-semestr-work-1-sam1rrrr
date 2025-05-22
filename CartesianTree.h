#ifndef CARTESIANTREE_H
#define CARTESIANTREE_H

#pragma once

class CartesianTree {
    struct Node {
        int key;
        int priority;
        Node* left;
        Node* right;

        explicit Node(int k);
    };

    Node* root;

    void merge(Node* left, Node* right, Node*& result);
    void split(Node* node, int key, Node*& left, Node*& right);
    void clear(Node* node);
    void printInOrder(Node* node);

public:
    CartesianTree();
    ~CartesianTree();

    void insert(int key);
    void remove(int key);
    bool find(int key);
    void printInOrder();
};

#endif // CARTESIANTREE_H