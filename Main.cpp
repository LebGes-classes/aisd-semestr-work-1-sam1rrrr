#include "CartesianTree.h"
#include <iostream>

using namespace std;

int main() {
    CartesianTree tree;
    
    tree.insert(228);
    tree.insert(1337);
    tree.insert(1488);
    tree.insert(69);
    tree.insert(11);
    tree.insert(11111999);

    tree.printInOrder();

    int key = 0;
    cout << (tree.find(key)) << "\n";

    key = 1488;
    cout << (tree.find(key)) << "\n";

    tree.remove(1488);
    tree.printInOrder();

    tree.remove(228);
    tree.printInOrder();

    return 0;
}