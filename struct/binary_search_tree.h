//
// Created by sparkai on 23-8-16.
//

#ifndef CPPDATASTRUCTURE_BINARY_SEARCH_TREE_H
#define CPPDATASTRUCTURE_BINARY_SEARCH_TREE_H


#include <iostream>

class Node {
public:
    int key;
    int payload;
    Node *leftNode;
    Node *rightNode;
    Node *parent;
public:

    Node(int key_, int payload_, Node *parent_ = nullptr, Node *leftNode_ = nullptr, Node *rightNode_ = nullptr)
            : key(key_), payload(payload_), leftNode(leftNode_), rightNode(rightNode_), parent(parent_) {};

    ~Node() {
        // todo remember to destroy allocated memory.
    };


    bool hasLeftChild() const {
        return leftNode != nullptr;
    }

    bool hasRightChild() const {
        return rightNode != nullptr;
    }

    bool isLeftChild() {
        return parent and parent->leftNode == this;
    }

    bool isRightChild() {
        return parent and parent->rightNode == this;
    }

    bool isLeaf() const {
        return leftNode == nullptr and rightNode == nullptr;
    }

    bool isRoot() const {
        return parent == nullptr;
    }


};

class BinarySearchTree {
    Node *root;
    int count = 0;
public:
    BinarySearchTree() : root(nullptr) {};

    BinarySearchTree(int key, int val) {
        root = new Node(key, val);
        count++;
    }

    ~BinarySearchTree() {
        delete root;
    };


    /**
     * insert key and payload
     * @param key
     * @param val
     */
    void insert(int key, int val) {
        if (root == nullptr) {
            root = new Node(key, val);
        } else {
            _insert(key, val, root);
        }
        count++;
    }

    /**
     * in-order print
     */
    void inorder() {
        _inorder(root);
    }

    std::pair<bool, int> get(int key) {
        if (root != nullptr) {
            auto res = _get(key, root);
            if (res != nullptr) {
                return {true, res->payload};
            } else {
                return {false, 0};
            }
        } else {
            return {false, 0};
        }
    }

    /**
     * delete node by key
     * @param key
     */
    void remove(int key) {
        if (count > 1) {
            auto res = _get(key, root);
            if (res != nullptr) {
                _remove(key, res);
                delete res;
                count--;
            } else {
                std::cout << "Not find key " << key << std::endl;
            }
        } else {
            if (root->key == key) {
                delete root;
                root = nullptr;
                count--;
            } else {
                std::cout << "Not find key " << key << std::endl;
            }
        }
    }


private:
    /**
     * @note the method does not delete the any node, that only modify the point to,
     * you need manually call delete for deleted key
     * @param key
     * @param currentNode
     */
    void _remove(int key, Node *currentNode) {
        if (currentNode->isLeaf()) {
            // the deleted node do not have child.
            if (currentNode->isLeftChild()) {
                currentNode->parent->leftNode = nullptr;
            } else {
                currentNode->parent->rightNode = nullptr;
            }
            //delete currentNode;

        } else if (currentNode->hasLeftChild() and currentNode->hasRightChild()) {
            // the deleted node has two child.



        } else {
            // the deleted node has one child.
            if (currentNode->hasLeftChild()) {
                if (currentNode->isLeftChild()) {
                    currentNode->parent->leftNode = currentNode->leftNode;
                    currentNode->leftNode->parent = currentNode->parent;
                    //delete currentNode;
                } else if (currentNode->isRightChild()) {
                    currentNode->parent->rightNode = currentNode->leftNode;
                    currentNode->leftNode->parent = currentNode->parent;
                } else {
                    // current node is root node.
                    root = currentNode->leftNode;
                    currentNode->leftNode->parent = nullptr;
                }
            } else {
                if (currentNode->parent->leftNode == currentNode) {
                    currentNode->parent->leftNode = currentNode->rightNode;
                    currentNode->rightNode->parent = currentNode->parent;
                } else if (currentNode->parent->rightNode == currentNode) {
                    currentNode->parent->rightNode = currentNode->rightNode;
                    currentNode->rightNode->parent = currentNode->parent;
                } else {
                    root = currentNode->rightNode;
                    currentNode->rightNode->parent = nullptr;
                }
            }
        }

    }

    Node *_get(int key, Node *currentNode) {
        if (currentNode != nullptr) {
            if (currentNode->key == key) return currentNode;
            if (key < currentNode->key) {
                return _get(key, currentNode->leftNode);
            } else {
                return _get(key, currentNode->rightNode);
            }
        } else {
            return nullptr;
        }

    }


    void _inorder(Node *currentNode) {
        if (currentNode->hasLeftChild()) _inorder(currentNode->leftNode);
        std::cout << currentNode->key << " : " << currentNode->payload << std::endl;
        if (currentNode->hasRightChild()) _inorder(currentNode->rightNode);
    }

    void _insert(int key, int val, Node *currentNode) {
        if (key < currentNode->key) {
            if (currentNode->hasLeftChild()) {
                _insert(key, val, currentNode->leftNode);
            } else {
                currentNode->leftNode = new Node(key, val, currentNode);
            }
        } else {
            if (currentNode->hasRightChild()) {
                _insert(key, val, currentNode->rightNode);
            } else {
                currentNode->rightNode = new Node(key, val, currentNode);
            }
        }
    }

};


#endif //CPPDATASTRUCTURE_BINARY_SEARCH_TREE_H
