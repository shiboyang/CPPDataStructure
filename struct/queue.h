//
// Created by shiby on 23-6-6.
//

#ifndef CPPDATASTRUCTURE_QUEUE_H
#define CPPDATASTRUCTURE_QUEUE_H


#include <cstdlib>

// this queue is implemented by array.
// the front of queue return array[0]
// the back of queue return array[currentSize-1]

template<typename T>
class Queue {
public:
    explicit Queue(int size_);

    ~Queue();

    T front();

    T back();

    bool empty();

    unsigned int size();

    void push(T item);

    void pop();

private:
    T *container;
    unsigned int totalSize = 10;
    unsigned int currentSize = 0;
};

template<typename T>
Queue<T>::Queue(int size_) {
    totalSize = size_;
    container = new T[totalSize];
}

template<typename T>
Queue<T>::~Queue() {
    delete container;
}

template<typename T>
T Queue<T>::front() {
    if (empty()) exit(-1);
    return container[0];
}

template<typename T>
T Queue<T>::back() {
    if (empty()) exit(-1);
    return container[currentSize - 1];
}

template<typename T>
bool Queue<T>::empty() {
    return currentSize == 0;
}

template<typename T>
unsigned int Queue<T>::size() {
    return currentSize;
}

template<typename T>
void Queue<T>::push(T item) {
    if (currentSize >= totalSize) return;
    container[currentSize++] = item;
}

template<typename T>
void Queue<T>::pop() {
    if (empty()) return;
    for (int i = 0; i < currentSize; ++i) {
        container[i] = container[i + 1];
    }
    currentSize--;
}


#endif //CPPDATASTRUCTURE_QUEUE_H
