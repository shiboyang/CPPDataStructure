//
// Created by sparkai on 23-8-14.
//

#ifndef CPPDATASTRUCTURE_BINARY_TREE_H
#define CPPDATASTRUCTURE_BINARY_TREE_H

#include <iostream>

class BinaryTree {
    char data;
    BinaryTree *leftNode;
    BinaryTree *rightNode;

public:

    explicit BinaryTree(char c = ' ') : data(c), leftNode(nullptr), rightNode(nullptr) {};


    BinaryTree *insertLeft(char c) {
        auto *newTree = new BinaryTree(c);
        if (leftNode == nullptr) {
            leftNode = newTree;

        } else {
            newTree->leftNode = leftNode;
            leftNode = newTree;
        }
        return newTree;
    }

    BinaryTree *insertRight(char c) {
        auto *newTree = new BinaryTree(c);
        if (rightNode == nullptr) {
            rightNode = newTree;
        } else {
            newTree->rightNode = rightNode;
            rightNode = newTree;
        }
        return newTree;
    }

    BinaryTree *getRightChild() {
        return rightNode;
    }

    BinaryTree *getLeftChild() {
        return leftNode;
    }

    void setRootValue(char c) {
        data = c;
    }

    char getRootValue() const {
        return data;
    }

    void preorder() const {
        std::cout << data << std::endl;
        if (leftNode != nullptr) leftNode->preorder();
        if (rightNode != nullptr) rightNode->preorder();
    }

    void inorder() const {
        if (leftNode != nullptr) leftNode->inorder();
        std::cout << data << std::endl;
        if (rightNode != nullptr) rightNode->inorder();
    }

    void postorder() const {
        if (leftNode != nullptr) leftNode->postorder();
        if (rightNode != nullptr) rightNode->postorder();
        std::cout << data << std::endl;
    }

};

#endif //CPPDATASTRUCTURE_BINARY_TREE_H