//
// Created by shiby on 23-6-8.
//

#ifndef CPPDATASTRUCTURE_DEQUE_H
#define CPPDATASTRUCTURE_DEQUE_H

#include <cstdlib>
#include <iostream>

template<typename T>
struct QNode {
    struct QNode<T> *next;
    T data;

    explicit QNode(T data_) : data(data_), next(nullptr) {};
};


// this dequeue is based on a linked ForwardList
template<typename T>
class DeQueue {
public:
    typedef struct QNode<T> node_type;
    typedef T value_type;

    DeQueue() : frontNode(nullptr), rearNode(nullptr), count(0) {};

    ~DeQueue() {
        for (int i = 0; i < count; ++i) {
            node_type *nextNode = frontNode->next;
            delete frontNode;
            frontNode = nextNode;
        }
        std::cout << "delete dequeue" << std::endl;
    }

    bool empty() {
        return count == 0;
    }

    int size() {
        return count;
    }

    value_type front() {
        if (empty()) exit(-1);
        return frontNode->data;
    }

    value_type back() {
        if (empty()) exit(-1);
        return rearNode->data;
    }

    void push_back(T data) {
        auto newNode = new QNode<T>(data);
        if (empty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        count++;
    }

    void push_front(T data) {
        auto newNode = new QNode<T>(data);
        if (empty()) {
            frontNode = rearNode = newNode;
        } else {
            newNode->next = frontNode;
            frontNode = newNode;
        }
        count++;
    }

    void pop_back() {
        if (empty()) exit(-1);
        auto currentNode = frontNode;
        while (currentNode->next == rearNode) {
            currentNode = currentNode->next;
        }

        delete rearNode;
        rearNode = currentNode;
        count--;

    }

    void pop_front() {
        if (empty()) exit(-1);
        auto node = rearNode;
        rearNode = rearNode->next;
        delete node;
        count--;
    }


private:
    node_type *frontNode;
    node_type *rearNode;
    int count = 0;
};

#endif //CPPDATASTRUCTURE_DEQUE_H
