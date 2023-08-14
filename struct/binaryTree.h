//
// Created by sparkai on 23-8-14.
//

#ifndef CPPDATASTRUCTURE_BINARYTREE_H
#define CPPDATASTRUCTURE_BINARYTREE_H

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

    char getRootValue() {
        return data;
    }


};

#endif //CPPDATASTRUCTURE_BINARYTREE_H