//
// Created by sparkai on 23-8-15.
//
#include "binary_tree.h"
#include <iostream>
#include <sstream>


void test_traversal_binary_tree(const BinaryTree &tree) {
    std::cout << "Preorder: " << std::endl;
    tree.preorder();
    std::cout << "Inorder: " << std::endl;
    tree.inorder();
    std::cout << "PostOrder: " << std::endl;
    tree.postorder();
}


int main() {
    BinaryTree tree('1');
    tree.insertLeft('2');
    tree.insertRight('3');
    tree.insertLeft('4');
    tree.insertLeft('5');
    tree.insertRight('6');
    test_traversal_binary_tree(tree);


    return 0;
}