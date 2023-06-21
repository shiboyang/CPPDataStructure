//
// Created by shiby on 23-6-8.
//

#ifndef CPPDATASTRUCTURE_DEQUEUE_H
#define CPPDATASTRUCTURE_DEQUEUE_H

#include <cstdlib>

template<typename T>
struct QNode {
    struct QNode<T> *next;
    T data;

    explicit QNode(T data_) : data(data_), next(nullptr) {};
};


// this dequeue is implemented by linked List
template<typename T>
class DeQueue {
public:
    typedef struct QNode<T> node_type;
    typedef T value_type;

    DeQueue() : frontNode(nullptr), rearNode(nullptr), currentCount(0) {};

    bool empty() {
        return currentCount == 0;
    }

    int size() {
        return currentCount;
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
        currentCount++;
    }

    void push_front(T data) {
        auto newNode = new QNode<T>(data);
        if (empty()) {
            frontNode = rearNode = newNode;
        } else {
            newNode->next = frontNode;
            frontNode = newNode;
        }
        currentCount++;
    }

    void pop_back() {
        if (empty()) exit(-1);
        auto currentNode = frontNode;
        while (currentNode->next == rearNode) {
            currentNode = currentNode->next;
        }

        delete rearNode;
        rearNode = currentNode;
        currentCount--;

    }

    void pop_front() {
        if (empty()) exit(-1);
        auto node = rearNode;
        rearNode = rearNode->next;
        delete node;
        currentCount--;
    }


private:
    node_type *frontNode;
    node_type *rearNode;
    int currentCount = 0;
};

#endif //CPPDATASTRUCTURE_DEQUEUE_H
