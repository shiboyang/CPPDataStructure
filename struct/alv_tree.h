//
// Created by sparkai on 23-8-17.
//

#ifndef CPPDATASTRUCTURE_ALV_TREE_H
#define CPPDATASTRUCTURE_ALV_TREE_H

#include "binary_search_tree.h"

int min(int x, int y) {
    if (x < y)
        return x;
    else
        return y;
}

int max(int x, int y) {
    if (x > y)
        return x;
    else
        return y;
}

class AVLTree : public BinarySearchTree {

public:
    void rotateLeft(Node *rotateNode) {
        auto newNode = rotateNode->rightNode;
        rotateNode->rightNode = newNode->leftNode;
        if (newNode->hasLeftChild()) {
            newNode->leftNode->parent = rotateNode;
        }
        if (rotateNode->isRoot()) {
            root = newNode;
        } else {
            if (rotateNode->isRightChild()) {
                rotateNode->parent->rightNode = newNode;
            } else {
                rotateNode->parent->leftNode = newNode;
            }
        }
        newNode->leftNode = rotateNode;
        newNode->parent = rotateNode->parent;
        rotateNode->parent = newNode;

        rotateNode->balanceFactor = rotateNode->balanceFactor + 1 - min(0, newNode->balanceFactor);
        newNode->balanceFactor = newNode->balanceFactor + 1 - max(rotateNode->balanceFactor, 0);
    }

    void rotateRight(Node *rotateNode) {
        auto newNode = rotateNode->leftNode;
        rotateNode->leftNode = newNode->rightNode;
        if (newNode->hasRightChild()) {
            newNode->rightNode->parent = rotateNode;
        }
        if (rotateNode->isRoot()) {
            root = newNode;
        } else {
            if (rotateNode->isRightChild())
                rotateNode->parent->rightNode = newNode;
            else
                rotateNode->parent->leftNode = newNode;
        }
        newNode->rightNode = rotateNode;
        newNode->parent = rotateNode->parent;
        rotateNode->parent = newNode;

        rotateNode->balanceFactor = rotateNode->balanceFactor - 1 - min(newNode->balanceFactor, 0);
        newNode->balanceFactor = newNode->balanceFactor - 1 - max(0, rotateNode->balanceFactor);
    }

    void rebalance(Node *currentNode) {
        if (currentNode->balanceFactor < -1) {
            // left rotate
            //进行左旋前，先检查旋转节点的右子树是否“左重”，如果左重需要现将右子树右旋
            //然后再对旋转节点进行左旋
            if (currentNode->rightNode->balanceFactor > 1)
                rotateRight(currentNode->rightNode);
            rotateLeft(currentNode);
        } else {
            // right rotate
            // 同理，如果旋转节点的左子树“右重” 需要先把旋转节点的左子树左旋 再对旋转节点进行右旋
            if (currentNode->leftNode->balanceFactor < -1)
                rotateLeft(currentNode->leftNode);
            rotateRight(currentNode);
        }
    }

    void updateBalance(Node *currentNode) {
        if (currentNode->balanceFactor > 1 or currentNode->balanceFactor < -1) {
            rebalance(currentNode);
            return;
        }
        if (currentNode->parent != nullptr) {
            if (currentNode->isLeftChild())
                currentNode->parent->balanceFactor++;
            else
                currentNode->parent->balanceFactor--;

            // In updating the balance factor, if the updated balance factor is equal to 0, then stop updating.
            if (currentNode->parent->balanceFactor != 0) {
                updateBalance(currentNode->parent);
            }
        }
    }

    void put(int key, int val) override {
        if (root == nullptr) {
            root = new Node(key, val);
        } else {
            _put(key, val, root);
        }
        count++;
    }

private:
    void _put(int key, int val, Node *currentNode) {
        if (key < currentNode->key) {
            if (currentNode->hasLeftChild())
                _put(key, val, currentNode->leftNode);
            else {
                currentNode->leftNode = new Node(key, val, currentNode);
                updateBalance(currentNode->leftNode);
            }
        } else {
            if (currentNode->hasRightChild())
                _put(key, val, currentNode->rightNode);
            else {
                currentNode->rightNode = new Node(key, val, currentNode);
                updateBalance(currentNode->rightNode);
            }
        }
    }

};

#endif //CPPDATASTRUCTURE_ALV_TREE_H
