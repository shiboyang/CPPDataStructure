//
// Created by shiby on 23-6-19.
//

#ifndef CPPDATASTRUCTURE_UNORDEREDLIST_H
#define CPPDATASTRUCTURE_UNORDEREDLIST_H


// linked List based List
#include "dequeue.h"


template<typename T, typename Container= DeQueue<T>>
class List {
public:

    List() : container(Container()) {}


    typename Container::value_type front() {
        return container.front();
    }

    typename Container::value_type back() {
        return container.back();
    }

    bool empty() {
        return container.empty();
    }

    int size() {
        return container.size();
    }

    void push_back(T data) {
        container.push_back(data);
    }




private:
    Container container;
    typename Container::node_type *head;
};

#endif //CPPDATASTRUCTURE_UNORDEREDLIST_H
