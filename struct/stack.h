//
// Created by shiby on 23-6-3.
//

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#include <iostream>

template<typename T>
class Stack {

public:
    explicit Stack(int size_);

    ~Stack();

    bool empty();

    void push(T item);

    void pop();

    T top();

    int size();

private:
    T *container;
    int totalSize;
    int currentSize = 0;
};

template<typename T>
Stack<T>::Stack(int size_) {
    container = new T[size_];
    totalSize = size_;
    currentSize = 0;
}

template<typename T>
Stack<T>::~Stack() {
    delete container;
}

template<typename T>
bool Stack<T>::empty() {
    return currentSize == 0;
}

template<typename T>
void Stack<T>::push(T item) {
    if (currentSize < totalSize) {
        container[currentSize++] = item;
    } else {
        exit(-1);
    }
}

template<typename T>
void Stack<T>::pop() {
    if (!empty()) currentSize--;
}

template<typename T>
T Stack<T>::top() {
    if (!empty()) {
        return container[currentSize - 1];
    } else {
        exit(-1);
    }
}

template<typename T>
int Stack<T>::size() {
    return totalSize;
}


#endif //DATASTRUCTURE_STACK_H
